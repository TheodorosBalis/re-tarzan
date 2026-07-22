#include "tarzan_ghidra_types.hpp"

// Address: 0x00462560
// Label: TarzanToTheRescue::UpdateRhino
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TarzanToTheRescue::UpdateRhino(int entry)

{
  undefined4 *dataCursor;
  short *value5;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  uint value6;
  int *intCursor;
  int value4;
  int value;
  undefined4 localState9;
  undefined4 localState8;
  undefined4 localState7;
  undefined1 localState2 [12];
  undefined4 localState6;
  undefined4 localState5;
  undefined4 localState4;
  int localState [2];
  int localState3;
  
  value = entry;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    entry = 0;
    _g_TarzanToTheRescueActiveEntityCount = TarzanToTheRescue::CountActiveEntities();
    *(undefined4 *)(value2 + 0x38) = _g_TarzanToTheRescueActiveEntityCount;
    value3 = *(int *)(value + 0x38);
    localState9 = *(undefined4 *)(value3 + 0x14);
    localState7 = *(undefined4 *)(value3 + 0x1c);
    localState8 = *(undefined4 *)(value3 + 0x18);
    CEntities::CheckEntityHitByPlayerAttackOrThrowable(value);
    switch(*(undefined4 *)(value2 + 0xc)) {
    case 1:
      CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,
                         &entry,localState);
      if (resultFlag != '\0') {
        QueuePlayerDamageEvent(value,0xd);
        *(int *)(g_PlayerEntitySceneObject + 0x14) =
             *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
        *(int *)(g_PlayerEntitySceneObject + 0x1c) =
             *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
        *(undefined4 *)(value2 + 0x10) = 0;
        *(undefined4 *)(value2 + 0x1c) = 0;
        *(undefined4 *)(value2 + 0x60) = *(undefined4 *)(value2 + 0xc);
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x2c),7);
        *(undefined4 *)(value2 + 0xc) = 5;
        return;
      }
      if (*(int *)(value2 + 0x34) == 1) {
        value3 = GetAngleFromXZVector12Bit
                          (*(int *)(value2 + 0x54) - *(int *)(*(int *)(value + 0x38) + 0x14),
                           *(int *)(value2 + 0x5c) - *(int *)(*(int *)(value + 0x38) + 0x1c));
        value6 = value3 - 0x800U & 0xfff;
        *(uint *)(value2 + 0x3c) = value6;
        value3 = GetWrappedSignedAngleDelta12Bit
                          ((int)*(short *)(*(int *)(value + 0x38) + 0xa2),value6);
        value3 = value3 >> 1;
        if (value3 < -100) {
          value3 = -100;
        }
        else if (100 < value3) {
          value3 = 100;
        }
        value5 = (short *)(*(int *)(value + 0x38) + 0xa2);
        *value5 = *value5 + (short)value3;
      }
      *(undefined4 *)(value2 + 0x10) = 0x3c;
      CEntities::MoveEntitySceneObjectAlongFacingWithSpeedRamp
                (*(undefined4 *)(value + 0x38),(undefined4 *)(value2 + 0x10),0);
      value3 = *(int *)(value2 + 0x4c);
      *(int *)(value2 + 0x4c) = value3 + 1;
      if (4 < value3) {
        TarzanToTheRescue::ChooseRhinoRandomActiveTarget(value);
      }
      value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                        (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1);
      if (value3 != 0) {
        *(undefined4 *)(value2 + 0xc) = 2;
        *(undefined4 *)(value2 + 0x34) = 0;
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x2c),1);
        value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                          (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1);
        if ((value3 != 0) &&
           (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                              (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1),
           value3 != 0)) {
          value3 = *(int *)(value + 0x38);
          *(undefined4 *)(value3 + 0x14) = *(undefined4 *)(value3 + 0x48);
          *(undefined4 *)(value3 + 0x18) = *(undefined4 *)(value3 + 0x4c);
          *(undefined4 *)(value3 + 0x1c) = *(undefined4 *)(value3 + 0x50);
        }
      }
      value3 = TarzanToTheRescue::HandleRhinoCollisionWithActiveEntry(value);
      if (value3 != 0) {
        *(undefined4 *)(value2 + 0xc) = 4;
        *(undefined4 *)(value2 + 0x34) = 0;
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x2c),3);
        if (*(int *)(value2 + 0x2c) != 0) {
          *(undefined4 *)(value2 + 0x1c) = 0xffffffd8;
          CEntities::SelectScriptAttachmentSequence(*(int *)(value2 + 0x2c),5);
          value2 = *(int *)(value + 0x38);
          intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                    (*(undefined4 *)(value2 + 0x14),*(undefined4 *)(value2 + 0x18),
                                     *(undefined4 *)(value2 + 0x1c),0x178,0x11);
          if (((intCursor != (int *)0x0) && (*intCursor != 0)) &&
             (value2 = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000), value2 != 0))
          {
            *(undefined4 *)(value2 + 0x34) = 0x3c;
          }
        }
      }
      break;
    case 2:
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,
                         &entry,localState);
      if (resultFlag != '\0') {
        QueuePlayerDamageEvent(value,0xd);
        *(undefined4 *)(value2 + 0x10) = 0;
        *(undefined4 *)(value2 + 0x1c) = 0;
        *(undefined4 *)(value2 + 0x60) = *(undefined4 *)(value2 + 0xc);
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x2c),7);
        *(int *)(g_PlayerEntitySceneObject + 0x14) =
             *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
        *(int *)(g_PlayerEntitySceneObject + 0x1c) =
             *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
        *(undefined4 *)(value2 + 0xc) = 5;
        return;
      }
      value3 = TarzanToTheRescue::HandleRhinoCollisionWithActiveEntry(value);
      if (value3 != 0) {
        *(undefined4 *)(value2 + 0xc) = 4;
        *(undefined4 *)(value2 + 0x34) = 0;
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x2c),3);
        *(undefined4 *)(value2 + 0x4c) = 0x14;
        if (*(int *)(value2 + 0x2c) == 0) {
          return;
        }
        *(undefined4 *)(value2 + 0x1c) = 0xffffffd8;
        CEntities::SelectScriptAttachmentSequence(*(int *)(value2 + 0x2c),5);
        value = *(int *)(value + 0x38);
        intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                  (*(undefined4 *)(value + 0x14),*(undefined4 *)(value + 0x18),
                                   *(undefined4 *)(value + 0x1c),0x178,0x11);
        if (intCursor == (int *)0x0) {
          return;
        }
        if (*intCursor == 0) {
          return;
        }
        value = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
        if (value == 0) {
          return;
        }
        *(undefined4 *)(value + 0x34) = 0x3c;
        return;
      }
      value5 = (short *)(*(int *)(value + 0x38) + 0xa2);
      *value5 = *value5 + *(short *)(value2 + 0x30);
      CEntities::MoveEntitySceneObjectAlongFacingWithSpeedRamp
                (*(undefined4 *)(value + 0x38),value2 + 0x10,0);
      value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                        (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1);
      if (((value3 != 0) &&
          (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                             (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1),
          value3 != 0)) &&
         (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                            (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1),
         value3 != 0)) {
        value3 = *(int *)(value + 0x38);
        *(undefined4 *)(value3 + 0x14) = *(undefined4 *)(value3 + 0x48);
        *(undefined4 *)(value3 + 0x18) = *(undefined4 *)(value3 + 0x4c);
        *(undefined4 *)(value3 + 0x1c) = *(undefined4 *)(value3 + 0x50);
      }
      if (shortValue == 1) {
        *(undefined4 *)(value2 + 0xc) = 1;
        *(undefined4 *)(value2 + 0x4c) = 0;
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x2c),0);
      }
      break;
    case 3:
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,
                         &entry,localState);
      if (resultFlag != '\0') {
        *(int *)(g_PlayerEntitySceneObject + 0x14) =
             *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
        *(int *)(g_PlayerEntitySceneObject + 0x1c) =
             *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
        value3 = *(int *)(value + 0x38);
        *(undefined4 *)(value3 + 0x14) = *(undefined4 *)(value3 + 0x48);
        *(undefined4 *)(value3 + 0x18) = *(undefined4 *)(value3 + 0x4c);
        *(undefined4 *)(value3 + 0x1c) = *(undefined4 *)(value3 + 0x50);
        QueuePlayerDamageEvent(value,0xd);
      }
      CEntities::MoveEntitySceneObjectAlongFacingWithSpeedRamp
                (*(undefined4 *)(value + 0x38),(undefined4 *)(value2 + 0x10),0);
      value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                        (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1);
      if (((value3 != 0) &&
          (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                             (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1),
          value3 != 0)) &&
         (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                            (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1),
         value3 != 0)) {
        value3 = *(int *)(value + 0x38);
        *(undefined4 *)(value3 + 0x14) = *(undefined4 *)(value3 + 0x48);
        *(undefined4 *)(value3 + 0x18) = *(undefined4 *)(value3 + 0x4c);
        *(undefined4 *)(value3 + 0x1c) = *(undefined4 *)(value3 + 0x50);
      }
      if (shortValue == 2) {
        if ((((*(int *)(g_PlayerEntitySceneObjectData + 0x10) < -0xcaf2) &&
             (value2 = GetSceneAttachmentWorldPositionByMask
                                (*(undefined4 *)(value + 0x38),1,&localState6), value2 != 0)) &&
            (intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                       (localState6,localState5,localState4,0x178,0x11),
            intCursor != (int *)0x0)) &&
           ((*intCursor != 0 &&
            (value2 = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000), value2 != 0))))
        {
          *(undefined4 *)(value2 + 0x10) = 6;
          *(undefined4 *)(value2 + 0x34) = 0x3c;
        }
      }
      else if (shortValue == 1) {
        value3 = RandomModulo(4);
        value4 = RandomModulo(4);
        *(int *)(value2 + 0x30) = (0x39 - value3) + value4;
        *(undefined4 *)(value2 + 0xc) = 2;
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x2c),1);
        *(undefined4 *)(value2 + 0x10) = 0x3c;
      }
      break;
    case 4:
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,
                         &entry,localState);
      if (resultFlag != '\0') {
        *(int *)(g_PlayerEntitySceneObject + 0x14) =
             *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
        *(int *)(g_PlayerEntitySceneObject + 0x1c) =
             *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
        value3 = *(int *)(value + 0x38);
        *(undefined4 *)(value3 + 0x14) = *(undefined4 *)(value3 + 0x48);
        *(undefined4 *)(value3 + 0x18) = *(undefined4 *)(value3 + 0x4c);
        *(undefined4 *)(value3 + 0x1c) = *(undefined4 *)(value3 + 0x50);
        QueuePlayerDamageEvent(value,0xd);
      }
      dataCursor = (undefined4 *)(value2 + 0x10);
      *(undefined4 *)(value2 + 0x14) = 4;
      *dataCursor = 0;
      *(undefined4 *)(value2 + 0x18) = 4;
      *(undefined4 *)(value2 + 0x34) = 0;
      TarzanToTheRescue::ChooseRhinoRandomActiveTarget(value);
      CEntities::MoveEntitySceneObjectAlongFacingWithSpeedRamp(*(undefined4 *)(value + 0x38),dataCursor,0);
      value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                        (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1);
      if (((value3 != 0) &&
          (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                             (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1),
          value3 != 0)) &&
         (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                            (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1),
         value3 != 0)) {
        value3 = *(int *)(value + 0x38);
        *(undefined4 *)(value3 + 0x14) = *(undefined4 *)(value3 + 0x48);
        *(undefined4 *)(value3 + 0x18) = *(undefined4 *)(value3 + 0x4c);
        *(undefined4 *)(value3 + 0x1c) = *(undefined4 *)(value3 + 0x50);
      }
      if (shortValue == 1) {
        *(undefined4 *)(value2 + 0xc) = 3;
        CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x2c),6);
        *dataCursor = 0;
        *(undefined4 *)(value2 + 0x14) = 2;
        *(undefined4 *)(value2 + 0x18) = 2;
      }
      break;
    case 5:
      value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                        (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1);
      if (((value3 != 0) &&
          (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                             (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1),
          value3 != 0)) &&
         (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                            (*(undefined4 *)(value + 0x38),&localState9,localState2,0x200,1),
         value3 != 0)) {
        value3 = *(int *)(value + 0x38);
        *(undefined4 *)(value3 + 0x14) = *(undefined4 *)(value3 + 0x48);
        *(undefined4 *)(value3 + 0x18) = *(undefined4 *)(value3 + 0x4c);
        *(undefined4 *)(value3 + 0x1c) = *(undefined4 *)(value3 + 0x50);
      }
      shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      if (shortValue == 1) {
        if (*(int *)(value2 + 0x60) == 1) {
          *(undefined4 *)(value2 + 0xc) = 1;
          *(undefined4 *)(value2 + 0x4c) = 0;
          *(undefined4 *)(value2 + 0x10) = 0x3c;
          CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x2c),0);
          return;
        }
        if (*(int *)(value2 + 0x60) == 2) {
          *(undefined4 *)(value2 + 0xc) = 2;
          *(undefined4 *)(value2 + 0x10) = 0x3c;
          CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x2c),1);
          return;
        }
      }
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,
                         &entry,localState);
      if (resultFlag != '\0') {
        *(int *)(g_PlayerEntitySceneObject + 0x14) =
             *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
        *(int *)(g_PlayerEntitySceneObject + 0x1c) =
             *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
        value2 = *(int *)(value + 0x38);
        *(undefined4 *)(value2 + 0x14) = *(undefined4 *)(value2 + 0x48);
        *(undefined4 *)(value2 + 0x18) = *(undefined4 *)(value2 + 0x4c);
        *(undefined4 *)(value2 + 0x1c) = *(undefined4 *)(value2 + 0x50);
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(value);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value);
  }
  return;
}

