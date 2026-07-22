#include "tarzan_ghidra_types.hpp"

// Address: 0x0040D0B0
// Label: CampsiteCommotion::UpdateClayton
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateClayton(int entry)

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

