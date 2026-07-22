#include "tarzan_ghidra_types.hpp"

// Address: 0x004395A0
// Label: SplitModelHeapFreeBlockForAlloc
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int SplitModelHeapFreeBlockForAlloc(int arg1,int arg2,undefined4 arg3)

{
  int value;
  
  UnlinkModelHeapFreeBlock(arg1,arg3);
  *(int *)(arg1 + 8) = *(int *)(arg1 + 8) + (-6 - arg2);
  InsertModelHeapFreeBlockSorted(arg1,arg3);
  value = *(int *)(arg1 + 8);
  *(int *)(arg1 + 0x20 + value * 4) = arg2;
  *(int *)(arg1 + 0x24 + value * 4) = arg1;
  value = arg1 + 0x18 + value * 4;
  *(int *)(value + 0x24 + arg2 * 4) = value;
  return 0;
}

