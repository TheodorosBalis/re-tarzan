#include "tarzan_ghidra_types.hpp"

// Address: 0x0040CC40
// Label: CampsiteCommotion::InitFallingBoxSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::InitFallingBoxSpawner(int entry)

{
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

