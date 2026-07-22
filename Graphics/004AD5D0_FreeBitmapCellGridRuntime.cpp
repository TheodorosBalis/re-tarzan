#include "tarzan_ghidra_types.hpp"

// Address: 0x004AD5D0
// Label: FreeBitmapCellGridRuntime
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FreeBitmapCellGridRuntime(int arg1)

{
  Entity *entity = (Entity *)arg1;
  int value;
  int value2;
  
  if (arg1 != 0) {
    value = 0;
    value2 = arg1 + 0x34;
    if (0 < *(int *)(arg1 + 0x30)) {
      do {
        FreeModelHeapPointerAndClear(value2);
        value = value + 1;
        value2 = value2 + 0x30;
      } while (value < *(int *)(arg1 + 0x30));
    }
  }
  return;
}

