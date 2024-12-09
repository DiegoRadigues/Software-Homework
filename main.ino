#include "fsm.h"
#include "motor_control.h"
#include "sensor.h"
#include "bluetooth.h"

// Timing
unsigned long startTime = 0;  
bool systemStopped = false; 

void setup() {
  // init serial (for debug if needed)
  Serial.begin(9600);  
  initMotor();      // from motor_control
  initSensor();     // from sensor
  initBluetooth();  // from bluetooth
  fsmInit();        // from fsm
  
  startTime = millis();
}

void loop() {
  // regular FSM update
  unsigned long currentTime = millis();
  handleSensor();
  fsmUpdate(currentTime);
  
  // Check for stop conditions: either 5 direction changes or >30s
  if (!systemStopped && (fsmGetDirectionChanges() >= 5 || (currentTime - startTime) >= 30000)) {
    fsmStopSystem();
    systemStopped = true;
  }
  
  // Once stopped, do nothing else. System reactivates only by reboot.
}

// The sensor interrupt or trigger callback:
// Called from sensor.cpp once an object is detected.
// Just triggers FSM event and send Bluetooth msg.
void sensorDetectedCallback() {
  if (!systemStopped) {
    fsmOnObjectDetected();
    sendDirectionMsg(fsmGetCurrentDirection()); // from bluetooth
  }
}
