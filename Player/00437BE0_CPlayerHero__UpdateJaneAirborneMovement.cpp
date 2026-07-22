#include "tarzan_ghidra_types.hpp"

// Address: 0x00437BE0
// Label: CPlayerHero::UpdateJaneAirborneMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short CPlayerHero::UpdateJaneAirborneMovement(void)

{
  ushort *dataCursor;
  short shortValue;
  ushort value4;
  short shortValue2;
  int value;
  int value2;
  int value3;
  ushort value5;
  ushort value6;
  undefined4 *dataCursor2;
  
  if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
    CPlayerHero::UpdateJaneRouteRelativeFacing();
    CPlayerHero::ApproachJaneForwardSpeed();
    CPlayerHero::ApplyJaneForwardMotionXZ();
    shortValue2 = g_PlayerActionState;
    if ((_g_PlayerSequenceFlags & 0x2000) == 0) {
      if (g_PlayerFacingCurrentCollisionSurface != '\0') {
        g_PlayerActionState = 8;
        g_PreviousPlayerActionState = shortValue2;
                    /* WARNING: Could not recover jumptable at 0x00437c25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        shortValue2 = (*(code *)g_JaneEnterDamageHandlerPtr)();
        return shortValue2;
      }
      if (g_NatureTerrainHazardContactFlag != 0) {
        g_JaneDamageReactionType = 2;
        if (g_PlayerActionState != 8) {
          g_PreviousPlayerActionState = g_PlayerActionState;
          g_PlayerActionState = 8;
          (*(code *)g_JaneEnterDamageHandlerPtr)();
          shortValue2 = QueuePlayerDamageEvent(0,7);
        }
        return shortValue2;
      }
    }
    RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_PlayerEntitySceneObject);
    CPlayerHero::TrySnapDownToGround();
    if (g_PlayerJumpArcActive != '\0') {
      value3 = CPlayerHero::TryClampJumpArcToSurfaceCeiling(0x14e);
      if (value3 == 0) {
        CPlayerHero::UpdateJumpArcVerticalMotion(1);
      }
      else {
        *(int *)(g_PlayerEntitySceneObjectData + 6) = value3;
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 4;
        (*(code *)g_JaneEnterFallingHandlerPtr)();
        g_PlayerJumpArcActive = '\0';
      }
    }
  }
  else {
    CPlayerHero::UpdateJumpArcVerticalMotion(1);
    CPlayerHero::ApproachJaneForwardSpeed();
    CPlayerHero::ApplyJaneForwardMotionXZ();
  }
  shortValue2 = 0;
  *(short *)(g_PlayerAnimationState + 0x14) = *(short *)(g_PlayerAnimationState + 0x14) + -1;
  if (*(short *)(g_PlayerAnimationState + 0x14) < 0) {
    if ((*(byte *)(g_PlayerAnimationState + 0x1f) & 1) == 0) {
      do {
        *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(g_PlayerAnimationState + 0x16) + 1;
        value2 = g_PlayerEntitySceneObject;
        value = (int)*(short *)(g_PlayerAnimationState + 0x16);
        value3 = *(int *)(g_PlayerAnimationState + 0xc);
        value5 = *(ushort *)(value3 + value * 4);
        value6 = value5 & 0x8000;
        if (value6 == 0) break;
        switch(value5) {
        case 0x8000:
          *(short *)(g_PlayerAnimationState + 0x16) = *(short *)(value3 + 2 + value * 4) + -1;
          if (shortValue2 == 0) {
            shortValue2 = 2;
          }
          break;
        case 0x8001:
          *(int *)(g_PlayerAnimationState + 0xc) = value3 + 4 + value * 4;
          *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
          break;
        case 0x8002:
          return *(short *)(*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                           *(short *)(g_PlayerAnimationState + 0x16) * 4);
        case 0x8003:
          shortValue2 = *(short *)(value3 + 2 + value * 4);
          break;
        case 0x8004:
          SetPlayerActionState
                    (*(undefined2 *)
                      (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                      *(short *)(g_PlayerAnimationState + 0x16) * 4));
          return shortValue2;
        case 0x8005:
          shortValue2 = CPlayerHero::PlayHeroModeAnimation
                            (*(undefined2 *)
                              (*(int *)(g_PlayerAnimationState + 0xc) + 2 +
                              *(short *)(g_PlayerAnimationState + 0x16) * 4));
          return shortValue2;
        case 0x8006:
          value4 = *(ushort *)(value3 + 2 + value * 4);
          if (value4 == 0x8000) {
            *(undefined4 *)(g_PlayerEntitySceneObjectData + 2) = g_CurrentWorldSceneContext;
          }
          else {
            *(uint *)(g_PlayerEntitySceneObjectData + 2) =
                 g_WorldEntitySceneObjectArrayBase + (uint)value4 * 0x68;
          }
          break;
        case 0x8007:
          g_PlayerJumpArcActive = '\x01';
          if (*(int *)(g_PlayerEntitySceneObject + 0x60) != 0) {
            *(undefined4 *)(*(int *)(g_PlayerEntitySceneObject + 0x60) + 0x60) = 0;
          }
          *(undefined4 *)(value2 + 0x60) = 0;
          break;
        case 0x8008:
          g_PlayerTiltControlEnabled = *(short *)(value3 + 2 + value * 4) != 0;
          break;
        case 0x8009:
          value2 = g_PlayerEntitySceneObject + 0x14;
          goto LAB_0043370c;
        case 0x800a:
          PlayAudioById(*(undefined2 *)(value3 + 2 + value * 4),(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
          break;
        case 0x800b:
          value2 = g_PlayerEntitySceneObject + 0x14;
          dataCursor2 = &g_PlayerLoopingSoundHandle;
          goto LAB_0043370d;
        case 0x800c:
          DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
          break;
        case 0x800d:
          value2 = 0;
LAB_0043370c:
          dataCursor2 = (undefined4 *)0x0;
LAB_0043370d:
          PlayAudioById(*(undefined2 *)(value3 + 2 + value * 4),(int *)dataCursor2,(undefined4 *)value2);
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
                 *(undefined2 *)(value3 + 2 + value * 4);
          }
          else {
            *g_PlayerEntitySceneObjectData = *(ushort *)(value3 + 2 + value * 4);
          }
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 1;
          break;
        case 0x8011:
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = *(undefined2 *)(value3 + 2 + value * 4)
          ;
          break;
        case 0x8012:
          if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 4) == 0) {
            *(undefined2 *)(g_PlayerEntitySceneObject + 0x76) =
                 *(undefined2 *)(value3 + 2 + value * 4);
          }
          else {
            *g_PlayerEntitySceneObjectData = *(ushort *)(value3 + 2 + value * 4);
          }
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 0x82
          ;
          break;
        case 0x8013:
          *(short *)(g_PlayerAnimationState + 0x1c) =
               (short)(0x100 / (ulonglong)(longlong)(int)(*(ushort *)(value3 + 2 + value * 4) + 1));
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
          *(byte *)(g_PlayerAnimationState + 0x1e) = *(byte *)(g_PlayerAnimationState + 0x1e) | 2;
          break;
        case 0x8014:
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
          *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
          break;
        case 0x8015:
          CPlayerHero::MoveToAnimationAttachmentWithCollision();
          if (shortValue2 == 0) {
            shortValue2 = 0xe;
          }
          break;
        case 0x8016:
          value4 = *(ushort *)(value3 + 2 + value * 4);
          *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 6;
          *(ushort *)(g_PlayerEntitySceneObject + 0x76) = *g_PlayerEntitySceneObjectData;
          *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
          *(short *)(g_PlayerAnimationState + 0x1c) =
               (short)(0x100 / (ulonglong)(longlong)(int)(value4 + 1));
          break;
        case 0x8017:
          g_PlayerAnimationSurfaceSide = *(undefined1 *)(value3 + 2 + value * 4);
          break;
        case 0x8018:
          shortValue2 = 0xf;
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
            *dataCursor = *dataCursor | *(ushort *)(value3 + 2 + value * 4);
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
          *(uint *)(g_PlayerEntitySceneObject + 0x70) = (uint)*(ushort *)(value3 + 2 + value * 4);
          break;
        case 0x801f:
          CPlayerHero::RefreshPowerFruitDrawWindow();
          break;
        case 0x8020:
          CPlayerHero::ClearPowerFruitDrawWindow();
          break;
        case 0x8021:
          value2 = (uint)*(ushort *)(value3 + 2 + value * 4) * 4;
          PlayForceFeedbackEffect_Stub
                    (0,*(undefined2 *)(&g_PlayerForceFeedbackEffectTable + value2),
                     CONCAT31((int3)((uint)value3 >> 8),
                              (&g_PlayerForceFeedbackEffectParamByte)[value2]));
          break;
        case 0x8022:
          CPlayerHero::UpdateAnimationEffectEntitySceneObject
                    (CONCAT22(*(short *)(g_PlayerAnimationState + 0x16) >> 0xf,
                              *(undefined2 *)(value3 + 2 + value * 4)));
          break;
        case 0x8023:
          QueuePlayerDamageEvent(0,0x200);
        }
      } while (value6 != 0);
      if ((*(byte *)(g_PlayerAnimationState + 0x1e) & 4) == 0) {
        *g_PlayerEntitySceneObjectData = value5;
      }
      else {
        *(ushort *)(g_PlayerEntitySceneObject + 0x76) = value5;
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
        value5 = *(ushort *)(*(int *)(g_PlayerAnimationState + 0xc) + shortValue * 4);
        if ((value5 & 0x8000) == 0) {
          *g_PlayerEntitySceneObjectData = value5;
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
      shortValue2 = 0x10;
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
  return shortValue2;
}

