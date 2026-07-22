#include "tarzan_ghidra_types.hpp"

// Address: 0x00482950
// Label: CEntities::UpdateLeafSwimmingFinishWhirlpool
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities::UpdateLeafSwimmingFinishWhirlpool(int entry)

{
  Entity *entity = (Entity *)entry;
  short *value7;
  short shortValue;
  short shortValue2;
  int value2;
  char resultFlag;
  int value3;
  int value4;
  uint value6;
  int value5;
  int value;
  
  value7 = (short *)(entity->sceneObjects + 0xa2);
  *value7 = *value7 + 0x100;
  value3 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value3 == 0) goto LAB_00482c8e;
  value = *(int *)(g_PlayerEntitySceneObjectData + 8) - *(int *)(entity->sceneObjects + 0x14);
  value5 = *(int *)(g_PlayerEntitySceneObjectData + 0x10) - *(int *)(entity->sceneObjects + 0x1c)
  ;
  value4 = SqrtToInt(value5 * value5 + value * value);
  value4 = value4 >> 6;
  GetAngleFromXZVector12Bit(-value,value5);
  if ((value4 < 1) || (0x578 < value4)) {
LAB_00482a4c:
    if (0x200 < value4) goto LAB_00482c8e;
  }
  else if (0x200 < value4) {
    value2 = (0x578 - value4) / 0x18;
    value6 = GetAngleFromXZVector12Bit(value,value5);
    *(int *)(g_PlayerEntitySceneObjectData + 8) =
         *(int *)(g_PlayerEntitySceneObjectData + 8) -
         ((short)(&g_SinCosTable12Bit)[(value6 & 0xfff) - 0x400 & 0xfff] * value2 >> 0xc);
    *(int *)(g_PlayerEntitySceneObjectData + 0x10) =
         *(int *)(g_PlayerEntitySceneObjectData + 0x10) -
         ((short)(&g_SinCosTable12Bit)[value6 & 0xfff] * value2 >> 0xc);
    goto LAB_00482a4c;
  }
  if (0 < value4) {
    g_LeafSwimmingCameraDistanceBoostActive = 1;
    if (g_PlayerActionState != 3) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 3;
      (*(code *)g_LeafSwimmingEnterFinishWhirlpoolCallback)();
      if (_g_PlayerHeroMode == 0xb) {
        PlayAudioById(0x455,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
      }
      if (_g_PlayerHeroMode == 0xc) {
        PlayAudioById(0x45a,(int *)entity->sceneObjects + 0x104,(undefined4 *)entity->sceneObjects + 0x14);
      }
    }
    if (*(int *)(value3 + 0xc) == 0) {
      value6 = GetAngleFromXZVector12Bit(-value,value5);
      *(uint *)(value3 + 0x10) = value6 & 0xfff;
      *(undefined4 *)(value3 + 0xc) = 1;
    }
    value4 = *(int *)(value3 + 0x14) + -3;
    *(int *)(value3 + 0x14) = value4;
    if (value4 < 0) {
      *(undefined4 *)(value3 + 0x14) = 0;
    }
    value4 = *(int *)(value3 + 0x10);
    value5 = *(int *)(value3 + 0x14);
    shortValue = (&g_SinCosTable12Bit)[-value4 - 0x400U & 0xfff];
    shortValue2 = (&g_SinCosTable12Bit)[-value4 & 0xfff];
    value = *(int *)(entity->sceneObjects + 0x14);
    value2 = *(int *)(entity->sceneObjects + 0x1c);
    *(uint *)(value3 + 0x10) = value4 + *(int *)(value3 + 0x2c) & 0xfff;
    *(int *)(value3 + 0x2c) = *(int *)(value3 + 0x2c) + 1;
    *(int *)(g_PlayerEntitySceneObjectData + 8) = (shortValue * value5 >> 0xc) + value;
    *(int *)(g_PlayerEntitySceneObjectData + 0x10) = (shortValue2 * value5 >> 0xc) + value2;
    value7 = (short *)(g_PlayerEntitySceneObject + 0xa2);
    value4 = GetWrappedSignedAngleDelta12Bit
                      ((int)*(short *)(g_PlayerEntitySceneObject + 0xa2),-*(int *)(value3 + 0x10));
    *value7 = *value7 + (short)(value4 >> 2);
    *(short *)(g_PlayerEntitySceneObject + 0xa0) =
         *(short *)(g_PlayerEntitySceneObject + 0xa0) + 0x10;
    if (0x3ff < *(short *)(g_PlayerEntitySceneObject + 0xa0)) {
      *(undefined2 *)(g_PlayerEntitySceneObject + 0xa0) = 800;
    }
    *(short *)(g_PlayerEntitySceneObject + 0xa4) =
         *(short *)(g_PlayerEntitySceneObject + 0xa4) + *(short *)(value3 + 0x38);
    if (0x20 < *(int *)(value3 + 0x38)) {
      *(undefined4 *)(value3 + 0x38) = 0x20;
    }
    if (0x100 < *(short *)(g_PlayerEntitySceneObject + 0xa4)) {
      *(undefined2 *)(g_PlayerEntitySceneObject + 0xa4) = 0x100;
    }
    value4 = *(int *)(value3 + 0x34) + 4;
    *(int *)(value3 + 0x34) = value4;
    if (200 < value4) {
      *(undefined4 *)(value3 + 0x34) = 200;
    }
    value4 = *(int *)(value3 + 0x30) + *(int *)(value3 + 0x34);
    *(int *)(value3 + 0x30) = value4;
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + (value4 >> 8);
    value4 = *(int *)(value3 + 0x3c);
    *(int *)(value3 + 0x3c) = value4 + 1;
    if (100 < value4) {
      g_HudCountdownBcdTime = 0;
      *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0x8001;
      SetHudCountdownDisplay(0,0x8000);
      CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
      return;
    }
    *(int *)(g_PlayerEntitySceneObjectData + 0x24) =
         (*(int *)(g_PlayerEntitySceneObjectData + 0x24) -
         (*(int *)(g_PlayerEntitySceneObjectData + 0x24) >> 6)) + -8;
  }
LAB_00482c8e:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

