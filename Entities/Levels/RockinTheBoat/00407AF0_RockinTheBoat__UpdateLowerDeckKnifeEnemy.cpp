#include "tarzan_ghidra_types.hpp"

// Address: 0x00407AF0
// Label: RockinTheBoat::UpdateLowerDeckKnifeEnemy
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RockinTheBoat::UpdateLowerDeckKnifeEnemy(int entry)

{
  Entity *entity = (Entity *)entry;
  char resultFlag;
  short shortValue;
  int value3;
  undefined4 value6;
  uint value7;
  int value4;
  uint value8;
  uint value9;
  uint value10;
  int value;
  int value2;
  undefined4 value5;
  
  value4 = entity->sceneObjects;
  if (value4 == 0) {
    return;
  }
  if (*(short *)(entry + 0x4a) == 0) {
    if (((*(int *)(((EntitySceneObject *)value4)->worldObject + 0xc) != 0) &&
        (*(int *)(g_PlayerEntitySceneObject + 0x108) == 1)) &&
       (value2 = ((EntitySceneObject *)value4)->x - *(int *)(g_PlayerEntitySceneObjectData + 8),
       value3 = ((EntitySceneObject *)value4)->y - *(int *)(g_PlayerEntitySceneObjectData + 0xc),
       value = ((EntitySceneObject *)value4)->z - *(int *)(g_PlayerEntitySceneObjectData + 0x10),
       0x400000 < value * value + value3 * value3 + value2 * value2)) {
      *(undefined2 *)(entry + 0x4a) = 1;
      *(byte *)(value4 + 0xf) = *(byte *)(value4 + 0xf) | 0x80;
    }
    goto LAB_00407f26;
  }
  value2 = 999999;
  if ((*(int *)(g_PlayerEntitySceneObject + 0x108) == 1) &&
     (*(int *)(g_PlayerEntitySceneObject + 0x110) == ((EntitySceneObject *)value4)->surfacePathIndex)) {
    value2 = *(int *)(g_PlayerEntitySceneObject + 0x10c);
  }
  value8 = ((EntitySceneObject *)value4)->surfaceIndex - value2;
  if ((int)value8 < 0) {
    *(undefined1 *)(value4 + 0x75) = 0;
  }
  else {
    *(undefined1 *)(value4 + 0x75) = 0xff;
  }
  value3 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value3 == 0) goto LAB_00407f26;
  value6 = *(undefined4 *)(value3 + 0x10);
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag != '\0') {
    switch(*(undefined4 *)(value3 + 0x58)) {
    case 1:
    case 5:
      value5 = 0x3a3;
      break;
    case 2:
    case 6:
      value5 = 0x3b1;
      break;
    case 3:
    case 4:
      value5 = 0x3ac;
      break;
    default:
      goto switchD_00407b85_default;
    }
    PlayAudioById(value5,(int *)&((EntitySceneObject *)value4)->soundPosition,(undefined4 *)&((EntitySceneObject *)value4)->x);
switchD_00407b85_default:
    CEntities::SelectScriptAttachmentSequence(value6,8);
    *(undefined4 *)(value3 + 0xc4) = *(undefined4 *)(value3 + 0xc);
    *(undefined4 *)(value3 + 0xc) = 9;
  }
  if (*(short *)(entry + 0x3e) < 0) {
    CEntities::ProcessEntityDeath(value4,2);
    value6 = RandomModulo(6);
    switch(value6) {
    case 1:
      PlayAudioById(0x3cd,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    case 2:
      PlayAudioById(0x3ce,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    case 3:
      PlayAudioById(0x3cf,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    case 4:
      PlayAudioById(0x3d0,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    case 5:
      PlayAudioById(0x3d1,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    default:
      PlayAudioById(0x3cc,(int *)0,(undefined4 *)&((EntitySceneObject *)value4)->x);
      CEntities::ReleaseEntityToFreeList((byte *)entry);
      return;
    }
  }
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  if (3 < *(int *)(value3 + 0xc) - 8U) goto LAB_00407f26;
  value9 = (int)value8 >> 0x1f;
  switch(*(int *)(value3 + 0xc)) {
  case 8:
    if (value2 < 0xf423e) {
      *(byte *)(value4 + 0x75) = ((-1 < (int)value8) - 1U & 1) - 1;
      if (shortValue == 3) {
        value7 = *(int *)(g_PlayerEntitySceneObjectData + 0xc) - ((EntitySceneObject *)value4)->y;
        value10 = (int)value7 >> 0x1f;
        if (((int)((value7 ^ value10) - value10) < 0x100) && ((int)((value8 ^ value9) - value9) < 400)) {
          QueuePlayerDamageEvent(entry,0x2008);
        }
        goto LAB_00407f26;
      }
      if (shortValue != 1) goto LAB_00407f26;
      if ((-1 < value2) && ((int)((value8 ^ value9) - value9) < 0x181)) {
        value4 = RandomModulo(3);
        CEntities::SelectScriptAttachmentSequence(value6,*(undefined4 *)(&DAT_004bd780 + value4 * 4));
        goto LAB_00407f26;
      }
    }
    break;
  case 9:
    if (shortValue == 1) {
      *(int *)(value3 + 0xc) = *(int *)(value3 + 0xc4);
      if (*(int *)(value3 + 0xc4) == 10) {
        CEntities::SelectScriptAttachmentSequence(value6,1);
      }
      if (*(int *)(value3 + 0xc) == 8) {
        CEntities::SelectScriptAttachmentSequence(value6,4);
      }
      if (*(int *)(value3 + 0xc) == 0xb) {
        CEntities::SelectScriptAttachmentSequence(value6,0);
      }
    }
    goto LAB_00407f26;
  case 10:
    if (value2 != 999999) {
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,*(undefined4 *)(entry + 0x50));
      ((EntitySceneObject *)value4)->y = ((EntitySceneObject *)value4)->y + *(int *)(value4 + 0x58);
      value8 = ((EntitySceneObject *)value4)->surfaceIndex - value2;
      *(byte *)(value4 + 0x75) = ((-1 < (int)value8) - 1U & 1) - 1;
      if ((int)((value8 ^ (int)value8 >> 0x1f) - ((int)value8 >> 0x1f)) < 0x181) {
        *(undefined4 *)(value3 + 0xc) = 8;
        CEntities::SelectScriptAttachmentSequence(value6,4);
      }
      goto LAB_00407f26;
    }
    break;
  case 0xb:
    if (((shortValue == 1) && (value2 != 999999)) && (0x180 < (int)((value8 ^ value9) - value9))) {
      CEntities::SelectScriptAttachmentSequence(value6,1);
      *(undefined4 *)(value3 + 0xc) = 10;
    }
    goto LAB_00407f26;
  }
  CEntities::SelectScriptAttachmentSequence(value6,0);
  *(undefined4 *)(value3 + 0xc) = 0xb;
LAB_00407f26:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

