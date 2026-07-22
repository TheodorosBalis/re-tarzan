#include "tarzan_ghidra_types.hpp"

// Address: 0x0042F260
// Label: RefreshEntitySceneObjectNatureTerrainVerticalDelta
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RefreshEntitySceneObjectNatureTerrainVerticalDelta(int arg1)

{
  undefined4 value;
  
  value = FindNearestNatureTerrainGroundOffset(&g_CurrentWorldSceneContext,arg1 + 0x14,200);
  *(undefined4 *)(arg1 + 0x58) = value;
  return;
}

