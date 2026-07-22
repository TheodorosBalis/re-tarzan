#include "tarzan_ghidra_types.hpp"

// Address: 0x004B2E3D
// Label: __sbh_alloc_new_region
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 * __sbh_alloc_new_region(void)

{
  undefined4 *dataCursor;
  LPVOID value;
  
  if (g_CrtSmallBlockHeapRegionCount == g_CrtSmallBlockHeapRegionCapacity) {
    value = HeapReAlloc(newHeapPTR,0,mallocPTR,(g_CrtSmallBlockHeapRegionCapacity * 5 + 0x50) * 4);
    if (value == (LPVOID)0x0) {
      return (undefined4 *)0x0;
    }
    g_CrtSmallBlockHeapRegionCapacity = g_CrtSmallBlockHeapRegionCapacity + 0x10;
    mallocPTR = value;
  }
  dataCursor = (undefined4 *)((int)mallocPTR + g_CrtSmallBlockHeapRegionCount * 0x14);
  value = HeapAlloc(newHeapPTR,8,0x41c4);
  dataCursor[4] = value;
  if (value != (LPVOID)0x0) {
    value = VirtualAlloc((LPVOID)0x0,0x100000,0x2000,4);
    dataCursor[3] = value;
    if (value != (LPVOID)0x0) {
      dataCursor[2] = 0xffffffff;
      *dataCursor = 0;
      dataCursor[1] = 0;
      g_CrtSmallBlockHeapRegionCount = g_CrtSmallBlockHeapRegionCount + 1;
      *(undefined4 *)dataCursor[4] = 0xffffffff;
      return dataCursor;
    }
    HeapFree(newHeapPTR,0,(LPVOID)dataCursor[4]);
  }
  return (undefined4 *)0x0;
}

