// Function that meausres the distance of the robot away from the net

void measureDistance() { 
  // Instructs the ultrasonic sensor to release a burst of ultrasound
  digitalWrite(trigPin, LOW); // Set the trigger pin to LOW 
  delayMicroseconds(2); // Short pause to allow the signal to settle
  digitalWrite(trigPin, HIGH); // Set trigger pin to HIGH
  delayMicroseconds(5);
  digitalWrite(trigPin, LOW); // Set the trigger pin once again to LOW

  pingTime = pulseIn(echoPin, HIGH); // Measures the ping time of the ultrasonic sound wave
  pingTime = pingTime/1000000.; // Converts ping time from microseconds to seconds

  distance = ((speedOfSound*pingTime)/2); // Calculates the one-way distance from the robot to the net

  if (distance < 0.05) {
    distance = distance + 0.21;
  }

  else if(distance >= 0.05 && distance < 0.10) {
    distance = distance + 0.20;
  }

  else if(distance >= 0.10 && distance < 0.15) {
    distance = distance + 0.22;
  }
  
  else if(distance >= 0.15 && distance < 0.20) {
    distance = distance + 0.12;
  }

  else if(distance >= 0.20 && distance < 0.25) {
    distance = distance + 0.08;
  }

  else if(distance >= 0.25 && distance < 0.30){
    distance = distance + 0.14;
  }
  
  else if(distance >= 0.30 && distance < 0.35){
    distance = distance + 0.01;
  }

  
  else if(distance >= 0.35 && distance < 0.40){
    distance = distance - 0.03;
  }

  
  else if(distance >= 0.40 && distance < 0.45){
    distance = distance + 0.04;
  }

  else if(distance >= 0.45 && distance < 0.50){
    distance = distance;
  }

  
  else if(distance >= 0.50 && distance < 0.55){
    distance = distance - 0.03; 
  }

  
  else if(distance >= 0.55 && distance < 0.60){
    distance = distance - 0.075;
  }
  
  else if(distance >= 0.60 && distance < 0.65){
    distance = distance - 0.03;
  }
  
  else if(distance >= 0.65 && distance < 0.70){
    distance = distance - 0.01;
  }
  
  else if(distance >= 0.70 && distance < 0.75){
    distance = distance - 0.05;
  }

  else if(distance >= 0.75 && distance < 0.80){
    distance = distance + 0.03;
  }

  else if(distance >= 0.80 && distance < 0.85){
    distance = distance - 0.07;
  }

  else if(distance >= 0.85 && distance < 0.90){
    distance = distance - 0.04;
  }

  else if(distance >= 0.90 && distance < 0.95){
    distance = distance + 0.04;
  }

  else if(distance >= 0.95 && distance < 1.00){
    distance = distance - 0.28;
  }
  
  else {
    distance = distance;
  }
}
