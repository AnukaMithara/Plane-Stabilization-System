![image](https://github.com/AnukaMithara/Plane-Stabilization-System/assets/48363103/28fc8398-4b1f-4158-b45e-955fa606636a)# Plane Stabilization System

The Plane Stabilization System is an Arduino-based project that utilizes the MPU6050 sensor, transmitter, receiver, and three servo motors to achieve stability and control for a plane during flight. This project aims to address the challenge of maintaining stable flight conditions by implementing a real-time stabilization system.

## Features

- Real-time stabilization of a plane using an Arduino board, MPU6050 sensor, transmitter, and receiver.
- Control of two servo motors for aileron adjustments and one servo motor for elevator control.
- Calibration routines to ensure accurate sensor readings.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno, Arduino Mega)
- MPU6050 6-DOF (Degrees of Freedom) sensor module
- Transmitter and receiver (for remote control)
- Three servo motors (two for ailerons, one for elevator)
- Breadboard and jumper wires
- Power supply (based on the specifications of your servos)

## Installation

1. Clone or download the project repository from GitHub.
2. Connect the MPU6050 sensor, transmitter, receiver, and servo motors to the Arduino board according to the wiring diagram provided in the repository.
3. Open the Arduino IDE and navigate to `File > Open` to open the main Arduino sketch file (.ino file) from the downloaded repository.
4. Ensure that you have the required libraries installed. If not, install the following libraries using the Arduino Library Manager (`Sketch > Include Library > Manage Libraries`):
   - Servo by Arduino
   - MPU6050 by Jeff Rowberg
5. Select the appropriate board and port from the `Tools` menu in the Arduino IDE.
6. Upload the sketch to the Arduino board.
7. Connect a power supply to the Arduino board and ensure that the servo motors are connected properly.

## Usage

1. Power on the plane and ensure that the Arduino board is connected and running the stabilization system.
2. The stabilization system will adjust the servo motors based on the gyroscope readings and receiver inputs to maintain stability during flight.
3. Monitor the stabilization system's behavior through the serial monitor in the Arduino IDE.
4. If needed, perform calibration of the MPU6050 sensor to ensure accurate readings.
5. Adjust the code and servo positions as necessary to achieve the desired stabilization performance.
6. Test the stabilization system in a controlled environment to evaluate its effectiveness in maintaining stable flight conditions.

## Contributing

Contributions to the Plane Stabilization System project are welcome. If you have any suggestions, bug reports, or feature requests, please open an issue on the GitHub repository.
