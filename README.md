# Project Description

This project implements a finite state machine (FSM) controlling a DC motor with an Adafruit Motor Shield, using an HC-SR04 ultrasonic sensor to detect obstacles and toggle the motor’s rotation direction, and sending state updates via an HC-05 Bluetooth module. After 5 direction changes or 30 seconds of operation, the motor stops and only restarts upon system reboot.

## Branches

- `feature-fsm`: FSM logic
- `feature-motor-control`: Motor control code
- `feature-sensor`: Sensor reading code
- `feature-bluetooth`: Bluetooth communication code

Each feature branch must be peer-reviewed via Pull Requests (PR) before merging into `main`.

## Required Hardware
- **Arduino** (e.g. Arduino Uno)
- **Adafruit Motor Shield (V2)** for motor control
- **HC-SR04 Ultrasonic Sensor** for distance measurement
- **HC-05 Bluetooth module** for wireless communication
- **DC Motor** (connected to the Motor Shield)

## Wiring (Example)
- HC-SR04: Trig → Pin 2, Echo → Pin 3
- HC-05: RX → Pin 10, TX → Pin 11
- Motor connected to Motor Shield output M1 (for example)

## Libraries to Install
1. **Adafruit Motor Shield V2 Library**  
2. **SoftwareSerial** 

## Setup
- Connect all hardware as described above.
- Install the required library (Adafruit Motor Shield V2).
- Select the correct **Board** and **Port** in the Arduino IDE.
- Verify and Upload the code.

## Usage
After merging all branches and uploading to Arduino, the system:
- Starts idle (motor off).
- On first object detection (e.g. a hand in front of the HC-SR04), the motor runs clockwise (CW).
- On the next detection, it toggles to counter-clockwise (CCW), then again CW, and so forth.
- After 5 toggles or 30 seconds, the motor stops and can only restart by rebooting the Arduino.
- Each detection sends a Bluetooth message (CW, CCW, etc.) readable on a connected smartphone app or terminal connected to the HC-05 module.

## Notes
- You can adjust the motor speed or direction in `motor_control.cpp`.
- You can tweak the debounce time or distance threshold for the HC-SR04 in `sensor.cpp`.
- For debugging, you can add `Serial.println()` statements in various files to trace behavior.

## Workflow
- Develop feature branches independently.
- Submit PRs for code review before merging into `main`.
- Ensure code quality, FSM correctness, and adhere to the project’s coding guidelines.
