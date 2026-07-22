#include "tarzan_ghidra_types.hpp"

// Address: 0x004B312D
// Label: ReleaseVirtualSmallBlockHeapRegion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseVirtualSmallBlockHeapRegion(undefined **arg1)

{
  VirtualFree(arg1[4],0,0x8000);
  if ((undefined **)g_CrtSmallBlockHeap == arg1) {
    g_CrtSmallBlockHeap = arg1[1];
  }
  if (arg1 != &g_CrtStaticVirtualHeapRegionHeader) {
    *(undefined **)arg1[1] = *arg1;
    *(undefined **)(*arg1 + 4) = arg1[1];
    HeapFree(newHeapPTR,0,arg1);
    return;
  }
  g_CrtStaticVirtualHeapRegionAvailable = 0xffffffff;
  return;
}

