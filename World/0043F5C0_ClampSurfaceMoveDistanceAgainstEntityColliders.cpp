#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F5C0
// Label: ClampSurfaceMoveDistanceAgainstEntityColliders
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 ClampSurfaceMoveDistanceAgainstEntityColliders(int arg1,undefined4 arg2)

{
  int *intCursor;
  int entry;
  int entry2;
  
  entry2 = g_ActiveEntityListHead;
  if (g_ActiveEntityListHead != 0) {
    do {
      for (entry = *(int *)(entry2 + 0x38); entry != 0; entry = *(int *)(entry + 0x34)) {
        if (arg1 != entry) {
          arg2 = ClampSurfaceMoveDistanceAgainstEntityAttachment(arg1,entry,arg2);
        }
      }
      intCursor = (int *)(entry2 + 0x20);
      entry2 = *intCursor;
    } while (*intCursor != 0);
    return arg2;
  }
  return arg2;
}

