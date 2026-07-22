#include "tarzan_ghidra_types.hpp"

// Address: 0x00442650
// Label: CEntities::CheckEntitySceneObjectCollisionDelta
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::CheckEntitySceneObjectCollisionDelta(int entry2)

{
  uint value;
  uint value2;
  int entry;
  
  value = *(int *)(entry2 + 0x14) - *(int *)(entry2 + 0x48);
  value2 = (int)value >> 0x1f;
  entry = (value ^ value2) - value2;
  if (entry < 0x10) {
    entry = entry + 0x10;
  }
  else {
    entry = entry + 8;
  }
  value = *(int *)(entry2 + 0x1c) - *(int *)(entry2 + 0x50);
  value2 = (int)value >> 0x1f;
  value = entry + ((value ^ value2) - value2);
  entry = CEntities::GetEntitySceneObjectVerticalCollisionDelta(entry2);
  if (entry == 0x7fffffff) {
    *(undefined4 *)(entry2 + 0x14) = *(undefined4 *)(entry2 + 0x48);
    *(undefined4 *)(entry2 + 0x18) = *(undefined4 *)(entry2 + 0x4c);
    *(undefined4 *)(entry2 + 0x1c) = *(undefined4 *)(entry2 + 0x50);
    return 1;
  }
  if (entry < 0) {
    if ((int)(~value + 1) <= entry) {
      *(int *)(entry2 + 0x18) = *(int *)(entry2 + 0x18) + entry;
      return 1;
    }
  }
  else if (entry <= (int)value) {
    *(int *)(entry2 + 0x18) = *(int *)(entry2 + 0x18) + entry;
    return 1;
  }
  return 0;
}

