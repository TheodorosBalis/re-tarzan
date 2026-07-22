#include "tarzan_ghidra_types.hpp"

// Address: 0x0040CB60
// Label: CampsiteCommotion::UpdateBoxPusherB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateBoxPusherB(int entry)

{
  Entity *entity = (Entity *)entry;
  if (entity->sceneObjects != 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  }
  if (*(int *)(entry + 0x14) == 0) {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

