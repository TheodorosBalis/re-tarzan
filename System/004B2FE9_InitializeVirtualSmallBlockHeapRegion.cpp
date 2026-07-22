#include "tarzan_ghidra_types.hpp"

// Address: 0x004B2FE9
// Label: InitializeVirtualSmallBlockHeapRegion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined ** InitializeVirtualSmallBlockHeapRegion(void)

{
  bool flagByte;
  int *lpAddress;
  LPVOID value2;
  undefined **dataCursor;
  int value;
  undefined **lpMem;
  
  if (g_CrtStaticVirtualHeapRegionAvailable == -1) {
    lpMem = &g_CrtStaticVirtualHeapRegionHeader;
  }
  else {
    lpMem = HeapAlloc(newHeapPTR,0,0x2020);
    if (lpMem == (undefined **)0x0) {
      return (undefined **)0x0;
    }
  }
  lpAddress = VirtualAlloc((LPVOID)0x0,0x400000,0x2000,4);
  if (lpAddress != (int *)0x0) {
    value2 = VirtualAlloc(lpAddress,0x10000,0x1000,4);
    if (value2 != (LPVOID)0x0) {
      if (lpMem == &g_CrtStaticVirtualHeapRegionHeader) {
        if (g_CrtStaticVirtualHeapRegionHeader == (undefined *)0x0) {
          g_CrtStaticVirtualHeapRegionHeader = (undefined *)&g_CrtStaticVirtualHeapRegionHeader;
        }
        if (g_CrtVirtualHeapRegionList == (undefined *)0x0) {
          g_CrtVirtualHeapRegionList = (undefined *)&g_CrtStaticVirtualHeapRegionHeader;
        }
      }
      else {
        *lpMem = (undefined *)&g_CrtStaticVirtualHeapRegionHeader;
        lpMem[1] = g_CrtVirtualHeapRegionList;
        g_CrtVirtualHeapRegionList = (undefined *)lpMem;
        *(undefined ***)lpMem[1] = lpMem;
      }
      lpMem[5] = (undefined *)(lpAddress + 0x100000);
      dataCursor = lpMem + 6;
      lpMem[3] = (undefined *)(lpMem + 0x26);
      lpMem[4] = (undefined *)lpAddress;
      lpMem[2] = (undefined *)dataCursor;
      value = 0;
      do {
        flagByte = 0xf < value;
        value = value + 1;
        *dataCursor = (undefined *)((flagByte - 1 & 0xf1) - 1);
        dataCursor[1] = (undefined *)0xf1;
        dataCursor = dataCursor + 2;
      } while (value < 0x400);
      memset(lpAddress,0,0x10000);
      for (; lpAddress < lpMem[4] + 0x10000; lpAddress = lpAddress + 0x400) {
        *(undefined1 *)(lpAddress + 0x3e) = 0xff;
        *lpAddress = (int)(lpAddress + 2);
        lpAddress[1] = 0xf0;
      }
      return lpMem;
    }
    VirtualFree(lpAddress,0,0x8000);
  }
  if (lpMem != &g_CrtStaticVirtualHeapRegionHeader) {
    HeapFree(newHeapPTR,0,lpMem);
  }
  return (undefined **)0x0;
}

