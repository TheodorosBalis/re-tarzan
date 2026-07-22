#include "tarzan_ghidra_types.hpp"

// Address: 0x00445640
// Label: CEntities::ResolveChildSceneObjectArrayFromRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CEntities::ResolveChildSceneObjectArrayFromRef(char *entry2)

{
  int entry;
  
  if (*entry2 == '\0') {
    entry = ResolveSceneAssetRelativePointerEntry(entry2 + *(int *)(entry2 + 4) + 4);
    if ((entry != 0) && (*(int *)(entry + 0x28) != 0)) {
      return *(int *)(entry + 0x28) + 0x28 + entry;
    }
  }
  else if (*entry2 == '\x01') {
    entry = ResolveSceneContextPackedRelativeBlock
                      (entry2 + *(int *)(entry2 + 4) + 4,g_CurrentWorldSceneContext);
    return entry;
  }
  return 0;
}

