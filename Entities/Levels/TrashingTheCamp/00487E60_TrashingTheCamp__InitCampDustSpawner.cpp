#include "tarzan_ghidra_types.hpp"

// Address: 0x00487E60
// Label: TrashingTheCamp::InitCampDustSpawner
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::InitCampDustSpawner(int entry)

{
  *(undefined4 *)(entry + 0x4c) = 0;
  if (*(short *)(entry + 0x44) != 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

