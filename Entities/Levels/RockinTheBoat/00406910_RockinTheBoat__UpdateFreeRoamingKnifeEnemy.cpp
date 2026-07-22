#include "tarzan_ghidra_types.hpp"

// Address: 0x00406910
// Label: RockinTheBoat::UpdateFreeRoamingKnifeEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::UpdateFreeRoamingKnifeEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  short shortValue;
  int value2;
  undefined4 value7;
  int value3;
  uint value8;
  int value4;
  int value5;
  uint value9;
  int value;
  undefined4 value6;
  int localState [2];
  int localState2;
  
  g_RockinTheBoatKnifeEnemyTargetZ = *(int *)(g_PlayerEntitySceneObjectData + 0x10);
  if (g_RockinTheBoatClampKnifeEnemyTargetZ != '\0') {
    if (g_RockinTheBoatKnifeEnemyTargetZ < 0x2001) {
      if (g_RockinTheBoatKnifeEnemyTargetZ < 0x500) {
        g_RockinTheBoatKnifeEnemyTargetZ = 0x1800;
      }
      else {
        g_RockinTheBoatClampKnifeEnemyTargetZ = '\0';
      }
    }
    else {
      g_RockinTheBoatKnifeEnemyTargetZ = 0x1800;
    }
  }
  value4 = entity->sceneObjects;
  if (value4 == 0) {
    return;
  }
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 == 0) {
    return;
  }
  value7 = *(undefined4 *)(value2 + 0x10);
  ((EntitySceneObject *)value4)->y = 0;
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag == '\0') goto LAB_00406a08;
  switch(*(undefined4 *)(value2 + 0x58)) {
  case 1:
  case 5:
    value6 = 0x3a3;
    break;
  case 2:
  case 6:
    value6 = 0x3b1;
    break;
  case 3:
  case 4:
    value6 = 0x3ac;
    break;
  default:
    goto switchD_004069aa_default;
  }
  PlayAudioById(value6,(int *)&((EntitySceneObject *)value4)->soundPosition,(undefined4 *)&((EntitySceneObject *)value4)->x);
switchD_004069aa_default:
  CEntities::SelectScriptAttachmentSequence(value7,8);
  *(undefined4 *)(value2 + 0xc4) = *(undefined4 *)(value2 + 0xc);
  *(undefined4 *)(value2 + 0xc) = 9;
LAB_00406a08:
  if (*(short *)(entry + 0x3e) < 0) {
    value7 = RandomModulo(6);
    switch(value7) {
    case 1:
      value7 = 0x3cd;
      break;
    case 2:
      value7 = 0x3ce;
      break;
    case 3:
      value7 = 0x3cf;
      break;
    case 4:
      value7 = 0x3d0;
      break;
    case 5:
      value7 = 0x3d1;
      break;
    default:
      value7 = 0x3cc;
    }
    PlayAudioById(value7,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
    CEntities::ProcessEntityDeathAndRelease(entry,2);
    return;
  }
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue == 5) {
    *(undefined2 *)(entry + 0x4a) = 1;
  }
  switch(*(undefined4 *)(value2 + 0xc)) {
  case 8:
    value5 = ((EntitySceneObject *)value4)->x - *(int *)(g_PlayerEntitySceneObjectData + 8);
    value3 = ((EntitySceneObject *)value4)->y - *(int *)(g_PlayerEntitySceneObjectData + 0xc);
    value = ((EntitySceneObject *)value4)->z - *(int *)(g_PlayerEntitySceneObjectData + 0x10);
    if ((shortValue == 3) && (value * value + value3 * value3 + value5 * value5 < 160000)) {
      QueuePlayerDamageEvent(entry,8);
    }
    value8 = GetAngleFromXZVector12Bit(value5,value);
    if (value3 < 500) {
      value3 = SqrtToInt(value * value + value5 * value5);
      if (value3 >> 6 < 0x100) {
        value3 = 0x100 - (value3 >> 6);
        *(int *)(g_PlayerEntitySceneObject + 0x14) =
             *(int *)(g_PlayerEntitySceneObject + 0x14) -
             ((short)(&g_SinCosTable12Bit)[(value8 & 0xfff) - 0x400 & 0xfff] * value3 >> 0xc);
        *(int *)(g_PlayerEntitySceneObject + 0x1c) =
             *(int *)(g_PlayerEntitySceneObject + 0x1c) -
             ((short)(&g_SinCosTable12Bit)[value8 & 0xfff] * value3 >> 0xc);
      }
    }
    value3 = GetAngleFromXZVector12Bit
                      (*(int *)(g_PlayerEntitySceneObject + 0x14) - ((EntitySceneObject *)value4)->x,
                       *(int *)(g_PlayerEntitySceneObject + 0x1c) - ((EntitySceneObject *)value4)->z);
    value3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value4)->yaw,value3 - 0x800U & 0xfff);
    ((EntitySceneObject *)value4)->yaw = ((EntitySceneObject *)value4)->yaw + (short)(value3 >> 2);
    if (shortValue == 1) {
      value = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
               *(int *)(entity->sceneObjects + 0x1c);
      value3 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
              *(int *)(entity->sceneObjects + 0x14);
      if ((value * value + value3 * value3 < 0x24001) &&
         (*(int *)(g_PlayerEntitySceneObjectData + 0xc) < -0xff)) {
        value3 = RandomModulo(3);
        CEntities::SelectScriptAttachmentSequence(value7,*(undefined4 *)(&DAT_004bd780 + value3 * 4));
      }
      else {
        *(undefined2 *)(entry + 0x4a) = 0;
        CEntities::SelectScriptAttachmentSequence(value7,1);
        *(undefined4 *)(value2 + 0xc) = 10;
      }
    }
    resultFlag = RockinTheBoat::PushPointAwayFromShipRail((int *)(&((EntitySceneObject *)value4)->x));
    if ((resultFlag != '\0') &&
       (value8 = *(int *)(g_PlayerEntitySceneObjectData + 8) - ((EntitySceneObject *)value4)->x,
       value9 = (int)value8 >> 0x1f, (int)((value8 ^ value9) - value9) < 0x50)) {
      *(undefined2 *)(entry + 0x4a) = 0;
      *(undefined4 *)(value2 + 0xc) = 0xb;
      CEntities::SelectScriptAttachmentSequence(value7,0);
      return;
    }
    break;
  case 9:
    if (shortValue == 1) {
      *(undefined2 *)(entry + 0x4a) = 0;
      *(int *)(value2 + 0xc) = *(int *)(value2 + 0xc4);
      if (*(int *)(value2 + 0xc4) == 10) {
        CEntities::SelectScriptAttachmentSequence(value7,1);
      }
      if (*(int *)(value2 + 0xc) == 8) {
        CEntities::SelectScriptAttachmentSequence(value7,4);
      }
      if (*(int *)(value2 + 0xc) == 0xb) {
        CEntities::SelectScriptAttachmentSequence(value7,0);
      }
    }
    break;
  case 10:
    value3 = RockinTheBoat::ChooseKnifeEnemyPathTarget(entry,localState);
    if (value3 == 0) {
      value8 = GetAngleFromXZVector12Bit
                        (localState[0] - ((EntitySceneObject *)value4)->x,localState2 - ((EntitySceneObject *)value4)->z);
      value3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value4)->yaw,(value8 & 0xfff) + 0x800)
      ;
      ((EntitySceneObject *)value4)->yaw = ((EntitySceneObject *)value4)->yaw + (short)(value3 >> 3);
      if (*(short *)(entry + 0x4a) == 0) {
        value3 = 0;
      }
      else {
        value3 = *(int *)(entry + 0x4c);
      }
      value = ((EntitySceneObject *)value4)->x -
               ((short)(&g_SinCosTable12Bit)[(int)((EntitySceneObject *)value4)->yaw - 0x400U & 0xfff] * value3
               >> 0xc);
      ((EntitySceneObject *)value4)->x = value;
      value3 = ((EntitySceneObject *)value4)->z -
              ((short)(&g_SinCosTable12Bit)[(int)((EntitySceneObject *)value4)->yaw & 0xfff] * value3 >> 0xc);
      ((EntitySceneObject *)value4)->z = value3;
      value5 = *(int *)(g_PlayerEntitySceneObjectData + 0x10) - value3;
      value = *(int *)(g_PlayerEntitySceneObjectData + 8) - value;
      if (value5 * value5 + value * value < 0x24001) {
        if (((g_RockinTheBoatKnifeEnemyTargetZ - value3) * (g_RockinTheBoatKnifeEnemyTargetZ - value3)
             + value * value < 0x24001) &&
           (-0x100 < *(int *)(g_PlayerEntitySceneObjectData + 0xc))) {
          *(undefined2 *)(entry + 0x4a) = 0;
          *(undefined4 *)(value2 + 0xc) = 8;
          CEntities::SelectScriptAttachmentSequence(value7,4);
        }
        else {
          *(undefined4 *)(value2 + 0xc) = 0xb;
          CEntities::SelectScriptAttachmentSequence(value7,0);
        }
      }
    }
    else {
      *(undefined2 *)(entry + 0x4a) = 0;
      *(undefined4 *)(value2 + 0xc) = 0xb;
      CEntities::SelectScriptAttachmentSequence(value7,0);
    }
    resultFlag = RockinTheBoat::PushPointAwayFromShipRail((int *)(&((EntitySceneObject *)value4)->x));
    if ((resultFlag != '\0') &&
       (value8 = *(int *)(g_PlayerEntitySceneObjectData + 8) - ((EntitySceneObject *)value4)->x,
       value9 = (int)value8 >> 0x1f, (int)((value8 ^ value9) - value9) < 0x30)) {
      *(undefined2 *)(entry + 0x4a) = 0;
      *(undefined4 *)(value2 + 0xc) = 0xb;
      CEntities::SelectScriptAttachmentSequence(value7,0);
      return;
    }
    break;
  case 0xb:
    g_RockinTheBoatClampKnifeEnemyTargetZ = '\x01';
    if ((shortValue == 1) &&
       (value4 = RockinTheBoat::ChooseKnifeEnemyPathTarget(entry,localState), value4 == 0)) {
      *(undefined2 *)(entry + 0x4a) = 0;
      CEntities::SelectScriptAttachmentSequence(value7,1);
      *(undefined4 *)(value2 + 0xc) = 10;
      return;
    }
  }
  return;
}

