#include "tarzan_ghidra_types.hpp"

// Address: 0x004240B0
// Label: ElephantHairDare::UpdateYoungTantor
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::UpdateYoungTantor(int entry)

{
  Entity *entity = (Entity *)entry;
  byte flagByte;
  int value;
  int value2;
  int value3;
  char resultFlag;
  short shortValue;
  int value4;
  
  value = entity->sceneObjects;
  if ((value != 0) &&
     (value4 = CEntities::FindEntityAttachmentByFlags(entry,0x400), value4 != 0)) {
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    CEntities::MoveAnimalFromRuntimeFlagsAndCheckCollision(entry,value,0x14,10);
    CEntities::HandleAnimalScriptEvent(entry,value,(int)shortValue);
    value2 = ((EntitySceneObject *)value)->surfaceIndex;
    value3 = *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + ((EntitySceneObject *)value)->surfacePathIndex * 4) + 8 +
                     ((EntitySceneObject *)value)->surfacePathIndex * 4 + g_CollisionSurfaceTable);
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      g_PlayerDamageContactEntitySceneObject = value;
    }
    resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
    if (resultFlag != '\0') {
      CEntities::IsTargetEntityInFront(entry,g_PlayerEntity);
    }
    shortValue = *(short *)(entry + 0x48);
    if (shortValue == 0) {
      *(byte *)(entry + 0x4a) = *(byte *)(entry + 0x4a) | 1;
      *(undefined2 *)(entry + 0x48) = 3;
      CEntities::SelectScriptAttachmentSequence(value4,2);
    }
    else {
      if (shortValue == 2) {
        flagByte = *(byte *)(value + 0x75);
      }
      else {
        if (shortValue != 3) goto LAB_0042419f;
        flagByte = *(byte *)(value + 0x75);
      }
      if (flagByte == 0) {
        if (value3 - value2 < 0x12d) {
          *(undefined1 *)(value + 0x75) = 0xff;
        }
      }
      else if (value2 < 0x12d) {
        *(byte *)(value + 0x75) = ~flagByte;
      }
    }
  }
LAB_0042419f:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

