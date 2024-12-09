#include "sensor.h"

// Using HC-SR04
// trigger pin, echo pin
#define TRIG_PIN 2
#define ECHO_PIN 3

// Dist threshold (qd: ~10cm)
static unsigned long lastDetection = 0;

extern void sensorDetectedCallback(); // declared in main.ino

void initSensor() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void handleSensor() {
  // Simple polling every loop
  // Send trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration = pulseIn(ECHO_PIN, HIGH, 30000UL);
  if (duration > 0) {
    unsigned long dist = duration / 58; // convert µs to cm
    if (dist > 0 && dist < 20) {
      // object detected
      // avoid multiple triggers in short time
      unsigned long now = millis();
      if (now - lastDetection > 500) {
        lastDetection = now;
        sensorDetectedCallback();
      }
    }
  }
}
