#include "tarzan_ghidra_types.hpp"

// Address: 0x004B280B
// Label: __sbh_free_block
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __sbh_free_block(uint *arg1,int arg2)

{
  char *stringCursor;
  uint *dataCursor4;
  int *intCursor;
  char resultFlag;
  uint value3;
  uint value4;
  uint value5;
  byte flagByte;
  uint value6;
  uint *dataCursor;
  uint *dataCursor2;
  uint *dataCursor3;
  uint value;
  uint value2;
  uint localState;
  
  value3 = arg1[4];
  dataCursor3 = (uint *)(arg2 + -4);
  value2 = arg2 - arg1[3] >> 0xf;
  intCursor = (int *)(value2 * 0x204 + 0x144 + value3);
  value = *dataCursor3;
  localState = value - 1;
  if ((localState & 1) == 0) {
    value4 = *(uint *)(localState + (int)dataCursor3);
    value5 = *(uint *)(arg2 + -8);
    if ((value4 & 1) == 0) {
      value6 = ((int)value4 >> 4) - 1;
      if (0x3f < value6) {
        value6 = 0x3f;
      }
      if (*(int *)((int)dataCursor3 + value + 3) == *(int *)((int)dataCursor3 + value + 7)) {
        if (value6 < 0x20) {
          stringCursor = (char *)(value6 + 4 + value3);
          value6 = ~(0x80000000U >> ((byte)value6 & 0x1f));
          dataCursor = (uint *)(value3 + 0x44 + value2 * 4);
          *dataCursor = *dataCursor & value6;
          *stringCursor = *stringCursor + -1;
          if (*stringCursor == '\0') {
            *arg1 = *arg1 & value6;
          }
        }
        else {
          stringCursor = (char *)(value6 + 4 + value3);
          value6 = ~(0x80000000U >> ((byte)value6 - 0x20 & 0x1f));
          dataCursor = (uint *)(value3 + 0xc4 + value2 * 4);
          *dataCursor = *dataCursor & value6;
          *stringCursor = *stringCursor + -1;
          if (*stringCursor == '\0') {
            arg1[1] = arg1[1] & value6;
          }
        }
      }
      localState = localState + value4;
      *(undefined4 *)(*(int *)((int)dataCursor3 + value + 7) + 4) =
           *(undefined4 *)((int)dataCursor3 + value + 3);
      *(undefined4 *)(*(int *)((int)dataCursor3 + value + 3) + 8) =
           *(undefined4 *)((int)dataCursor3 + value + 7);
    }
    dataCursor = (uint *)(((int)localState >> 4) + -1);
    if ((uint *)0x3f < dataCursor) {
      dataCursor = (uint *)0x3f;
    }
    dataCursor2 = arg1;
    if ((value5 & 1) == 0) {
      dataCursor3 = (uint *)((int)dataCursor3 - value5);
      dataCursor2 = (uint *)(((int)value5 >> 4) + -1);
      if ((uint *)0x3f < dataCursor2) {
        dataCursor2 = (uint *)0x3f;
      }
      localState = localState + value5;
      dataCursor = (uint *)(((int)localState >> 4) + -1);
      if ((uint *)0x3f < dataCursor) {
        dataCursor = (uint *)0x3f;
      }
      if (dataCursor2 != dataCursor) {
        if (dataCursor3[1] == dataCursor3[2]) {
          if (dataCursor2 < (uint *)0x20) {
            value = ~(0x80000000U >> ((byte)dataCursor2 & 0x1f));
            dataCursor4 = (uint *)(value3 + 0x44 + value2 * 4);
            *dataCursor4 = *dataCursor4 & value;
            stringCursor = (char *)((int)dataCursor2 + value3 + 4);
            *stringCursor = *stringCursor + -1;
            if (*stringCursor == '\0') {
              *arg1 = *arg1 & value;
            }
          }
          else {
            value = ~(0x80000000U >> ((byte)dataCursor2 - 0x20 & 0x1f));
            dataCursor4 = (uint *)(value3 + 0xc4 + value2 * 4);
            *dataCursor4 = *dataCursor4 & value;
            stringCursor = (char *)((int)dataCursor2 + value3 + 4);
            *stringCursor = *stringCursor + -1;
            if (*stringCursor == '\0') {
              arg1[1] = arg1[1] & value;
            }
          }
        }
        *(uint *)(dataCursor3[2] + 4) = dataCursor3[1];
        *(uint *)(dataCursor3[1] + 8) = dataCursor3[2];
      }
    }
    if (((value5 & 1) != 0) || (dataCursor2 != dataCursor)) {
      dataCursor3[1] = intCursor[(int)dataCursor * 2 + 1];
      dataCursor3[2] = (uint)(intCursor + (int)dataCursor * 2);
      (intCursor + (int)dataCursor * 2)[1] = (int)dataCursor3;
      *(uint **)(dataCursor3[1] + 8) = dataCursor3;
      if (dataCursor3[1] == dataCursor3[2]) {
        resultFlag = *(char *)((int)dataCursor + value3 + 4);
        *(char *)((int)dataCursor + value3 + 4) = resultFlag + '\x01';
        flagByte = (byte)dataCursor;
        if (dataCursor < (uint *)0x20) {
          if (resultFlag == '\0') {
            *arg1 = *arg1 | 0x80000000U >> (flagByte & 0x1f);
          }
          dataCursor = (uint *)(value3 + 0x44 + value2 * 4);
          *dataCursor = *dataCursor | 0x80000000U >> (flagByte & 0x1f);
        }
        else {
          if (resultFlag == '\0') {
            arg1[1] = arg1[1] | 0x80000000U >> (flagByte - 0x20 & 0x1f);
          }
          dataCursor = (uint *)(value3 + 0xc4 + value2 * 4);
          *dataCursor = *dataCursor | 0x80000000U >> (flagByte - 0x20 & 0x1f);
        }
      }
    }
    *dataCursor3 = localState;
    *(uint *)((localState - 4) + (int)dataCursor3) = localState;
    *intCursor = *intCursor + -1;
    if (*intCursor == 0) {
      if (g_CrtSmallBlockHeapPendingFreeRegion != (uint *)0x0) {
        VirtualFree((LPVOID)(g_CrtSmallBlockHeapPendingFreeGroupIndex * 0x8000 +
                            g_CrtSmallBlockHeapPendingFreeRegion[3]),0x8000,0x4000);
        g_CrtSmallBlockHeapPendingFreeRegion[2] =
             g_CrtSmallBlockHeapPendingFreeRegion[2] |
             0x80000000U >> ((byte)g_CrtSmallBlockHeapPendingFreeGroupIndex & 0x1f);
        *(undefined4 *)
         (g_CrtSmallBlockHeapPendingFreeRegion[4] + 0xc4 +
         g_CrtSmallBlockHeapPendingFreeGroupIndex * 4) = 0;
        *(char *)(g_CrtSmallBlockHeapPendingFreeRegion[4] + 0x43) =
             *(char *)(g_CrtSmallBlockHeapPendingFreeRegion[4] + 0x43) + -1;
        if (*(char *)(g_CrtSmallBlockHeapPendingFreeRegion[4] + 0x43) == '\0') {
          g_CrtSmallBlockHeapPendingFreeRegion[1] =
               g_CrtSmallBlockHeapPendingFreeRegion[1] & 0xfffffffe;
        }
        if (g_CrtSmallBlockHeapPendingFreeRegion[2] == 0xffffffff) {
          VirtualFree((LPVOID)g_CrtSmallBlockHeapPendingFreeRegion[3],0,0x8000);
          HeapFree(newHeapPTR,0,(LPVOID)g_CrtSmallBlockHeapPendingFreeRegion[4]);
          memmove(g_CrtSmallBlockHeapPendingFreeRegion,g_CrtSmallBlockHeapPendingFreeRegion + 5,
                  (g_CrtSmallBlockHeapRegionCount * 0x14 - (int)g_CrtSmallBlockHeapPendingFreeRegion
                  ) + -0x14 + mallocPTR);
          g_CrtSmallBlockHeapRegionCount = g_CrtSmallBlockHeapRegionCount + -1;
          if (g_CrtSmallBlockHeapPendingFreeRegion < arg1) {
            arg1 = arg1 + -5;
          }
          g_CrtSmallBlockHeapSearchCursor = mallocPTR;
        }
      }
      g_CrtSmallBlockHeapPendingFreeRegion = arg1;
      g_CrtSmallBlockHeapPendingFreeGroupIndex = value2;
    }
  }
  return;
}

