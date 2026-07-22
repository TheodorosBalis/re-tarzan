#include "tarzan_ghidra_types.hpp"

// Address: 0x004678B0
// Label: TarzanToTheRescue::UpdateFallingBoulderDust
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateFallingBoulderDust(int entry)

{
  Entity *entity = (Entity *)entry;
  *(int *)(entity->sceneObjects + 0x30) = *(int *)(entity->sceneObjects + 0x30) + -0xe6;
  if (*(int *)(entity->sceneObjects + 0x30) < 0) {
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
  }
  return;
}

