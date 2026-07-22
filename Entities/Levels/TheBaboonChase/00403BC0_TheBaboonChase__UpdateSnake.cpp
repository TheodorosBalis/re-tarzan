#include "tarzan_ghidra_types.hpp"

// Address: 0x00403BC0
// Label: TheBaboonChase::UpdateSnake
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TheBaboonChase::UpdateSnake(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value9;
  char resultFlag;
  short shortValue;
  int value;
  uint value8;
  int value2;
  int value3;
  int value4;
  int value5;
  undefined4 value6;
  undefined4 value7;
  int localState2 [2];
  int localState;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value == 0) goto LAB_00403d57;
  if (*(int *)(value + 0xc) == 0) {
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value4 = *(int *)(entity->sceneObjects + 0x1c) - *(int *)(g_PlayerEntitySceneObject + 0x1c);
    value5 = *(int *)(entity->sceneObjects + 0x14) - *(int *)(g_PlayerEntitySceneObject + 0x14);
    value8 = GetAngleFromXZVector12Bit(value5,value4);
    value3 = entity->sceneObjects;
    value2 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value3)->yaw,(value8 & 0xfff) + 0x800);
    value9 = (short *)(&((EntitySceneObject *)value3)->yaw);
    *value9 = *value9 + (short)(value2 >> 1);
    value2 = value4 * value4 + value5 * value5;
    value3 = CEntities::IsEntityVectorMostlyPositiveZ(entry,g_PlayerEntity);
    if (((value3 == 0) || (0x3ffff < value2)) || (value2 < 1)) goto LAB_00403d57;
    value7 = 1;
    value6 = *(undefined4 *)(value + 0x10);
    *(undefined4 *)(value + 0xc) = 1;
  }
  else {
    if (*(int *)(value + 0xc) != 1) goto LAB_00403d57;
    value8 = GetAngleFromXZVector12Bit
                      (*(int *)(entity->sceneObjects + 0x14) -
                       *(int *)(g_PlayerEntitySceneObject + 0x14),
                       *(int *)(entity->sceneObjects + 0x1c) -
                       *(int *)(g_PlayerEntitySceneObject + 0x1c));
    value3 = entity->sceneObjects;
    value2 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value3)->yaw,(value8 & 0xfff) + 0x800);
    value9 = (short *)(&((EntitySceneObject *)value3)->yaw);
    *value9 = *value9 + (short)(value2 >> 1);
    value3 = GetSceneAttachmentWorldPositionByMask(entity->sceneObjects,0x200,localState2);
    if (((value3 != 0) &&
        (localState2[0] = localState2[0] - *(int *)(g_PlayerEntitySceneObject + 0x14),
        localState = localState - *(int *)(g_PlayerEntitySceneObject + 0x1c),
        value3 = localState * localState + localState2[0] * localState2[0], value3 < 40000)) && (0 < value3)) {
      g_PlayerFacingCurrentCollisionSurface = 1;
      g_JaneDamageReactionType = 3;
      QueuePlayerDamageEvent(entry,7);
    }
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (shortValue != 1) goto LAB_00403d57;
    value6 = *(undefined4 *)(value + 0x10);
    value7 = 0;
    *(undefined4 *)(value + 0xc) = 0;
  }
  CEntities::SelectScriptAttachmentSequence(value6,value7);
LAB_00403d57:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

