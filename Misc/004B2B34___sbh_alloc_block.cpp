#include "tarzan_ghidra_types.hpp"

// Address: 0x004B2B34
// Label: __sbh_alloc_block
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int * __sbh_alloc_block(uint *arg1)

{
  char *stringCursor;
  int *intCursor2;
  char resultFlag;
  int *intCursor3;
  undefined4 value5;
  byte flagByte;
  uint value6;
  int value3;
  uint *dataCursor3;
  int value;
  int *intCursor;
  uint *dataCursor;
  uint *dataCursor2;
  uint value4;
  int value2;
  uint localState;
  uint localState3;
  int localState2;
  
  dataCursor3 = mallocPTR + g_CrtSmallBlockHeapRegionCount * 5;
  value6 = (int)arg1 + 0x17U & 0xfffffff0;
  value3 = ((int)((int)arg1 + 0x17U) >> 4) + -1;
  flagByte = (byte)value3;
  arg1 = g_CrtSmallBlockHeapSearchCursor;
  if (value3 < 0x20) {
    localState = 0xffffffff >> (flagByte & 0x1f);
    localState3 = 0xffffffff;
  }
  else {
    localState3 = 0xffffffff >> (flagByte - 0x20 & 0x1f);
    localState = 0;
  }
  for (; (arg1 < dataCursor3 && ((arg1[1] & localState3) == 0 && (*arg1 & localState) == 0));
      arg1 = arg1 + 5) {
  }
  dataCursor = mallocPTR;
  if (arg1 == dataCursor3) {
    for (; (dataCursor < g_CrtSmallBlockHeapSearchCursor &&
           ((dataCursor[1] & localState3) == 0 && (*dataCursor & localState) == 0)); dataCursor = dataCursor + 5) {
    }
    arg1 = dataCursor;
    if (dataCursor == g_CrtSmallBlockHeapSearchCursor) {
      for (; (dataCursor < dataCursor3 && (dataCursor[2] == 0)); dataCursor = dataCursor + 5) {
      }
      dataCursor2 = mallocPTR;
      arg1 = dataCursor;
      if (dataCursor == dataCursor3) {
        for (; (dataCursor2 < g_CrtSmallBlockHeapSearchCursor && (dataCursor2[2] == 0));
            dataCursor2 = dataCursor2 + 5) {
        }
        arg1 = dataCursor2;
        if ((dataCursor2 == g_CrtSmallBlockHeapSearchCursor) &&
           (arg1 = (uint *)__sbh_alloc_new_region(), arg1 == (uint *)0x0)) {
          return (int *)0x0;
        }
      }
      value5 = __sbh_alloc_new_group(arg1);
      *(undefined4 *)arg1[4] = value5;
      if (*(int *)arg1[4] == -1) {
        return (int *)0x0;
      }
    }
  }
  intCursor3 = (int *)arg1[4];
  localState2 = *intCursor3;
  if ((localState2 == -1) ||
     ((intCursor3[localState2 + 0x31] & localState3) == 0 && (intCursor3[localState2 + 0x11] & localState) == 0)) {
    localState2 = 0;
    dataCursor3 = (uint *)(intCursor3 + 0x11);
    if ((intCursor3[0x31] & localState3) == 0 && (intCursor3[0x11] & localState) == 0) {
      do {
        dataCursor = dataCursor3 + 0x21;
        localState2 = localState2 + 1;
        dataCursor3 = dataCursor3 + 1;
      } while ((*dataCursor & localState3) == 0 && (localState & *dataCursor3) == 0);
    }
  }
  value3 = 0;
  intCursor2 = intCursor3 + localState2 * 0x81 + 0x51;
  localState = intCursor3[localState2 + 0x11] & localState;
  if (localState == 0) {
    localState = intCursor3[localState2 + 0x31] & localState3;
    value3 = 0x20;
  }
  for (; -1 < (int)localState; localState = localState << 1) {
    value3 = value3 + 1;
  }
  intCursor = (int *)intCursor2[value3 * 2 + 1];
  value = *intCursor - value6;
  value2 = (value >> 4) + -1;
  if (0x3f < value2) {
    value2 = 0x3f;
  }
  g_CrtSmallBlockHeapSearchCursor = arg1;
  if (value2 != value3) {
    if (intCursor[1] == intCursor[2]) {
      if (value3 < 0x20) {
        stringCursor = (char *)((int)intCursor3 + value3 + 4);
        value4 = ~(0x80000000U >> ((byte)value3 & 0x1f));
        intCursor3[localState2 + 0x11] = value4 & intCursor3[localState2 + 0x11];
        *stringCursor = *stringCursor + -1;
        if (*stringCursor == '\0') {
          *arg1 = *arg1 & value4;
        }
      }
      else {
        stringCursor = (char *)((int)intCursor3 + value3 + 4);
        value4 = ~(0x80000000U >> ((byte)value3 - 0x20 & 0x1f));
        intCursor3[localState2 + 0x31] = intCursor3[localState2 + 0x31] & value4;
        *stringCursor = *stringCursor + -1;
        if (*stringCursor == '\0') {
          arg1[1] = arg1[1] & value4;
        }
      }
    }
    *(int *)(intCursor[2] + 4) = intCursor[1];
    *(int *)(intCursor[1] + 8) = intCursor[2];
    if (value == 0) goto LAB_004b2dfa;
    intCursor[1] = intCursor2[value2 * 2 + 1];
    intCursor[2] = (int)(intCursor2 + value2 * 2);
    (intCursor2 + value2 * 2)[1] = (int)intCursor;
    *(int **)(intCursor[1] + 8) = intCursor;
    if (intCursor[1] == intCursor[2]) {
      resultFlag = *(char *)(value2 + 4 + (int)intCursor3);
      flagByte = (byte)value2;
      if (value2 < 0x20) {
        *(char *)(value2 + 4 + (int)intCursor3) = resultFlag + '\x01';
        if (resultFlag == '\0') {
          *arg1 = *arg1 | 0x80000000U >> (flagByte & 0x1f);
        }
        intCursor3[localState2 + 0x11] = intCursor3[localState2 + 0x11] | 0x80000000U >> (flagByte & 0x1f);
      }
      else {
        *(char *)(value2 + 4 + (int)intCursor3) = resultFlag + '\x01';
        if (resultFlag == '\0') {
          arg1[1] = arg1[1] | 0x80000000U >> (flagByte - 0x20 & 0x1f);
        }
        intCursor3[localState2 + 0x31] = intCursor3[localState2 + 0x31] | 0x80000000U >> (flagByte - 0x20 & 0x1f);
      }
    }
  }
  if (value != 0) {
    *intCursor = value;
    *(int *)(value + -4 + (int)intCursor) = value;
  }
LAB_004b2dfa:
  intCursor = (int *)((int)intCursor + value);
  *intCursor = value6 + 1;
  *(uint *)((int)intCursor + (value6 - 4)) = value6 + 1;
  value3 = *intCursor2;
  *intCursor2 = value3 + 1;
  if (((value3 == 0) && (arg1 == g_CrtSmallBlockHeapPendingFreeRegion)) &&
     (localState2 == g_CrtSmallBlockHeapPendingFreeGroupIndex)) {
    g_CrtSmallBlockHeapPendingFreeRegion = (uint *)0x0;
  }
  *intCursor3 = localState2;
  return intCursor + 1;
}

