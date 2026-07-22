#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B710
// Label: ResetProjectionState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetProjectionState(void)

{
  int value;
  undefined4 *stateFlags;
  
  stateFlags = &g_ProjectionDepthScale;
  for (value = 0x3a; value != 0; value = value + -1) {
    *stateFlags = 0;
    stateFlags = stateFlags + 1;
  }
  RestoreDefaultProjectionState();
  return;
}

