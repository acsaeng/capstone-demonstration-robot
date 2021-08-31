// Function that shoots the projectile into the target

void shootBall() { 
  //  Kinematic equation that calculates the angular speed necessary to launch the ball
  angularSpeed = 0.792804694892816 * pow(distance, 5) - 6.49040934100877 * pow(distance, 4) + 20.5275746574592 * pow(distance, 3) - 32.8989742874332 * pow(distance, 2) + 37.3396046930129 * distance + 0.389709401814137;
  rpm = angularSpeed * (30 / 3.141592653); // Converts angular speed in rad/s to rpm
  rpm = (int) rpm; // Converts float to integer

  shootingStepper.begin(rpm, microsteps); // Sets the speed of the motor
  shootingStepper.rotate(95);
  delay(2000);

  // Returns the shooting arm to its initial position
  shootingStepper.begin(20, microsteps); 
  shootingStepper.rotate(-95);
    
  for (int platformAngle = 60; platformAngle >= 0; platformAngle -= 1) {
  liftingMotor.write(platformAngle); 
  delay(15);
  }    
  
  shoot = false; // Reset the 'shoot' action as a Boolean false
}
