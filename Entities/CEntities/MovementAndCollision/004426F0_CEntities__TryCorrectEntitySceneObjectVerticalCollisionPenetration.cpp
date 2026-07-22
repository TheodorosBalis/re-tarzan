#include "tarzan_ghidra_types.hpp"

// Address: 0x004426F0
// Label: CEntities::TryCorrectEntitySceneObjectVerticalCollisionPenetration
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::TryCorrectEntitySceneObjectVerticalCollisionPenetration(int entry3)

{
  uint value;
  int entry;
  uint value2;
  int entry2;
  
  value = *(int *)(entry3 + 0x14) - *(int *)(entry3 + 0x48);
  value2 = (int)value >> 0x1f;
  entry2 = (value ^ value2) - value2;
  if (entry2 < 0x10) {
    entry2 = 4;
  }
  entry = CEntities::GetEntitySceneObjectVerticalCollisionDelta(entry3);
  if (((entry != 0x7fffffff) && (entry < 0)) && ((int)(~(entry2 + 0x4000U) + 1) <= entry)) {
    *(int *)(entry3 + 0x18) = *(int *)(entry3 + 0x18) + entry;
    return 1;
  }
  return 0;
}

