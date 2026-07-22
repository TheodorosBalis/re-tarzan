#include "tarzan_ghidra_types.hpp"

// Address: 0x00465FA0
// Label: TarzanToTheRescue::UpdateBoxInElephantRide
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TarzanToTheRescue::UpdateBoxInElephantRide(uint entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  int value;
  char resultFlag;
  short shortValue;
  int value2;
  int *intCursor;
  int value3;
  int value4;
  int value5;
  uint value6;
  uint value7;
  bool flagByte;
  undefined4 value8;
  undefined1 localState2 [4];
  undefined1 localState [16];
  
  value = entry;
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if ((value2 != 0) && (g_AdultTarzanElephantEntitySceneObject != 0)) {
    if (*(int *)(value2 + 0xc) == 0) {
      resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                        (g_AdultTarzanElephantEntitySceneObject,0x100,
                         entity->sceneObjects,0x100,localState2,localState);
      if (resultFlag != '\0') {
        value3 = RandomModulo(2);
        *(undefined4 *)(value2 + 0xc) = 1;
        if (value3 == 0) {
          value2 = entity->sceneObjects;
          value8 = 0x3b7;
        }
        else {
          if (value3 != 1) goto LAB_004664d9;
          value2 = entity->sceneObjects;
          value8 = 0x3b8;
        }
        PlayAudioById(value8,(int *)&((EntitySceneObject *)value2)->soundPosition,(undefined4 *)&((EntitySceneObject *)value2)->x);
      }
    }
    else if (*(int *)(value2 + 0xc) == 1) {
      dataCursor = (ushort *)(entity->sceneObjects + 0xe);
      *dataCursor = *dataCursor & 0x7fff;
      _g_CampBoxCameraShakeTimer = 0x10;
      _g_CampBoxCameraShakeAmplitude = 0x14;
      PlayForceFeedbackEffect_Stub(0,2,0xf);
      g_ExtraLifeMeterProgress = g_ExtraLifeMeterProgress + 1;
      if (((EntitySceneObject *)value2)->worldObject == 0) {
        value3 = entity->sceneObjects;
        intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                  (((EntitySceneObject *)value3)->x + -0x80,((EntitySceneObject *)value3)->y + -0x80,
                                   ((EntitySceneObject *)value3)->z,0x178,0x11);
        if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
          *(undefined2 *)(intCursor[0xe] + 0xc) = 0x2017;
        }
        value3 = entity->sceneObjects;
        value3 = CEntities::SpawnEntityByTypeAtPosition
                          (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y + -0x180,
                           ((EntitySceneObject *)value3)->z + -0x20,0x14,0x11);
        if (value3 != 0) {
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 11000;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 11000;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 11000;
        }
        value3 = entity->sceneObjects;
        value3 = CEntities::SpawnEntityByTypeAtPosition
                          (((EntitySceneObject *)value3)->x + 0x80,((EntitySceneObject *)value3)->y + -0x180,
                           ((EntitySceneObject *)value3)->z + -0x20,0x14,0x11);
        if (value3 != 0) {
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 11000;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 11000;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 11000;
        }
        entry = 0;
        value7 = 0x200;
        do {
          value4 = RandomModulo(0x200,*(undefined4 *)(*(int *)(value + 0x38) + 0x1c),0x160,0x11);
          value3 = *(int *)(*(int *)(value + 0x38) + 0x18);
          value5 = RandomModulo(0x200);
          value4 = RandomModulo(0x200,(value3 - value4) + -0x100 + value5);
          value3 = *(int *)(*(int *)(value + 0x38) + 0x14);
          value5 = RandomModulo(0x200);
          value3 = CEntities::SpawnEntityByTypeAtPosition((value3 - value4) + value5);
          if ((value3 != 0) &&
             (value4 = CEntities::FindEntityAttachmentByFlags(value3,0x20000000), value4 != 0)) {
            value5 = RandomModulo(0x1e);
            *(int *)(value4 + 0x40) =
                 (int)(short)(&g_SinCosTable12Bit)[value7 - 0x400 & 0xfff] * (value5 + 0x32) >> 0xc;
            *(int *)(value4 + 0x44) =
                 (int)(short)(&g_SinCosTable12Bit)[value7 & 0xfff] * (value5 + 0x32) >> 0xc;
            shortValue = RandomModulo(0x40);
            *(short *)(value4 + 0x54) = -0x60 - shortValue;
            if (g_AdultTarzanElephantEntitySceneObject != 0) {
              *(undefined4 *)(value4 + 0x24) = *(undefined4 *)(*(int *)(value + 0x38) + 0x18);
            }
            value6 = entry & 0x80000001;
            flagByte = value6 == 0;
            if ((int)value6 < 0) {
              flagByte = (value6 - 1 | 0xfffffffe) == 0xffffffff;
            }
            if (!flagByte) {
              *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x2018;
            }
            *(undefined2 *)(value4 + 0x56) = 0xff80;
            *(short *)(*(int *)(value3 + 0x38) + 0xa2) = ((short)entry + 1) * 0x200;
            *(undefined2 *)(*(int *)(value3 + 0x38) + 0xa0) = 0x400;
            value3 = RandomModulo(0x32);
            *(int *)(value4 + 0x18) = value3 + 0x1e;
            *(undefined4 *)(value4 + 0x10) = 0;
          }
          value7 = value7 + 0x200;
          entry = entry + 1;
        } while ((int)value7 < 0x1200);
      }
      if (((EntitySceneObject *)value2)->worldObject == 1) {
        value3 = *(int *)(value + 0x38);
        intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                  (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y + -0x80,
                                   ((EntitySceneObject *)value3)->z,0x178,0x11);
        if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
          *(undefined2 *)(intCursor[0xe] + 0xc) = 0x2017;
        }
        value3 = *(int *)(value + 0x38);
        CEntities::SpawnEntityByTypeAtPosition
                  (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y,
                   ((EntitySceneObject *)value3)->z,0x178,0x11);
        value3 = *(int *)(value + 0x38);
        value3 = CEntities::SpawnEntityByTypeAtPosition
                          (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y + -0x180,
                           ((EntitySceneObject *)value3)->z + -0x20,0x14,0x11);
        if (value3 != 0) {
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 11000;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 11000;
          *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 11000;
        }
        entry = 0;
        value7 = 0;
        do {
          value3 = *(int *)(value + 0x38);
          value3 = CEntities::SpawnEntityByTypeAtPosition
                            (((EntitySceneObject *)value3)->x,((EntitySceneObject *)value3)->y + -0x100,
                             ((EntitySceneObject *)value3)->z,0x160,0x11);
          if ((value3 != 0) &&
             (value4 = CEntities::FindEntityAttachmentByFlags(value3,0x20000000), value4 != 0)) {
            value5 = RandomModulo(0x1e);
            *(int *)(value4 + 0x40) =
                 (int)(short)(&g_SinCosTable12Bit)[value7 & 0xfff] * (value5 + 0x32) >> 0xc;
            *(int *)(value4 + 0x44) =
                 (int)(short)(&g_SinCosTable12Bit)[value7 + 0x400 & 0xfff] * (value5 + 0x32) >> 0xc;
            shortValue = RandomModulo(0x40);
            *(short *)(value4 + 0x54) = -0x60 - shortValue;
            *(undefined4 *)(value4 + 0x24) =
                 *(undefined4 *)(g_AdultTarzanElephantEntitySceneObject + 0x18);
            value6 = entry & 0x80000001;
            flagByte = value6 == 0;
            if ((int)value6 < 0) {
              flagByte = (value6 - 1 | 0xfffffffe) == 0xffffffff;
            }
            if (!flagByte) {
              *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x2018;
            }
            *(undefined2 *)(value4 + 0x56) = 0xff80;
            *(short *)(*(int *)(value3 + 0x38) + 0xa2) = ((short)entry + 1) * 0x400;
            *(undefined2 *)(*(int *)(value3 + 0x38) + 0xa0) = 0x400;
            value3 = RandomModulo(0x32);
            *(int *)(value4 + 0x18) = value3 + 0x1e;
            *(undefined4 *)(value4 + 0x10) = 0;
          }
          value7 = value7 + 0x400;
          entry = entry + 1;
        } while ((int)value7 < 0x1000);
      }
      *(undefined4 *)(value2 + 0xc) = 2;
    }
  }
LAB_004664d9:
  resultFlag = IsEntityOutsideOuterActivationBounds(value);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value);
  }
  return;
}

