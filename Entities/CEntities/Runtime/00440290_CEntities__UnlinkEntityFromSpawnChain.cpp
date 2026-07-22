#include "tarzan_ghidra_types.hpp"

// Address: 0x00440290
// Label: CEntities::UnlinkEntityFromSpawnChain
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UnlinkEntityFromSpawnChain(int entry)

{
  if (*(int *)(entry + 0x14) != 0) {
    *(undefined4 *)(*(int *)(entry + 0x14) + 0x18) = *(undefined4 *)(entry + 0x18);
  }
  if (*(int *)(entry + 0x18) != 0) {
    *(undefined4 *)(*(int *)(entry + 0x18) + 0x14) = *(undefined4 *)(entry + 0x14);
  }
  *(undefined4 *)(entry + 0x14) = 0;
  *(undefined4 *)(entry + 0x18) = 0;
  return;
}

