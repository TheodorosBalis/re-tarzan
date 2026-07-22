#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F610
// Label: PushEntitySceneObjectAwayFromEntityColliders
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 PushEntitySceneObjectAwayFromEntityColliders(int arg1,undefined4 arg2)

{
  int *intCursor;
  int entry;
  int entry2;
  
  entry2 = g_ActiveEntityListHead;
  if (g_ActiveEntityListHead != 0) {
    do {
      for (entry = *(int *)(entry2 + 0x38); entry != 0; entry = *(int *)(entry + 0x34)) {
        if ((entry != arg1) && ((*(uint *)(*(int *)(entry + -4) + 0x28) & 0x200) == 0)) {
          PushEntitySceneObjectOutOfEntityCollision(arg1,0x20,entry,0x10,arg2);
        }
      }
      intCursor = (int *)(entry2 + 0x20);
      entry2 = *intCursor;
    } while (*intCursor != 0);
    return 0;
  }
  return 0;
}

