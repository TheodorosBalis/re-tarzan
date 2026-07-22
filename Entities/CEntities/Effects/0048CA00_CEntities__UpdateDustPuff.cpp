#include "tarzan_ghidra_types.hpp"

// Address: 0x0048CA00
// Label: CEntities::UpdateDustPuff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::UpdateDustPuff(int entry)

{
  Entity *entity = (Entity *)entry;
  if (entity->sceneObjects != 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  }
  return;
}

