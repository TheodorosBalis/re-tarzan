#include "tarzan_ghidra_types.hpp"

// Address: 0x004402E0
// Label: CEntities::UnlinkEntityFromProcessingList
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UnlinkEntityFromProcessingList(int entry2)

{
  int entry;
  
  if (*(int **)(entry2 + 0x24) != (int *)0x0) {
    if (*(int *)(entry2 + 0x1c) == 0) {
      entry = *(int *)(entry2 + 0x20);
      **(int **)(entry2 + 0x24) = entry;
      if (entry != 0) {
        *(undefined4 *)(*(int *)(entry2 + 0x20) + 0x1c) = 0;
      }
    }
    else {
      *(undefined4 *)(*(int *)(entry2 + 0x1c) + 0x20) = *(undefined4 *)(entry2 + 0x20);
      if (*(int *)(entry2 + 0x20) != 0) {
        *(undefined4 *)(*(int *)(entry2 + 0x20) + 0x1c) = *(undefined4 *)(entry2 + 0x1c);
        *(undefined4 *)(entry2 + 0x1c) = 0;
        *(undefined4 *)(entry2 + 0x20) = 0;
        *(undefined4 *)(entry2 + 0x24) = 0;
        return;
      }
    }
  }
  *(undefined4 *)(entry2 + 0x1c) = 0;
  *(undefined4 *)(entry2 + 0x20) = 0;
  *(undefined4 *)(entry2 + 0x24) = 0;
  return;
}

