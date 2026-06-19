//ultrasonic sensor
const int trigPin = 12;
const int echoPin = 13;

//right motor
const int rightEnable = 11; //pwm pin for right speed
const int rightInput1 = 10;
const int rightInput2 = 9;

//left motor
const int leftEnable = 5;  //pwm pin for left motor speed
const int leftInput1 = 6;
const int leftInput2 = 7;

void setup() {
  Serial.begin(9600); // Opens the serial port  (for testing purposes)
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //configure right motor
  pinMode(rightEnable, OUTPUT);
  pinMode(rightInput1, OUTPUT);
  pinMode(rightInput2, OUTPUT);

  //configure left motor
  pinMode(leftEnable, OUTPUT);
  pinMode(leftInput1, OUTPUT);
  pinMode(leftInput2, OUTPUT);
}

void loop() {
  float distance = readDistance();

  if (distance < 10) {
    stop();
  } else {
    moveForward(130);
  }

  delay(60);
}