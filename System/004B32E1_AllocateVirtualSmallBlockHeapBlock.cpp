#include "tarzan_ghidra_types.hpp"

// Address: 0x004B32E1
// Label: AllocateVirtualSmallBlockHeapBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Type propagation algorithm not settling */

int * AllocateVirtualSmallBlockHeapBlock(uint arg1)

{
  int *intCursor;
  undefined **dataCursor;
  int value;
  int *intCursor2;
  int *intCursor3;
  undefined *dataCursor4;
  undefined **dataCursor2;
  int *intCursor4;
  undefined **dataCursor3;
  int localState;
  
  intCursor4 = (int *)g_CrtSmallBlockHeap;
  do {
    if (intCursor4[4] != -1) {
      intCursor3 = (int *)intCursor4[2];
      value = ((int)intCursor3 + (-0x18 - (int)intCursor4) >> 3) * 0x1000 + intCursor4[4];
      if (intCursor3 < intCursor4 + 0x806) {
        do {
          if (((int)arg1 <= *intCursor3) && (arg1 < (uint)intCursor3[1])) {
            intCursor2 = (int *)AllocateVirtualSmallBlockPageUnits(value,*intCursor3,arg1);
            if (intCursor2 != (int *)0x0) goto LAB_004b33ac;
            intCursor3[1] = arg1;
          }
          intCursor3 = intCursor3 + 2;
          value = value + 0x1000;
        } while (intCursor3 < intCursor4 + 0x806);
      }
      intCursor = (int *)intCursor4[2];
      value = intCursor4[4];
      for (intCursor3 = intCursor4 + 6; intCursor3 < intCursor; intCursor3 = intCursor3 + 2) {
        if (((int)arg1 <= *intCursor3) && (arg1 < (uint)intCursor3[1])) {
          intCursor2 = (int *)AllocateVirtualSmallBlockPageUnits(value,*intCursor3,arg1);
          if (intCursor2 != (int *)0x0) {
LAB_004b33ac:
            g_CrtSmallBlockHeap = (undefined *)intCursor4;
            *intCursor3 = *intCursor3 - arg1;
            intCursor4[2] = (int)intCursor3;
            return intCursor2;
          }
          intCursor3[1] = arg1;
        }
        value = value + 0x1000;
      }
    }
    intCursor4 = (int *)*intCursor4;
    if (intCursor4 == (int *)g_CrtSmallBlockHeap) {
      dataCursor3 = &g_CrtStaticVirtualHeapRegionHeader;
      while ((dataCursor3[4] == (undefined *)0xffffffff || (dataCursor3[3] == (undefined *)0x0))) {
        dataCursor3 = (undefined **)*dataCursor3;
        if (dataCursor3 == &g_CrtStaticVirtualHeapRegionHeader) {
          dataCursor4 = (undefined *)InitializeVirtualSmallBlockHeapRegion();
          if (dataCursor4 == (undefined *)0x0) {
            return (int *)0x0;
          }
          intCursor4 = *(int **)(dataCursor4 + 0x10);
          *(char *)(intCursor4 + 2) = (char)arg1;
          g_CrtSmallBlockHeap = dataCursor4;
          *intCursor4 = (int)intCursor4 + arg1 + 8;
          intCursor4[1] = 0xf0 - arg1;
          *(uint *)(dataCursor4 + 0x18) = *(int *)(dataCursor4 + 0x18) - (arg1 & 0xff);
          return intCursor4 + 0x40;
        }
      }
      dataCursor = (undefined **)dataCursor3[3];
      localState = 0;
      intCursor4 = (int *)(dataCursor3[4] + ((int)dataCursor + (-0x18 - (int)dataCursor3) >> 3) * 0x1000);
      dataCursor4 = *dataCursor;
      dataCursor2 = dataCursor;
      for (; (dataCursor4 == (undefined *)0xffffffff && (localState < 0x10)); localState = localState + 1) {
        dataCursor2 = dataCursor2 + 2;
        dataCursor4 = *dataCursor2;
      }
      intCursor3 = VirtualAlloc(intCursor4,localState << 0xc,0x1000,4);
      if (intCursor3 != intCursor4) {
        return (int *)0x0;
      }
      memset(intCursor4,localState << 0xc,0);
      dataCursor2 = dataCursor;
      if (0 < localState) {
        intCursor3 = intCursor4 + 1;
        do {
          *(undefined1 *)(intCursor3 + 0x3d) = 0xff;
          intCursor3[-1] = (int)(intCursor3 + 1);
          *intCursor3 = 0xf0;
          *dataCursor2 = (undefined *)0xf0;
          dataCursor2[1] = (undefined *)0xf1;
          intCursor3 = intCursor3 + 0x400;
          dataCursor2 = dataCursor2 + 2;
          localState = localState + -1;
        } while (localState != 0);
      }
      for (; (dataCursor2 < dataCursor3 + 0x806 && (*dataCursor2 != (undefined *)0xffffffff));
          dataCursor2 = dataCursor2 + 2) {
      }
      g_CrtSmallBlockHeap = (undefined *)dataCursor3;
      dataCursor3[3] = (undefined *)(-(uint)(dataCursor2 < dataCursor3 + 0x806) & (uint)dataCursor2);
      *(char *)(intCursor4 + 2) = (char)arg1;
      dataCursor3[2] = (undefined *)dataCursor;
      *dataCursor = *dataCursor + -arg1;
      intCursor4[1] = intCursor4[1] - arg1;
      *intCursor4 = (int)intCursor4 + arg1 + 8;
      return intCursor4 + 0x40;
    }
  } while( true );
}

