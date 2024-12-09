#ifndef FSM_H
#define FSM_H

// States
typedef enum {
  STATE_IDLE,
  STATE_RUNNING_CW,
  STATE_RUNNING_CCW,
  STATE_STOPPED
} fsm_state_t;

void fsmInit();
void fsmUpdate(unsigned long now);
void fsmOnObjectDetected();
void fsmStopSystem();
int fsmGetDirectionChanges();
fsm_state_t fsmGetCurrentDirection(); // returns CW or CCW state

#endif
