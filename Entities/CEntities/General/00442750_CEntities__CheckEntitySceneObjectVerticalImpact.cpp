#include "tarzan_ghidra_types.hpp"

// Address: 0x00442750
// Label: CEntities::CheckEntitySceneObjectVerticalImpact
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CEntities::CheckEntitySceneObjectVerticalImpact(int entry2)

{
  uint value;
  uint value2;
  uint value3;
  int entry;
  uint value4;
  uint value5;
  uint value6;
  
  value = *(int *)(entry2 + 0x18) - *(int *)(entry2 + 0x4c);
  value4 = (int)value >> 0x1f;
  value2 = *(int *)(entry2 + 0x14) - *(int *)(entry2 + 0x48);
  value5 = (int)value2 >> 0x1f;
  value3 = *(int *)(entry2 + 0x1c) - *(int *)(entry2 + 0x50);
  value6 = (int)value3 >> 0x1f;
  entry = CEntities::GetEntitySceneObjectVerticalCollisionDelta(entry2);
  if (entry != 0x7fffffff) {
    if (entry == 0) {
      return 1;
    }
    if ((entry < 0) &&
       ((int)(~(((value ^ value4) - value4) + 0x4000 +
               ((value3 ^ value6) - value6) + ((value2 ^ value5) - value5)) + 1) <= entry)) {
      *(int *)(entry2 + 0x18) = *(int *)(entry2 + 0x18) + entry;
      return 1;
    }
  }
  return 0;
}

