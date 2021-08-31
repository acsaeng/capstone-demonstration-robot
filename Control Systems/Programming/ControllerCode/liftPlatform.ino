// Function that adjusts the angle of the base

void liftPlatform() {

    // Servo sweep that lifts the platform
      for (int platformAngle = 0; platformAngle <= 60; platformAngle += 1) {
      liftingMotor.write(platformAngle); 
      delay(15);
      }     
}
