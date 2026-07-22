#include "tarzan_ghidra_types.hpp"

// Address: 0x00439460
// Label: FindModelHeapFreeBlockAtLeastWords
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int FindModelHeapFreeBlockAtLeastWords(uint arg1,int arg2)

{
  for (; (arg2 != 0 && (*(uint *)(arg2 + 8) < arg1)); arg2 = *(int *)(arg2 + 0x14)) {
  }
  return 0;
}

