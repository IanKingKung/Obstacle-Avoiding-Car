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

void moveBackward(int speed) {
  leftWheelBackward(speed);
  rightWheelBackward(speed);
}

void stop() {
  analogWrite(leftEnable, 0);
  analogWrite(rightEnable, 0);
}

void rightTurn(int degrees, int speed) {
  //turn right wheel forward, left wheel backwards
  //time to complete full rotation = 7.3 seconds
  //20.27 ms per degree
  rightWheelBackward(speed);
  leftWheelForward(speed);

  float timeDuration = degrees * 19;
  delay(timeDuration);
  stop();
}

void leftTurn(int degrees, int speed) {
  //turn right wheel forward, left wheel backwards
  //time to complete full rotation = 7.0 seconds
  //19.44 ms per degree
  rightWheelForward(speed);
  leftWheelBackward(speed);

  float timeDuration = degrees * 19.2;
  delay(timeDuration);
  stop();
}

void spinLeft() {
  rightWheelForward(140);
  leftWheelBackward(140);
}

void spinRight() {
  rightWheelBackward(140);
  leftWheelForward(140);
}