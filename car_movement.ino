void leftWheelForward(int speed) {
  digitalWrite(leftInput1, HIGH);
  digitalWrite(leftInput2, LOW);
  analogWrite(leftEnable, speed);   
}

void leftWheelBackward(int speed) {
  digitalWrite(leftInput1, LOW);
  digitalWrite(leftInput2, HIGH);
  analogWrite(leftEnable, speed);   
}

void rightWheelForward(int speed) {
  digitalWrite(rightInput1, HIGH);
  digitalWrite(rightInput2, LOW);
  analogWrite(rightEnable, speed);   
}

void rightWheelBackward(int speed) {
  digitalWrite(rightInput1, LOW);
  digitalWrite(rightInput2, HIGH);
  analogWrite(rightEnable, speed);  
}

void moveForward(int speed) {
  leftWheelForward(speed);
  rightWheelForward(speed);
}

void stop() {
  analogWrite(leftEnable, 0);
  analogWrite(rightEnable, 0);
}