#include "tarzan_ghidra_types.hpp"

// Address: 0x00439240
// Label: RelocateModelHeapBlockIntoFreeGap
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RelocateModelHeapBlockIntoFreeGap(undefined4 *arg1,int arg2)

{
  undefined4 *dataCursor;
  int value;
  int value2;
  undefined4 value4;
  int value3;
  undefined4 *dataCursor2;
  undefined4 *dataCursor3;
  undefined4 *dataCursor4;
  undefined4 *dataCursor5;
  
  UnlinkModelHeapFreeBlock(arg1,arg2);
  value = arg1[2];
  dataCursor2 = arg1 + 6;
  dataCursor = arg1 + value + 6;
  value2 = dataCursor[2];
  dataCursor3 = dataCursor + 6;
  value4 = arg1[3];
  dataCursor4 = dataCursor;
  dataCursor5 = arg1;
  for (value3 = 6; value3 != 0; value3 = value3 + -1) {
    *dataCursor5 = *dataCursor4;
    dataCursor4 = dataCursor4 + 1;
    dataCursor5 = dataCursor5 + 1;
  }
  arg1[3] = value4;
  *(undefined4 **)arg1[1] = dataCursor2;
  for (value3 = value2; value3 != 0; value3 = value3 + -1) {
    value4 = *dataCursor3;
    dataCursor3 = dataCursor3 + 1;
    *dataCursor2 = value4;
    dataCursor2 = dataCursor2 + 1;
  }
  dataCursor2 = arg1 + arg1[2] + 6;
  dataCursor[value2 + 9] = dataCursor2;
  dataCursor2[2] = value;
  dataCursor2[1] = 0xffffffff;
  *(undefined2 *)dataCursor2 = 0;
  dataCursor2[3] = arg1;
  if (arg1 == *(undefined4 **)(arg2 + 8)) {
    value4 = FindNextModelHeapCompactionCursor(dataCursor2);
    *(undefined4 *)(arg2 + 8) = value4;
  }
  FreeModelHeapBlock(dataCursor2 + 6,arg2);
  return;
}

