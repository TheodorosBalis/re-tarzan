#include "tarzan_ghidra_types.hpp"

// Address: 0x004448B0
// Label: CEntities::ProcessEntityDeathAndRelease
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::ProcessEntityDeathAndRelease(int entry)

{
  Entity *entity = (Entity *)entry;
  if (entity->sceneObjects != 0) {
    CEntities::ProcessEntityDeath(entity->sceneObjects,2);
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
  }
  return;
}

