#include "tarzan_ghidra_types.hpp"

// Address: 0x00475A80
// Label: KerchakChase::UpdateRunningAnimal
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::UpdateRunningAnimal(int entry)

{
  Entity *entity = (Entity *)entry;
  byte *value4;
  short *value5;
  char resultFlag;
  int value;
  int value2;
  int value3;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    value2 = *(int *)(value + 0xc);
    if (value2 == 0) {
      value2 = CEntities::IsEntityVectorMostlyPositiveZ(entry,g_PlayerEntity);
      if (value2 != 0) {
        *(undefined4 *)(value + 0xc) = 1;
        value4 = (byte *)(entity->sceneObjects + 0xf);
        *value4 = *value4 | 0x80;
      }
    }
    else if (value2 == 1) {
      CEntities::MoveEntityWithCollisionAndEaseSurfaceAngles(entry,0x5a);
      value2 = entity->sceneObjects;
      value3 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value2);
      ((EntitySceneObject *)value2)->y = ((EntitySceneObject *)value2)->y + value3;
      value2 = ((EntitySceneObject *)value)->x;
      ((EntitySceneObject *)value)->x = value2 + -1;
      if (value2 == 0) {
        ((EntitySceneObject *)value)->x = 0xc;
      }
      value2 = *(int *)(entity->sceneObjects + 0x114);
      if ((value2 != 0) && (((EntitySceneObject *)value2)->x == 1)) {
        *(undefined4 *)(value + 0xc) = 2;
      }
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    }
    else if (value2 == 2) {
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      CEntities::MoveEntityWithCollisionAndEaseSurfaceAngles(entry,0x5a);
      value = entity->sceneObjects;
      value2 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value);
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + value2;
      value5 = (short *)(entity->sceneObjects + 0xa4);
      *value5 = *value5 + -0x14;
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

