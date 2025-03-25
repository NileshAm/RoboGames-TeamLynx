#include "pins.h"
#include "motor_control.h"
#include <Arduino.h>
#include "receiver.h"
#include "restart.h"

unsigned long lastSignalTime = 0; // Tracks last valid SBUS data
int prevWeapon = -1;              // Stores previous weapon value

void setup()
{
    Serial.begin(115200);

    // initilize reciever
    setupReciever();

    /* Initialize motors */
    setupMotors();
}

void loop()
{
    if (sbus_rx.Read())
    {
        /* Get SBUS data */
        data = sbus_rx.data();
        lastSignalTime = millis(); // Update last valid signal time

        // Map SBUS values to motor control range
        int throttle = map(data.ch[THROTTLE_CHANNEL], 172, 1811, 255, -255); // CH1: Throttle
        int steering = map(data.ch[STEERING_CHANNEL], 172, 1811, 255, -255); // CH2: Steering

        // 3-state switch (-1, 0, 1) -1 is the off state.
        int weaponState = map(data.ch[WEAPON_STATE_CHANNEL], 500, 1500, -1, 1); // 3-state switch (-1, 0, 1)

        int weapon = map(data.ch[WEAPON_CHANNEL], 172, 1811, 0, 255); // CH3: Weapon control
        bool killSwitch = (data.ch[KILL_SWITCH_CHANNEL] > 1000);      // CH6: Kill switch


        // Invert steering if that channel is high
        if (data.ch[STEERING_INVERT_CHANNEL] > 1000)
        {
            steering = -1 * steering;
            throttle = -1 * throttle;
        }

        /* Noise Filtering */
        if (abs(throttle) < NOISE_THRESHOLD)
            throttle = 0;
        if (abs(steering) < NOISE_THRESHOLD)
            steering = 0;
        if (weapon < NOISE_THRESHOLD)
            weapon = 0;

        /* Handle failsafe conditions */
        if (data.failsafe || killSwitch)
        {
            Serial.println("⚠️ EMERGENCY STOP! FAILSAFE or KILL SWITCH ACTIVE! ⚠️");
            throttle = 0;
            steering = 0;
            weapon = 0;

            // Stop all motors. not having below two lines can cause serious accidents.
            controlMotors(0, 0);
            controlWeapon(0);

            restart(); // Restart system if kill switch is toggled
        }

        if (data.lost_frame)
        {
            Serial.println("⚠️ FRAME LOST! ⚠️");
        }

        /* Send values to motor control */
        controlMotors(throttle, steering);

        /* Only update the weapon motor if the value changes */
        if (weapon != prevWeapon || weaponState == -1)
        {
            int pwmval;
            if (weaponState == -1)
            { // If weapon is off, stop the motor
                pwmval = 0;
            }
            else if (weaponState == 1)
            {
                pwmval = -1 * weapon; // Reverse the weapon direction
            }
            else
            {
                pwmval = weapon;
            }

            controlWeapon(pwmval);
            prevWeapon = weapon; // Update previous value
        }

        /* Debug Output */
        Serial.print("Throttle: ");
        Serial.print(throttle);
        Serial.print("\tSteering: ");
        Serial.print(steering);
        Serial.print("\tWeapon: ");
        Serial.println(weapon);
        Serial.print("\tKill Switch: ");
        Serial.println(killSwitch ? "ON" : "OFF");
    }

    /* No Signal Timeout - If no SBUS data received in TIMEOUT_MS, stop the bot */
    if (millis() - lastSignalTime > TIMEOUT_MS)
    {
        Serial.println("⛔ NO SIGNAL! STOPPING BOT ⛔");
        controlMotors(0, 0); // Stop all motors
        controlWeapon(0);
    }
}
