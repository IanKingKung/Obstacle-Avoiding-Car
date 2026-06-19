//sensor workings
float readDistance() {
  //read in data every 10 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  float distance = duration * 0.0343 / 2;  //convert time to distance in cm
  Serial.println(distance);

  return distance;
  delay(60);
}