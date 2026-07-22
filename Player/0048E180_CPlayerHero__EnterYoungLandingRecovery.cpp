#include "tarzan_ghidra_types.hpp"

// Address: 0x0048E180
// Label: CPlayerHero::EnterYoungLandingRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterYoungLandingRecovery(void)

{
  undefined2 value2;
  int value;
  undefined4 value3;
  
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (g_PlayerHeldThrowableEntity != 0) {
    *(undefined2 *)(g_PlayerHeldThrowableEntity + 0x48) = 7;
  }
  value2 = g_PlayerActionState;
  g_PlayerHeldThrowableEntity = 0;
  if (g_PlayerCurrentCollisionMode == 5) {
    g_PlayerActionState = 0x12;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_YoungEnterSurfingModeHandlerPtr)();
    return;
  }
  if (g_PlayerPickupInteractionFlags == 0x4000) {
    value3 = 0x19;
  }
  else {
    if (g_PlayerCurrentAnimationId == 0x15) {
      CPlayerHero::PlayAnimation(0x18);
      _g_CampBoxCameraShakeTimer = 0x28;
      _g_CampBoxCameraShakeAmplitude = 8;
      PlayForceFeedbackEffect_Stub(0,2,0xf);
      goto LAB_0048e373;
    }
    if ((g_PlayerCollisionContactFlags & 0x800000) != 0) {
      QueuePlayerDamageEvent(0,5);
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x30;
      (*(code *)g_YoungEnterJumpDamageHandlerPtr)();
      return;
    }
    if ((g_PlayerCollisionContactFlags & 0x200000) != 0) {
      value = RandomModulo(4);
      if (value == 1) {
        value3 = 0x32;
      }
      else if (value == 2) {
        value3 = 0x33;
      }
      else if (value == 3) {
        value3 = 0x34;
      }
      else {
        value3 = 0x35;
      }
      PlayAudioById(value3,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x31;
      (*(code *)g_YoungEnterBouncingModeHandlerPtr)();
      return;
    }
    if (((g_PlayerSurfaceTriggerPacket & 0x200) != 0) && ((g_PlayerInputHeldMask & 0x200000) != 0))
    {
      g_PlayerActionState = 0x31;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterBouncingModeHandlerPtr)();
      return;
    }
    if ((g_PlayerSurfaceTriggerPacket & 0x100) != 0) {
      g_PlayerActionState = 0x31;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterScriptedDeathKnockbackHandlerPtr)();
      return;
    }
    g_PlayerBounceChainCount = 0;
    if ((g_PreviousPlayerActionState == 8) && ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0))
    {
      value3 = 0x17;
    }
    else {
      value3 = 0x16;
    }
  }
  CPlayerHero::PlayAnimation(value3);
LAB_0048e373:
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  return;
}

