#include "tarzan_ghidra_types.hpp"

// Address: 0x004394F0
// Label: UnlinkModelHeapFreeBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UnlinkModelHeapFreeBlock(int arg1,int arg2)

{
  if (*(int *)(arg1 + 0x10) == 0) {
    *(undefined4 *)(arg2 + 4) = *(undefined4 *)(arg1 + 0x14);
  }
  else {
    *(undefined4 *)(*(int *)(arg1 + 0x10) + 0x14) = *(undefined4 *)(arg1 + 0x14);
  }
  if (*(int *)(arg1 + 0x14) != 0) {
    *(undefined4 *)(*(int *)(arg1 + 0x14) + 0x10) = *(undefined4 *)(arg1 + 0x10);
  }
  return;
}

