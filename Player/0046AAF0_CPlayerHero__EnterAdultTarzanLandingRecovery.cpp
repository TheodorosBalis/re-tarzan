#include "tarzan_ghidra_types.hpp"

// Address: 0x0046AAF0
// Label: CPlayerHero::EnterAdultTarzanLandingRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterAdultTarzanLandingRecovery(void)

{
  undefined2 value2;
  int value;
  undefined4 value3;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  g_PlayerHeldThrowableEntity = 0;
  if (g_PlayerCurrentAnimationId == 0x16) {
    _g_CampBoxCameraShakeTimer = 0x32;
    _g_CampBoxCameraShakeAmplitude = 0x14;
    PlayForceFeedbackEffect_Stub(0,2,0xf);
  }
  value2 = g_PlayerActionState;
  if ((g_PlayerCollisionContactFlags & 0x800000) != 0) {
    QueuePlayerDamageEvent(0,5);
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x2e;
    (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
    return;
  }
  if ((g_PlayerCollisionContactFlags & 0x200000) == 0) {
    if (((g_PlayerSurfaceTriggerPacket & 0x200) == 0) || ((g_PlayerInputHeldMask & 0x200000) == 0))
    {
      if ((g_PlayerSurfaceTriggerPacket & 0x100) == 0) {
        if (g_PlayerCurrentCollisionMode == 1) {
          g_PlayerActionState = 0x49;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_AdultTarzanEnterFreeMovementLandingRecoveryHandlerPtr)();
          return;
        }
        if (g_PlayerCurrentCollisionMode != 5) {
          if (g_PlayerCurrentAnimationId == 0x16) {
            value3 = 0x1a;
          }
          else {
            g_PlayerBounceChainCount = 0;
            if ((g_PreviousPlayerActionState == 8) &&
               ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0)) {
              value3 = 0x19;
            }
            else {
              value3 = 0x18;
            }
          }
          CPlayerHero::PlayAdultTarzanAnimation(value3);
          *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
          g_PlayerTargetMoveSpeed = 0;
          *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
          *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
          *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
          return;
        }
        g_PlayerActionState = 0x11;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterTreeSurfingBoostHandlerPtr)();
        return;
      }
      value = RandomModulo(4);
      if (value == 1) {
        value3 = 99;
      }
      else if (value == 2) {
        value3 = 100;
      }
      else if (value == 3) {
        value3 = 0x65;
      }
      else {
        value3 = 0x66;
      }
      PlayAudioById(value3,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
      value = g_PlayerEntitySceneObject + 0x14;
      value3 = 0x28b;
    }
    else {
      value = RandomModulo(4);
      if (value == 1) {
        value3 = 99;
      }
      else if (value == 2) {
        value3 = 100;
      }
      else if (value == 3) {
        value3 = 0x65;
      }
      else {
        value3 = 0x66;
      }
      PlayAudioById(value3,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
      value = g_PlayerEntitySceneObject + 0x14;
      value3 = 0x28c;
    }
  }
  else {
    value = RandomModulo(4);
    if (value == 1) {
      value = g_PlayerEntitySceneObject + 0x14;
      value3 = 99;
    }
    else if (value == 2) {
      value = g_PlayerEntitySceneObject + 0x14;
      value3 = 100;
    }
    else if (value == 3) {
      value = g_PlayerEntitySceneObject + 0x14;
      value3 = 0x65;
    }
    else {
      value = g_PlayerEntitySceneObject + 0x14;
      value3 = 0x66;
    }
  }
  PlayAudioById(value3,(int *)0,(undefined4 *)value);
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 0x2d;
  (*(code *)g_AdultTarzanEnterBounceHandlerPtr)();
  return;
}

