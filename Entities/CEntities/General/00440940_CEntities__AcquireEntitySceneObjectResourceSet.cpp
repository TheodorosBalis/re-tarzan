#include "tarzan_ghidra_types.hpp"

// Address: 0x00440940
// Label: CEntities::AcquireEntitySceneObjectResourceSet
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::AcquireEntitySceneObjectResourceSet(int entry3)

{
  int entry;
  int entry2;
  
  entry = *(int *)(entry3 + 0x10);
  if (entry != 0) {
    if ((*(int *)(entry + 0xc) == 0) && (*(int *)(entry + 8) == -1)) {
      RequestResourceSetLoad(entry);
      *(int *)(entry + 100) = entry3;
      *(int *)(entry3 + 100) = entry;
      return;
    }
    entry2 = *(int *)(entry + 100);
    if (entry2 != 0) {
      *(int *)(entry3 + 0x68) = entry2;
      *(int *)(entry2 + 100) = entry3;
    }
    *(int *)(entry3 + 100) = entry;
    *(int *)(entry + 100) = entry3;
  }
  return;
}

