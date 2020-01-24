## Welcome to GitHub RoboCar project pages

This is a robotics project run by members of the Parramatta MakerSpace Association (PAMSA).
The aim of this project is to build a small mobile robot for kids.
The robot can be remotely controlled or programmed to accomplish a number of tasks.
We are building this from scratch, learning as we go.
All project data files can be found on our Google Drive. This repo only contains the code that runs on our robot.

### Repo structure

All source code is contained in the src folder.
Configuration files for Visual Studio Code are found in the .vscode folder

### Visual Studio Code configuration

If used, Visual Studio Code should be pre-configured to generate and run code for Arduino.
It means that the Arduino IDE should be installed and all necessary VSC extensions installed:
- Arduino
- C/C++
- C++ Intellisense
VSC natively handles GitHub commands but requires a third party tool to do so. Git GUI will be required to allow VSC to provide Source Control functionality GitHub style.

If necessary, locally update the c_cpp_properties.json file to suit your environment.

---
## Software Architecture

This project uses the Adapter model to teach the students the importance of properly defining component interfaces.
We've also used practices borrowed from UML to define the architecture:

### Packages
Packages encapsulte software elements that define a specific build of the system.
A package is a class that sole purpose is to instantiate and initialise the softwrae for a particular system or set of behaviours.
It creates all necessary components and their respective relationships.

### Components
Components represent physical or logical parts of a system as a single modular software element.
Each component can be developed by one individual or a small team of designers.
Each component is defined by its interface(s) and expected behaviour(s).

## PkgRoboCar
PkgRoboCar is the main build package for the project.
It is intended to only build RoboCar for a single platform (Arduino) at this stage.

## RoboCar components
### CMan
CMan is the nervous system of RoboCar.
Its primary role is to relay information between the other components, processing it as required to satisfy the expect behaviour.

### CCom
CCom is the external communication system of RoboCar.
Its primary role is to receive and send information from and to the remote controller.

### CMot
CCmot is the motion controller.
Its primary role is to control and enable all RoboCar movements.

### CSen
CSen is the sensory interface of RoboCar.
Its primary role is to provide sensory information to CMan to assist the decision making process.

## Test Architecture
To test individual components a series of alternate builds will be created.
Each build will interface one or more RoboCar component(s) with a test component, e.g. "TstCMan" is the test component for the CMan component.
The purpose of each test component is solely to exercise and prove the correct behaviour of each component before their integration into the PkgRoboCar build.
This methodology allows for early debugging without the need for specific hardware. The hardware, however, has to be emulated as thoroughly as possible.
