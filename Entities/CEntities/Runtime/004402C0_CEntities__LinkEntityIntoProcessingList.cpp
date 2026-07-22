#include "tarzan_ghidra_types.hpp"

// Address: 0x004402C0
// Label: CEntities::LinkEntityIntoProcessingList
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::LinkEntityIntoProcessingList(int *entry2,int sceneObject)

{
  int entry;
  
  entry = *entry2;
  if (entry != 0) {
    *(int *)(sceneObject + 0x20) = entry;
    *(int *)(entry + 0x1c) = sceneObject;
  }
  *entry2 = sceneObject;
  *(int **)(sceneObject + 0x24) = entry2;
  return;
}

