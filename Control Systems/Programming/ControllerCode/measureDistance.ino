// Function that meausres the distance of the robot away from the net

void measureDistance() { 
  // Instructs the ultrasonic sensor to release a burst of ultrasound
  digitalWrite(trigPin, LOW); // Set the trigger pin to LOW 
  delayMicroseconds(2); // Short pause to allow the signal to settle
  digitalWrite(trigPin, HIGH); // Set trigger pin to HIGH
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW); // Set the trigger pin once again to LOW

  pingTime = pulseIn(echoPin, HIGH); // Measures the ping time of the ultrasonic sound wave
  pingTime = pingTime / 1000000.; // Converts ping time from microseconds to seconds

  distance = ((speedOfSound * pingTime) / 2); // Calculates the one-way distance from the robot to the net
}
