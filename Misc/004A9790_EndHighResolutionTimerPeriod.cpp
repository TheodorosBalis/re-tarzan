#include "tarzan_ghidra_types.hpp"

// Address: 0x004A9790
// Label: EndHighResolutionTimerPeriod
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void EndHighResolutionTimerPeriod(void)

{
  if (g_HighResolutionTimerPeriodActive != 0) {
    timeEndPeriod(1);
  }
  return;
}

