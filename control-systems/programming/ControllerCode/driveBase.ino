// Function that control the movement of the base in one-dimension

void driveBase() { 
  while(shoot == false) {
      if(Serial.available() > 0) {
      input = Serial.read(); // Reads input data from the bluetooth device
      delay(10);

      // Moves the base forward 
      if(input >= 0 && input < 127) {
          drivingMotor.writeMicroseconds(1000);
      }

       // Moves the base backward
      else if(input > 127 && input <= 254) {
          drivingMotor.writeMicroseconds(2000);
      }

      // Command to shoot the ball
      else if(input == 255) {
        shoot = true;
        break;
      }

      // Sets the base as stationary
      else {
          drivingMotor.writeMicroseconds(1510);
      }
    }
  }
}
