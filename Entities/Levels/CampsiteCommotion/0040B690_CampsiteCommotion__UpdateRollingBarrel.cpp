#include "tarzan_ghidra_types.hpp"

// Address: 0x0040B690
// Label: CampsiteCommotion::UpdateRollingBarrel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CampsiteCommotion::UpdateRollingBarrel(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  
  value = entity->sceneObjects;
  if (value != 0) {
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,*(undefined4 *)(entry + 0x4c));
    *(short *)(value + 0xa0) = ((EntitySceneObject *)value)->surfaceIndex << 1;
    ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58) + -0x60;
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,0x1005);
      g_PlayerDamageContactEntitySceneObject = value;
    }
    CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if ((*(byte *)(value + 0x13c) & 2) != 0) {
      CEntities::ReleaseEntityToFreeList((byte *)entry);
    }
  }
  return;
}

