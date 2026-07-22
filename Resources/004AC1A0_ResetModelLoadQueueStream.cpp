#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC1A0
// Label: ResetModelLoadQueueStream
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetModelLoadQueueStream(undefined4 arg1,undefined4 arg2)

{
  SeekVirtualGameFileHandle(arg1,arg2,0);
  return;
}

