#include "tarzan_ghidra_types.hpp"

// Address: 0x004A97B0
// Label: GetTimeTicks
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int GetTimeTicks(void)

{
  BOOL value;
  int value2;
  DWORD apiResult;
  bool flagByte;
  LARGE_INTEGER localState;
  
  if (_g_HighResolutionTimerFrequency != _g_DoubleZero) {
    value = QueryPerformanceCounter(&localState);
    if (value != 0) {
      flagByte = localState.s.LowPart < g_HighResolutionTimerBaseCounterLow;
      localState.s.LowPart = localState.s.LowPart - g_HighResolutionTimerBaseCounterLow;
      localState.s.HighPart = (localState.s.HighPart - g_HighResolutionTimerBaseCounterHigh) - (uint)flagByte
      ;
      CallCIntrinsicDispatch2();
      value2 = ConvertFpuTopToInt64();
      return value2;
    }
  }
  apiResult = timeGetTime();
  return apiResult * 1000;
}

