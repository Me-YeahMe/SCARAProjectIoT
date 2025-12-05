#include <ESP32Servo.h>

const int pinDir1   = 21;
const int pinStep1  = 34;

const int pinDir2   = 35;
const int pinStep2  = 36;

const int pinDir3   = 39;
const int pinStep3  = 40;

const int pinServo = 10;

const int servoOpen = 0;
const int servoClosed = 180;

const int stepperVel = 1000;
const int movementSteps = 50; //Unknown
const int gripperHeight = 400;

char input;

Servo gripper;

void setup() {
  Serial.begin(115200);

  pinMode(pinDir1, OUTPUT);
  pinMode(pinStep1, OUTPUT);

  pinMode(pinDir2, OUTPUT);
  pinMode(pinStep2, OUTPUT);

  pinMode(pinDir3, OUTPUT);
  pinMode(pinStep3, OUTPUT);

  gripper.attach(pinServo);
  gripper.write(servoClosed);
}

void moveStepper(int steps, bool direction, int velocity, int pinD, int pinS) {
  digitalWrite(pinD, direction);

  for (int i = 0; i < steps; i++) {
    digitalWrite(pinS, HIGH);
    delayMicroseconds(velocity);
    digitalWrite(pinS, LOW);
    delayMicroseconds(velocity);
  }
}

void openGripper() {
  gripper.write(servoOpen);
}

void closeGripper() {
  gripper.write(servoClosed);
}

void loop() {
  //if (Serial.available()) {
    //input = Serial.read();
    /*Serial.print("You typed: " );
    Serial.print(input);
    Serial.print(input);
    Serial.print(input);*/

    //Serial.read();
    moveStepper(movementSteps, LOW, stepperVel, pinDir1, pinStep1);
    delay(300);

    moveStepper(movementSteps, HIGH, stepperVel, pinDir2, pinStep2);
    delay(300);

    openGripper();
    delay(700);

    moveStepper(gripperHeight, HIGH, stepperVel, pinDir3, pinStep3);
    delay(300);

    closeGripper();
    delay(700);

    moveStepper(gripperHeight, LOW, stepperVel, pinDir3, pinStep3);
    delay(300);

    moveStepper(movementSteps, LOW, stepperVel, pinDir2, pinStep2);
    delay(300);

    moveStepper(movementSteps * 2, HIGH, stepperVel, pinDir1, pinStep1);
    delay(300);

    moveStepper(movementSteps, LOW, stepperVel, pinDir2, pinStep2);
    delay(300);

    moveStepper(gripperHeight, HIGH, stepperVel, pinDir3, pinStep3);
    delay(300);

    openGripper();
    delay(700);

    moveStepper(gripperHeight, LOW, stepperVel, pinDir3, pinStep3);
    delay(300);

    closeGripper();
    delay(700);

    moveStepper(movementSteps, HIGH, stepperVel, pinDir2, pinStep2);
    delay(300);

    moveStepper(movementSteps, LOW, stepperVel, pinDir1, pinStep1);
    delay(5000);
  //}

}