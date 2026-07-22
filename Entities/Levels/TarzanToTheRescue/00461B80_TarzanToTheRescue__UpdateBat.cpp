#include "tarzan_ghidra_types.hpp"

// Address: 0x00461B80
// Label: TarzanToTheRescue::UpdateBat
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateBat(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  short *value8;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int value;
  undefined4 value7;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 == 0) goto switchD_00461d00_caseD_3;
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag != '\0') {
    if (*(int *)(value2 + 0x48) == 0) {
      PlayAudioById(0x13a,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
    }
    if (*(short *)(entry + 0x3e) < 0) {
      CEntities::ProcessEntityDeathAndRelease(entry,0);
      return;
    }
  }
  if (*(int *)(value2 + 0xc) != 0) {
    value5 = *(int *)(value2 + 0x10) - *(int *)(entity->sceneObjects + 0x14);
    value3 = *(int *)(value2 + 0x18) - *(int *)(entity->sceneObjects + 0x1c);
    value3 = value3 * value3 + value5 * value5;
    if (*(int *)(value2 + 0x48) == 0) {
      if (0x10c2400 < value3) {
        *(undefined4 *)(value2 + 0xc) = 5;
        *(int *)(value2 + 0x28) =
             ((int)g_LevelEntityInitScratch_Field1388 * *(int *)(value2 + 0x3c) >> 0xc) +
             *(int *)(value2 + 0x10);
        value3 = (int)g_SinCosTable12Bit;
        *(undefined4 *)(value2 + 0x2c) = *(undefined4 *)(value2 + 0x14);
        *(int *)(value2 + 0x30) = (value3 * *(int *)(value2 + 0x3c) >> 0xc) + *(int *)(value2 + 0x18);
      }
    }
    else if (0x861200 < value3) {
      *(undefined4 *)(value2 + 0xc) = 5;
      *(undefined4 *)(value2 + 0x28) = *(undefined4 *)(value2 + 0x10);
      *(undefined4 *)(value2 + 0x2c) = *(undefined4 *)(value2 + 0x14);
      *(undefined4 *)(value2 + 0x30) = *(undefined4 *)(value2 + 0x18);
    }
  }
  if (entity->sceneObjects == 0) goto switchD_00461d00_caseD_3;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue == 0x40) {
    value3 = RandomModulo(4);
    if (value3 == 0) {
      value3 = entity->sceneObjects + 0x14;
      value7 = 0x124;
    }
    else if (value3 == 1) {
      value3 = entity->sceneObjects + 0x14;
      value7 = 0x125;
    }
    else if (value3 == 2) {
      value3 = entity->sceneObjects + 0x14;
      value7 = 0x126;
    }
    else {
      if (value3 != 3) goto LAB_00461cf4;
      value3 = entity->sceneObjects + 0x14;
      value7 = 0x127;
    }
    PlayAudioById(value7,(int *)0,(undefined4 *)value3);
  }
LAB_00461cf4:
  switch(*(undefined4 *)(value2 + 0xc)) {
  case 0:
    value3 = entity->sceneObjects;
    value5 = ((EntitySceneObject *)value3)->x - *(int *)(g_PlayerEntitySceneObject + 0x14);
    value4 = ((EntitySceneObject *)value3)->z - *(int *)(g_PlayerEntitySceneObject + 0x1c);
    if (value4 * value4 + value5 * value5 < 0x400001) {
      *(undefined4 *)(value2 + 0xc) = 1;
    }
    else {
      ((EntitySceneObject *)value3)->x =
           ((int)(&g_SinCosTable12Bit)[*(int *)(value2 + 0x1c) - 0x400U & 0xfff] *
            *(int *)(value2 + 0x3c) >> 0xc) + *(int *)(value2 + 0x10);
      *(int *)(entity->sceneObjects + 0x1c) =
           ((int)(&g_SinCosTable12Bit)[*(uint *)(value2 + 0x1c) & 0xfff] * *(int *)(value2 + 0x3c) >>
           0xc) + *(int *)(value2 + 0x18);
      *(short *)(entity->sceneObjects + 0xa2) = *(short *)(value2 + 0x1c) + -0x400;
      *(uint *)(value2 + 0x1c) = *(int *)(value2 + 0x1c) + 0x20U & 0xfff;
    }
    break;
  case 1:
    value3 = entity->sceneObjects;
    value = ((EntitySceneObject *)value3)->x - *(int *)(g_PlayerEntitySceneObject + 0x14);
    value5 = ((EntitySceneObject *)value3)->z - *(int *)(g_PlayerEntitySceneObject + 0x1c);
    value6 = (((EntitySceneObject *)value3)->y - *(int *)(g_PlayerEntitySceneObject + 0x18)) + 200;
    value3 = SqrtToInt(value * value + value5 * value5);
    value4 = GetAngleFromXZVector12Bit(value6,value3 >> 6);
    value7 = GetAngleFromXZVector12Bit(value,value5);
    value3 = entity->sceneObjects;
    value4 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(value3 + 0xa0),-value4);
    value8 = (short *)(value3 + 0xa0);
    *value8 = *value8 + (short)(value4 >> 3);
    value3 = entity->sceneObjects;
    value4 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value3)->yaw,value7);
    value8 = (short *)(&((EntitySceneObject *)value3)->yaw);
    *value8 = *value8 + (short)(value4 >> 3);
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->x =
         ((EntitySceneObject *)value3)->x -
         ((int)(&g_SinCosTable12Bit)[((EntitySceneObject *)value3)->yaw - 0x400 & 0xfff] *
          *(int *)(value2 + 0x40) >> 0xc);
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->z =
         ((EntitySceneObject *)value3)->z -
         ((int)(&g_SinCosTable12Bit)[((EntitySceneObject *)value3)->yaw & 0xfff] * *(int *)(value2 + 0x40) >>
         0xc);
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->y =
         ((EntitySceneObject *)value3)->y +
         ((int)(&g_SinCosTable12Bit)[*(ushort *)(value3 + 0xa0) - 0x400 & 0xfff] *
          *(int *)(value2 + 0x40) >> 0xc);
    if (value6 * value6 + value * value + value5 * value5 < 90000) {
      *(undefined4 *)(value2 + 0xc) = 2;
      if (*(int *)(value2 + 0x48) == 1) {
        PlayAudioById(0x14d,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
      }
      value7 = RandomModulo(0x1000);
      *(undefined4 *)(value2 + 0x20) = value7;
      value3 = RandomModulo(0x200);
      *(int *)(value2 + 0x24) = -0x80 - value3;
      if (*(int *)(value2 + 0x48) == 0) {
        QueuePlayerDamageEvent(entry,0x2002);
      }
      if (*(int *)(value2 + 0x48) == 1) {
        QueuePlayerDamageEvent(entry,0x2005);
      }
    }
    break;
  case 2:
    value3 = *(int *)(value2 + 0x44);
    *(int *)(value2 + 0x28) =
         ((&g_SinCosTable12Bit)[*(uint *)(value2 + 0x20) - 0x400 & 0xfff] * value3 >> 0xc) +
         *(int *)(g_PlayerEntitySceneObject + 0x14);
    *(int *)(value2 + 0x30) =
         ((&g_SinCosTable12Bit)[*(uint *)(value2 + 0x20) & 0xfff] * value3 >> 0xc) +
         *(int *)(g_PlayerEntitySceneObject + 0x1c);
    value6 = *(int *)(g_PlayerEntitySceneObject + 0x18) +
            ((&g_SinCosTable12Bit)[*(int *)(value2 + 0x24) - 0x400U & 0xfff] * value3 >> 0xc);
    *(int *)(value2 + 0x2c) = value6;
    value3 = entity->sceneObjects;
    value = ((EntitySceneObject *)value3)->x - *(int *)(value2 + 0x28);
    value6 = ((EntitySceneObject *)value3)->y - value6;
    value5 = ((EntitySceneObject *)value3)->z - *(int *)(value2 + 0x30);
    value3 = SqrtToInt(value * value + value5 * value5);
    value4 = GetAngleFromXZVector12Bit(value6,value3 >> 6);
    value7 = GetAngleFromXZVector12Bit(value,value5);
    value3 = entity->sceneObjects;
    value4 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(value3 + 0xa0),-value4);
    value8 = (short *)(value3 + 0xa0);
    *value8 = *value8 + (short)(value4 >> 3);
    value3 = entity->sceneObjects;
    value4 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value3)->yaw,value7);
    value8 = (short *)(&((EntitySceneObject *)value3)->yaw);
    *value8 = *value8 + (short)(value4 >> 3);
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->x =
         ((EntitySceneObject *)value3)->x -
         ((int)(&g_SinCosTable12Bit)[((EntitySceneObject *)value3)->yaw - 0x400 & 0xfff] *
          *(int *)(value2 + 0x40) >> 0xc);
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->z =
         ((EntitySceneObject *)value3)->z -
         ((int)(&g_SinCosTable12Bit)[((EntitySceneObject *)value3)->yaw & 0xfff] * *(int *)(value2 + 0x40) >>
         0xc);
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->y =
         ((EntitySceneObject *)value3)->y +
         ((int)(&g_SinCosTable12Bit)[*(ushort *)(value3 + 0xa0) - 0x400 & 0xfff] *
          *(int *)(value2 + 0x40) >> 0xc);
    if (value6 * value6 + value * value + value5 * value5 < 90000) {
      *(undefined4 *)(value2 + 0xc) = 1;
      return;
    }
    break;
  case 4:
    value8 = (short *)(entity->sceneObjects + 0xa4);
    *value8 = *value8 + 0x100;
    dataCursor = (ushort *)(entity->sceneObjects + 0xa4);
    *dataCursor = *dataCursor & 0xfff;
    if ((*(short *)(entity->sceneObjects + 0xa4) == 0) &&
       (*(undefined4 *)(value2 + 0xc) = 2, *(int *)(value2 + 0x48) == 1)) {
      PlayAudioById(0x14d,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
    }
    break;
  case 5:
    *(int *)(value2 + 0x28) = *(int *)(value2 + 0x10);
    *(undefined4 *)(value2 + 0x2c) = *(undefined4 *)(value2 + 0x14);
    *(undefined4 *)(value2 + 0x30) = *(undefined4 *)(value2 + 0x18);
    value3 = entity->sceneObjects;
    value6 = ((EntitySceneObject *)value3)->x - *(int *)(value2 + 0x28);
    value = ((EntitySceneObject *)value3)->y - *(int *)(value2 + 0x2c);
    value5 = ((EntitySceneObject *)value3)->z - *(int *)(value2 + 0x30);
    value3 = SqrtToInt(value6 * value6 + value5 * value5);
    value4 = GetAngleFromXZVector12Bit(value,value3 >> 6);
    value7 = GetAngleFromXZVector12Bit(value6,value5);
    value3 = entity->sceneObjects;
    value4 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(value3 + 0xa0),-value4);
    value8 = (short *)(value3 + 0xa0);
    *value8 = *value8 + (short)(value4 >> 3);
    value3 = entity->sceneObjects;
    value4 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value3)->yaw,value7);
    value8 = (short *)(&((EntitySceneObject *)value3)->yaw);
    *value8 = *value8 + (short)(value4 >> 3);
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->x =
         ((EntitySceneObject *)value3)->x -
         ((int)(&g_SinCosTable12Bit)[((EntitySceneObject *)value3)->yaw - 0x400 & 0xfff] *
          *(int *)(value2 + 0x40) >> 0xc);
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->z =
         ((EntitySceneObject *)value3)->z -
         ((int)(&g_SinCosTable12Bit)[((EntitySceneObject *)value3)->yaw & 0xfff] * *(int *)(value2 + 0x40) >>
         0xc);
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->y =
         ((EntitySceneObject *)value3)->y +
         ((int)(&g_SinCosTable12Bit)[*(ushort *)(value3 + 0xa0) - 0x400 & 0xfff] *
          *(int *)(value2 + 0x40) >> 0xc);
    if (value * value + value6 * value6 + value5 * value5 <=
        *(int *)(value2 + 0x3c) * *(int *)(value2 + 0x3c)) {
      *(undefined4 *)(value2 + 0x20) = 0;
      *(undefined4 *)(value2 + 0x1c) = 0;
      *(undefined4 *)(value2 + 0xc) = 0;
      return;
    }
  }
switchD_00461d00_caseD_3:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

