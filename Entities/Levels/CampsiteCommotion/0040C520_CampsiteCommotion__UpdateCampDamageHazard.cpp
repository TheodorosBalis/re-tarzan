#include "tarzan_ghidra_types.hpp"

// Address: 0x0040C520
// Label: CampsiteCommotion::UpdateCampDamageHazard
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateCampDamageHazard(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  
  value = entity->sceneObjects;
  if (value != 0) {
    CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,3);
      g_PlayerDamageContactEntitySceneObject = value;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

