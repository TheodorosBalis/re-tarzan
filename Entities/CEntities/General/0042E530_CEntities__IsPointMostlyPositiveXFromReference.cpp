#include "tarzan_ghidra_types.hpp"

// Address: 0x0042E530
// Label: CEntities::IsPointMostlyPositiveXFromReference
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool CEntities::IsPointMostlyPositiveXFromReference(int *entry,int *sceneObject)

{
  uint value;
  
  value = GetAngleFromXZVector12Bit(*entry - *sceneObject,entry[2] - sceneObject[2]);
  if ((value & 0xfff) < 0x400) {
    return true;
  }
  return 0xc00 < (value & 0xfff);
}

