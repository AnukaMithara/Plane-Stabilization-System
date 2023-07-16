![image](https://github.com/AnukaMithara/Plane-Stabilization-System/assets/48363103/28fc8398-4b1f-4158-b45e-955fa606636a)# Plane Stabilization System

The Plane Stabilization System is an Arduino-based project that utilizes the MPU6050 sensor and three servo motors to achieve stability and control for a plane during flight. This project aims to address the challenge of maintaining stable flight conditions by implementing a real-time stabilization system.

## Features

- Real-time stabilization of a plane using an Arduino board and MPU6050 sensor.
- Control of three servo motors for precise adjustments to maintain stability.
- Calibration routines to ensure accurate sensor readings.

## Hardware Requirements

- Arduino board (e.g., Arduino Uno, Arduino Mega)
- MPU6050 6-DOF (Degrees of Freedom) sensor module
- Three servo motors
- Breadboard and jumper wires
- Power supply (based on the specifications of your servos)

## Installation

1. Clone or download the project repository from GitHub.
2. Connect the MPU6050 sensor and servo motors to the Arduino board according to the wiring diagram provided in the repository.
3. Open the Arduino IDE and navigate to `File > Open` to open the main Arduino sketch file (.ino file) from the downloaded repository.
4. Ensure that you have the required libraries installed. If not, install the following libraries using the Arduino Library Manager (`Sketch > Include Library > Manage Libraries`):
   - MPU6050 by Jeff Rowberg
   - Servo by Arduino
5. Select the appropriate board and port from the `Tools` menu in the Arduino IDE.
6. Upload the sketch to the Arduino board.
7. Connect a power supply to the Arduino board and ensure that the servo motors are connected properly.
8. Run the stabilization system and observe the behavior of the servos in response to the MPU6050 sensor readings.

## Usage

- The stabilization system will automatically adjust the servo motors based on the sensor readings to maintain stability during flight.
- Perform sensor calibration if required to ensure accurate readings from the MPU6050 sensor.

## Contributing

Contributions to the Plane Stabilization System project are welcome. If you have any suggestions, bug reports, or feature requests, please open an issue on the GitHub repository.

## License

This project is licensed under the [MIT License](LICENSE).
