#include "tarzan_ghidra_types.hpp"

// Address: 0x00428830
// Label: ElephantHairDare::UpdateCrocodile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ElephantHairDare::UpdateCrocodile(int entry)

{
  int *intCursor;
  int value;
  int value2;
  char resultFlag;
  short shortValue;
  int value3;
  int value4;
  uint value7;
  int value5;
  undefined4 value6;
  undefined4 localState5;
  undefined4 localState4;
  undefined4 localState3;
  int localState [2];
  int localState2;
  
  value2 = entry;
  value3 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value3 == 0) {
    return;
  }
  value = *(int *)(value2 + 0x38);
  value5 = (((int)(short)(&g_SinCosTable12Bit)[*(uint *)(value3 + 0x18) & 0xfff] *
            *(int *)(value3 + 0x2c) >> 0xc) + *(int *)(value3 + 0x24)) - *(int *)(value + 0x1c);
  value4 = (((int)(short)(&g_SinCosTable12Bit)[*(uint *)(value3 + 0x18) - 0x400 & 0xfff] *
            *(int *)(value3 + 0x2c) >> 0xc) + *(int *)(value3 + 0x1c)) - *(int *)(value + 0x14);
  *(int *)(value + 0x14) = (value4 >> 4) + *(int *)(value + 0x14);
  intCursor = (int *)(*(int *)(value2 + 0x38) + 0x1c);
  *intCursor = *intCursor + (value5 >> 4);
  shortValue = GetAngleFromXZVector12Bit(value4,value5);
  *(ushort *)(*(int *)(value2 + 0x38) + 0xa2) = shortValue - 0x800U & 0xfff;
  value = *(int *)(value3 + 0x28);
  if (value == 0) {
    *(int *)(value3 + 0x18) = *(int *)(value3 + 0x18) + 10;
  }
  if (value == 1) {
    *(int *)(value3 + 0x18) = *(int *)(value3 + 0x18) + -0xe;
  }
  if (value == 2) {
    *(int *)(value3 + 0x18) = *(int *)(value3 + 0x18) + -8;
  }
  *(uint *)(value3 + 0x18) = *(uint *)(value3 + 0x18) & 0xfff;
  shortValue = CEntities::UpdateScriptedEntitySceneObjectAttachment(value2);
  if (shortValue != 0) {
    CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value3 + 0x14),0);
    *(undefined4 *)(value3 + 0x30) = 0;
  }
  resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                    (g_PlayerEntitySceneObject,0x200,*(undefined4 *)(value2 + 0x38),0x200,&entry,
                     localState);
  if (resultFlag != '\0') {
    *(int *)(g_PlayerEntitySceneObject + 0x14) =
         *(int *)(g_PlayerEntitySceneObject + 0x14) + localState[0];
    *(int *)(g_PlayerEntitySceneObject + 0x1c) =
         *(int *)(g_PlayerEntitySceneObject + 0x1c) + localState2;
    if (*(int *)(value3 + 0x30) == 0) {
      QueuePlayerDamageEvent(value2,0x1008);
      CEntities::SelectScriptAttachmentSequence(*(undefined4 *)(value3 + 0x14),3);
      *(undefined4 *)(value3 + 0x30) = 1;
    }
  }
  value7 = NextRandomValue();
  if ((value7 & 0x1f) == 0) {
    value7 = NextRandomValue();
    switch(value7 & 3) {
    case 1:
      value3 = *(int *)(value2 + 0x38) + 0x14;
      value6 = 0x10b;
      break;
    case 2:
      value3 = *(int *)(value2 + 0x38) + 0x14;
      value6 = 0x10c;
      break;
    case 3:
      value3 = *(int *)(value2 + 0x38) + 0x14;
      value6 = 0x10d;
      break;
    default:
      goto switchD_004289a8_default;
    }
    PlayAudioById(value6,(int *)0,(undefined4 *)value3);
  }
switchD_004289a8_default:
  value7 = *(int *)(g_PlayerEntitySceneObjectData + 8) - *(int *)(*(int *)(value2 + 0x38) + 0x14);
  if ((int)value7 < 0) {
    value7 = ~value7 + 1;
  }
  if ((int)value7 < 0x800) {
    value3 = GetSceneAttachmentWorldPositionByMask(*(int *)(value2 + 0x38),0x400,&localState5);
    if (value3 != 0) {
      CEntities::SpawnEntityByTypeAtPosition(localState5,localState4,localState3,0x7e,0x11);
    }
    value3 = GetSceneAttachmentWorldPositionByMask(*(undefined4 *)(value2 + 0x38),0x2000,&localState5);
    if (value3 != 0) {
      CEntities::SpawnEntityByTypeAtPosition(localState5,localState4,localState3,0x7e,0x11);
    }
    value3 = GetSceneAttachmentWorldPositionByMask(*(undefined4 *)(value2 + 0x38),0x4000,&localState5);
    if (value3 != 0) {
      CEntities::SpawnEntityByTypeAtPosition(localState5,localState4,localState3,0x7e,0x11);
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(value2);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value2);
  }
  return;
}

