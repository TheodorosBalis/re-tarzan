#include "tarzan_ghidra_types.hpp"

// Address: 0x00457740
// Label: Stampede::UpdateTreeFragmentImpactObstacle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void Stampede::UpdateTreeFragmentImpactObstacle(int entry)

{
  Entity *entity = (Entity *)entry;
  ushort *dataCursor;
  byte *value7;
  short *value8;
  short shortValue;
  undefined4 value11;
  undefined4 value12;
  int value5;
  char resultFlag;
  int value6;
  uint value9;
  uint value10;
  int value;
  int value2;
  int *intCursor;
  int value3;
  int value4;
  int localState;
  undefined4 localState4;
  int localState3;
  int localState2;
  
  value5 = entry;
  value6 = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  if (value6 != 0) {
    switch(*(undefined4 *)(value6 + 0xc)) {
    case 0:
      if (g_StampedeElephantsEntity != 0) {
        value = entity->sceneObjects;
        localState4 = ((EntitySceneObject *)value)->x;
        localState3 = ((EntitySceneObject *)value)->y;
        localState2 = ((EntitySceneObject *)value)->z + 1000;
        value = CEntities::IsPointMostlyPositiveXFromReference
                           (&localState4,g_PlayerEntitySceneObject + 0x14);
        if (value != 0) {
          value = *(int *)(value6 + 0x70);
          *(undefined4 *)(value6 + 0xc) = 2;
          value4 = *(int *)(g_StampedeElephantsEntity + 0x38);
          ((EntitySceneObject *)value)->x = *(undefined4 *)(value4 + 0x14);
          ((EntitySceneObject *)value)->y = *(undefined4 *)(value4 + 0x18);
          ((EntitySceneObject *)value)->z = *(undefined4 *)(value4 + 0x1c);
          value7 = (byte *)(*(int *)(value6 + 0x70) + 0xf);
          *value7 = *value7 | 0x80;
        }
      }
      break;
    case 1:
      value = *(int *)(entity->sceneObjects + 0x1c) - g_StampedeCameraTargetZ;
      value4 = *(int *)(entity->sceneObjects + 0x14) - g_StampedeCameraTargetX;
      value9 = GetAngleFromXZVector12Bit(value4,value);
      value9 = value9 & 0xfff;
      value10 = GetAngleFromXZVector12Bit(value4,value);
      *(undefined2 *)(entity->sceneObjects + 0xc) = 0x2006;
      *(uint *)(value6 + 0x88) = value9;
      localState = 0;
      do {
        if (localState == 0) {
          value = entity->sceneObjects;
          value = CEntities::SpawnEntityByTypeAtPosition
                             (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + -0x2d4,
                              ((EntitySceneObject *)value)->z,0x160,0x11);
          *(int *)(value6 + 0x80) = value;
joined_r0x00457948:
          if (value != 0) {
            value7 = (byte *)(*(int *)(value + 0x38) + 0xf);
            *value7 = *value7 | 8;
            if (localState == 0) {
              *(undefined4 *)(*(int *)(value + 0x38) + 0x10) = g_CurrentWorldSceneContext;
              *(undefined2 *)(*(int *)(value + 0x38) + 0xc) = 0x2004;
              value = CEntities::FindEntityAttachmentByFlags(value,0x20000000);
              if (value != 0) {
                *(int *)(value + 0x40) =
                     (short)(&g_SinCosTable12Bit)[value9 - 0x3c4 & 0xfff] * -0x82 >> 0xc;
                shortValue = (&g_SinCosTable12Bit)[value9 + 0x3c & 0xfff];
                *(undefined2 *)(value + 0x54) = 0xff96;
                *(undefined2 *)(value + 0x56) = 0xff76;
                *(int *)(value + 0x44) = shortValue * -0x82 >> 0xc;
LAB_00457a64:
                *(undefined4 *)(value + 0x24) = *(undefined4 *)(entity->sceneObjects + 0x18);
                *(undefined4 *)(value + 0x2c) = 1;
                ((EntitySceneObject *)value)->y = 0x1a;
                ((EntitySceneObject *)value)->worldObject = 0;
              }
            }
            else if (localState == 1) {
              *(undefined4 *)(*(int *)(value + 0x38) + 0x10) = g_CurrentWorldSceneContext;
              *(undefined2 *)(*(int *)(value + 0x38) + 0xc) = 0x2005;
              value = CEntities::FindEntityAttachmentByFlags(value,0x20000000);
              if (value != 0) {
                *(int *)(value + 0x40) =
                     (short)(&g_SinCosTable12Bit)[(value10 & 0xfff) - 0x43c & 0xfff] * -0x7f >> 0xc;
                shortValue = (&g_SinCosTable12Bit)[(value10 & 0xfff) - 0x3c & 0xfff];
                *(undefined2 *)(value + 0x54) = 0x8a;
                *(undefined2 *)(value + 0x56) = 0x6a;
                *(int *)(value + 0x44) = shortValue * -0x7f >> 0xc;
                goto LAB_00457a64;
              }
            }
          }
        }
        else if (localState == 1) {
          value = entity->sceneObjects;
          value = CEntities::SpawnEntityByTypeAtPosition
                             (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + -0x1b6,
                              ((EntitySceneObject *)value)->z,0x160,0x11);
          *(int *)(value6 + 0x84) = value;
          goto joined_r0x00457948;
        }
        localState = localState + 1;
      } while (localState < 2);
      value = entity->sceneObjects;
      value = CEntities::SpawnEntityByTypeAtPosition
                         (((EntitySceneObject *)value)->x,((EntitySceneObject *)value)->y + -0x1b6,
                          ((EntitySceneObject *)value)->z,0x15e,0x11);
      if (value != 0) {
        *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
        *(undefined4 *)(*(int *)(value + 0x38) + 0xa8) = 0x4c2c;
        *(undefined4 *)(*(int *)(value + 0x38) + 0xac) = 0x4c2c;
        *(undefined4 *)(*(int *)(value + 0x38) + 0xb0) = 0x4c2c;
        *(undefined4 *)(*(int *)(value + 0x38) + 0x6c) = 0xffffff80;
      }
      _g_CampBoxCameraShakeTimer = 4;
      _g_CampBoxCameraShakeAmplitude = 0x48;
      PlayForceFeedbackEffect_Stub(0,2,0xf);
      *(undefined4 *)(value6 + 0xc) = 3;
      break;
    case 2:
      if (g_StampedeElephantsEntity != 0) {
        CEntities::AdvanceEntitySceneObjectParabolicArc
                  (*(int *)(g_StampedeElephantsEntity + 0x38) + 0x14,value6 + 0x74,value6 + 0x10
                   ,*(int *)(value6 + 0x70) + 0x14);
      }
      value = *(int *)(value6 + 0x70);
      value2 = ((EntitySceneObject *)value)->x - *(int *)(value6 + 0x74);
      value4 = *(int *)(value6 + 0x7c);
      value3 = ((EntitySceneObject *)value)->y - *(int *)(value6 + 0x78);
      ((EntitySceneObject *)value)->yaw = ((EntitySceneObject *)value)->yaw + 0x100;
      value4 = ((EntitySceneObject *)value)->z - value4;
      value8 = (short *)(*(int *)(value6 + 0x70) + 0xa0);
      *value8 = *value8 + 0x20;
      if (value4 * value4 + value3 * value3 + value2 * value2 < 0x4000) {
        *(undefined4 *)(value6 + 0xc) = 1;
        dataCursor = (ushort *)(*(int *)(value6 + 0x70) + 0xe);
        *dataCursor = *dataCursor & 0x7fff;
      }
      break;
    case 3:
      if ((*(int *)(value6 + 0x84) != 0) &&
         (value = CEntities::FindEntityAttachmentByFlags(*(int *)(value6 + 0x84),0x20000000),
         value != 0)) {
        value4 = *(int *)(*(int *)(value6 + 0x84) + 0x38);
        value11 = *(undefined4 *)(value4 + 0x14);
        localState3 = *(int *)(value4 + 0x18);
        localState2 = *(int *)(value4 + 0x1c);
        if (*(int *)(value + 0x5c) == 0x10) {
          entry = 0;
          do {
            if (entry == 0) {
              value2 = CEntities::SpawnEntityByTypeAtPosition(value11,localState3,localState2,0x160,0x11);
              value4 = *(int *)(value6 + 0x88);
              if (value2 != 0) {
                *(undefined2 *)(*(int *)(value2 + 0x38) + 0xa0) =
                     *(undefined2 *)(*(int *)(*(int *)(value6 + 0x84) + 0x38) + 0xa0);
                *(undefined2 *)(*(int *)(value2 + 0x38) + 0xa2) =
                     *(undefined2 *)(*(int *)(*(int *)(value6 + 0x84) + 0x38) + 0xa2);
                *(undefined2 *)(*(int *)(value2 + 0x38) + 0xa4) =
                     *(undefined2 *)(*(int *)(*(int *)(value6 + 0x84) + 0x38) + 0xa4);
                value7 = (byte *)(*(int *)(value2 + 0x38) + 0xf);
                *value7 = *value7 | 8;
                *(undefined4 *)(*(int *)(value2 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
                *(undefined2 *)(*(int *)(value2 + 0x38) + 0xc) = 0x200b;
                value2 = CEntities::FindEntityAttachmentByFlags(value2,0x20000000);
                if (value2 != 0) {
                  *(int *)(value2 + 0x40) =
                       (short)(&g_SinCosTable12Bit)[value4 - 0x480U & 0xfff] * -0x84 >> 0xc;
                  shortValue = (&g_SinCosTable12Bit)[value4 - 0x80U & 0xfff];
                  *(undefined2 *)(value2 + 0x54) = 0x10;
                  *(undefined2 *)(value2 + 0x56) = 0xa0;
                  *(int *)(value2 + 0x44) = shortValue * -0x84 >> 0xc;
                  *(undefined4 *)(value2 + 0x24) = *(undefined4 *)(*(int *)(value5 + 0x38) + 0x18);
                  *(undefined4 *)(value2 + 0x2c) = 1;
                  value12 = *(undefined4 *)(value + 0x20);
                  *(undefined4 *)(value2 + 0x10) = 0;
                  *(undefined4 *)(value2 + 0x18) = value12;
                }
              }
            }
            entry = entry + 1;
          } while (entry < 2);
          value = CEntities::SpawnEntityByTypeAtPosition(value11,localState3,localState2,0x15e,0x11);
          if (value != 0) {
            *(undefined4 *)(*(int *)(value + 0x38) + 0xb4) = 1;
            *(undefined4 *)(*(int *)(value + 0x38) + 0xa8) = 0x4c2c;
            *(undefined4 *)(*(int *)(value + 0x38) + 0xac) = 0x4c2c;
            *(undefined4 *)(*(int *)(value + 0x38) + 0xb0) = 0x4c2c;
            *(undefined4 *)(*(int *)(value + 0x38) + 0x6c) = 0xffffff80;
          }
          intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                     (value11,localState3 + 0x180,localState2 + -0x100,0x178,0x11);
          if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
            *(int *)(intCursor[0xe] + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x30c0;
            *(undefined2 *)(intCursor[0xe] + 0xc) = 0x2054;
            *(undefined4 *)(intCursor[0xe] + 0x6c) = 0xffffff80;
            value = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
            if (value != 0) {
              value4 = *(int *)(*(int *)(value5 + 0x38) + 0x18);
              *(undefined4 *)(value + 0x524) = 0x100;
              ((EntitySceneObject *)value)->next = value4 + 0x200;
            }
          }
          _g_CampBoxCameraShakeTimer = 4;
          _g_CampBoxCameraShakeAmplitude = 0x48;
          PlayForceFeedbackEffect_Stub(0,2,0xf);
          CEntities::ReleaseEntityAndMarkDescriptorConsumed(*(undefined4 *)(value6 + 0x84));
        }
      }
    }
  }
  resultFlag = IsEntityOutsideOuterActivationBounds(value5);
  if (resultFlag != '\0') {
    CEntities::ReleaseEntityToFreeList((byte *)value5);
  }
  return;
}

