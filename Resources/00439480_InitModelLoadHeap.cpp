#include "tarzan_ghidra_types.hpp"

// Address: 0x00439480
// Label: InitModelLoadHeap
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitModelLoadHeap(undefined4 *arg1,undefined2 *arg2,int arg3)

{
  int value;
  
  value = (arg3 + 3U >> 2) - 0xc;
  *(int *)(arg2 + 4) = value;
  *(undefined4 *)(arg2 + 2) = 0;
  *arg2 = 0;
  *(undefined4 *)(arg2 + 6) = 0;
  *(undefined4 *)(arg2 + 10) = 0;
  *(undefined4 *)(arg2 + 8) = 0;
  *(undefined4 *)(arg2 + value * 2 + 0x10) = 0;
  *(undefined4 *)(arg2 + value * 2 + 0xe) = 0xffffffff;
  arg2[value * 2 + 0xc] = 0;
  *(undefined2 **)(arg2 + value * 2 + 0x12) = arg2;
  *arg1 = arg2;
  arg1[1] = arg2;
  arg1[2] = arg2;
  arg1[3] = 0;
  return;
}

