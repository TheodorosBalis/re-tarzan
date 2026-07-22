#include "tarzan_ghidra_types.hpp"

// Address: 0x0048E620
// Label: CPlayerHero::UpdateYoungBlockAnimation
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungBlockAnimation(void)

{
  undefined2 value;
  char resultFlag;
  
  value = g_PlayerActionState;
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048e6de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0x30;
        g_PreviousPlayerActionState = value;
        (*(code *)g_YoungEnterJumpDamageHandlerPtr)();
        if (g_PlayerDamageInvulnerabilityTicks == 0) {
          g_PlayerDamageInvulnerabilityTicks = 0x3c;
          g_PlayerDamageFlashTicks = 0x3c;
        }
        return;
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048e6c1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048e74d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0xc;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048e713. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterPlayerDamageHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048e730. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = 1;
    CPlayerHero::ApplyDamageContactPushback();
  }
  value = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048e79e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTarzanMovingJumpHandlerPtr)();
      return;
    }
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048e7bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterTarzanStandingJumpHandlerPtr)();
    return;
  }
  if ((g_PlayerCurrentAnimationId == 0x1c) &&
     (g_PlayerBlockDamageGuardActive = 1, (g_PlayerInputHeldMask & 0x80000) == 0)) {
    CPlayerHero::PlayAnimation(0x1d);
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value;
    (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

