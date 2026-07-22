#include "tarzan_ghidra_types.hpp"

// Address: 0x004B329C
// Label: FreeVirtualSmallBlockHeapAllocation
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FreeVirtualSmallBlockHeapAllocation(int arg1,int arg2,byte *arg3)

{
  int *intCursor;
  
  intCursor = (int *)(arg1 + 0x18 + (arg2 - *(int *)(arg1 + 0x10) >> 0xc) * 8);
  *intCursor = *intCursor + (uint)*arg3;
  *arg3 = 0;
  intCursor[1] = 0xf1;
  if ((*intCursor == 0xf0) &&
     (g_CrtVirtualHeapDecommittablePageCount = g_CrtVirtualHeapDecommittablePageCount + 1,
     g_CrtVirtualHeapDecommittablePageCount == 0x20)) {
    DecommitVirtualSmallBlockHeapPages(0x10);
  }
  return;
}

