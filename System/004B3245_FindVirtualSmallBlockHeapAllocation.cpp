#include "tarzan_ghidra_types.hpp"

// Address: 0x004B3245
// Label: FindVirtualSmallBlockHeapAllocation
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int FindVirtualSmallBlockHeapAllocation(undefined *arg1,undefined4 *arg2,uint *arg3)

{
  undefined **dataCursor;
  uint value;
  
  dataCursor = &g_CrtStaticVirtualHeapRegionHeader;
  while ((arg1 <= dataCursor[4] || (dataCursor[5] <= arg1))) {
    dataCursor = (undefined **)*dataCursor;
    if (dataCursor == &g_CrtStaticVirtualHeapRegionHeader) {
      return 0;
    }
  }
  if (((uint)arg1 & 0xf) != 0) {
    return 0;
  }
  if (((uint)arg1 & 0xfff) < 0x100) {
    return 0;
  }
  *arg2 = dataCursor;
  value = (uint)arg1 & 0xfffff000;
  *arg3 = value;
  return ((int)(arg1 + (-0x100 - value)) >> 4) + 8 + value;
}

