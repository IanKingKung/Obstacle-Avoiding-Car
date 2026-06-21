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
  //carActive or not based on button logic
  if(digitalRead(buttonPin) == LOW) {
    carActive = !carActive;

    if(carActive) Serial.println("car active");
    else Serial.println("car NOT active");
    delay(250);
  }

  // if(carActive) {
  //   rightTurn(90);
  //   stop();
  //   delay(1500);
  //   leftTurn(90);
  //   stop();
  //   delay(1500);
  // } else {
  //   stop();
  // }

  //car is active
  if(carActive) {

    float distance = readDistance();

    if (distance < carDistance) { //obstacle detected
      
      for(int i = 1; i < 5; i++) {
        int degreeToTurn = 45 * i;  //how many degrees to turn
        float newDistance;  //hold new distance when car turns

        leftTurn(degreeToTurn, 150);
        newDistance = readDistance();
        if(newDistance >= carDistance) {
          break;
        }
        delay(200);

        rightTurn(degreeToTurn, 150); //reset
        delay(200);

        rightTurn(degreeToTurn, 150);
        newDistance = readDistance();
        if(newDistance >= carDistance) {
          break;
        }
        delay(200);

        leftTurn(degreeToTurn, 150); //reset
        delay(200);
      }
      
    } else {  //no obstacle detected
      moveForward(160);
    }
    delay(60);

  } else { //car is not active
    stop();
  }
  delay(60);
}