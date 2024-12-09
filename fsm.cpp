#include "fsm.h"
#include "motor_control.h"

// Minimal comments (fr/eng): FSM gère états
static fsm_state_t currentState = STATE_IDLE;
static int directionChanges = 0; // count after first run
// directionChanges compte chaque inversion
// Running states: CW or CCW
// On first detection: go to CW, next detection: CCW, etc.

void fsmInit() {
  currentState = STATE_IDLE;
  directionChanges = 0;
}

void fsmUpdate(unsigned long now) {
  // Possibly nothing here if not time-based transitions except stop handled in main
}

void fsmOnObjectDetected() {
  if (currentState == STATE_STOPPED) return;
  
  if (currentState == STATE_IDLE) {
    // first detection
    currentState = STATE_RUNNING_CW;
    setMotorCW();
  } else if (currentState == STATE_RUNNING_CW) {
    currentState = STATE_RUNNING_CCW;
    directionChanges++;
    setMotorCCW();
  } else if (currentState == STATE_RUNNING_CCW) {
    currentState = STATE_RUNNING_CW;
    directionChanges++;
    setMotorCW();
  }
}

void fsmStopSystem() {
  currentState = STATE_STOPPED;
  stopMotor();
}

int fsmGetDirectionChanges() {
  return directionChanges;
}

fsm_state_t fsmGetCurrentDirection() {
  return currentState;
}
