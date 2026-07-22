#include "tarzan_ghidra_types.hpp"

// Address: 0x004446B0
// Label: RunDormantPhase2Pass
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RunDormantPhase2Pass(void)

{
  byte *value;
  
  _g_RuntimeProcessingPhase = 2;
  for (value = g_DormantPhase2EntityListHead; value != (byte *)0x0;
      value = *(byte **)(value + 0x20)) {
    if ((*value & 1) != 0) {
      ((Entity *)value)->Update((Entity *)value);
    }
  }
  _g_RuntimeProcessingPhase = 0;
  return;
}

