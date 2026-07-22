#include "tarzan_ghidra_types.hpp"

// Address: 0x004395F0
// Label: AllocModelHeapBlockHeader
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int AllocModelHeapBlockHeader(int arg1,int arg2)

{
  int value;
  undefined4 value2;
  uint value3;
  
  value3 = arg1 + 3U >> 2;
  value = FindModelHeapFreeBlockAtLeastWords(value3,*(undefined4 *)(arg2 + 4));
  if (value == 0) {
    return 0;
  }
  if (value3 + 0x58 < *(uint *)(value + 8)) {
    value = SplitModelHeapFreeBlockForAlloc(value,value3,arg2);
  }
  else {
    UnlinkModelHeapFreeBlock(value);
  }
  if (value == *(int *)(arg2 + 8)) {
    value2 = FindNextModelHeapCompactionCursor(value);
    *(undefined4 *)(arg2 + 8) = value2;
  }
  return value;
}

