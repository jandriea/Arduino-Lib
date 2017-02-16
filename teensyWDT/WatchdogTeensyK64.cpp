#include "WatchdogTeensyK64.h"

#if defined(__MK64FX512__)

void WatchdogTeensy3::enable(int toVal) {
    const uint32_t K64FWDONESEC = 0x00B80000;   //approx 1 second delay
    if((toVal < 1) || (toVal > 356)) toVal = 356;
    WDOG_UNLOCK = WDOG_UNLOCK_SEQ1;
    WDOG_UNLOCK = WDOG_UNLOCK_SEQ2;
    uint32_t wdogCntl = K64FWDONESEC * toVal;
    WDOG_TOVALH = wdogCntl >> 16;
    WDOG_TOVALL = wdogCntl & 0xFFFF;
    enableWDT();
}

void WatchdogTeensy3::reset() {
    noInterrupts();
    WDOG_REFRESH = 0xA602;
    WDOG_REFRESH = 0xB480;
    interrupts();
}

void WatchdogTeensy3::disableWDT() {
    WDOG_UNLOCK = WDOG_UNLOCK_SEQ1;
    WDOG_UNLOCK = WDOG_UNLOCK_SEQ2;
    WDOG_STCTRLH &= 0xFFFE;
}

void WatchdogTeensy3::enableWDT() {
  	WDOG_UNLOCK = WDOG_UNLOCK_SEQ1;
  	WDOG_UNLOCK = WDOG_UNLOCK_SEQ2;
    WDOG_STCTRLH |= 0x0001;
    reset();
}

#endif
