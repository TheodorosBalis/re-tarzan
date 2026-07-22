#include "tarzan_ghidra_types.hpp"

// Address: 0x0043A2D0
// Label: ResolveSceneAssetRelativePointerEntry
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int ResolveSceneAssetRelativePointerEntry(int *arg1)

{
  int entry;
  
  entry = *(int *)(arg1[1] + 4 + (int)arg1);
  if (entry != 0) {
    return entry + *arg1;
  }
  return 0;
}

