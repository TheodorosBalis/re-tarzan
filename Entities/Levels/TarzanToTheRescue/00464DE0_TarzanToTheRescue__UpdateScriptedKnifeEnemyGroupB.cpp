#include "tarzan_ghidra_types.hpp"

// Address: 0x00464DE0
// Label: TarzanToTheRescue::UpdateScriptedKnifeEnemyGroupB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TarzanToTheRescue::UpdateScriptedKnifeEnemyGroupB(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value5;
  ushort *dataCursor;
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  uint value8;
  int value3;
  int value4;
  uint value6;
  undefined4 value7;
  undefined4 localState8;
  undefined4 localState7;
  undefined4 localState6;
  undefined1 localState [12];
  int localState5;
  int localState4;
  int localState3;
  int localState2;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value == 0) goto switchD_00465234_caseD_a;
  value4 = *(int *)(entity->sceneObjects + 0x110) * 4 + 4;
  localState5 = *(int *)(value4 + g_CollisionSurfaceTable) + value4 + g_CollisionSurfaceTable;
  SnapCameraAnchorAttachmentToNearestPathSegment(localState,g_PlayerEntitySceneObject + 0x14);
  value4 = *(int *)(localState5 + 0x3c + localState4 * 0x1c);
  value2 = localState3 - *(int *)(localState5 + 0x30 + localState4 * 0x1c);
  value3 = localState2 - *(int *)(localState5 + (localState4 + 2) * 0x1c);
  value2 = SqrtToInt(value3 * value3 + value2 * value2);
  value4 = value4 + (value2 >> 6);
  value2 = *(int *)(localState5 + 4) + -0x200;
  if (value2 < value4) {
    value4 = value2;
  }
  if (value4 < 0x200) {
    value4 = 0x200;
  }
  value6 = value4 - *(int *)(entity->sceneObjects + 0x10c);
  value4 = localState3 - *(int *)(g_PlayerEntitySceneObject + 0x14);
  value2 = localState2 - *(int *)(g_PlayerEntitySceneObject + 0x1c);
  value8 = GetAngleFromXZVector12Bit(value4,value2);
  value4 = SqrtToInt(value2 * value2 + value4 * value4);
  if (value4 >> 6 < 0x100) {
    value4 = 0x100 - (value4 >> 6);
    *(int *)(g_PlayerEntitySceneObject + 0x14) =
         *(int *)(g_PlayerEntitySceneObject + 0x14) -
         ((short)(&g_SinCosTable12Bit)[(value8 & 0xfff) - 0x400 & 0xfff] * value4 >> 0xc);
    *(int *)(g_PlayerEntitySceneObject + 0x1c) =
         *(int *)(g_PlayerEntitySceneObject + 0x1c) -
         ((short)(&g_SinCosTable12Bit)[value8 & 0xfff] * value4 >> 0xc);
  }
  value4 = entity->sceneObjects;
  value2 = ((EntitySceneObject *)value4)->x - *(int *)(g_PlayerEntitySceneObject + 0x14);
  value3 = ((EntitySceneObject *)value4)->z - *(int *)(g_PlayerEntitySceneObject + 0x1c);
  value4 = ((EntitySceneObject *)value4)->y - *(int *)(g_PlayerEntitySceneObject + 0x18);
  GetAngleFromXZVector12Bit(value2,value3);
  value8 = SqrtToInt(value4 * value4 + value3 * value3 + value2 * value2);
  if ((int)(value8 & 0xffffffc0) < 0x4000) {
    QueuePlayerDamageEvent(entry,0xc);
  }
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(entry);
  if (resultFlag != '\0') {
    if (((*(int *)(value + 0x58) == 0) && (*(int *)(value + 0xc) != 9)) &&
       (PlayAudioById(0x39f,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14),
       g_TarzanToTheRescueTrackedKnifeEnemyGroupA0 == 0)) {
      *(undefined4 *)(value + 0xc4) = *(undefined4 *)(value + 0xc);
      CEntities::SelectScriptAttachmentSequence
                (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 9);
      *(undefined4 *)(value + 0xc) = 9;
      if (*(short *)(entry + 0x3e) < 0) {
        g_TarzanToTheRescueTrackedKnifeEnemyGroupB0 = 0;
        value = entity->sceneObjects;
        value7 = 0x3cc;
        goto LAB_00465180;
      }
    }
    if (*(int *)(value + 0x58) == 3) {
      if (g_TarzanToTheRescueKnifeEnemyGroupCReleased == 0) {
        *(undefined2 *)(entry + 0x3e) = 0x280;
      }
      else if (*(int *)(value + 0xc) != 9) {
        PlayAudioById(0x3a8,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
        *(int *)(value + 0xc4) = *(int *)(value + 0xc);
        if (*(int *)(value + 0xc) == 0x20) {
          *(undefined4 *)(value + 0xc4) = 7;
        }
        CEntities::SelectScriptAttachmentSequence
                  (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 9);
        *(undefined4 *)(value + 0xc) = 9;
        g_TarzanToTheRescueScriptedBarrierLeftDone = 1;
        if (*(short *)(entry + 0x3e) < 0) {
          PlayAudioById(0x3cd,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
          _g_TarzanToTheRescueTrackedKnifeEnemyGroupB1 = 0;
          CEntities::ProcessEntityDeathAndRelease(entry,0);
          return;
        }
      }
    }
    if (*(int *)(value + 0x58) == 1) {
      if (g_TarzanToTheRescueScriptedBarrierRightDone == 0) {
        *(undefined2 *)(entry + 0x3e) = 0x280;
      }
      else if (*(int *)(value + 0xc) != 9) {
        PlayAudioById(0x3a8,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
        *(int *)(value + 0xc4) = *(int *)(value + 0xc);
        if (*(int *)(value + 0xc) == 0x20) {
          *(undefined4 *)(value + 0xc4) = 7;
        }
        CEntities::SelectScriptAttachmentSequence
                  (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 9);
        *(undefined4 *)(value + 0xc) = 9;
        g_TarzanToTheRescueScriptedBarrierAltDone = 1;
        if (*(short *)(entry + 0x3e) < 0) {
          g_TarzanToTheRescueScriptedPathPropFlagB = 1;
          g_TarzanToTheRescueTrackedKnifeEnemyGroupB2 = 0;
          value = entity->sceneObjects;
          value7 = 0x3ce;
LAB_00465180:
          PlayAudioById(value7,(int *)0,(undefined4 *)&((EntitySceneObject *)value)->x);
          CEntities::ProcessEntityDeathAndRelease(entry,0);
          return;
        }
      }
    }
    if ((*(int *)(value + 0x58) == 7) && (*(int *)(value + 0xc) != 9)) {
      PlayAudioById(0x39f,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
      *(undefined4 *)(value + 0xc4) = *(undefined4 *)(value + 0xc);
      CEntities::SelectScriptAttachmentSequence
                (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 9);
      *(undefined4 *)(value + 0xc) = 9;
      if (*(short *)(entry + 0x3e) < 0) {
        g_TarzanToTheRescueScriptedPathPropFlagA = 1;
        PlayAudioById(0x3cf,(int *)0,(undefined4 *)entity->sceneObjects + 0x14);
        g_TarzanToTheRescueTrackedKnifeEnemyGroupB3 = 0;
        CEntities::ProcessEntityDeathAndRelease(entry,0);
        return;
      }
    }
  }
  if (0x1c < *(int *)(value + 0xc) - 4U) goto switchD_00465234_caseD_a;
  value8 = (int)value6 >> 0x1f;
  switch(*(int *)(value + 0xc)) {
  case 4:
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (*(int *)(value + 0x58) == 3) {
      *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
    }
    if (*(int *)(value + 0x58) == 0) {
      *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
    }
    if (*(int *)(value + 0x58) == 1) {
      *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
    }
    if (*(int *)(value + 0x58) == 7) {
      *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
    }
    value2 = GetAngleFromXZVector12Bit
                      (*(int *)(g_PlayerEntitySceneObject + 0x14) -
                       *(int *)(entity->sceneObjects + 0x14),
                       *(int *)(g_PlayerEntitySceneObject + 0x1c) -
                       *(int *)(entity->sceneObjects + 0x1c));
    value4 = entity->sceneObjects;
    value2 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value4)->yaw,value2 - 0x800U & 0xfff);
    value5 = (short *)(&((EntitySceneObject *)value4)->yaw);
    *value5 = *value5 + (short)(value2 >> 2);
    if ((((shortValue == 3) &&
         (value4 = GetSceneAttachmentWorldPositionByMask
                            (entity->sceneObjects,0x100,&localState8), value4 != 0)) &&
        (value4 = CEntities::SpawnEntityByTypeAtPosition(localState8,localState7,localState6,0x16c,0x11),
        value4 != 0)) &&
       (value4 = CEntities::FindEntityAttachmentByFlags(value4,0x10000000), value4 != 0)) {
      ((EntitySceneObject *)value4)->next = *(undefined4 *)(entity->sceneObjects + 0x18);
      *(int *)(value4 + 0x70) = (int)*(short *)(entity->sceneObjects + 0xa2);
    }
    if (0x100 < (int)((value6 ^ value8) - value8)) {
      *(undefined4 *)(value + 0xc) = 7;
      if ((0 < (int)value6) && (*(char *)(entity->sceneObjects + 0x75) == -1)) {
        *(undefined1 *)(entity->sceneObjects + 0x75) = 0;
        dataCursor = (ushort *)(entity->sceneObjects + 0xa2);
        *dataCursor = *dataCursor ^ 0x800;
      }
      if (((int)value6 < 0) && (*(char *)(entity->sceneObjects + 0x75) == '\0')) {
        *(undefined1 *)(entity->sceneObjects + 0x75) = 0xff;
        dataCursor = (ushort *)(entity->sceneObjects + 0xa2);
        *dataCursor = *dataCursor ^ 0x800;
      }
      CEntities::SelectScriptAttachmentSequence
                (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 4);
      return;
    }
    if (shortValue != 1) break;
    value2 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
            *(int *)(entity->sceneObjects + 0x14);
    value4 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
            *(int *)(entity->sceneObjects + 0x1c);
    value4 = value4 * value4 + value2 * value2;
    if (value4 < 0x90000) {
      CEntities::SelectScriptAttachmentSequence
                (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 5);
      *(undefined4 *)(value + 0xc) = 8;
      return;
    }
    if (0x8fffff < value4) {
      CEntities::SelectScriptAttachmentSequence
                (((EntitySceneObject *)value)->worldObject,*(undefined4 *)(value + 0x54));
      *(undefined4 *)(value + 0xc) = 5;
      break;
    }
    value4 = *(int *)(value + 0x54) + 3;
    goto LAB_004658ae;
  case 5:
    value4 = *(int *)(entity->sceneObjects + 0x10c);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value2 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
            *(int *)(entity->sceneObjects + 0x14);
    value3 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
            *(int *)(entity->sceneObjects + 0x1c);
    if (value3 * value3 + value2 * value2 < 0x900000) {
      *(undefined4 *)(value + 0xc) = 4;
      CEntities::SelectScriptAttachmentSequence
                (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 3);
      return;
    }
    CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0x10);
    if (*(char *)(entity->sceneObjects + 0x75) == '\0') {
      value2 = *(int *)(entity->sceneObjects + 0x110);
      if (value4 < *(int *)(*(int *)(g_CollisionSurfaceTable + 4 + value2 * 4) + 8 + value2 * 4 +
                          g_CollisionSurfaceTable) + -0x200) break;
      *(undefined4 *)(value + 0xc) = 6;
      value4 = *(int *)(value + 0x54) + 1;
      goto LAB_004658ae;
    }
    if (0x200 < value4) break;
    value7 = ((EntitySceneObject *)value)->worldObject;
    value4 = *(int *)(value + 0x54) + 1;
    *(undefined4 *)(value + 0xc) = 6;
    goto LAB_004658b3;
  case 6:
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (shortValue == 1) {
      *(byte *)(entity->sceneObjects + 0x75) = ~*(byte *)(entity->sceneObjects + 0x75);
      dataCursor = (ushort *)(entity->sceneObjects + 0xa2);
      *dataCursor = *dataCursor ^ 0x800;
      *(undefined4 *)(value + 0xc) = 5;
    }
    break;
  case 7:
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value4 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
            *(int *)(entity->sceneObjects + 0x14);
    value2 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
            *(int *)(entity->sceneObjects + 0x1c);
    if (0x100 < (int)((value6 ^ value8) - value8)) {
      *(undefined4 *)(value + 0xc) = 7;
      if ((0 < (int)value6) && (*(char *)(entity->sceneObjects + 0x75) == -1)) {
        *(undefined1 *)(entity->sceneObjects + 0x75) = 0;
        dataCursor = (ushort *)(entity->sceneObjects + 0xa2);
        *dataCursor = *dataCursor ^ 0x800;
      }
      if (((int)value6 < 0) && (*(char *)(entity->sceneObjects + 0x75) == '\0')) {
        *(undefined1 *)(entity->sceneObjects + 0x75) = 0xff;
        dataCursor = (ushort *)(entity->sceneObjects + 0xa2);
        *dataCursor = *dataCursor ^ 0x800;
      }
    }
    if ((int)value6 < -0x40) {
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0x30);
      value = entity->sceneObjects;
LAB_004657df:
      value4 = CEntities::GetEntitySceneObjectVerticalCollisionDelta(value);
      ((EntitySceneObject *)value)->y = ((EntitySceneObject *)value)->y + value4;
      return;
    }
    if (0x40 < (int)value6) {
      CEntities::MoveEntitySceneObjectAndEaseFacingAngles(entry,0x30);
      value = entity->sceneObjects;
      goto LAB_004657df;
    }
    if (0x8ffff < value2 * value2 + value4 * value4) {
      value7 = ((EntitySceneObject *)value)->worldObject;
      value4 = *(int *)(value + 0x54) + 3;
      *(undefined4 *)(value + 0xc) = 4;
      goto LAB_004658b3;
    }
    *(undefined4 *)(value + 0xc) = 8;
    value4 = *(int *)(value + 0x54) + 5;
    goto LAB_004658ae;
  case 8:
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    value2 = GetAngleFromXZVector12Bit
                      (*(int *)(g_PlayerEntitySceneObject + 0x14) -
                       *(int *)(entity->sceneObjects + 0x14),
                       *(int *)(g_PlayerEntitySceneObject + 0x1c) -
                       *(int *)(entity->sceneObjects + 0x1c));
    value4 = entity->sceneObjects;
    value2 = GetWrappedSignedAngleDelta12Bit((int)((EntitySceneObject *)value4)->yaw,value2 - 0x800U & 0xfff);
    value5 = (short *)(&((EntitySceneObject *)value4)->yaw);
    *value5 = *value5 + (short)(value2 >> 2);
    if (shortValue == 5) {
      if (*(int *)(value + 0x58) == 3) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 1;
      }
      if (*(int *)(value + 0x58) == 0) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 1;
      }
      if (*(int *)(value + 0x58) == 1) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 1;
      }
      if (*(int *)(value + 0x58) == 7) {
        *(undefined4 *)(entity->sceneObjects + 0x70) = 1;
      }
    }
    else if ((shortValue == 3) &&
            (value4 = entity->sceneObjects,
            value2 = ((EntitySceneObject *)value4)->x - *(int *)(g_PlayerEntitySceneObject + 0x14),
            value3 = ((EntitySceneObject *)value4)->y - *(int *)(g_PlayerEntitySceneObject + 0x18),
            value4 = ((EntitySceneObject *)value4)->z - *(int *)(g_PlayerEntitySceneObject + 0x1c),
            value4 * value4 + value3 * value3 + value2 * value2 < 0x24000)) {
      QueuePlayerDamageEvent(entry,0xc);
    }
    if (0x100 < (int)((value6 ^ value8) - value8)) {
      *(undefined4 *)(value + 0xc) = 7;
      if ((0 < (int)value6) && (*(char *)(entity->sceneObjects + 0x75) == -1)) {
        *(undefined1 *)(entity->sceneObjects + 0x75) = 0;
        dataCursor = (ushort *)(entity->sceneObjects + 0xa2);
        *dataCursor = *dataCursor ^ 0x800;
      }
      if (((int)value6 < 0) && (*(char *)(entity->sceneObjects + 0x75) == '\0')) {
        *(undefined1 *)(entity->sceneObjects + 0x75) = 0xff;
        dataCursor = (ushort *)(entity->sceneObjects + 0xa2);
        *dataCursor = *dataCursor ^ 0x800;
      }
      CEntities::SelectScriptAttachmentSequence
                (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 4);
    }
    if (shortValue == 1) {
      value4 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
              *(int *)(entity->sceneObjects + 0x14);
      value2 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
              *(int *)(entity->sceneObjects + 0x1c);
      if (value2 * value2 + value4 * value4 < 0x90001) {
        value4 = RandomModulo(3);
        CEntities::SelectScriptAttachmentSequence
                  (((EntitySceneObject *)value)->worldObject,
                   *(int *)(&g_TarzanToTheRescueKnifeEnemyGroupBAttackScriptOffsetTable + value4 * 4)
                   + *(int *)(value + 0x54));
      }
      else {
        CEntities::SelectScriptAttachmentSequence
                  (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 3);
        if (*(int *)(value + 0x58) == 3) {
          *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
        }
        if (*(int *)(value + 0x58) == 0) {
          *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
        }
        if (*(int *)(value + 0x58) == 1) {
          *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
        }
        if (*(int *)(value + 0x58) == 7) {
          *(undefined4 *)(entity->sceneObjects + 0x70) = 0;
        }
        *(undefined4 *)(value + 0xc) = 4;
      }
    }
    break;
  case 9:
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
    if (shortValue != 1) break;
    *(int *)(value + 0xc) = *(int *)(value + 0xc4);
    if (*(int *)(value + 0xc4) == 5) {
      CEntities::SelectScriptAttachmentSequence
                (((EntitySceneObject *)value)->worldObject,*(undefined4 *)(value + 0x54));
    }
    if (*(int *)(value + 0xc) == 6) {
      CEntities::SelectScriptAttachmentSequence
                (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 1);
    }
    if (*(int *)(value + 0xc) == 4) {
      CEntities::SelectScriptAttachmentSequence
                (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 3);
    }
    if (*(int *)(value + 0xc) == 8) {
      CEntities::SelectScriptAttachmentSequence
                (((EntitySceneObject *)value)->worldObject,*(int *)(value + 0x54) + 5);
    }
    if (*(int *)(value + 0xc) != 7) break;
    value4 = *(int *)(value + 0x54) + 4;
LAB_004658ae:
    value7 = ((EntitySceneObject *)value)->worldObject;
LAB_004658b3:
    CEntities::SelectScriptAttachmentSequence(value7,value4);
    break;
  case 0x20:
    CEntities::UpdateScriptedEntitySceneObjectAttachment(entry);
  }
switchD_00465234_caseD_a:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

