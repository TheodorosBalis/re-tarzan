#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9710
// Label: InitHighResolutionTimer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void InitHighResolutionTimer(void)

{
  BOOL value;
  LARGE_INTEGER localState;
  
  if (g_HighResolutionTimerPeriodActive == 0) {
    timeBeginPeriod(1);
    g_HighResolutionTimerBaseCounterLow = 0;
    _g_HighResolutionTimerFrequency = 0.0;
    g_HighResolutionTimerBaseCounterHigh = 0;
    value = QueryPerformanceFrequency(&localState);
    if (value != 0) {
      if ((-1 < localState.s.HighPart) && ((0 < localState.s.HighPart || (1000 < localState.s.LowPart)))) {
        _g_HighResolutionTimerFrequency =
             _g_DoubleMicrosecondsPerSecond / (double)CONCAT44(localState.s.HighPart,localState.s.LowPart)
        ;
      }
      QueryPerformanceCounter((LARGE_INTEGER *)&g_HighResolutionTimerBaseCounterLow);
    }
  }
  return;
}

