#include "tarzan_ghidra_types.hpp"

// Address: 0x004034A0
// Label: TheBaboonChase::UpdateThrowingBaboon
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::UpdateThrowingBaboon(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value5;
  char resultFlag;
  short shortValue;
  int value;
  uint value4;
  int value2;
  int value3;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value != 0) {
    if (*(int *)(value + 0xc) == 0) {
      CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      value4 = GetAngleFromXZVector12Bit
                        (*(int *)(entity->sceneObjects + 0x14) -
                         *(int *)(g_PlayerEntitySceneObject + 0x14),
                         *(int *)(entity->sceneObjects + 0x1c) -
                         *(int *)(g_PlayerEntitySceneObject + 0x1c));
      value3 = entity->sceneObjects;
      value2 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value3)->yaw,value4 & 0xfff);
      value5 = (short *)(&((EntitySceneObject *)value3)->yaw);
      *value5 = *value5 + (short)(value2 >> 1);
      value3 = CEntities::IsEntityVectorMostlyPositiveZ(entry,g_PlayerEntity);
      if (value3 != 0) {
        *(undefined4 *)(value + 0xc) = 2;
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value + 0x18),2);
      }
    }
    else if (*(int *)(value + 0xc) == 2) {
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
      value4 = GetAngleFromXZVector12Bit
                        (*(int *)(entity->sceneObjects + 0x14) -
                         *(int *)(g_PlayerEntitySceneObject + 0x14),
                         *(int *)(entity->sceneObjects + 0x1c) -
                         *(int *)(g_PlayerEntitySceneObject + 0x1c));
      value3 = entity->sceneObjects;
      value2 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value3)->yaw,value4 & 0xfff);
      value5 = (short *)(&((EntitySceneObject *)value3)->yaw);
      *value5 = *value5 + (short)(value2 >> 1);
      if (shortValue == 3) {
        value = GetSceneAttachmentWorldPositionByMask
                          (entity->sceneObjects,0x100,&localState3);
        if (value != 0) {
          value = CEntities::SpawnEntityByTypeAtPosition(localState3,localState2,localState,0x91,0x11);
          if (value != 0) {
            value = CEntities::FindEntityAttachmentByFlags(value,0x10000000);
            if (value != 0) {
              *(undefined4 *)(value + 0x74) = 0x88;
            }
          }
        }
      }
      else if (shortValue == 1) {
        *(undefined4 *)(value + 0xc) = 6;
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

