#include "tarzan_ghidra_types.hpp"

// Address: 0x00475D20
// Label: KerchakChase::UpdateChaseFinishTrigger
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void KerchakChase::UpdateChaseFinishTrigger(undefined4 entry)

{
  char resultFlag;
  short shortValue;
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  short shortValue2;
  uint value7;
  undefined4 value8;
  undefined4 value9;
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if ((value == 0) ||
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x200), value2 == 0))
  goto LAB_00476155;
  if (*(int *)(value + 0xc) == 0) {
    value3 = GetEncodedEntitySceneObjectIdFromSourceRef(*(undefined4 *)(value2 + 0x18));
    CEntities::GetChildSceneAttachmentWorldPositionByMask
              (*(undefined4 *)(value2 + 0x18),1,(int *)(value + 0x10));
    value5 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) - *(int *)(value + 0x10);
    value6 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) - *(int *)(value + 0x18);
    if (value6 * value6 + value5 * value5 < 0x225510) {
      shortValue2 = 0;
      value7 = 0x200;
      do {
        value6 = RandomModulo(0x400,0x160,0x11);
        value5 = *(int *)(value + 0x18);
        value4 = RandomModulo(0x400);
        value6 = RandomModulo(0x400,*(undefined4 *)(value + 0x14),(value5 - value6) + value4);
        value5 = *(int *)(value + 0x10);
        value4 = RandomModulo(0x400);
        value5 = CEntities::SpawnEntityByTypeAtPosition((value5 - value6) + value4);
        if ((value5 != 0) &&
           (value6 = CEntities::FindEntityAttachmentByFlags(value5,0x20000000), value6 != 0)) {
          value4 = RandomModulo(0x1e);
          *(int *)(value6 + 0x40) =
               (int)(short)(&g_SinCosTable12Bit)[value7 - 0x400 & 0xfff] * (value4 + 0x3c) >> 0xc;
          *(int *)(value6 + 0x44) =
               (int)(short)(&g_SinCosTable12Bit)[value7 & 0xfff] * (value4 + 0x3c) >> 0xc;
          shortValue = RandomModulo(0x40);
          *(short *)(value6 + 0x54) = -0x60 - shortValue;
          *(undefined4 *)(*(int *)(value5 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
          *(undefined2 *)(*(int *)(value5 + 0x38) + 0xc) = 0x2004;
          *(undefined2 *)(value6 + 0x56) = 0xff80;
          *(short *)(*(int *)(value5 + 0x38) + 0xa2) = (shortValue2 + 1) * 0x200;
          *(undefined2 *)(*(int *)(value5 + 0x38) + 0xa0) = 0x400;
          value5 = RandomModulo(0x32);
          *(int *)(value6 + 0x18) = value5 + 0x3c;
          *(undefined4 *)(value6 + 0x10) = 0;
        }
        value7 = value7 + 0x200;
        shortValue2 = shortValue2 + 1;
      } while ((int)value7 < 0x1200);
      if (value3 == 0x2007) {
        *(undefined4 *)(value + 0xc) = 1;
        value8 = *(undefined4 *)(value2 + 0x18);
        value9 = 0x2008;
      }
      else {
        if (value3 != 0x200a) goto LAB_00476155;
        *(undefined4 *)(value + 0xc) = 1;
        value8 = *(undefined4 *)(value2 + 0x18);
        value9 = 0x2010;
      }
      DecodeEncodedEntitySceneObjectIdToSourceRef(value8,value9);
    }
    goto LAB_00476155;
  }
  if (((*(int *)(value + 0xc) != 1) ||
      (value5 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) - *(int *)(value + 0x10),
      value3 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) - *(int *)(value + 0x18),
      value3 = value3 * value3 + value5 * value5, 0x8ffff < value3)) || (value3 < 0)) goto LAB_00476155;
  value3 = GetEncodedEntitySceneObjectIdFromSourceRef(*(undefined4 *)(value2 + 0x18));
  if (value3 == 0x2008) {
    value8 = *(undefined4 *)(value2 + 0x18);
    value9 = 0x2009;
LAB_00475dd6:
    DecodeEncodedEntitySceneObjectIdToSourceRef(value8,value9);
  }
  else if (value3 == 0x2010) {
    value8 = *(undefined4 *)(value2 + 0x18);
    value9 = 0x200f;
    goto LAB_00475dd6;
  }
  shortValue2 = 0;
  value7 = 0x200;
  do {
    value3 = RandomModulo(0x400,0x160,0x11);
    value2 = *(int *)(value + 0x18);
    value5 = RandomModulo(0x400);
    value2 = RandomModulo(0x80,(value2 - value3) + value5);
    value3 = RandomModulo(0x400,value2 + 0x80 + *(int *)(value + 0x14));
    value2 = *(int *)(value + 0x10);
    value5 = RandomModulo(0x400);
    value2 = CEntities::SpawnEntityByTypeAtPosition((value2 - value3) + value5);
    if ((value2 != 0) &&
       (value3 = CEntities::FindEntityAttachmentByFlags(value2,0x20000000), value3 != 0)) {
      value5 = RandomModulo(0x1e);
      *(int *)(value3 + 0x40) =
           (int)(short)(&g_SinCosTable12Bit)[value7 - 0x400 & 0xfff] * (value5 + 0x3c) >> 0xc;
      *(int *)(value3 + 0x44) =
           (int)(short)(&g_SinCosTable12Bit)[value7 & 0xfff] * (value5 + 0x3c) >> 0xc;
      shortValue = RandomModulo(0x40);
      *(short *)(value3 + 0x54) = -0x60 - shortValue;
      *(undefined4 *)(*(int *)(value2 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
      *(undefined2 *)(*(int *)(value2 + 0x38) + 0xc) = 0x200d;
      *(undefined2 *)(value3 + 0x56) = 0xff80;
      *(short *)(*(int *)(value2 + 0x38) + 0xa2) = (shortValue2 + 1) * 0x200;
      *(undefined2 *)(*(int *)(value2 + 0x38) + 0xa0) = 0x400;
      value2 = RandomModulo(0x32);
      *(int *)(value3 + 0x18) = value2 + 0x3c;
      *(undefined4 *)(value3 + 0x10) = 0;
    }
    value7 = value7 + 0x200;
    shortValue2 = shortValue2 + 1;
  } while ((int)value7 < 0x2200);
  g_KerchakChaseCameraTrackPaused = 1;
  if (4000 < *(int *)(g_PlayerEntitySceneObject + 0x18)) {
    QueuePlayerDamageEvent(0,0x200);
    g_HudCountdownBcdTime = 0;
    *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0x8001;
    SetHudCountdownDisplay(0,0x8000);
    CEntities::ReleaseEntityAndMarkDescriptorConsumed(entry);
    return;
  }
  *(undefined4 *)(value + 0xc) = 2;
LAB_00476155:
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

