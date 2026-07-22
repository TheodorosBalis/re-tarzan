#include "tarzan_ghidra_types.hpp"

// Address: 0x0043A2F0
// Label: ResolveSceneAssetPointerEntry
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 ResolveSceneAssetPointerEntry(char *arg1)

{
  undefined4 value;
  
  if (*arg1 == '\0') {
    value = ResolveSceneAssetRelativePointerEntry(arg1 + *(int *)(arg1 + 4) + 4);
    return value;
  }
  if (*arg1 != '\x02') {
    return 0;
  }
  return *(undefined4 *)(arg1 + 4);
}

