#include "tarzan_ghidra_types.hpp"

// Address: 0x0048D680
// Label: CPlayerHero::UpdateYoungTarzanStopForwardMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungTarzanStopForwardMovement(void)

{
  undefined2 value;
  char resultFlag;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  value = g_PlayerActionState;
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048d732. Too many branches */
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
                    /* WARNING: Could not recover jumptable at 0x0048d715. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048d7a1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0xc;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048d767. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterPlayerDamageHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048d784. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero::ApplyDamageContactPushback();
  }
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value;
    (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
  }
  value = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (g_PlayerCurrentCollisionMode != 0) {
      if (g_PlayerCurrentCollisionMode < 3) {
        resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
        value = g_PlayerActionState;
        if (((resultFlag == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 1;
          g_PreviousPlayerActionState = value;
          (*(code *)g_YoungEnterTarzanMoveForwardHandlerPtr)();
        }
      }
      else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 0xe;
        g_PreviousPlayerActionState = value;
        (*(code *)g_YoungEnterTouchSurfaceOnSurfingHandlerPtr)();
      }
    }
  }
  value = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) {
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048d89e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTarzanMovingJumpHandlerPtr)();
      return;
    }
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0048d8bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterTarzanStandingJumpHandlerPtr)();
    return;
  }
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
    if (g_PlayerCurrentCollisionMode == 2) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = value;
      (*(code *)g_YoungEnterTarzanTurnAroundHandlerPtr)();
    }
    else if ((g_PlayerInputHeldMask & 0x80) == 0) {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + 0x2d;
    }
    else {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + -0x2d;
    }
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

