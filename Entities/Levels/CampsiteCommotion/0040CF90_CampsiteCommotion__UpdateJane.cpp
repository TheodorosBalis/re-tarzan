#include "tarzan_ghidra_types.hpp"

// Address: 0x0040CF90
// Label: CampsiteCommotion::UpdateJane
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateJane(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  
  if (entity->sceneObjects != 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

