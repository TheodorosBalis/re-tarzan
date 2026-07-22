#include "tarzan_ghidra_types.hpp"

// Address: 0x004397C0
// Label: BindModelHeapBlockHandle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void BindModelHeapBlockHandle(int arg1,int *arg2)

{
  if (*(undefined4 **)(arg1 + -0x14) != (undefined4 *)0xffffffff) {
    **(undefined4 **)(arg1 + -0x14) = 0;
  }
  *(undefined2 *)(arg1 + -0x18) = 0;
  *(int **)(arg1 + -0x14) = arg2;
  *arg2 = arg1;
  return;
}

