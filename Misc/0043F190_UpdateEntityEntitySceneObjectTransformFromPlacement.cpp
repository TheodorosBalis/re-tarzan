#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F190
// Label: UpdateEntityEntitySceneObjectTransformFromPlacement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateEntityEntitySceneObjectTransformFromPlacement(int arg1)

{
  int entry;
  
  if (*(int *)(arg1 + 0x108) != 1) {
    entry = FindNatureTerrainCollisionRegionAtPosition(arg1 + 0x14);
    if (entry != 0) {
      *(undefined4 *)(arg1 + 0x108) = 2;
      *(int *)(arg1 + 0x10c) = entry;
      ComputeEntitySceneObjectCollisionMoveDelta(0,0,arg1);
      return;
    }
    *(undefined4 *)(arg1 + 0x108) = 0;
  }
  ComputeEntitySceneObjectCollisionMoveDelta(0,0,arg1);
  return;
}

