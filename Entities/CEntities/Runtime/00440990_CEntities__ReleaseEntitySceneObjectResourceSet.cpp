#include "tarzan_ghidra_types.hpp"

// Address: 0x00440990
// Label: CEntities::ReleaseEntitySceneObjectResourceSet
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ReleaseEntitySceneObjectResourceSet(int entry3)

{
  int entry;
  int entry2;
  
  entry = *(int *)(entry3 + 0x10);
  if (entry != 0) {
    entry2 = *(int *)(entry3 + 100);
    if (entry2 == 0) {
      *(undefined4 *)(entry + 100) = *(undefined4 *)(entry3 + 0x68);
    }
    else if (entry2 == entry) {
      *(undefined4 *)(entry + 100) = *(undefined4 *)(entry3 + 0x68);
      if (*(int *)(entry3 + 0x68) != 0) {
        *(int *)(*(int *)(entry3 + 0x68) + 100) = entry;
      }
    }
    else {
      *(undefined4 *)(entry2 + 0x68) = *(undefined4 *)(entry3 + 0x68);
      if (*(int *)(entry3 + 0x68) != 0) {
        *(undefined4 *)(*(int *)(entry3 + 0x68) + 100) = *(undefined4 *)(entry3 + 100);
      }
    }
    *(undefined4 *)(entry3 + 0x68) = 0;
    *(undefined4 *)(entry3 + 100) = 0;
  }
  if (*(int *)(entry + 100) == 0) {
    ReleaseResourceSet(*(undefined4 *)(entry3 + 0x10));
    *(undefined4 *)(entry3 + 0x10) = 0;
  }
  return;
}

