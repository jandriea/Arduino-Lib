#ifndef WatchdogTeensyK64
#define WatchdogTeensyK64

#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif

class WatchdogTeensyK64 {
private:
  void enableWDT();
  void disableWDT();

public:
  void enable(int WDTSeconds); // Enable watchdog timer and initialize timeout in seconds
  void reset(); // Keep alive by reset the watchdog occassionally
};


#endif
