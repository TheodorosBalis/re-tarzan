#include "tarzan_ghidra_types.hpp"

// Address: 0x00463490
// Label: TarzanToTheRescue::UpdateSwingingDestructibleObject
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TarzanToTheRescue::UpdateSwingingDestructibleObject(int entry)

{
  ushort *dataCursor;
  int value;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  int value4;
  short shortValue2;
  uint value6;
  undefined4 value5;
  undefined1 localState [16];
  
  value = entry;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  entry = value2;
  if (value2 != 0) {
    if (*(int *)(value2 + 0xc) == 0) {
      *(short *)(*(int *)(value + 0x38) + 0xa4) =
           (short)((int)(short)(&g_SinCosTable12Bit)[*(int *)(value2 + 0x18) - 0x400U & 0xfff] *
                   *(int *)(value2 + 0x10) >> 0xc);
      *(short *)(*(int *)(value + 0x38) + 0xa2) =
           (short)(((int)(short)(&g_SinCosTable12Bit)[*(int *)(value2 + 0x18) - 0x400U & 0xfff] << 7)
                  >> 0xc);
      if (*(short *)(*(int *)(value + 0x38) + 0xa4) == 0) {
        PlayAudioById(0x388,0,*(int *)(value + 0x38) + 0x14);
      }
      *(uint *)(value2 + 0x18) = *(int *)(value2 + 0x14) + *(int *)(value2 + 0x18) & 0xfff;
      if ((g_AdultTarzanElephantEntitySceneObject != 0) &&
         (resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                            (g_AdultTarzanElephantEntitySceneObject,0x100,
                             *(undefined4 *)(value + 0x38),0x100,&entry,localState), resultFlag != '\0'
         )) {
        value3 = RandomModulo(2);
        *(undefined4 *)(value2 + 0xc) = 1;
        if (value3 == 0) {
          value2 = *(int *)(value + 0x38);
          value5 = 0x3b9;
        }
        else {
          if (value3 != 1) goto LAB_00463791;
          value2 = *(int *)(value + 0x38);
          value5 = 0x3ba;
        }
        PlayAudioById(value5,(int *)value2 + 0x104,(undefined4 *)value2 + 0x14);
      }
    }
    else if (*(int *)(value2 + 0xc) == 1) {
      dataCursor = (ushort *)(*(int *)(value + 0x38) + 0xe);
      *dataCursor = *dataCursor & 0x7fff;
      _g_CampBoxCameraShakeTimer = 0x10;
      _g_CampBoxCameraShakeAmplitude = 0x14;
      PlayForceFeedbackEffect_Stub(0,2,0xf);
      g_ExtraLifeMeterProgress = g_ExtraLifeMeterProgress + 1;
      value3 = *(int *)(value + 0x38);
      CEntities::SpawnEntityByTypeAtPosition
                (*(undefined4 *)(value3 + 0x14),*(int *)(value3 + 0x18) + 0x4b0,
                 *(undefined4 *)(value3 + 0x1c),0x178,0x11);
      value3 = *(int *)(value + 0x38);
      value3 = CEntities::SpawnEntityByTypeAtPosition
                        (*(undefined4 *)(value3 + 0x14),*(int *)(value3 + 0x18) + 0x4b0,
                         *(int *)(value3 + 0x1c) + -0x20,0x14,0x11);
      if (value3 != 0) {
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 11000;
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 11000;
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 11000;
      }
      shortValue2 = 0;
      value6 = 0x200;
      do {
        value3 = *(int *)(value + 0x38);
        value3 = CEntities::SpawnEntityByTypeAtPosition
                          (*(undefined4 *)(value3 + 0x14),*(int *)(value3 + 0x18) + 0x4b0,
                           *(undefined4 *)(value3 + 0x1c),0x160,0x11);
        if (value3 != 0) {
          *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x2019;
          value4 = CEntities::FindEntityAttachmentByFlags(value3,0x20000000);
          value2 = entry;
          if (value4 != 0) {
            value2 = RandomModulo(0x1e);
            *(int *)(value4 + 0x40) =
                 (int)(short)(&g_SinCosTable12Bit)[value6 - 0x400 & 0xfff] * (value2 + 0x32) >> 0xc;
            *(int *)(value4 + 0x44) =
                 (int)(short)(&g_SinCosTable12Bit)[value6 & 0xfff] * (value2 + 0x32) >> 0xc;
            shortValue = RandomModulo(0x40);
            *(undefined2 *)(value4 + 0x56) = 0xff80;
            *(short *)(value4 + 0x54) = -0x60 - shortValue;
            *(short *)(*(int *)(value3 + 0x38) + 0xa2) = shortValue2 * 0x400 + 0x200;
            *(undefined2 *)(*(int *)(value3 + 0x38) + 0xa0) = 0x400;
            value2 = RandomModulo(0x14);
            *(undefined4 *)(value4 + 0x10) = 0;
            *(int *)(value4 + 0x18) = value2 + 0x32;
            value2 = entry;
            if (g_AdultTarzanElephantEntitySceneObject != 0) {
              *(undefined4 *)(value4 + 0x24) =
                   *(undefined4 *)(g_AdultTarzanElephantEntitySceneObject + 0x18);
            }
          }
        }
        value6 = value6 + 0x400;
        shortValue2 = shortValue2 + 1;
      } while ((int)value6 < 0x1200);
      *(undefined4 *)(value2 + 0xc) = 2;
    }
  }
LAB_00463791:
  resultFlag = IsEntityOutsideOuterActivationBounds(value);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value);
  }
  return;
}

