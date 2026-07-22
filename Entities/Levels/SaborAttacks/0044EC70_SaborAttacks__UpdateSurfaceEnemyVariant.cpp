#include "tarzan_ghidra_types.hpp"

// Address: 0x0044EC70
// Label: SaborAttacks::UpdateSurfaceEnemyVariant
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SaborAttacks::UpdateSurfaceEnemyVariant(int entry)

{
  Entity *entity = (Entity *)entry;
  short shortValue;
  int value;
  int value2;
  char resultFlag;
  char resultFlag2;
  short shortValue2;
  int value3;
  int value4;
  
  value = entity->sceneObjects;
  if ((value != 0) &&
     (value3 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value3 != 0)) {
    shortValue2 = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    shortValue = *(short *)(value3 + 0x18);
    CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value,0x3c,0);
    resultFlag = CEntities::HandleAnimalScriptEvent(entry,value,(int)shortValue2);
    value2 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value)->surfacePathIndex * 4) + 8 +
                     ((EntitySceneObject *)value)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
    value4 = ((EntitySceneObject *)value)->surfaceIndex;
    resultFlag2 = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag2 != '\0') {
      g_PlayerDamageContactEntitySceneObject = value;
      QueuePlayerDamageEvent(entry,0x1006);
    }
    CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    switch(*(undefined2 *)(entry + 0x48)) {
    case 0:
      CEntities::SelectScriptAttachmentSequence(value3,0);
      *(undefined2 *)(entry + 0x48) = 1;
      break;
    case 1:
      if (resultFlag != '\0') {
        if (*(char *)(value + 0x75) == '\0') {
          value4 = value2 - value4;
        }
        if (value4 < 0x578) {
          CEntities::SelectScriptAttachmentSequence(value3,2);
          *(undefined2 *)(entry + 0x48) = 2;
        }
      }
      break;
    case 2:
      if (shortValue == 0) {
        CEntities::SelectScriptAttachmentSequence(value3,5);
        *(undefined2 *)(entry + 0x48) = 3;
      }
      break;
    case 3:
      if (shortValue == 0) {
        *(byte *)(value + 0x75) = ~*(byte *)(value + 0x75);
        CEntities::RefreshAnimalFacingAndCollisionAfterTurn(entry,value);
        *(undefined2 *)(entry + 0x48) = 0;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

