#include "tarzan_ghidra_types.hpp"

// Address: 0x00440270
// Label: CEntities::AppendEntityToChildChain
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::AppendEntityToChildChain(int entry3,int sceneObject)

{
  int entry;
  int entry2;
  
  entry2 = *(int *)(entry3 + 0x18);
  while (entry = entry2, entry != 0) {
    entry3 = entry;
    entry2 = *(int *)(entry + 0x18);
  }
  *(int *)(entry3 + 0x18) = sceneObject;
  *(int *)(sceneObject + 0x14) = entry3;
  return;
}

