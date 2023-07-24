#include <Servo.h>
#include "I2Cdev.h"
#include "MPU6050.h"

#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

#define CH1 A0  //Get Chanel 1 receiver input for A0 pin
#define CH2 A1  //Get Chanel 2 receiver input for A0 pin

MPU6050 accelgyro;  // create object from MPU6050

int16_t gx, gy, gz;
int16_t ax, ay, az;

int x, y;  //Gyroscope values in degrees

#define OUTPUT_READABLE_ACCELGYRO

Servo leftAlieron;   // create servo object to control left alieron
Servo rightAlieron;  // create servo object to control right alieron
Servo elevators;     // create servo object to control elevators

int CH1Value, CH2Value;

void setup() {

// join I2C bus (I2Cdev library doesn't do this automatically)
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif

  Serial.begin(9600);

  // initialize device
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();

  // verify connection
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");


  pinMode(CH1, INPUT);
  pinMode(CH2, INPUT);

  leftAlieron.attach(5);   // attaches the servo on pin 9 to the servo object
  rightAlieron.attach(6);  // attaches the servo on pin 9 to the servo object
  elevators.attach(9);     // attaches the servo on pin 9 to the servo object

  accelgyro.getMotion6(&gx, &gy, &gz, &ax, &ay, &az);
}
void loop() {
  // read raw accel/gyro measurements from device
  accelgyro.getMotion6(&gx, &gy, &gz, &ax, &ay, &az);

  y = map(gx, -17000, 17000, 0, 180);  //Mapping the gyroscope values to servo values
  x = map(gy, -17000, 17000, 0, 180);  //Mapping the gyroscope values to servo values

  CH1Value = pulseIn(CH1, HIGH);                 //Get Chanel 1 from receiver values
  CH1Value = map(CH1Value, 1000, 2000, 0, 180);  //Mapping the Receiver values to servo values

  CH2Value = pulseIn(CH2, HIGH);                 //Get Chanel 2 from receiver values
  CH2Value = map(CH2Value, 1000, 2000, 0, 180);  //Mapping the Receiver values to servo values

  if (((CH1Value < 75) && (CH1Value >= 0)) || ((CH1Value > 105) && (CH1Value <= 180))) {  //Check the signal available for Channel 1

    leftAlieron.write(CH1Value);
    rightAlieron.write(CH1Value);
    Serial.print("Ch1: ");
    Serial.print(CH1Value);
  } else {  //If not get gyroscope signal
    leftAlieron.write(180 - x);
    rightAlieron.write(180 - x);
    Serial.print("Gyro x: ");
    Serial.print(x);
  }


  if (((CH2Value < 75) && (CH2Value >= 0)) || ((CH2Value > 105) && (CH2Value <= 180))) {  //Check the signal available for Channel 2

    elevators.write(CH2Value);
    Serial.print("  Ch2: ");
    Serial.println(CH2Value);
  } else {  //If not get gyroscope signal
    elevators.write(y);
    Serial.print("  Gyro y: ");
    Serial.println(y);
  }
  delay(500);
}
