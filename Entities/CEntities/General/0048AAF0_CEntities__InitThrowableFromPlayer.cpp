#include "tarzan_ghidra_types.hpp"

// Address: 0x0048AAF0
// Label: CEntities::InitThrowableFromPlayer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CEntities::InitThrowableFromPlayer(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  undefined1 value4;
  short shortValue;
  char resultFlag;
  ushort value5;
  int value2;
  int value3;
  uint value6;
  uint value7;
  int value;
  
  value = entity->sceneObjects;
  if (value == 0) goto LAB_0048aeb9;
  intCursor = (int *)(&((EntitySceneObject *)value)->x);
  ((EntitySceneObject *)value)->worldObject = g_WorldEntitySceneObjectArrayBase + 0x3a8;
  GetSceneAttachmentWorldPositionByMask(g_PlayerEntitySceneObject,0x100,intCursor);
  *(undefined2 *)(value + 0x140) = 0;
  *(uint *)(value + 0x13c) = *(uint *)(value + 0x13c) | 1;
  ((EntitySceneObject *)value)->roll = 1;
  value4 = *(undefined1 *)(g_PlayerEntitySceneObject + 0x75);
  *(byte *)(value + 0xe) = *(byte *)(value + 0xe) | 0x10;
  *(undefined1 *)(value + 0x75) = value4;
  (&g_PowerFruitAmmoType0)[g_SelectedThrowablePowerFruitType] =
       (&g_PowerFruitAmmoType0)[g_SelectedThrowablePowerFruitType] + -1;
  *(undefined1 *)(value + 0x74) = 0x7f;
  value2 = CEntities::CreateRuntimeMotionStateAttachment(entry);
  if (value2 != 0) {
    if (g_PlayerCurrentCollisionMode == 1) {
      *(undefined2 *)(entry + 0x46) = 0x10;
      *(undefined4 *)(entry + 0x30) = *(undefined4 *)(g_EntityTypeCallbackTable + 0x84);
      value3 = CEntities::FindNearestScriptedEnemyInPlayerFacingCone();
      if (value3 == 0) {
        *(int *)(entry + 0x4c) = (int)*(short *)(g_PlayerEntitySceneObject + 0xa2);
        *(undefined4 *)(value2 + 0x20) = 0;
      }
      else {
        shortValue = *(short *)(g_PlayerEntitySceneObject + 0xa2);
        value3 = GetAngleFromXZVector12Bit
                          (*(int *)(value3 + 0x14) - *intCursor,
                           *(int *)(value3 + 0x1c) - ((EntitySceneObject *)value)->z);
        value6 = value3 - 0x800U & 0xfff;
        if ((((shortValue + -0x180) * 0x100000 >> 0x14 & 0xfffU) < value6) &&
           (value6 < ((shortValue + 0x180) * 0x100000 >> 0x14 & 0xfffU))) {
          *(uint *)(entry + 0x4c) = value6;
          *(undefined4 *)(value2 + 0x20) = 0;
        }
        else {
          *(int *)(entry + 0x4c) = (int)*(short *)(g_PlayerEntitySceneObject + 0xa2);
          *(undefined4 *)(value2 + 0x20) = 0;
        }
      }
    }
    else {
      value3 = CEntities::FindNearestForwardTargetEntityForThrow(intCursor);
      if (value3 != 0) {
        *(int *)(entry + 0x50) = value3;
      }
      value6 = (int)*(uint *)(g_PlayerEntitySceneObject + 0x58) >> 0x1f;
      if ((int)((*(uint *)(g_PlayerEntitySceneObject + 0x58) ^ value6) - value6) < 0x41) {
        if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
          value5 = 0x400 - *(short *)(g_PlayerEntitySceneObject + 0x130);
        }
        else {
          value5 = *(short *)(g_PlayerEntitySceneObject + 0x130) - 0x400;
        }
        *(int *)(value2 + 0x20) =
             (short)(&g_SinCosTable12Bit)[(value5 & 0xfff) - 0x400 & 0xfff] * 0x50 >> 0xc;
      }
      else if ((value3 != 0) && (value3 = *(int *)(value3 + 0x38), value3 != 0)) {
        value6 = *(int *)(g_PlayerEntitySceneObjectData + 8) - *(int *)(value3 + 0x14);
        value7 = (int)value6 >> 0x1f;
        value3 = GetAngleFromXZVector12Bit
                          ((value6 ^ value7) - value7,
                           *(int *)(g_PlayerEntitySceneObjectData + 0xc) - *(int *)(value3 + 0x18));
        *(int *)(value2 + 0x20) =
             (short)(&g_SinCosTable12Bit)[(value3 - 0x400U & 0xfff) - 0x400 & 0xfff] * 0x50 >> 0xc;
      }
    }
  }
  if (g_SelectedThrowablePowerFruitType == 1) {
    *(undefined2 *)(value + 0xc) = 0x202b;
    *(undefined2 *)(entry + 0x4a) = 8;
    if (value2 != 0) {
      if (g_PlayerThrowLowArcSelected == '\0') {
        *(undefined4 *)(value2 + 0x1c) = 0;
        *(undefined4 *)(value2 + 0x10) = 0x60;
        *(undefined4 *)(value2 + 0x14) = 0;
        *(undefined4 *)(value2 + 0x18) = 0;
        *(undefined4 *)(value2 + 0x20) = 0x60;
        goto LAB_0048ae9f;
      }
      *(undefined4 *)(value2 + 0x10) = 0x10;
      *(undefined4 *)(value2 + 0x1c) = 0;
      *(undefined4 *)(value2 + 0x14) = 0;
      *(undefined4 *)(value2 + 0x18) = 0;
      *(undefined4 *)(value2 + 0x20) = 0xffffffa0;
      *(undefined4 *)(value2 + 0x2c) = 0x80;
      *(undefined4 *)(value2 + 0x28) = 8;
    }
  }
  else if (g_SelectedThrowablePowerFruitType == 2) {
    *(undefined2 *)(value + 0xc) = 0x202c;
    *(undefined2 *)(entry + 0x4a) = 4;
    resultFlag = RandomModulo(4);
    *(char *)(value + 0x74) = resultFlag + '\x03';
    if (value2 != 0) {
      *(undefined4 *)(value2 + 0x10) = 0x60;
      *(undefined4 *)(value2 + 0x1c) = 0;
      *(undefined4 *)(value2 + 0x14) = 0;
      *(undefined4 *)(value2 + 0x18) = 0;
LAB_0048ae9f:
      *(undefined4 *)(value2 + 0x2c) = 0x80;
      *(undefined4 *)(value2 + 0x28) = 0;
    }
  }
  else if (g_SelectedThrowablePowerFruitType == 3) {
    *(undefined2 *)(value + 0xc) = 0x2026;
    value3 = CreateEntityEntitySceneObject((uint *)entry,0x16);
    if (value3 != 0) {
      *(int *)(value3 + 0x14) = *intCursor;
      *(undefined4 *)(value3 + 0x18) = ((EntitySceneObject *)value)->y;
      *(undefined4 *)(value3 + 0x1c) = ((EntitySceneObject *)value)->z;
      value = g_WorldEntitySceneObjectArrayBase + 0x3a8;
      *(ushort *)(value3 + 0xe) = *(ushort *)(value3 + 0xe) | 0x1421;
      *(int *)(value3 + 0x10) = value;
      *(undefined2 *)(value3 + 0xc) = 0x2032;
      *(undefined4 *)(value3 + 0x30) = 0x800;
    }
    *(undefined2 *)(entry + 0x4a) = 3;
    if (value2 != 0) {
      *(undefined4 *)(value2 + 0x10) = 0x60;
      *(undefined4 *)(value2 + 0x1c) = 0;
      *(undefined4 *)(value2 + 0x14) = 0;
      *(undefined4 *)(value2 + 0x18) = 0;
      *(int *)(value2 + 0x20) = *(int *)(value2 + 0x20) + -8;
      *(undefined4 *)(value2 + 0x2c) = 0x80;
      *(undefined4 *)(value2 + 0x28) = 2;
    }
  }
  else {
    *(undefined2 *)(value + 0xc) = 0x202e;
    *(undefined2 *)(entry + 0x4a) = 1;
    if (value2 != 0) {
      *(undefined4 *)(value2 + 0x1c) = 0;
      *(undefined4 *)(value2 + 0x14) = 0;
      *(undefined4 *)(value2 + 0x18) = 0;
      *(undefined4 *)(value2 + 0x10) = 0x60;
      *(int *)(value2 + 0x20) = *(int *)(value2 + 0x20) + -8;
      *(undefined4 *)(value2 + 0x2c) = 0x80;
      *(undefined4 *)(value2 + 0x28) = 3;
    }
  }
  CEntities::LinkEntityIntoProcessingList(&g_ActiveThrowableEntityList,entry);
LAB_0048aeb9:
  *(undefined2 *)(entry + 0x48) = 5;
  if ((*(byte *)(entry + 0x44) & 1) == 0) {
    g_PlayerHeldThrowableEntity = entry;
    return;
  }
  CEntities::ReleaseEntityToFreeList((byte *)entry);
  return;
}

