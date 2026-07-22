#include "tarzan_ghidra_types.hpp"

// Address: 0x00444560
// Label: CWorld::UpdateHudPhase
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CWorld::UpdateHudPhase(void)

{
  _g_RuntimeProcessingPhase = 4;
  CWorld::UpdateHud();
  _g_RuntimeProcessingPhase = 0;
  return;
}

