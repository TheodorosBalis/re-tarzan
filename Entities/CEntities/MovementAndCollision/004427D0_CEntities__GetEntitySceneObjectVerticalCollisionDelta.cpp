#include "tarzan_ghidra_types.hpp"

// Address: 0x004427D0
// Label: CEntities::GetEntitySceneObjectVerticalCollisionDelta
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::GetEntitySceneObjectVerticalCollisionDelta(int entry2)

{
  int entry;
  
  entry = *(int *)(entry2 + 0x58);
  if ((((*(int *)(entry2 + 0x108) == 1) && (*(int *)(entry2 + 0x114) != 0)) &&
      ((*(uint *)(*(int *)(entry2 + 0x114) + 0x14) & 0x800) != 0)) && (entry < 1)) {
    *(uint *)(entry2 + 0x13c) = *(uint *)(entry2 + 0x13c) | 4;
    entry = 0x3ffffffe;
  }
  return entry;
}

