#include <Servo.h>

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

//on/off button and conditionals
const int buttonPin = 2;
bool carActive = false;

//car distance const
const int carDistance = 20;

//servo control
const int servoPin =3;
Servo radarServo; //servo object


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

  //configure button
  pinMode(buttonPin, INPUT_PULLUP);

  //configure the servo
  radarServo.attach(servoPin);

  
}

void loop() {

  //carActive or not based on button logic
  if(digitalRead(buttonPin) == LOW) {
    carActive = !carActive;

    if(carActive) Serial.println("car active");
    else Serial.println("car NOT active");
    delay(200);   //DO NOT CHANGE, used for debouncing purposes
  }

  //car is active
  if(carActive) {

    float distance = readDistance();

    if (distance < carDistance) { //obstacle detected
      stop();
      discoverNewPath(distance);
    } else {  //no obstacle detected
      moveForward(160);
    }
    delay(60);

  } else { //car is not active
    stop();
  }
  delay(60);
}



/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////
void discoverNewPath(float oldDistance) {
    float leftDistance;
    float rightDistance;

    radarServo.write(90); //look straight
    delay(600);

    radarServo.write(45); //looks right
    delay(600);
    rightDistance = readDistance();

    radarServo.write(135); //looks left
    delay(600);
    leftDistance = readDistance();

    radarServo.write(90); //reset the servo
    delay(600);

    //movement cases
    if(leftDistance <= carDistance && rightDistance <= carDistance) { 
      //experience dead end, back up for a brief period
      moveBackward(160);
      delay(1000);
      stop();
    } else if (rightDistance >= carDistance && leftDistance < carDistance) {
      //right direction is clear
      rightTurn(45, 140);
    } else if (leftDistance >= carDistance && rightDistance < carDistance) {
      //left direction is clear
      leftTurn(45, 140);
    } else {
      //both sides are clear, pick the better path
      if(leftDistance > rightDistance) {
        leftTurn(45, 140);
      } else {
        rightTurn(45, 140);
      }
    }

}