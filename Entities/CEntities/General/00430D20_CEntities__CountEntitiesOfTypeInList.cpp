#include "tarzan_ghidra_types.hpp"

// Address: 0x00430D20
// Label: CEntities::CountEntitiesOfTypeInList
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::CountEntitiesOfTypeInList(int entry,short sceneObject)

{
  int count;
  
  count = 0;
  for (; entry != 0; entry = *(int *)(entry + 0x20)) {
    if (*(short *)(entry + 0x46) == sceneObject) {
      count = count + 1;
    }
  }
  return count;
}

