#include "tarzan_ghidra_types.hpp"

// Address: 0x004396E0
// Label: FreeModelHeapBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FreeModelHeapBlock(int arg1,int arg2)

{
  undefined2 *dataCursor;
  int value;
  undefined2 *dataCursor2;
  
  dataCursor2 = (undefined2 *)(arg1 + -0x18);
  if (*(undefined4 **)(arg1 + -0x14) != (undefined4 *)0xffffffff) {
    **(undefined4 **)(arg1 + -0x14) = 0;
  }
  dataCursor = *(undefined2 **)(arg1 + -0xc);
  value = arg1 + *(int *)(arg1 + -0x10) * 4;
  if ((dataCursor2 < *(undefined2 **)(arg2 + 8)) ||
     (*(undefined2 **)(arg2 + 8) == (undefined2 *)0x0)) {
    *(undefined2 **)(arg2 + 8) = dataCursor2;
  }
  if (*(int *)(value + 4) == 0) {
    UnlinkModelHeapFreeBlock(value,arg2);
    value = *(int *)(arg1 + -0x10) + *(int *)(value + 8) + 6;
    *dataCursor2 = 0;
    *(int *)(arg1 + -0x10) = value;
    *(undefined2 **)(arg1 + 0xc + value * 4) = dataCursor2;
  }
  if ((dataCursor == (undefined2 *)0x0) || (*(int *)(dataCursor + 2) != 0)) {
    *(undefined4 *)(arg1 + -0x14) = 0;
  }
  else {
    value = *(int *)(arg1 + -0x10);
    *dataCursor = 0;
    *(int *)(dataCursor + 4) = *(int *)(dataCursor + 4) + value + 6;
    *(undefined2 **)(arg1 + 0xc + *(int *)(arg1 + -0x10) * 4) = dataCursor;
    UnlinkModelHeapFreeBlock(dataCursor,arg2);
    if ((dataCursor < *(undefined2 **)(arg2 + 8)) ||
       (dataCursor2 = dataCursor, *(undefined2 **)(arg2 + 8) == (undefined2 *)0x0)) {
      *(undefined2 **)(arg2 + 8) = dataCursor;
      InsertModelHeapFreeBlockSorted(dataCursor,arg2);
      return;
    }
  }
  InsertModelHeapFreeBlockSorted(dataCursor2,arg2);
  return;
}

