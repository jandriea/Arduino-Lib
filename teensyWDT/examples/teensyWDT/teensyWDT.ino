#include "WatchdogTeensyK64.h"

WatchdogTeensyK64 wdt; //initiate watchdog class

// the setup function runs once when you press reset or power the board
void setup() {
    wdt.enable(2); // Set watchdog timeout 2 seconds
}

// the loop function runs over and over again until power down or reset
void loop() {
  wdt.reset(); // Reset watchdog
}
