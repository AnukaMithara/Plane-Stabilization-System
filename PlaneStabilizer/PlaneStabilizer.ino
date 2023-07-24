#include <Servo.h>      // Include the Servo library to control servos
#include "I2Cdev.h"     // Include the I2Cdev library for I2C communication
#include "MPU6050.h"    // Include the MPU6050 library for interfacing with the accelerometer and gyroscope

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
    #include "Wire.h"   // Include the Wire library for I2C communication
#endif

#define CH1 A0          // Define the analog pin A0 to read Channel 1 receiver input
#define CH2 A1          // Define the analog pin A1 to read Channel 2 receiver input

MPU6050 accelgyro;      // Create an object from MPU6050 for accessing the accelerometer and gyroscope

int16_t gx, gy, gz;     // Variables to store raw gyroscope data
int16_t ax, ay, az;     // Variables to store raw accelerometer data

int x, y;               // Variables to store gyroscope values in degrees

#define OUTPUT_READABLE_ACCELGYRO  // Define an output for reading accelerometer and gyroscope values

Servo leftAlieron;      // Create a servo object to control the left aileron
Servo rightAlieron;     // Create a servo object to control the right aileron
Servo elevators;        // Create a servo object to control the elevators

int CH1Value, CH2Value; // Variables to store the mapped values from the receiver

void setup() {

    #if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
        Wire.begin();   // Initialize the Wire library for I2C communication
    #elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
        Fastwire::setup(400, true); // If using the BUILTIN_FASTWIRE, set up the Fastwire communication
    #endif

    //Serial.begin(9600); // Start the serial communication for debugging 

    accelgyro.initialize(); // Initialize the MPU6050 accelerometer and gyroscope

    pinMode(CH1, INPUT); // Set CH1 pin as input to read the receiver value
    pinMode(CH2, INPUT); // Set CH2 pin as input to read the receiver value

    leftAlieron.attach(5);   // Attach the leftAlieron servo to pin 5
    rightAlieron.attach(6);  // Attach the rightAlieron servo to pin 6
    elevators.attach(9);     // Attach the elevators servo to pin 9

    accelgyro.getMotion6(&gx, &gy, &gz, &ax, &ay, &az); // Read the initial gyroscope values
}

void loop() {
    accelgyro.getMotion6(&gx, &gy, &gz, &ax, &ay, &az); // Read the gyroscope and accelerometer values

    y = map(gx, -17000, 17000, 0, 180); // Map the gyroscope x-axis values to servo values (0 to 180 degrees)
    x = map(gy, -17000, 17000, 0, 180); // Map the gyroscope y-axis values to servo values (0 to 180 degrees)

    CH1Value = pulseIn(CH1, HIGH); // Read the pulse width of the signal from Channel 1 receiver
    CH1Value = map(CH1Value, 1000, 2000, 0, 180); // Map the receiver values to servo values (0 to 180 degrees)

    CH2Value = pulseIn(CH2, HIGH); // Read the pulse width of the signal from Channel 2 receiver
    CH2Value = map(CH2Value, 1000, 2000, 0, 180); // Map the receiver values to servo values (0 to 180 degrees)

    // Check if the receiver signal is within the range of 75 to 105 for Channel 1
    if (((CH1Value < 75) && (CH1Value >= 0)) || ((CH1Value > 105) && (CH1Value <= 180))) {
        // If within range, control the left and right ailerons with the receiver value
        leftAlieron.write(CH1Value);
        rightAlieron.write(CH1Value);
    } else {
        // If not within range, control the left and right ailerons with the gyroscope signal
        leftAlieron.write(180 - x);
        rightAlieron.write(180 - x);
    }

    // Check if the receiver signal is within the range of 75 to 105 for Channel 2
    if (((CH2Value < 75) && (CH2Value >= 0)) || ((CH2Value > 105) && (CH2Value <= 180))) {
        // If within range, control the elevators with the receiver value
        elevators.write(CH2Value);
    } else {
        // If not within range, control the elevators with the gyroscope signal
        elevators.write(y);
    }

    delay(50); // Add a short delay
}
