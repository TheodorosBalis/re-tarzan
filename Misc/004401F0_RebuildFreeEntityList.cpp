#include "tarzan_ghidra_types.hpp"

// Address: 0x004401F0
// Label: RebuildFreeEntityList
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RebuildFreeEntityList(void)

{
  int entry;
  int *intCursor;
  int entry2;
  
  entry = (_g_EntityPoolCount & 0xffff) - 1;
  g_FreeEntityListHead = (int *)0x0;
  if (0 < entry) {
    entry2 = entry * 0x54;
    do {
      intCursor = (int *)(g_EntityPoolBase + entry2);
      if (*intCursor == 0) {
        if (g_FreeEntityListHead == (int *)0x0) {
          g_FreeEntityListHead = intCursor;
          intCursor[4] = 0;
        }
        else {
          g_FreeEntityListHead[3] = (int)intCursor;
          intCursor[4] = (int)g_FreeEntityListHead;
          g_FreeEntityListHead = intCursor;
        }
        intCursor[3] = 0;
      }
      entry2 = entry2 + -0x54;
      entry = entry + -1;
    } while (entry != 0);
  }
  return;
}

