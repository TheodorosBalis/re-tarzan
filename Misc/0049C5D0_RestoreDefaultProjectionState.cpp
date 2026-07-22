#include "tarzan_ghidra_types.hpp"

// Address: 0x0049C5D0
// Label: RestoreDefaultProjectionState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RestoreDefaultProjectionState(void)

{
  int value;
  undefined4 *stateFlags;
  undefined4 *stateFlags2;
  undefined4 localState [12];
  
  g_ProjectionDepthScale = 0x44000000;
  g_ProjectionScreenOriginX = 0x43a00000;
  _g_ProjectionScreenOriginY = 0x43700000;
  SetIdentityFloat3x3Matrix(localState);
  stateFlags = localState;
  stateFlags2 = &g_ProjectMatrix00;
  for (value = 9; value != 0; value = value + -1) {
    *stateFlags2 = *stateFlags;
    stateFlags = stateFlags + 1;
    stateFlags2 = stateFlags2 + 1;
  }
  _g_ProjectTranslateX = 0;
  _g_ProjectTranslateY = 0;
  _g_ProjectTranslateZ = 0;
  return;
}

