#include "tarzan_ghidra_types.hpp"

// Address: 0x004396C0
// Label: CompactAndAllocModelHeapBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

int CompactAndAllocModelHeapBlock(undefined4 arg1,undefined4 arg2)

{
  CompactModelHeapFully(arg2);
  AllocModelHeapBlock(arg1,arg2);
  return 0;
}

