#include "tarzan_ghidra_types.hpp"

// Address: 0x00407130
// Label: RockinTheBoat::UpdateDeckKnifeEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::UpdateDeckKnifeEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  int value;
  char resultFlag;
  short shortValue;
  uint value7;
  int value5;
  undefined4 value8;
  uint value9;
  uint value10;
  uint value11;
  int value2;
  int value3;
  int value4;
  undefined4 value6;
  bool localState;
  uint localState3;
  int localState2;
  
  value = entity->sceneObjects;
  if (value == 0) {
    return;
  }
  if (*(short *)(entry + 0x4a) == 0) {
    if (((*(int *)(((EntitySceneObject *)value)->worldObject + 0xc) != 0) &&
        (*(int *)(g_PlayerEntitySceneObject + 0x108) == 1)) &&
       (value5 = ((EntitySceneObject *)value)->x - *(int *)(g_PlayerEntitySceneObjectData + 8),
       value2 = ((EntitySceneObject *)value)->y - *(int *)(g_PlayerEntitySceneObjectData + 0xc),
       value3 = ((EntitySceneObject *)value)->z - *(int *)(g_PlayerEntitySceneObjectData + 0x10),
       0x700000 < value2 * value2 + value3 * value3 + value5 * value5)) {
      *(undefined2 *)(entry + 0x4a) = 1;
      *(byte *)(value + 0xf) = *(byte *)(value + 0xf) | 0x80;
    }
    goto LAB_00407886;
  }
  value5 = ((EntitySceneObject *)value)->surfaceIndex;
  localState2 = 0xdac;
  localState = true;
  if (*(int *)(g_PlayerEntitySceneObject + 0x108) == 1) {
    localState = *(uint *)(g_PlayerEntitySceneObject + 0x110) ==
                (g_RockinTheBoatDeckSurfaceA & 0xffff);
    if (localState) {
      localState2 = *(int *)(g_PlayerEntitySceneObject + 0x10c);
    }
    localState = !localState;
    if (*(uint *)(g_PlayerEntitySceneObject + 0x110) == (g_RockinTheBoatDeckSurfaceB & 0xffff)) {
      localState = false;
      localState2 = *(int *)(g_PlayerEntitySceneObject + 0x10c) +
                 (g_RockinTheBoatDeckPathOffsetA & 0xffff);
    }
    if (*(uint *)(g_PlayerEntitySceneObject + 0x110) == (uint)*( undefined2 *)((int)&g_RockinTheBoatDeckSurfaceB + 2)) {
      localState = false;
      localState2 = *(int *)(g_PlayerEntitySceneObject + 0x10c) + (uint)g_RockinTheBoatDeckPathOffsetB
                 + (g_RockinTheBoatDeckPathOffsetA & 0xffff);
    }
  }
  value2 = value5;
  if (((EntitySceneObject *)value)->surfacePathIndex == (g_RockinTheBoatDeckSurfaceB & 0xffff)) {
    value2 = (g_RockinTheBoatDeckPathOffsetA & 0xffff) + value5;
  }
  if (((EntitySceneObject *)value)->surfacePathIndex == (uint)*( undefined2 *)((int)&g_RockinTheBoatDeckSurfaceB + 2)) {
    value2 = (g_RockinTheBoatDeckPathOffsetA & 0xffff) +
             value5 + (uint)g_RockinTheBoatDeckPathOffsetB;
  }
  value7 = value2 - localState2;
  if ((int)value7 < 0) {
    *(undefined1 *)(value + 0x75) = 0;
  }
  else {
    *(undefined1 *)(value + 0x75) = 0xff;
  }
  localState3 = 99999;
  for (value5 = g_ScriptedEnemyEntityListHead; value5 != 0; value5 = *(int *)(value5 + 0x20)) {
    if (((value5 != entry) && (*(short *)(value5 + 0x46) == 0x151)) &&
       (*(short *)(value5 + 0x4a) != 0)) {
      value5 = *(int *)(value5 + 0x38);
      if (value5 != 0) {
        value4 = ((EntitySceneObject *)value)->x - *(int *)(value5 + 0x14);
        value3 = ((EntitySceneObject *)value)->z - *(int *)(value5 + 0x1c);
        value5 = SqrtToInt(value3 * value3 + value4 * value4);
        localState3 = value5 >> 6;
        value8 = GetAngleFromXZVector12Bit(value4,value3);
        value5 = GetWrappedAngleDistance12Bit(value8,(int)*(short *)(value + 0x132));
        if (0x400 < value5) {
          localState3 = ~localState3 + 1;
        }
        if (*(char *)(value + 0x75) != '\0') {
          localState3 = ~localState3 + 1;
        }
      }
      break;
    }
  }
  value5 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value5 == 0) goto LAB_00407886;
  value8 = *(undefined4 *)(value5 + 0x10);
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag != '\0') {
    switch(*(undefined4 *)(value5 + 0x58)) {
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
      goto switchD_0040735f_default;
    }
    PlayAudioById(value6,(int *)&((EntitySceneObject *)value)->soundPosition,(undefined4 *)&((EntitySceneObject *)value)->x);
switchD_0040735f_default:
    CEntities::SelectScriptAttachmentSequence(value8,8);
    *(undefined4 *)(value5 + 0xc4) = *(undefined4 *)(value5 + 0xc);
    *(undefined4 *)(value5 + 0xc) = 9;
  }
  if (*(short *)(entry + 0x3e) < 0) {
    CEntities::ProcessEntityDeath(value,2);
    value8 = RandomModulo(6);
    switch(value8) {
    case 1:
      PlayAudioById(0x3cd,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    case 2:
      PlayAudioById(0x3ce,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    case 3:
      PlayAudioById(0x3cf,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    case 4:
      PlayAudioById(0x3d0,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    case 5:
      PlayAudioById(0x3d1,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    default:
      PlayAudioById(0x3cc,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    }
  }
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (shortValue == 5) {
    *(undefined2 *)(entry + 0x48) = 1;
  }
  if (3 < *(int *)(value5 + 0xc) - 8U) goto LAB_00407886;
  value10 = (int)value7 >> 0x1f;
  switch(*(int *)(value5 + 0xc)) {
  case 8:
    if ((localState) || (*(byte *)(value + 0x75) = ((-1 < (int)value7) - 1U & 1) - 1, shortValue != 3)) {
      if (shortValue == 1) {
        if (localState2 < 0) {
          *(undefined2 *)(entry + 0x48) = 0;
          CEntities::SelectScriptAttachmentSequence(value8,0);
          *(undefined4 *)(value5 + 0xc) = 0xb;
        }
        else if ((int)((value7 ^ value10) - value10) < 0x181) {
          value5 = RandomModulo(3);
          CEntities::SelectScriptAttachmentSequence
                    (value8,*(undefined4 *)(&DAT_004bd780 + value5 * 4));
        }
        else {
          *(undefined2 *)(entry + 0x48) = 0;
          CEntities::SelectScriptAttachmentSequence(value8,0);
          *(undefined4 *)(value5 + 0xc) = 0xb;
        }
      }
    }
    else {
      value9 = *(int *)(g_PlayerEntitySceneObjectData + 0xc) - ((EntitySceneObject *)value)->y;
      value11 = (int)value9 >> 0x1f;
      if (((int)((value9 ^ value11) - value11) < 0x100) && ((int)((value7 ^ value10) - value10) < 400)) {
        QueuePlayerDamageEvent(entry,0x2008);
      }
    }
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,0x2008);
      g_PlayerDamageContactEntitySceneObject = value;
    }
    goto LAB_00407886;
  case 9:
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,0x2008);
      g_PlayerDamageContactEntitySceneObject = value;
    }
    if (shortValue == 1) {
      *(int *)(value5 + 0xc) = *(int *)(value5 + 0xc4);
      if (*(int *)(value5 + 0xc4) == 10) {
        CEntities::SelectScriptAttachmentSequence(value8,1);
      }
      if (*(int *)(value5 + 0xc) == 8) {
        CEntities::SelectScriptAttachmentSequence(value8,4);
      }
      if (*(int *)(value5 + 0xc) == 0xb) {
        CEntities::SelectScriptAttachmentSequence(value8,0);
      }
    }
    resultFlag = CEntities::CheckPlayerDamageContact(value);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(entry,0x2008);
      g_PlayerDamageContactEntitySceneObject = value;
    }
    goto LAB_00407886;
  case 10:
    if (*(short *)(entry + 0x48) == 0) {
      value6 = 0;
    }
    else {
      value6 = *(undefined4 *)(entry + 0x50);
    }
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,value6);
    value3 = ((EntitySceneObject *)value)->y + *(int *)(value + 0x58);
    ((EntitySceneObject *)value)->y = value3;
    value7 = ((EntitySceneObject *)value)->surfacePathIndex;
    if (value7 == (g_RockinTheBoatDeckSurfaceA & 0xffff)) {
      value2 = ((EntitySceneObject *)value)->surfaceIndex;
    }
    if (value7 == (g_RockinTheBoatDeckSurfaceB & 0xffff)) {
      value2 = (g_RockinTheBoatDeckPathOffsetA & 0xffff) + ((EntitySceneObject *)value)->surfaceIndex;
    }
    if (value7 == g_RockinTheBoatDeckSurfaceB >> 0x10) {
      value2 = (uint)g_RockinTheBoatDeckPathOffsetB + (g_RockinTheBoatDeckPathOffsetA & 0xffff) +
               ((EntitySceneObject *)value)->surfaceIndex;
    }
    value7 = value2 - localState2;
    *(byte *)(value + 0x75) = ((-1 < (int)value7) - 1U & 1) - 1;
    if (((int)((value7 ^ (int)value7 >> 0x1f) - ((int)value7 >> 0x1f)) < 0x181) &&
       (value7 = *(int *)(g_PlayerEntitySceneObjectData + 0xc) - value3, value10 = (int)value7 >> 0x1f,
       (int)((value7 ^ value10) - value10) < 0x100)) {
      *(undefined2 *)(entry + 0x48) = 0;
      *(undefined4 *)(value5 + 0xc) = 8;
      CEntities::SelectScriptAttachmentSequence(value8,4);
    }
    if (((int)localState3 < 0) && (-0x1c2 < (int)localState3)) {
      *(undefined2 *)(entry + 0x48) = 0;
      CEntities::SelectScriptAttachmentSequence(value8,0);
      *(undefined4 *)(value5 + 0xc) = 0xb;
    }
    break;
  case 0xb:
    if (((shortValue == 1) && ((-1 < (int)localState3 || ((int)localState3 < -0x1c1)))) &&
       (0x180 < (int)((value7 ^ value10) - value10))) {
      CEntities::SelectScriptAttachmentSequence(value8,1);
      *(undefined4 *)(value5 + 0xc) = 10;
    }
  }
  resultFlag = CEntities::CheckPlayerDamageContact(value);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent(entry,0x2008);
    g_PlayerDamageContactEntitySceneObject = value;
  }
LAB_00407886:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

