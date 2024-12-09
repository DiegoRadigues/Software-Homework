#include "motor_control.h"
#include <Adafruit_MotorShield.h>
#include <Wire.h>

// Minimal: Mtr shield config
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_DCMotor *myMotor = NULL;

void initMotor() {
  AFMS.begin(); // Default freq ~1.6kHz
  myMotor = AFMS.getMotor(1); // M1 port
  if (myMotor) {
    myMotor->setSpeed(150); // speed mid-range
    myMotor->run(RELEASE);
  }
}

void setMotorCW() {
  if (myMotor) {
    myMotor->run(FORWARD);
  }
}

void setMotorCCW() {
  if (myMotor) {
    myMotor->run(BACKWARD);
  }
}

void stopMotor() {
  if (myMotor) {
    myMotor->run(RELEASE);
  }
}
