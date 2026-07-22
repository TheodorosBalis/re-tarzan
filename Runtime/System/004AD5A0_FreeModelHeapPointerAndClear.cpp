#include "tarzan_ghidra_types.hpp"

// Address: 0x004AD5A0
// Label: FreeModelHeapPointerAndClear
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FreeModelHeapPointerAndClear(int *arg1)

{
  if (arg1 != (int *)0x0) {
    if (*arg1 != 0) {
      FreeModelHeapBlock(*arg1,&g_ModelLoadHeapState);
    }
    *arg1 = 0;
  }
  return;
}

