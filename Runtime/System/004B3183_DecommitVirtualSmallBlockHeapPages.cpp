#include "tarzan_ghidra_types.hpp"

// Address: 0x004B3183
// Label: DecommitVirtualSmallBlockHeapPages
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DecommitVirtualSmallBlockHeapPages(int arg1)

{
  BOOL value;
  int *intCursor;
  int value2;
  undefined *dataCursor;
  undefined *dataCursor2;
  int localState;
  
  dataCursor = g_CrtVirtualHeapRegionList;
  do {
    dataCursor2 = dataCursor;
    if (*(int *)(dataCursor + 0x10) != -1) {
      localState = 0;
      intCursor = (int *)(dataCursor + 0x2010);
      value2 = 0x3ff000;
      do {
        if (*intCursor == 0xf0) {
          value = VirtualFree((LPVOID)(value2 + *(int *)(dataCursor + 0x10)),0x1000,0x4000);
          if (value != 0) {
            *intCursor = -1;
            g_CrtVirtualHeapDecommittablePageCount = g_CrtVirtualHeapDecommittablePageCount + -1;
            if ((*(int **)(dataCursor + 0xc) == (int *)0x0) || (intCursor < *(int **)(dataCursor + 0xc))) {
              *(int **)(dataCursor + 0xc) = intCursor;
            }
            localState = localState + 1;
            arg1 = arg1 + -1;
            if (arg1 == 0) break;
          }
        }
        value2 = value2 + -0x1000;
        intCursor = intCursor + -2;
      } while (-1 < value2);
      dataCursor2 = *(undefined **)(dataCursor + 4);
      if ((localState != 0) && (*(int *)(dataCursor + 0x18) == -1)) {
        intCursor = (int *)(dataCursor + 0x20);
        value2 = 1;
        do {
          if (*intCursor != -1) break;
          value2 = value2 + 1;
          intCursor = intCursor + 2;
        } while (value2 < 0x400);
        if (value2 == 0x400) {
          ReleaseVirtualSmallBlockHeapRegion(dataCursor);
        }
      }
    }
    if ((dataCursor2 == g_CrtVirtualHeapRegionList) || (dataCursor = dataCursor2, arg1 < 1)) {
      return;
    }
  } while( true );
}

