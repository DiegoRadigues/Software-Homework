#include "bluetooth.h"
#include "fsm.h"
// For HC-05, using hardware Serial or SoftwareSerial:
#include <SoftwareSerial.h>

// Suppose BT on pins 10(RX),11(TX)
SoftwareSerial BTSerial(10,11); // RX, TX

void initBluetooth() {
  BTSerial.begin(9600);
}

void sendDirectionMsg(int state) {
  // minimal msg
  // state:  STATE_RUNNING_CW or STATE_RUNNING_CCW
  if (state == STATE_RUNNING_CW) {
    BTSerial.println("CW");
  } else if (state == STATE_RUNNING_CCW) {
    BTSerial.println("CCW");
  } else if (state == STATE_IDLE) {
    BTSerial.println("IDLE");
  } else if (state == STATE_STOPPED) {
    BTSerial.println("STOPPED");
  }
}
