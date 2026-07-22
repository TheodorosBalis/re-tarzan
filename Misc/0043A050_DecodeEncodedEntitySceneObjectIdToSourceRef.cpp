#include "tarzan_ghidra_types.hpp"

// Address: 0x0043A050
// Label: DecodeEncodedEntitySceneObjectIdToSourceRef
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DecodeEncodedEntitySceneObjectIdToSourceRef(undefined1 *arg1,uint arg2)

{
  uint value;
  int entry;
  
  value = arg2 & 0x7000;
  if (value == 0) {
    *arg1 = 1;
    *(uint *)(arg1 + 4) =
         (((arg2 & 0xfff) * 4 + -4) - (int)arg1) + g_NatureTerrainSceneObjectSourceRefTable;
  }
  else {
    if (value == 0x2000) {
      *arg1 = 2;
      *(uint *)(arg1 + 4) =
           (arg2 & 0xfff) * 0x30 + 0x34 + *(int *)(g_CurrentWorldSceneContext + 0xc);
      return;
    }
    if (value == 0x5000) {
      entry = ((arg2 & 0xfff) * 8 - (int)arg1) + g_NatureTerrainModelSourceRefTable;
      *arg1 = 0;
      *(int *)(arg1 + 4) = entry;
      return;
    }
  }
  return;
}

