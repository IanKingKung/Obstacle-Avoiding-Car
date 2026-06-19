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
}

void loop() {
  if(digitalRead(buttonPin) == LOW) {
    carActive = !carActive;

    // if(carActive) Serial.println("car active");
    // else Serial.println("car NOT active");
    delay(300);
  }

  if(carActive) {
    float distance = readDistance();

    if (distance < 10) {
      stop();
    } else {
      moveForward(140);
    }

    delay(60);
  } else {
    stop();
  }
  

  delay(60);
}