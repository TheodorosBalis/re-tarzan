#include "tarzan_ghidra_types.hpp"

// Address: 0x00488B00
// Label: TrashingTheCamp::UpdateCampfire
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TrashingTheCamp::UpdateCampfire(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  
  if (entity->sceneObjects != 0) {
    *(ushort *)(entity->sceneObjects + 0xc) = (ushort)(TotalGameLoopTicks >> 1) & 0xf;
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

