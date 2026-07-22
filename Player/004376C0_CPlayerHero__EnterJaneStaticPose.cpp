#include "tarzan_ghidra_types.hpp"

// Address: 0x004376C0
// Label: CPlayerHero::EnterJaneStaticPose
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint CPlayerHero::EnterJaneStaticPose(void)

{
  ushort *dataCursor;
  short shortValue;
  ushort value4;
  ushort value5;
  int value;
  int value2;
  int value3;
  uint value6;
  undefined4 *dataCursor2;
  
  g_PlayerCurrentAnimationId = 1;
  *(undefined4 *)(g_PlayerAnimationState + 0xc) = _g_JaneStaticPoseAnimationScriptPtr;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  value6 = 0;
  *(short *)(g_PlayerAnimationState + 0x14) = *(short *)(g_PlayerAnimationState + 0x14) + -1;
  if (*(short *)(g_PlayerAnimationState + 0x14) < 0) {
    if ((*(byte *)(g_PlayerAnimationState + 0x1f) & 1) == 0) {
      do {
        *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(g_PlayerAnimationState + 0x16) + 1;
        value3 = g_PlayerEntitySceneObject;
        value2 = (int)*(short *)(g_PlayerAnimationState + 0x16);
        value = *(int *)(g_PlayerAnimationState + 0xc);
        value4 = *(ushort *)(value + value2 * 4);
        if ((value4 & 0x8000) == 0) break;
        switch(value4) {
        case 0x8000:
          *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(value + 2 + value2 * 4) + -1;
          if (value6 == 0) {
            value6 = 2;
          }
          break;
        case 0x8001:
          *(int *)(g_PlayerAnimationState + 0xc) = value + 4 + value2 * 4;
          *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
          break;
        case 0x8002:
          return (uint)*(ushort *)
                        (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                        *(short *)(g_PlayerAnimationState + 0x16) * 4);
        case 0x8003:
          value6 = (uint)*(ushort *)(value + 2 + value2 * 4);
          break;
        case 0x8004:
          SetPlayerActionState
                    (*(undefined2 *)
                      (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                      *(short *)(g_PlayerAnimationState + 0x16) * 4));
          return value6;
        case 0x8005:
          value6 = CPlayerHero::PlayHeroModeAnimation
                            (*(undefined2 *)
                              (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                              *(short *)(g_PlayerAnimationState + 0x16) * 4));
          return value6;
        case 0x8006:
          value5 = *(ushort *)(value + 2 + value2 * 4);
          if (value5 == 0x8000) {
            *(undefined4 *)(g_PlayerEntitySceneObjectData + 2) = g_CurrentWorldSceneContext;
          }
          else {
            *(uint *)(g_PlayerEntitySceneObjectData + 2) =
                 g_WorldEntitySceneObjectArrayBase + (uint)value5 * 0x68;
          }
          break;
        case 0x8007:
          g_PlayerJumpArcActive = 1;
          if (*(int *)(g_PlayerEntitySceneObject + 0x60) != 0) {
            *(undefined4 *)(*(int *)(g_PlayerEntitySceneObject + 0x60) + 0x60) = 0;
          }
          *(undefined4 *)(value3 + 0x60) = 0;
          break;
        case 0x8008:
          g_PlayerTiltControlEnabled = *(short *)(value + 2 + value2 * 4) != 0;
          break;
        case 0x8009:
          value3 = g_PlayerEntitySceneObject + 0x14;
          goto LAB_0043370c;
        case 0x800a:
          PlayAudioById(*(undefined2 *)(value + 2 + value2 * 4),(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
          break;
        case 0x800b:
          value3 = g_PlayerEntitySceneObject + 0x14;
          dataCursor2 = &g_PlayerLoopingSoundHandle;
          goto LAB_0043370d;
        case 0x800c:
          DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
          break;
        case 0x800d:
          value3 = 0;
LAB_0043370c:
          dataCursor2 = (undefined4 *)0x0;
LAB_0043370d:
          PlayAudioById(*(undefined2 *)(value + 2 + value2 * 4),(int *)dataCursor2,(undefined4 *)value3);
          break;
        case 0x800e:
          *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75)
          ;
          *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
               *(ushort *)(g_PlayerEntitySceneObject + 0xa2) ^ 0x800;
          break;
        case 0x800f:
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 4;
          break;
        case 0x8010:
          if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 4) == 0) {
            *(undefined2 *)(g_PlayerEntitySceneObject + 0x76) =
                 *(undefined2 *)(value + 2 + value2 * 4);
          }
          else {
            *g_PlayerEntitySceneObjectData = *(ushort *)(value + 2 + value2 * 4);
          }
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 1;
          break;
        case 0x8011:
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = *(undefined2 *)(value + 2 + value2 * 4)
          ;
          break;
        case 0x8012:
          if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 4) == 0) {
            *(undefined2 *)(g_PlayerEntitySceneObject + 0x76) =
                 *(undefined2 *)(value + 2 + value2 * 4);
          }
          else {
            *g_PlayerEntitySceneObjectData = *(ushort *)(value + 2 + value2 * 4);
          }
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 0x82
          ;
          break;
        case 0x8013:
          *(short *)(g_PlayerAnimationState + 0x1c) =
               (short)(0x100 / (ulonglong)(longlong)(int)(*(ushort *)(value + 2 + value2 * 4) + 1));
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 2;
          break;
        case 0x8014:
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
          *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
          break;
        case 0x8015:
          CPlayerHero::MoveToAnimationAttachmentWithCollision();
          if (value6 == 0) {
            value6 = 0xe;
          }
          break;
        case 0x8016:
          value5 = *(ushort *)(value + 2 + value2 * 4);
          *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 6;
          *(ushort *)(g_PlayerEntitySceneObject + 0x76) = *g_PlayerEntitySceneObjectData;
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
          *(short *)(g_PlayerAnimationState + 0x1c) =
               (short)(0x100 / (ulonglong)(longlong)(int)(value5 + 1));
          break;
        case 0x8017:
          g_PlayerAnimationSurfaceSide = *(undefined1 *)(value + 2 + value2 * 4);
          break;
        case 0x8018:
          value6 = 0xf;
          *(byte *)(g_PlayerAnimationState + 0x1f) = *(byte *)(g_PlayerAnimationState + 0x1f) | 1;
          break;
        case 0x8019:
          g_PlayerEntitySceneObjectData[1] = g_PlayerEntitySceneObjectData[1] ^ 2;
          break;
        case 0x801a:
          g_PlayerEntitySceneObjectData[1] = g_PlayerEntitySceneObjectData[1] ^ 4;
          break;
        case 0x801b:
          g_PlayerEntitySceneObjectData[1] = g_PlayerEntitySceneObjectData[1] ^ 8;
          break;
        case 0x801c:
          g_PlayerEntitySceneObjectData[1] = g_PlayerEntitySceneObjectData[1] & 0xfff1;
          break;
        case 0x801d:
          if (*(int *)(g_PlayerEntitySceneObject + 0x60) != 0) {
            dataCursor = (ushort *)(*(int *)(*(int *)(g_PlayerEntitySceneObject + 0x60) + -4) + 0x42);
            *dataCursor = *dataCursor | *(ushort *)(value + 2 + value2 * 4);
          }
          if (g_PlayerTriggeredCollisionEntry != 0) {
            *(ushort *)(g_PlayerTriggeredCollisionEntry + 0x42) =
                 *(ushort *)(g_PlayerTriggeredCollisionEntry + 0x42) |
                 *(ushort *)
                  (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                  *(short *)(g_PlayerAnimationState + 0x16) * 4);
          }
          break;
        case 0x801e:
          *(uint *)(g_PlayerEntitySceneObject + 0x70) = (uint)*(ushort *)(value + 2 + value2 * 4);
          break;
        case 0x801f:
          CPlayerHero::RefreshPowerFruitDrawWindow();
          break;
        case 0x8020:
          CPlayerHero::ClearPowerFruitDrawWindow();
          break;
        case 0x8021:
          value3 = (uint)*(ushort *)(value + 2 + value2 * 4) * 4;
          PlayForceFeedbackEffect_Stub
                    (0,*(undefined2 *)(&g_PlayerForceFeedbackEffectTable + value3),
                     CONCAT31((int3)((uint)value >> 8),
                              (&g_PlayerForceFeedbackEffectParamByte)[value3]));
          break;
        case 0x8022:
          CPlayerHero::UpdateAnimationEffectEntitySceneObject
                    (CONCAT22(*(short *)(g_PlayerAnimationState + 0x16) >> 0xf,
                              *(undefined2 *)(value + 2 + value2 * 4)));
          break;
        case 0x8023:
          QueuePlayerDamageEvent(0,0x200);
        }
      } while ((value4 & 0x8000) != 0);
      if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 4) == 0) {
        *g_PlayerEntitySceneObjectData = value4;
      }
      else {
        *(ushort *)(g_PlayerEntitySceneObject + 0x76) = value4;
      }
      *(undefined2 *)(g_PlayerAnimationState + 0x14) =
           *(undefined2 *)
            (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
            *(short *)(g_PlayerAnimationState + 0x16) * 4);
      if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 0x80) != 0) {
        *(short *)(g_PlayerAnimationState + 0x1c) =
             (short)(0x100 / (longlong)(*(short *)(g_PlayerAnimationState + 0x14) + 2));
      }
    }
    else {
      *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(g_PlayerAnimationState + 0x16) + -1;
      shortValue = *(short *)(g_PlayerAnimationState + 0x16);
      while (-1 < shortValue) {
        value4 = *(ushort *)(*(int *)(g_PlayerAnimationState + 0xc) + shortValue * 4);
        if ((value4 & 0x8000) == 0) {
          *g_PlayerEntitySceneObjectData = value4;
          *(undefined2 *)(g_PlayerAnimationState + 0x14) =
               *(undefined2 *)
                (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                *(short *)(g_PlayerAnimationState + 0x16) * 4);
          goto LAB_00433a9e;
        }
        *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(g_PlayerAnimationState + 0x16) + -1;
        shortValue = *(short *)(g_PlayerAnimationState + 0x16);
      }
      *(ushort *)(g_PlayerAnimationState + 0x1e) =
           *(ushort *)(g_PlayerAnimationState + 0x1e) & 0xfeff;
      value6 = 0x10;
    }
  }
LAB_00433a9e:
  if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 2) != 0) {
    *(short *)(g_PlayerEntitySceneObject + 0x78) =
         *(short *)(g_PlayerEntitySceneObject + 0x78) + *(short *)(g_PlayerAnimationState + 0x1c);
  }
  if (0xff < *(short *)(g_PlayerEntitySceneObject + 0x78)) {
    *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
    *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
    *g_PlayerEntitySceneObjectData = *(ushort *)(g_PlayerEntitySceneObject + 0x76);
  }
  return value6;
}

