#include "tarzan_ghidra_types.hpp"

// Address: 0x0048C410
// Label: CEntities::InitConsumedPickupPlaceholder
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitConsumedPickupPlaceholder(int entry)

{
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

