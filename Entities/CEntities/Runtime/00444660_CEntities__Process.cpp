#include "tarzan_ghidra_types.hpp"

// Address: 0x00444660
// Label: CEntities::Process
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::Process(void)

{
  byte *value2;
  int *intCursor;
  int value;
  
  _g_RuntimeProcessingPhase = 2;
  value = 0;
  intCursor = g_Phase2EntityList;
  if (0 < *g_Phase2EntityList) {
    do {
      value2 = (byte *)intCursor[value + 1];
      value = value + 1;
      if ((*value2 & 1) != 0) {
        ((Entity *)value2)->Update((Entity *)value2);
        intCursor = g_Phase2EntityList;
      }
    } while (value < *intCursor);
  }
  _g_RuntimeProcessingPhase = 0;
  CWorld::UpdateBonusLevelTimer();
  CWorld::UpdateHud();
  return;
}

