#include "tarzan_ghidra_types.hpp"

// Address: 0x00474440
// Label: KerchakChase::UpdateBreakableObstacleTrigger
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void KerchakChase::UpdateBreakableObstacleTrigger(undefined4 entry)

{
  undefined2 value8;
  int value;
  int value2;
  int value3;
  int value4;
  int value5;
  int value6;
  int *intCursor;
  int value7;
  uint value9;
  undefined4 value10;
  int localState7;
  int localState6;
  int localState5;
  int localState4;
  int localState3;
  undefined1 localState2 [4];
  undefined1 localState [16];
  
  value = CEntities::FindEntityAttachmentByFlags(entry,0x10000000);
  value9 = 0;
  if ((value != 0) &&
     (value2 = CEntities::FindEntityAttachmentByFlags(entry,0x200), value2 != 0)) {
    value3 = *(int *)(value + 0xc);
    if (value3 == 0) {
      value3 = *(int *)(value2 + 0x18);
      *(int *)(value + 0x10) = *(int *)(value3 + 0x20);
      *(undefined4 *)(value + 0x14) = *(undefined4 *)(value3 + 0x24);
      *(undefined4 *)(value + 0x18) = *(undefined4 *)(value3 + 0x28);
      if ((g_KerchakChasePrimaryPursuerEntity != 0) &&
         (value5 = *(int *)(*(int *)(g_KerchakChasePrimaryPursuerEntity + 0x38) + 0x1c) -
                  *(int *)(value + 0x18),
         value3 = *(int *)(*(int *)(g_KerchakChasePrimaryPursuerEntity + 0x38) + 0x14) -
                 *(int *)(value + 0x10), value5 * value5 + value3 * value3 < 0x5b710)) {
        *(undefined4 *)(value + 0xc) = 3;
      }
      value3 = CEntities::GetChildSceneObjectAttachmentList(*(undefined4 *)(value2 + 0x18),&localState4)
      ;
      if ((((value3 != 0) && ((*(uint *)(localState4 + 0xc) & 0xc0000000) == 0)) &&
          ((*(uint *)(localState4 + 0xc) & 0x200) != 0)) &&
         ((value3 = GetEntitySceneObjectAttachmentList(g_PlayerEntitySceneObject,&localState5),
          value3 != 0 && (0 < value3)))) {
        do {
          localState3 = value3;
          if (((*(uint *)(localState5 + 0xc) & 0xc0000000) == 0x80000000) &&
             (((*(uint *)(localState5 + 0xc) & 0x200) != 0 &&
              (value3 = TryComputeOrientedBoxRepelVectorXZ
                                 (g_PlayerEntitySceneObject,localState5,*(undefined4 *)(value2 + 0x18),
                                  localState4,localState2,localState), value3 != 0)))) {
            value3 = RandomModulo(3);
            if (value3 == 0) {
              PlayAudioById(0x366,(int *)0,(undefined4 *)0);
            }
            else {
              if (value3 == 1) {
                value10 = 0x367;
              }
              else {
                if (value3 != 2) goto LAB_00474962;
                value10 = 0x368;
              }
              PlayAudioById(value10,(int *)0,(undefined4 *)0);
            }
LAB_00474962:
            PlayAudioById(800,(int *)0,(undefined4 *)0);
            *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xffffe200;
            _g_CampBoxCameraShakeTimer = 0x20;
            _g_CampBoxCameraShakeAmplitude = 0x10;
            PlayForceFeedbackEffect_Stub(0,2,0xf);
            PlayForceFeedbackEffect_Stub(0,8,8);
            *(undefined4 *)(value + 0xc) = 1;
            value3 = CEntities::SpawnEntityByTypeAtPosition
                              (*(undefined4 *)(value + 0x10),*(int *)(value + 0x14) + -0x100,
                               *(int *)(value + 0x18) + -0x80,0x15e,0x11);
            if (value3 != 0) {
              *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
              *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 19000;
              *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 19000;
              *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 19000;
              *(undefined4 *)(*(int *)(value3 + 0x38) + 0x6c) = 0xffffff80;
            }
            value3 = CEntities::SpawnEntityByTypeAtPosition
                              (*(undefined4 *)(value + 0x10),*(int *)(value + 0x14) + -800,
                               *(int *)(value + 0x18) + -0x80,0x15e,0x11);
            if (value3 != 0) {
              *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
              *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 19000;
              *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 19000;
              *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 19000;
              *(undefined4 *)(*(int *)(value3 + 0x38) + 0x6c) = 0xffffff80;
            }
            value9 = 0;
            localState6 = 0;
            localState7 = 0;
            do {
              value3 = *(int *)(value + 0x18);
              if (localState7 < 0x401) {
                value5 = *(int *)(value + 0x10);
                value7 = *(int *)(value + 0x14) - localState7;
              }
              else {
                value3 = value3 + -0x100;
                value7 = *(int *)(value + 0x14) - localState6;
                value4 = RandomModulo(0x400,value7,value3,0x160,0x11);
                value6 = *(int *)(value + 0x10);
                value5 = RandomModulo(0x400);
                value5 = (value6 - value4) + value5;
              }
              value3 = CEntities::SpawnEntityByTypeAtPosition(value5,value7,value3);
              if ((value3 != 0) &&
                 (value5 = CEntities::FindEntityAttachmentByFlags(value3,0x20000000), value5 != 0
                 )) {
                value6 = (&g_KerchakChaseBreakableObstacleDebrisAngles)[value9 & 3];
                *(short *)(value5 + 0x54) = ((short)value9 + 4) * 0x20;
                if (localState7 < 0x401) {
                  *(int *)(value5 + 0x40) =
                       (short)(&g_SinCosTable12Bit)[value6 - 0x300U & 0xfff] * -100 >> 0xc;
                  *(int *)(value5 + 0x44) =
                       (short)(&g_SinCosTable12Bit)[value6 + 0x100U & 0xfff] * -100 >> 0xc;
                  *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x2005;
                  *(undefined4 *)(*(int *)(value3 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
                  *(short *)(value5 + 0x56) = (short)(value9 << 5);
                  value10 = *(undefined4 *)(value + 0x14);
                  *(undefined4 *)(value5 + 0x18) = 0x50;
                  *(undefined4 *)(value5 + 0x24) = value10;
                }
                else {
                  value6 = RandomModulo(1);
                  *(int *)(value5 + 0x40) =
                       (short)(&g_SinCosTable12Bit)[value6 - 0x280U & 0xfff] * -0x8c >> 0xc;
                  value6 = RandomModulo(1);
                  *(int *)(value5 + 0x44) =
                       (short)(&g_SinCosTable12Bit)[value6 + 0x180U & 0xfff] * -0x8c >> 0xc;
                  *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x2004;
                  *(undefined4 *)(*(int *)(value3 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
                  value8 = RandomModulo(0x1000);
                  *(undefined2 *)(*(int *)(value3 + 0x38) + 0xa2) = value8;
                  *(undefined2 *)(value5 + 0x56) = 0x100;
                  *(undefined2 *)(value5 + 0x54) = 0x100;
                  *(undefined4 *)(*(int *)(value3 + 0x38) + 0x6c) = 0xffffff80;
                  *(undefined4 *)(value5 + 0x24) = *(undefined4 *)(value + 0x14);
                  *(undefined4 *)(value5 + 0x18) = 100;
                }
                *(undefined4 *)(value5 + 0x10) = 0;
              }
              localState7 = localState7 + 0x200;
              value9 = value9 + 1;
              localState6 = localState6 + 0x60;
            } while (localState7 < 0x1000);
            intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                      (*(undefined4 *)(value + 0x10),*(undefined4 *)(value + 0x14),
                                       *(undefined4 *)(value + 0x18),0x178,0x11);
            if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
              *(int *)(intCursor[0xe] + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2ff0;
              *(undefined2 *)(intCursor[0xe] + 0xc) = 0x2035;
              value3 = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
              if (value3 != 0) {
                *(undefined4 *)(value3 + 0x34) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x18);
              }
            }
            DecodeEncodedEntitySceneObjectIdToSourceRef(*(undefined4 *)(value2 + 0x18),0x2006);
          }
          localState5 = localState5 + 0x10;
          localState3 = localState3 + -1;
          value3 = localState3;
        } while (localState3 != 0);
      }
    }
    else if (value3 == 1) {
      *(undefined4 *)(value + 0xc) = 2;
    }
    else if (value3 == 3) {
      _g_CampBoxCameraShakeTimer = 0x20;
      _g_CampBoxCameraShakeAmplitude = 0x10;
      PlayForceFeedbackEffect_Stub(0,2,0xf);
      PlayAudioById(800,(int *)0,(undefined4 *)0);
      *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xffffe200;
      *(undefined4 *)(value + 0xc) = 1;
      value3 = CEntities::SpawnEntityByTypeAtPosition
                        (*(undefined4 *)(value + 0x10),*(int *)(value + 0x14) + -0x100,
                         *(int *)(value + 0x18) + -0x80,0x15e,0x11);
      if (value3 != 0) {
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 19000;
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 19000;
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 19000;
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0x6c) = 0xffffff80;
      }
      value3 = CEntities::SpawnEntityByTypeAtPosition
                        (*(undefined4 *)(value + 0x10),*(int *)(value + 0x14) + -800,
                         *(int *)(value + 0x18) + -0x80,0x15e,0x11);
      if (value3 != 0) {
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb4) = 1;
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xa8) = 19000;
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xac) = 19000;
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0xb0) = 19000;
        *(undefined4 *)(*(int *)(value3 + 0x38) + 0x6c) = 0xffffff80;
      }
      localState6 = 0;
      localState7 = 0;
      do {
        value3 = *(int *)(value + 0x18);
        if (localState7 < 0x401) {
          value5 = *(int *)(value + 0x10);
          value7 = *(int *)(value + 0x14) - localState7;
        }
        else {
          value3 = value3 + -0x100;
          value7 = *(int *)(value + 0x14) - localState6;
          value4 = RandomModulo(0x400,value7,value3,0x160,0x11);
          value6 = *(int *)(value + 0x10);
          value5 = RandomModulo(0x400);
          value5 = (value6 - value4) + value5;
        }
        value3 = CEntities::SpawnEntityByTypeAtPosition(value5,value7,value3);
        if ((value3 != 0) &&
           (value5 = CEntities::FindEntityAttachmentByFlags(value3,0x20000000), value5 != 0)) {
          value6 = (&g_KerchakChaseBreakableObstacleDebrisAngles)[value9 & 3];
          *(short *)(value5 + 0x54) = ((short)value9 + 4) * 0x20;
          if (localState7 < 0x401) {
            *(int *)(value5 + 0x40) =
                 (short)(&g_SinCosTable12Bit)[value6 - 0x300U & 0xfff] * -100 >> 0xc;
            *(int *)(value5 + 0x44) =
                 (short)(&g_SinCosTable12Bit)[value6 + 0x100U & 0xfff] * -100 >> 0xc;
            *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x2005;
            *(undefined4 *)(*(int *)(value3 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
            *(short *)(value5 + 0x56) = (short)(value9 << 5);
            value10 = *(undefined4 *)(value + 0x14);
            *(undefined4 *)(value5 + 0x18) = 0x50;
            *(undefined4 *)(value5 + 0x24) = value10;
          }
          else {
            value6 = RandomModulo(1);
            *(int *)(value5 + 0x40) =
                 (short)(&g_SinCosTable12Bit)[value6 - 0x280U & 0xfff] * -0x8c >> 0xc;
            value6 = RandomModulo(1);
            *(int *)(value5 + 0x44) =
                 (short)(&g_SinCosTable12Bit)[value6 + 0x180U & 0xfff] * -0x8c >> 0xc;
            *(undefined2 *)(*(int *)(value3 + 0x38) + 0xc) = 0x2004;
            *(undefined4 *)(*(int *)(value3 + 0x38) + 0x10) = g_CurrentWorldSceneContext;
            value8 = RandomModulo(0x1000);
            *(undefined2 *)(*(int *)(value3 + 0x38) + 0xa2) = value8;
            *(undefined2 *)(value5 + 0x56) = 0x100;
            *(undefined2 *)(value5 + 0x54) = 0x100;
            *(undefined4 *)(*(int *)(value3 + 0x38) + 0x6c) = 0xffffff80;
            *(undefined4 *)(value5 + 0x24) = *(undefined4 *)(value + 0x14);
            *(undefined4 *)(value5 + 0x18) = 100;
          }
          *(undefined4 *)(value5 + 0x10) = 0;
        }
        localState7 = localState7 + 0x200;
        value9 = value9 + 1;
        localState6 = localState6 + 0x60;
      } while (localState7 < 0x1000);
      intCursor = (int *)CEntities::SpawnEntityByTypeAtPosition
                                (*(undefined4 *)(value + 0x10),*(undefined4 *)(value + 0x14),
                                 *(undefined4 *)(value + 0x18),0x178,0x11);
      if ((intCursor != (int *)0x0) && (*intCursor != 0)) {
        *(int *)(intCursor[0xe] + 0x10) = g_WorldEntitySceneObjectArrayBase + 0x2ff0;
        *(undefined2 *)(intCursor[0xe] + 0xc) = 0x2035;
        value = CEntities::FindEntityAttachmentByFlags(intCursor,0x10000000);
        if (value != 0) {
          *(undefined4 *)(value + 0x34) = *(undefined4 *)(g_PlayerEntitySceneObject + 0x18);
        }
      }
      DecodeEncodedEntitySceneObjectIdToSourceRef(*(undefined4 *)(value2 + 0x18),0x2006);
    }
  }
  KerchakChase::ReleaseIfOutsidePursuerProximity(entry);
  return;
}

