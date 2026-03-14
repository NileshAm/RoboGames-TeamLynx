# TeamLynx

<p align="center">
  <img src="/LYNX%20logo.jpg" width="60%">
</p>

<p align="center">
  <img src="/public/9f540a0e-9302-4341-aeda-7d520acef92c.webp" width="45%">
  <img src="/public/e1a06a91-7854-4188-a68a-3fb596bc37df.webp" width="45%">
</p>

In this repository contains the project files for the Team-Lynx battlebot. 

## About
* All the 3D modelling and design is done through solidworks. Assembly can be found [here](drawings-pdf\AssemblyV2.pdf).
* The PCB design use done by using Altium designer.
* Firmware is being ran on a STM32 blue pill for its high performance characteristics.


## Project Structure

```
└── 📁RoboGames-TeamLynx
    └── 📁code
        ├── code.ino
        ├── motor_control.h
        ├── pins.h
        ├── receiver.h
        ├── restart.h
    └── 📁downloads
        └── 📁5840-31zys-1.snapshot.6
            ├── M8 long shaft.stl
            ├── STD D-Shaft.stl
        └── 📁8mm-lead-screw-with-nut-1.snapshot.2
            ├── LeadScrew 8mm x 2mmPitch.JPG
            ├── LeadScrew 8mm x 2mmPitch.SLDPRT
            ├── LeadScrew 8mm x 2mmPitch.STEP
            ├── LeadScrew Nut 8mm x 2mmPitch.JPG
            ├── LeadScrew Nut 8mm x 2mmPitch.SLDPRT
            ├── LeadScrew Nut 8mm x 2mmPitch.STEP
        └── 📁arduino-mega-2560--1.snapshot.8
            ├── ArduinoMega_STEP_AP203.STEP
            ├── ArduinoMega.SLDPRT
        └── 📁arduino-nano-7.snapshot.2
            ├── arduino nano.SLDPRT
        └── 📁avian-4250-800kv-outrunner-brushless....
            └── 📁Outrunner Motor
            ├── Outrunner Motor.STEP
            ├── Screenshot 2023-02-23 193953.png
        └── 📁bts7960-43a-high-power-h-.....
            ├── 8 PIN HEADER, IC, .....
            ├── ALUMINUM ELECTROLYTIC ...
        └── 📁dc-motor-zy6812-100-120w-1.snapshot.4
            ├── DC motor zy6812 100w.SLDPRT
            ├── DC motor zy6812 100w.STEP
            ├── untitled.26.jpg
        └── 📁kfl08-8mm-zinc-aluminum-alloy-....
        └── 📁simple-box-bar-frame-1.snapshot.1
            ├── 11 Table Frame.SLDPRT
    └── 📁drawings
        ├── arduino nano.SLDDRW
        ├── Assembly.SLDDRW
        ├── AssemblyV2.SLDDRW
        .
        .
        .
    └── 📁drawings-pdf
        ├── ArduinoNano.pdf
        ├── ArmourAnnotations.png
        .
        .
        .
        .
    └── 📁laserCutFiles
        ├── BackArmourPlate.DXF
        ├── BottomArmourPlatex2.DXF
        ├── CasterMountx2.DXF
        .
        .
        .
        .
    └── 📁Parts
        └── 📁Vis
            ├── Assembly.mp4
        ├── AcralicPlate.SLDPRT
        ├── arduino nano.SLDPRT
        .
        .
        .
        .
    └── 📁PCB
        └── 📁Lync-main-board
            └── 📁__Previews
                ├── Schematic.SchDocPreview
            └── 📁Integrated Library
                └── 📁ALSR0310K00FE12
                    ├── ALSR0310K00FE12.SchLib
                    ├── ALSR0310K00FE12.STEP
                    ├── RESAD1869W81L1270D457.PcbLib
                .
                .
                .
            └── 📁PCB library
                ├── LM2596S.PcbLib
            └── 📁Schematic library
                ├── LM2596S.SchLib
            ├── 2layer-2oz.RUL
            ├── Logo.png
            ├── Lync-main-board.PrjPcb
            ├── Lync-main-board.PrjPcbStructure
            ├── PCB.PcbDoc
            ├── schematic.pdf
            ├── Schematic.SchDoc
        ├── Lync-main-board.zip
    └── 📁public
        ├── 9f540a0e-9302-4341-aeda-7d520acef92c.webp
        ├── Assembly.glb
        ├── AssemblyV2.STEP
        ├── e1a06a91-7854-4188-a68a-3fb596bc37df.webp
    └── 📁sheet metal parts
        ├── Back brace.SLDPRT
        ├── Back horizontal brace.SLDPRT
        ├── Back plate.SLDPRT
        ├── blade mount.SLDASM
        ├── Bottom brace.SLDPRT
        ├── motor mount level 1.SLDPRT
        ├── motor mount level 2.SLDPRT
        ├── motor mount level 3.SLDPRT
        ├── Top brace.SLDPRT
    ├── .gitignore
    ├── LYNX logo.jpg
    └── README.md
```