#include "tarzan_ghidra_types.hpp"

// Address: 0x00467980
// Label: TarzanToTheRescue::UpdateCrocodile3D
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void TarzanToTheRescue::UpdateCrocodile3D(int entry)

{
  int *intCursor;
  short *value5;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  uint value7;
  int value4;
  uint value8;
  int value;
  undefined4 value6;
  undefined4 localState6;
  undefined4 localState5;
  undefined4 localState4;
  undefined1 localState2 [12];
  int localState [2];
  int localState3;
  
  value = entry;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 == 0) goto switchD_004679d6_caseD_2;
  resultFlag = CEntities::CheckEntityHitByPlayerAttackOrThrowable(value);
  if ((resultFlag != '\0') && (*(int *)(value2 + 0xc) != 4)) {
    *(undefined4 *)(value2 + 0xc) = 4;
    CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x1c),3);
  }
  switch(*(undefined4 *)(value2 + 0xc)) {
  case 0:
    CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
    value7 = GetAngleFromXZVector12Bit
                      (*(int *)(*(int *)(value + 0x38) + 0x14) -
                       *(int *)(g_PlayerEntitySceneObject + 0x14),
                       *(int *)(*(int *)(value + 0x38) + 0x1c) -
                       *(int *)(g_PlayerEntitySceneObject + 0x1c));
    value3 = *(int *)(value + 0x38);
    value4 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(value3 + 0xa2),value7 & 0xfff);
    value5 = (short *)(value3 + 0xa2);
    *value5 = *value5 + (short)(value4 >> 4);
    *(undefined4 *)(value2 + 0xc) = 1;
    CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x1c),0);
    CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(*(undefined4 *)(value + 0x38));
    value2 = *(int *)(*(int *)(value + 0x38) + 0x58);
    if ((-0x100 < value2) && (value2 < 0x100)) {
      intCursor = (int *)(*(int *)(value + 0x38) + 0x18);
      *intCursor = *intCursor + value2;
    }
    break;
  case 1:
    resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                      (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,&entry
                       ,localState);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(value,0xc);
      *(int *)(g_PlayerEntitySceneObject + 0x14) =
           *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
      *(int *)(g_PlayerEntitySceneObject + 0x1c) =
           *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
      *(undefined4 *)(value2 + 0x14) = *(undefined4 *)(value2 + 0xc);
      CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x1c),2);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      *(undefined4 *)(value2 + 0xc) = 3;
      value2 = RandomModulo(4);
      if (value2 == 0) {
        value = *(int *)(value + 0x38) + 0x14;
        value6 = 0x10b;
      }
      else if (value2 == 1) {
        value = *(int *)(value + 0x38) + 0x14;
        value6 = 0x10c;
      }
      else if (value2 == 2) {
        value = *(int *)(value + 0x38) + 0x14;
        value6 = 0x10d;
      }
      else {
joined_r0x00467e26:
        if (value2 != 3) goto LAB_00467e3e;
        value = *(int *)(value + 0x38) + 0x14;
        value6 = 0x10e;
      }
LAB_00467e36:
      PlayAudioById(value6,(int *)0,(undefined4 *)value);
LAB_00467e3e:
      if (g_PlayerActionState == 0x2e) {
        return;
      }
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x2e;
      (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
      return;
    }
    CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
    value3 = *(int *)(value2 + 0x18);
    *(int *)(value2 + 0x18) = value3 + -1;
    if (value3 < 0) {
      value3 = RandomModulo(4);
      if (value3 == 0) {
        value3 = *(int *)(value + 0x38) + 0x14;
        value6 = 0x10b;
LAB_00467bc2:
        PlayAudioById(value6,(int *)0,(undefined4 *)value3);
      }
      else {
        if (value3 == 1) {
          value3 = *(int *)(value + 0x38) + 0x14;
          value6 = 0x10c;
          goto LAB_00467bc2;
        }
        if (value3 == 2) {
          value3 = *(int *)(value + 0x38) + 0x14;
          value6 = 0x10d;
          goto LAB_00467bc2;
        }
        if (value3 == 3) {
          value3 = *(int *)(value + 0x38) + 0x14;
          value6 = 0x10e;
          goto LAB_00467bc2;
        }
      }
      *(undefined4 *)(value2 + 0x18) = 0x78;
    }
    value7 = GetAngleFromXZVector12Bit
                      (*(int *)(*(int *)(value + 0x38) + 0x14) -
                       *(int *)(g_PlayerEntitySceneObject + 0x14),
                       *(int *)(*(int *)(value + 0x38) + 0x1c) -
                       *(int *)(g_PlayerEntitySceneObject + 0x1c));
    value3 = *(int *)(value + 0x38);
    value4 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(value3 + 0xa2),value7 & 0xfff);
    value5 = (short *)(value3 + 0xa2);
    *value5 = *value5 + (short)(value4 >> 4);
    value3 = *(int *)(value + 0x38);
    localState6 = *(undefined4 *)(value3 + 0x14);
    localState5 = *(undefined4 *)(value3 + 0x18);
    localState4 = *(undefined4 *)(value3 + 0x1c);
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(value3);
    value3 = *(int *)(*(int *)(value + 0x38) + 0x58);
    if ((-0x100 < value3) && (value3 < 0x100)) {
      intCursor = (int *)(*(int *)(value + 0x38) + 0x18);
      *intCursor = *intCursor + value3;
    }
    value3 = *(int *)(value + 0x38);
    shortValue = (&g_SinCosTable12Bit)[(int)*(short *)(value3 + 0xa2) & 0xfff];
    *(int *)(value3 + 0x14) =
         *(int *)(value3 + 0x14) -
         (((int)(short)(&g_SinCosTable12Bit)[(int)*(short *)(value3 + 0xa2) - 0x400U & 0xfff] << 5)
         >> 0xc);
    *(int *)(*(int *)(value + 0x38) + 0x1c) =
         *(int *)(*(int *)(value + 0x38) + 0x1c) - (((int)shortValue << 5) >> 0xc);
    value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                      (*(undefined4 *)(value + 0x38),&localState6,localState2,0,
                       *(int *)(value2 + 0x10) + 3);
    if (((value3 != 0) &&
        (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                           (*(undefined4 *)(value + 0x38),&localState6,localState2,0,
                            *(int *)(value2 + 0x10) + 3), value3 != 0)) &&
       (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                          (*(undefined4 *)(value + 0x38),&localState6,localState2,0,
                           *(int *)(value2 + 0x10) + 3), value3 != 0)) {
      value3 = *(int *)(value + 0x38);
      *(undefined4 *)(value3 + 0x14) = *(undefined4 *)(value3 + 0x48);
      *(undefined4 *)(value3 + 0x18) = *(undefined4 *)(value3 + 0x4c);
      *(undefined4 *)(value3 + 0x1c) = *(undefined4 *)(value3 + 0x50);
    }
    value3 = *(int *)(value + 0x38);
    value7 = *(int *)(value3 + 0x14) - *(int *)(value3 + 0x48);
    value8 = (int)value7 >> 0x1f;
    value7 = value7 ^ value8;
    if ((value7 == value8 || (int)(value7 - value8) < 0) &&
       (value7 = *(int *)(value3 + 0x1c) - *(int *)(value3 + 0x50), value8 = (int)value7 >> 0x1f,
       value7 = value7 ^ value8, value7 == value8 || (int)(value7 - value8) < 0)) {
      *(undefined4 *)(value2 + 0xc) = 5;
      CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x1c),4);
      return;
    }
    break;
  case 3:
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
    resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                      (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,&entry
                       ,localState);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(value,0xc);
      *(int *)(g_PlayerEntitySceneObject + 0x14) =
           *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
      *(int *)(g_PlayerEntitySceneObject + 0x1c) =
           *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
      if (g_PlayerActionState != 0x2e) {
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0x2e;
        (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
      }
    }
    if (shortValue == 1) {
      *(undefined4 *)(value2 + 0xc) = 1;
      CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x1c),0);
      return;
    }
    break;
  case 4:
    shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
    resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                      (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,&entry
                       ,localState);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(value,0xc);
      *(int *)(g_PlayerEntitySceneObject + 0x14) =
           *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
      *(int *)(g_PlayerEntitySceneObject + 0x1c) =
           *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
      if (g_PlayerActionState != 0x2e) {
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0x2e;
        (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
      }
    }
    if (shortValue != 1) break;
    goto LAB_00468186;
  case 5:
    resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                      (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value + 0x38),0x200,&entry
                       ,localState);
    if (resultFlag != '\0') {
      QueuePlayerDamageEvent(value,0xc);
      *(int *)(g_PlayerEntitySceneObject + 0x14) =
           *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
      *(int *)(g_PlayerEntitySceneObject + 0x1c) =
           *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState3;
      *(undefined4 *)(value2 + 0x14) = *(undefined4 *)(value2 + 0xc);
      CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x1c),2);
      CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
      *(undefined4 *)(value2 + 0xc) = 3;
      value2 = RandomModulo(4);
      if (value2 == 0) {
        value = *(int *)(value + 0x38) + 0x14;
        value6 = 0x10b;
      }
      else if (value2 == 1) {
        value = *(int *)(value + 0x38) + 0x14;
        value6 = 0x10c;
      }
      else {
        if (value2 != 2) goto joined_r0x00467e26;
        value = *(int *)(value + 0x38) + 0x14;
        value6 = 0x10d;
      }
      goto LAB_00467e36;
    }
    CEntities::UpdateScriptedEntitySceneObjectAttachment(value);
    value3 = *(int *)(value2 + 0x18);
    *(int *)(value2 + 0x18) = value3 + -1;
    if (value3 < 0) {
      value3 = RandomModulo(4);
      if (value3 == 0) {
        value3 = *(int *)(value + 0x38) + 0x14;
        value6 = 0x10b;
LAB_00467eda:
        PlayAudioById(value6,(int *)0,(undefined4 *)value3);
      }
      else {
        if (value3 == 1) {
          value3 = *(int *)(value + 0x38) + 0x14;
          value6 = 0x10c;
          goto LAB_00467eda;
        }
        if (value3 == 2) {
          value3 = *(int *)(value + 0x38) + 0x14;
          value6 = 0x10d;
          goto LAB_00467eda;
        }
        if (value3 == 3) {
          value3 = *(int *)(value + 0x38) + 0x14;
          value6 = 0x10e;
          goto LAB_00467eda;
        }
      }
      *(undefined4 *)(value2 + 0x18) = 0x78;
    }
    value7 = GetAngleFromXZVector12Bit
                      (*(int *)(*(int *)(value + 0x38) + 0x14) -
                       *(int *)(g_PlayerEntitySceneObject + 0x14),
                       *(int *)(*(int *)(value + 0x38) + 0x1c) -
                       *(int *)(g_PlayerEntitySceneObject + 0x1c));
    value3 = *(int *)(value + 0x38);
    value4 = GetWrappedSignedAngleDelta12Bit((int)*(short *)(value3 + 0xa2),value7 & 0xfff);
    value5 = (short *)(value3 + 0xa2);
    *value5 = *value5 + (short)(value4 >> 4);
    value3 = *(int *)(value + 0x38);
    localState6 = *(undefined4 *)(value3 + 0x14);
    localState5 = *(undefined4 *)(value3 + 0x18);
    localState4 = *(undefined4 *)(value3 + 0x1c);
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(value3);
    value3 = *(int *)(*(int *)(value + 0x38) + 0x58);
    if ((-0x100 < value3) && (value3 < 0x100)) {
      intCursor = (int *)(*(int *)(value + 0x38) + 0x18);
      *intCursor = *intCursor + value3;
    }
    value3 = *(int *)(value + 0x38);
    shortValue = (&g_SinCosTable12Bit)[(int)*(short *)(value3 + 0xa2) & 0xfff];
    *(int *)(value3 + 0x14) =
         *(int *)(value3 + 0x14) -
         (((int)(short)(&g_SinCosTable12Bit)[(int)*(short *)(value3 + 0xa2) - 0x400U & 0xfff] << 5)
         >> 0xc);
    *(int *)(*(int *)(value + 0x38) + 0x1c) =
         *(int *)(*(int *)(value + 0x38) + 0x1c) - (((int)shortValue << 5) >> 0xc);
    value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                      (*(undefined4 *)(value + 0x38),&localState6,localState2,0,
                       *(int *)(value2 + 0x10) + 3);
    if (((value3 != 0) &&
        (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                           (*(undefined4 *)(value + 0x38),&localState6,localState2,0,
                            *(int *)(value2 + 0x10) + 3), value3 != 0)) &&
       (value3 = TarzanToTheRescue::PushSceneObjectOutOfCollisionRail
                          (*(undefined4 *)(value + 0x38),&localState6,localState2,0,
                           *(int *)(value2 + 0x10) + 3), value3 != 0)) {
      value3 = *(int *)(value + 0x38);
      *(undefined4 *)(value3 + 0x14) = *(undefined4 *)(value3 + 0x48);
      *(undefined4 *)(value3 + 0x18) = *(undefined4 *)(value3 + 0x4c);
      *(undefined4 *)(value3 + 0x1c) = *(undefined4 *)(value3 + 0x50);
    }
    value3 = *(int *)(value + 0x38);
    if ((*(int *)(value3 + 0x14) != *(int *)(value3 + 0x48)) ||
       (*(int *)(value3 + 0x1c) != *(int *)(value3 + 0x50))) {
LAB_00468186:
      *(undefined4 *)(value2 + 0xc) = 1;
      CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value2 + 0x1c),0);
      return;
    }
  }
switchD_004679d6_caseD_2:
  resultFlag = IsEntityOutsideOuterActivationBounds(value);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value);
  }
  return;
}

