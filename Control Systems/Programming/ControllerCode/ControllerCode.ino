#include <Servo.h> // Include servo library
#include <Arduino.h> // Include stepper libraries
#include "BasicStepperDriver.h"

// Variables used to move the base of the robot
#define drivingPin A0
Servo drivingMotor;

int input; // Input obtained from the bluetooth via the Android device

// Variables used to measure the distance of the robot away from the net
#define trigPin 10
#define echoPin 11
float pingTime; float distance;
const float speedOfSound = 343; // Speed of the ultrasonic sound wave in m/s

// Variables used to lift the plaform
#define liftingPin A1
float platformAngle;
Servo liftingMotor; // Define the lifting servo motor

// Variables used to shoot the ball
#define DIR 13
#define STEP 12
int motorSteps = 200; float angularSpeed; float rpm; int microsteps = 1; // Initialize driving stepper specifications 
BasicStepperDriver shootingStepper(motorSteps, DIR, STEP); // Define the shooting stepper motor
bool shoot = false; // Initally sets the 'shoot' action as a Boolean false

void setup() {
  // Defines the pin for for devices with digitial control
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);  
  
  Serial.begin(9600); // Set the serial monitor to the bluetooth default baud rate
  drivingMotor.attach(drivingPin); // Initalizes pin the driving servo is connected to
  drivingMotor.writeMicroseconds(1510); // Sets the initial speed on the driving servo to zero (range from 1000-2000)
  liftingMotor.attach(liftingPin); // Initalizes pin the lifting servo is connected to
  liftingMotor.write(0);
}

void loop() {
  driveBase();
  measureDistance();
  delay(2000);
  liftPlatform();
  delay(3000);
  shootBall();
}
