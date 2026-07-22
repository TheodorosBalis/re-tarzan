#include "tarzan_ghidra_types.hpp"

// Address: 0x00474EC0
// Label: KerchakChase::UpdateBreakableTreeBarrier
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void KerchakChase::UpdateBreakableTreeBarrier(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  byte *value6;
  short *value7;
  char resultFlag;
  short shortValue;
  int value2;
  int value3;
  int value4;
  int value5;
  int value;
  undefined *dataCursor2;
  uint value8;
  int *intCursor;
  undefined1 localState3 [4];
  undefined1 localState2 [4];
  int localState6;
  int localState5;
  int localState4;
  undefined1 localState [16];
  
  value2 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value2 != 0) {
    CEntities::CheckAttachmentBoundsOverlapAndPushVector
              (g_PlayerEntitySceneObject,0x200,entity->sceneObjects,0x200,localState3,
               localState);
    value = *(int *)(value2 + 0xc);
    if (value == 0) {
      value3 = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x1c) -
              *(int *)(entity->sceneObjects + 0x1c);
      value = *(int *)(*(int *)(g_PlayerEntity + 0x38) + 0x14) -
               *(int *)(entity->sceneObjects + 0x14);
      if (value3 * value3 + value * value < 9000000) {
        *(undefined4 *)(value2 + 0xc) = 1;
      }
    }
    else if (value == 1) {
      CEntities::MoveEntitySceneObjectAlongFacingWithSpeedRamp
                (entity->sceneObjects,value2 + 0x10,1);
      value7 = (short *)(entity->sceneObjects + 0xa4);
      *value7 = *value7 - *(short *)(value2 + 0x1c);
      if (0x400 < *(short *)(entity->sceneObjects + 0xa4)) {
        *(undefined4 *)(value2 + 0xc) = 2;
        _g_CampBoxCameraShakeTimer = 8;
        _g_CampBoxCameraShakeAmplitude = 0x40;
        PlayForceFeedbackEffect_Stub(0,2,0xf);
        dataCursor2 = &g_KerchakChaseBreakableTreeFragmentOffsets;
        dataCursor = (ushort *)(entity->sceneObjects + 0xe);
        *dataCursor = *dataCursor & 0x7fff;
        intCursor = (int *)(value2 + 0x90);
        do {
          if (*intCursor != 0) {
            value6 = (byte *)(*intCursor + 0xf);
            *value6 = *value6 | 0x80;
            TransformVectorByBasis(entity->sceneObjects + 0xb8,dataCursor2,&localState6);
            *(int *)(*intCursor + 0x14) = *(int *)(entity->sceneObjects + 0x14) - localState6;
            *(int *)(*intCursor + 0x18) = *(int *)(entity->sceneObjects + 0x18) - localState5;
            *(int *)(*intCursor + 0x1c) = *(int *)(entity->sceneObjects + 0x1c) - localState4;
            *(undefined2 *)(*intCursor + 0xa2) = *(undefined2 *)(entity->sceneObjects + 0xa2);
            *(undefined2 *)(*intCursor + 0xa4) = *(undefined2 *)(entity->sceneObjects + 0xa4);
            value2 = *intCursor;
            value2 = CEntities::SpawnEntityByTypeAtPosition
                              (*(undefined4 *)(value2 + 0x14),*(int *)(value2 + 0x18) + -0x80,
                               *(undefined4 *)(value2 + 0x1c),0x15e,0x11);
            if (value2 != 0) {
              *(undefined4 *)(*(int *)(value2 + 0x38) + 0xb4) = 1;
              *(undefined4 *)(*(int *)(value2 + 0x38) + 0xa8) = 12000;
              *(undefined4 *)(*(int *)(value2 + 0x38) + 0xac) = 12000;
              *(undefined4 *)(*(int *)(value2 + 0x38) + 0xb0) = 12000;
              *(undefined4 *)(*(int *)(value2 + 0x38) + 0x6c) = 0xffffff80;
            }
            value2 = *intCursor;
            value2 = CEntities::SpawnEntityByTypeAtPosition
                              (*(undefined4 *)(value2 + 0x14),*(int *)(value2 + 0x18) + -0x80,
                               *(undefined4 *)(value2 + 0x1c),0x15e,0x11);
            if (value2 != 0) {
              *(undefined4 *)(*(int *)(value2 + 0x38) + 0xb4) = 1;
              *(undefined4 *)(*(int *)(value2 + 0x38) + 0xa8) = 12000;
              *(undefined4 *)(*(int *)(value2 + 0x38) + 0xac) = 12000;
              *(undefined4 *)(*(int *)(value2 + 0x38) + 0xb0) = 12000;
              *(undefined4 *)(*(int *)(value2 + 0x38) + 0x6c) = 0xffffff80;
            }
          }
          dataCursor2 = dataCursor2 + 0x10;
          intCursor = intCursor + 1;
        } while ((int)dataCursor2 < 0x50b090);
      }
    }
    else if (value == 2) {
      value = 0;
      do {
        value3 = *(int *)(value2 + 0x90 + value * 4);
        if (value3 != 0) {
          value3 = CEntities::AdvanceBounceMotionAndReturnImpact(value3,value * 0x60 + 0xa0 + value2);
          if (value3 != 0) {
            value3 = *(int *)(value2 + 0x90 + value * 4);
            shortValue = RandomModulo(0x20);
            value7 = (short *)(value3 + 0xa2);
            *value7 = *value7 + shortValue;
            value3 = *(int *)(value2 + 0x20 + value * 4);
            *(int *)(value2 + 0x20 + value * 4) = value3 + 1;
            if (value3 < 2) {
              _g_CampBoxCameraShakeTimer = 8;
              _g_CampBoxCameraShakeAmplitude = 0x10;
              PlayForceFeedbackEffect_Stub(0,2,0xf);
              value3 = *(int *)(value2 + 0x90 + value * 4);
              value3 = CEntities::SpawnEntityByTypeAtPosition
                                (*(undefined4 *)(value3 + 0x14),*(int *)(value3 + 0x18) + -0x80,
                                 *(undefined4 *)(value3 + 0x1c),0x15e,0x11);
              if (value3 != 0) {
                *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
                *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 12000;
                *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 12000;
                *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 12000;
                *(undefined4 *)(*(int *)(value3 + 0x38) + 0x6c) = 0xffffff80;
              }
              value3 = *(int *)(value2 + 0x90 + value * 4);
              value3 = CEntities::SpawnEntityByTypeAtPosition
                                (*(undefined4 *)(value3 + 0x14),*(int *)(value3 + 0x18) + -0x80,
                                 *(undefined4 *)(value3 + 0x1c),0x15e,0x11);
              if (value3 != 0) {
                *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
                *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 12000;
                *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 12000;
                *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 12000;
                *(undefined4 *)(*(int *)(value3 + 0x38) + 0x6c) = 0xffffff80;
              }
            }
            else {
              *(undefined4 *)(value2 + 0xc) = 4;
            }
          }
          value3 = *(int *)(value2 + 0x90 + value * 4);
          if (((*(byte *)(value3 + 0xf) & 0x80) != 0) &&
             (resultFlag = CEntities::CheckAttachmentBoundsOverlapAndPushVector
                                (g_PlayerEntitySceneObject,0x200,value3,0x200,localState2,&localState6),
             resultFlag != '\0')) {
            dataCursor = (ushort *)(*(int *)(value2 + 0x90 + value * 4) + 0xe);
            *dataCursor = *dataCursor & 0x7fff;
            value = *(int *)(value2 + 0x90 + value * 4);
            value = CEntities::SpawnEntityByTypeAtPosition
                               (*(undefined4 *)(value + 0x14),*(int *)(value + 0x18) + -0x80,
                                *(undefined4 *)(value + 0x1c),0x15e,0x11);
            if (value != 0) {
              *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
              *(undefined4 *)(*(int *)(value + 0x38) + 0xa8) = 12000;
              *(undefined4 *)(*(int *)(value + 0x38) + 0xac) = 12000;
              *(undefined4 *)(*(int *)(value + 0x38) + 0xb0) = 12000;
              *(undefined4 *)(*(int *)(value + 0x38) + 0x6c) = 0xffffff80;
            }
            value = 0;
            intCursor = (int *)(value2 + 0x90);
            value8 = 0x200;
            do {
              value3 = *intCursor;
              value3 = CEntities::SpawnEntityByTypeAtPosition
                                (*(undefined4 *)(value3 + 0x14),*(int *)(value3 + 0x18) + -0x80,
                                 *(undefined4 *)(value3 + 0x1c),0x160,0x11);
              if (value3 != 0) {
                *(undefined4 *)(*(int *)(value3 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
                *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x200e;
                value4 = CEntities::FindEntityAttachmentByFlags(value3,0x20000000);
                if (value4 != 0) {
                  value5 = RandomModulo(0x1e);
                  *(int *)(value4 + 0x40) =
                       (int)(short)(&g_SinCosTable12Bit)[value8 - 0x400 & 0xfff] * (value5 + 0x32) >>
                       0xc;
                  *(int *)(value4 + 0x44) =
                       (int)(short)(&g_SinCosTable12Bit)[value8 & 0xfff] * (value5 + 0x32) >> 0xc;
                  shortValue = RandomModulo(0x100);
                  *(short *)(value4 + 0x54) = shortValue + 0x7f;
                  shortValue = RandomModulo(0x100);
                  *(short *)(value4 + 0x56) = shortValue + 0x80;
                  *(short *)(*(int *)(value3 + 0x38) + 0xa2) = ((short)value + 1) * 0x200;
                  *(undefined2 *)(*(int *)(value3 + 0x38) + 0xa0) = 0x400;
                  *(undefined4 *)(value4 + 0x24) = *(undefined4 *)(entity->sceneObjects + 0x18);
                  value3 = RandomModulo(0x32);
                  *(int *)(value4 + 0x18) = value3 + 0x1e;
                  *(undefined4 *)(value4 + 0x10) = 0;
                }
              }
              value8 = value8 + 0x200;
              value = value + 1;
              intCursor = intCursor + 1;
            } while ((int)value8 < 0xa00);
          }
        }
        value = value + 1;
      } while (value < 4);
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(entry);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)entry);
  }
  return;
}

