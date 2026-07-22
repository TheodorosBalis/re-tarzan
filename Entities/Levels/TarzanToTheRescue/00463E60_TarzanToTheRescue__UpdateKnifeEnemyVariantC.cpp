#include "tarzan_ghidra_types.hpp"

// Address: 0x00463E60
// Label: TarzanToTheRescue::UpdateKnifeEnemyVariantC
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TarzanToTheRescue::UpdateKnifeEnemyVariantC(int entry)

{
  Entity *entity = (Entity *)entry;
  int *intCursor;
  byte *value5;
  short *value6;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  uint value8;
  int value4;
  int value;
  undefined4 value7;
  undefined4 localState6;
  undefined4 localState5;
  undefined4 localState4;
  undefined1 localState2 [12];
  int localState [2];
  int localState3;
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  value = 0;
  if (value2 == 0) goto switchD_004640b1_default;
  value3 = entity->sceneObjects;
  localState6 = ((EntitySceneObject *)value3)->x;
  localState5 = ((EntitySceneObject *)value3)->y;
  localState4 = ((EntitySceneObject *)value3)->z;
  RefreshEntitySceneObjectNatureTerrainVerticalDelta(value3);
  value3 = *(int *)(entity->sceneObjects + 0x58);
  if ((-0x100 < value3) && (value3 < 0x100)) {
    intCursor = (int *)(entity->sceneObjects + 0x18);
    *intCursor = *intCursor + value3;
  }
  value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                    (entity->sceneObjects,&localState6,localState2,0,6);
  if (((value3 != 0) &&
      (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                         (entity->sceneObjects,&localState6,localState2,0,6), value3 != 0))
     && (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                           (entity->sceneObjects,&localState6,localState2,0,6), value3 != 0))
  {
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->x = *(undefined4 *)(value3 + 0x48);
    ((EntitySceneObject *)value3)->y = *(undefined4 *)(value3 + 0x4c);
    ((EntitySceneObject *)value3)->z = *(undefined4 *)(value3 + 0x50);
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag != '\0') {
    if ((*(int *)(value2 + 0x58) == 5) && (*(int *)(value2 + 0xc) != 9)) {
      PlayAudioById(0x3a3,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
      *(undefined4 *)(value2 + 0xc4) = *(undefined4 *)(value2 + 0xc);
      CEntities::SelectScriptAttachmentSequence
                (*(undefined4 *)(value2 + 0x10),*(int *)(value2 + 0x54) + 5);
      *(undefined4 *)(value2 + 0xc) = 9;
      if (*(short *)(entry + 0x3e) < 0) {
        PlayAudioById(0x3d1,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
        CEntities::ProcessEntityDeathAndRelease(entry,0);
        g_TarzanToTheRescueTrackedKnifeEnemyVariantC = 0;
        g_TarzanToTheRescueScriptedBarrierRightDone = 1;
        g_TarzanToTheRescueKnifeEnemyVariantCReleased = 1;
        return;
      }
    }
    if ((*(int *)(value2 + 0x58) == 6) && (*(int *)(value2 + 0xc) != 9)) {
      PlayAudioById(0x3ac,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
      *(undefined4 *)(value2 + 0xc4) = *(undefined4 *)(value2 + 0xc);
      CEntities::SelectScriptAttachmentSequence
                (*(undefined4 *)(value2 + 0x10),*(int *)(value2 + 0x54) + 5);
      *(undefined4 *)(value2 + 0xc) = 9;
      if (*(short *)(entry + 0x3e) < 0) {
        CEntities::ProcessEntityDeathAndRelease(entry,0);
        _g_TarzanToTheRescueKnifeEnemyVariantDReleased = 0;
        return;
      }
    }
    if ((*(int *)(value2 + 0x58) == 4) &&
       (PlayAudioById(0x3b1,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14),
       *(int *)(value2 + 0xc) != 9)) {
      PlayAudioById(0x3b1,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
      *(undefined4 *)(value2 + 0xc4) = *(undefined4 *)(value2 + 0xc);
      CEntities::SelectScriptAttachmentSequence
                (*(undefined4 *)(value2 + 0x10),*(int *)(value2 + 0x54) + 5);
      *(undefined4 *)(value2 + 0xc) = 9;
      if (*(short *)(entry + 0x3e) < 0) {
        CEntities::ProcessEntityDeathAndRelease(entry,0);
        g_TarzanToTheRescueTrackedKnifeEnemyGroupA1 = 0;
        return;
      }
    }
  }
  switch(*(undefined4 *)(value2 + 0xc)) {
  case 8:
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if ((shortValue == 3) &&
       (value = entity->sceneObjects,
       value3 = ((EntitySceneObject *)value)->x - *(int *)(g_PlayerEntitySceneObject + 0x14),
       value4 = ((EntitySceneObject *)value)->y - *(int *)(g_PlayerEntitySceneObject + 0x18),
       value = ((EntitySceneObject *)value)->z - *(int *)(g_PlayerEntitySceneObject + 0x1c),
       value * value + value4 * value4 + value3 * value3 < 160000)) {
      QueuePlayerDamageEvent(entry,8);
    }
    value = entity->sceneObjects;
    value3 = ((EntitySceneObject *)value)->x - *(int *)(g_PlayerEntitySceneObject + 0x14);
    value4 = ((EntitySceneObject *)value)->z - *(int *)(g_PlayerEntitySceneObject + 0x1c);
    value = ((EntitySceneObject *)value)->y - *(int *)(g_PlayerEntitySceneObject + 0x18);
    value8 = GetAngleFromXZVector12Bit(value3,value4);
    value = SqrtToInt(value * value + value4 * value4 + value3 * value3);
    if (value >> 6 < 0x100) {
      value = 0x100 - (value >> 6);
      *(int *)(g_PlayerEntitySceneObject + 0x14) =
           *(int *)(g_PlayerEntitySceneObject + 0x14) -
           ((short)(&g_SinCosTable12Bit)[(value8 & 0xfff) - 0x400 & 0xfff] * value >> 0xc);
      *(int *)(g_PlayerEntitySceneObject + 0x1c) =
           *(int *)(g_PlayerEntitySceneObject + 0x1c) -
           ((short)(&g_SinCosTable12Bit)[value8 & 0xfff] * value >> 0xc);
    }
    value3 = GetAngleFromXZVector12Bit
                      (*(int *)(g_PlayerEntitySceneObject + 0x14) -
                       *(int *)(entity->sceneObjects + 0x14),
                       *(int *)(g_PlayerEntitySceneObject + 0x1c) -
                       *(int *)(entity->sceneObjects + 0x1c));
    value = entity->sceneObjects;
    value3 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value)->yaw,value3 - 0x800U & 0xfff);
    value6 = (short *)(&((EntitySceneObject *)value)->yaw);
    *value6 = *value6 + (short)(value3 >> 2);
    if (shortValue == 5) {
      value5 = (byte *)(entity->sceneObjects + 0xf);
      *value5 = *value5 | 2;
      if (*(int *)(value2 + 0x58) == 5) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 1;
      }
    }
    else if (shortValue == 1) {
      value = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
               *(int *)(entity->sceneObjects + 0x14);
      value3 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
              *(int *)(entity->sceneObjects + 0x1c);
      if (value3 * value3 + value * value < 0x24001) {
        value = RandomModulo(3);
        CEntities::SelectScriptAttachmentSequence
                  (*(undefined4 *)(value2 + 0x10),
                   *(int *)(&g_TarzanToTheRescueKnifeEnemyVariantCAttackScriptOffsetTable +
                           value * 4) + *(int *)(value2 + 0x54));
      }
      else {
        CEntities::SelectScriptAttachmentSequence
                  (*(undefined4 *)(value2 + 0x10),*(undefined4 *)(value2 + 0x54));
        value5 = (byte *)(entity->sceneObjects + 0xf);
        *value5 = *value5 | 2;
        if (*(int *)(value2 + 0x58) == 5) {
          *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
        }
        *(undefined4 *)(value2 + 0xc) = 10;
      }
    }
    break;
  case 9:
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (shortValue != 1) break;
    *(int *)(value2 + 0xc) = *(int *)(value2 + 0xc4);
    if (*(int *)(value2 + 0xc4) == 10) {
      CEntities::SelectScriptAttachmentSequence
                (*(undefined4 *)(value2 + 0x10),*(undefined4 *)(value2 + 0x54));
    }
    if (*(int *)(value2 + 0xc) == 8) {
      CEntities::SelectScriptAttachmentSequence
                (*(undefined4 *)(value2 + 0x10),*(int *)(value2 + 0x54) + 1);
    }
    if (*(int *)(value2 + 0xc) != 0xb) break;
    value = *(int *)(value2 + 0x54);
    value7 = *(undefined4 *)(value2 + 0x10);
    goto LAB_00464464;
  case 10:
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value3 = TarzanToTheRescue::ChooseKnifeEnemyPathTarget(entry,localState);
    if (value3 != 0) {
      *(undefined4 *)(value2 + 0xc) = 0xb;
      break;
    }
    value8 = GetAngleFromXZVector12Bit
                      (localState[0] - *(int *)(entity->sceneObjects + 0x14),
                       localState3 - *(int *)(entity->sceneObjects + 0x1c));
    value3 = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(entity->sceneObjects + 0xa2),(value8 & 0xfff) + 0x800);
    value6 = (short *)(entity->sceneObjects + 0xa2);
    *value6 = *value6 + (short)(value3 >> 2);
    value3 = *(int *)(value2 + 0x58);
    if (value3 == 5) {
      value = 0x1c;
    }
    if (value3 == 6) {
      value = 0x28;
    }
    if (value3 == 4) {
      value = 0x30;
    }
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->x =
         ((EntitySceneObject *)value3)->x -
         ((short)(&g_SinCosTable12Bit)[((EntitySceneObject *)value3)->yaw - 0x400 & 0xfff] * value >> 0xc);
    value3 = entity->sceneObjects;
    ((EntitySceneObject *)value3)->z =
         ((EntitySceneObject *)value3)->z -
         ((short)(&g_SinCosTable12Bit)[((EntitySceneObject *)value3)->yaw & 0xfff] * value >> 0xc);
    value3 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
            *(int *)(entity->sceneObjects + 0x1c);
    value = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
             *(int *)(entity->sceneObjects + 0x14);
    if (0x24000 < value3 * value3 + value * value) break;
    value7 = *(undefined4 *)(value2 + 0x10);
    value = *(int *)(value2 + 0x54) + 1;
    *(undefined4 *)(value2 + 0xc) = 8;
LAB_00464464:
    CEntities::SelectScriptAttachmentSequence(value7,value);
    break;
  case 0xb:
    value = TarzanToTheRescue::ChooseKnifeEnemyPathTarget(entry,localState);
    if (value == 0) {
      *(undefined4 *)(value2 + 0xc) = 10;
    }
  }
switchD_004640b1_default:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

