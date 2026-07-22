#include "tarzan_ghidra_types.hpp"

// Address: 0x00458A30
// Label: Stampede::UpdateMonkey
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void Stampede::UpdateMonkey(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value5;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  uint value7;
  int value3;
  int value4;
  undefined4 value8;
  undefined4 value6;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value == 0) goto LAB_00458c7e;
  value2 = entity->sceneObjects;
  value4 = ((EntitySceneObject *)value2)->x - *(int *)(g_PlayerEntitySceneObject + 0x14);
  value3 = ((EntitySceneObject *)value2)->z - *(int *)(g_PlayerEntitySceneObject + 0x1c);
  value2 = ((EntitySceneObject *)value2)->y - *(int *)(g_PlayerEntitySceneObject + 0x18);
  value7 = GetAngleFromXZVector12Bit(value4,value3);
  value2 = SqrtToInt(value2 * value2 + value3 * value3 + value4 * value4);
  if (value2 >> 6 < 0x100) {
    value2 = 0x100 - (value2 >> 6);
    *(int *)(g_PlayerEntitySceneObject + 0x14) =
         *(int *)(g_PlayerEntitySceneObject + 0x14) -
         ((short)(&g_SinCosTable12Bit)[(value7 & 0xfff) - 0x400 & 0xfff] * value2 >> 0xc);
    *(int *)(g_PlayerEntitySceneObject + 0x1c) =
         *(int *)(g_PlayerEntitySceneObject + 0x1c) -
         ((short)(&g_SinCosTable12Bit)[value7 & 0xfff] * value2 >> 0xc);
  }
  value2 = *(int *)(value + 0xc);
  if (value2 == 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value7 = GetAngleFromXZVector12Bit
                      (*(int *)(entity->sceneObjects + 0x14) -
                       *(int *)(g_PlayerEntitySceneObject + 0x14),
                       *(int *)(entity->sceneObjects + 0x1c) -
                       *(int *)(g_PlayerEntitySceneObject + 0x1c));
    value2 = entity->sceneObjects;
    value3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value2)->yaw,value7 & 0xfff);
    value5 = (short *)(&((EntitySceneObject *)value2)->yaw);
    *value5 = *value5 + (short)(value3 >> 1);
    value2 = CEntities::IsEntityVectorMostlyPositiveZ(entry,g_PlayerEntity);
    if (value2 == 0) goto LAB_00458c7e;
    value8 = ((EntitySceneObject *)value)->worldObject;
    value6 = 0;
    *(undefined4 *)(value + 0xc) = 1;
  }
  else {
    if (value2 != 1) {
      if (value2 == 2) {
        CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
        value7 = GetAngleFromXZVector12Bit
                          (*(int *)(entity->sceneObjects + 0x14) -
                           *(int *)(g_PlayerEntitySceneObject + 0x14),
                           *(int *)(entity->sceneObjects + 0x1c) -
                           *(int *)(g_PlayerEntitySceneObject + 0x1c));
        value = entity->sceneObjects;
        value2 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value)->yaw,value7 & 0xfff);
        value5 = (short *)(&((EntitySceneObject *)value)->yaw);
        *value5 = *value5 + (short)(value2 >> 1);
      }
      goto LAB_00458c7e;
    }
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value7 = GetAngleFromXZVector12Bit
                      (*(int *)(entity->sceneObjects + 0x14) -
                       *(int *)(g_PlayerEntitySceneObject + 0x14),
                       *(int *)(entity->sceneObjects + 0x1c) -
                       *(int *)(g_PlayerEntitySceneObject + 0x1c));
    value2 = entity->sceneObjects;
    value3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value2)->yaw,value7 & 0xfff);
    value5 = (short *)(&((EntitySceneObject *)value2)->yaw);
    *value5 = *value5 + (short)(value3 >> 1);
    if (shortValue == 3) {
      value = GetSceneAttachmentWorldPositionByMask(entity->sceneObjects,0x100,&localState3)
      ;
      if (value != 0) {
        CEntities::SpawnEntityByTypeAtPosition(localState3,localState2,localState,0x91,0x11);
      }
      goto LAB_00458c7e;
    }
    if (shortValue != 1) goto LAB_00458c7e;
    value8 = ((EntitySceneObject *)value)->worldObject;
    *(undefined4 *)(value + 0xc) = 2;
    value6 = 1;
  }
  CEntities::SelectScriptAttachmentSequence(value8,value6);
LAB_00458c7e:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

