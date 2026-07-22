#include "tarzan_ghidra_types.hpp"

// Address: 0x004397F0
// Label: ResizeModelHeapBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined2 * ResizeModelHeapBlock(int arg1,uint arg2,undefined4 arg3)

{
  uint value3;
  int value;
  undefined2 *dataCursor;
  int value2;
  
  value3 = (arg2 >> 2) - 6;
  value = arg1 + *(int *)(arg1 + -0x10) * 4;
  dataCursor = (undefined2 *)(arg1 + value3 * 4);
  value2 = *(int *)(arg1 + -0xc);
  *(undefined4 *)(dataCursor + 2) = *(undefined4 *)(arg1 + -0x14);
  *dataCursor = *(undefined2 *)(arg1 + -0x18);
  dataCursor[1] = *(undefined2 *)(arg1 + -0x16);
  if (*(int **)(dataCursor + 2) != (int *)0xffffffff) {
    **(int **)(dataCursor + 2) = (int)(dataCursor + 0xc);
  }
  *(uint *)(dataCursor + 4) = (*(int *)(arg1 + -0x10) - value3) + -6;
  if (value3 < 0x40) {
    if (*(int *)(value2 + 4) == 0) {
      *(undefined2 **)(value + 0xc) = dataCursor;
      UnlinkModelHeapFreeBlock(value2,arg3);
      *(undefined4 *)(value2 + 4) = 0xffffffff;
      *(uint *)(value2 + 8) = *(int *)(value2 + 8) + (arg2 >> 2);
      *(int *)(dataCursor + 6) = value2;
      FreeModelHeapBlock(value2 + 0x18,arg3);
      return dataCursor + 0xc;
    }
    *(int *)(dataCursor + 6) = value2;
    *(uint *)(value2 + 8) = *(int *)(value2 + 8) + arg2;
    return dataCursor + 0xc;
  }
  *(undefined4 *)(arg1 + -0x14) = 0xffffffff;
  *(uint *)(arg1 + -0x10) = value3;
  *(undefined2 **)(value + 0xc) = dataCursor;
  *(undefined2 **)(dataCursor + 6) = (undefined2 *)(arg1 + -0x18);
  FreeModelHeapBlock(arg1,arg3);
  return dataCursor + 0xc;
}

