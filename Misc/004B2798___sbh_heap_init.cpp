#include "tarzan_ghidra_types.hpp"

// Address: 0x004B2798
// Label: __sbh_heap_init
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 __sbh_heap_init(undefined4 arg1)

{
  mallocPTR = HeapAlloc(newHeapPTR,0,0x140);
  if (mallocPTR == (LPVOID)0x0) {
    return 0;
  }
  g_CrtSmallBlockHeapPendingFreeRegion = 0;
  g_CrtSmallBlockHeapRegionCount = 0;
  g_CrtSmallBlockHeapSearchCursor = mallocPTR;
  g_CrtSmallBlockHeapInitMode = arg1;
  g_CrtSmallBlockHeapRegionCapacity = 0x10;
  return 1;
}

