#include "tarzan_ghidra_types.hpp"

// Address: 0x00439520
// Label: InsertModelHeapFreeBlockSorted
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InsertModelHeapFreeBlockSorted(int arg1,int arg2)

{
  int value;
  int value2;
  
  if (*(int *)(arg2 + 4) == 0) {
    *(int *)(arg2 + 4) = arg1;
    *(undefined4 *)(arg1 + 0x14) = 0;
    *(undefined4 *)(arg1 + 0x10) = 0;
    return;
  }
  value2 = *(int *)(arg2 + 4);
  while( true ) {
    if (*(uint *)(arg1 + 8) <= *(uint *)(value2 + 8)) {
      value = *(int *)(value2 + 0x10);
      if (value != 0) {
        *(int *)(value + 0x14) = arg1;
        *(int *)(arg1 + 0x10) = value;
        *(int *)(arg1 + 0x14) = value2;
        *(int *)(value2 + 0x10) = arg1;
        return;
      }
      *(int *)(arg2 + 4) = arg1;
      *(undefined4 *)(arg1 + 0x10) = 0;
      *(int *)(arg1 + 0x14) = value2;
      *(int *)(value2 + 0x10) = arg1;
      return;
    }
    value = *(int *)(value2 + 0x14);
    if (value == 0) break;
    value2 = value;
    if (value == 0) {
      return;
    }
  }
  *(int *)(value2 + 0x14) = arg1;
  *(int *)(arg1 + 0x10) = value2;
  *(undefined4 *)(arg1 + 0x14) = 0;
  return;
}

