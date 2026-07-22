#include "tarzan_ghidra_types.hpp"

// Address: 0x004397A0
// Label: QueueModelHeapDeferredFree
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void QueueModelHeapDeferredFree(int arg1,int arg2,undefined2 arg3)

{
  *(undefined4 *)(arg1 + -4) = *(undefined4 *)(arg2 + 0xc);
  *(undefined2 *)(arg1 + -0x16) = arg3;
  *(int *)(arg2 + 0xc) = arg1 + -0x18;
  return;
}

