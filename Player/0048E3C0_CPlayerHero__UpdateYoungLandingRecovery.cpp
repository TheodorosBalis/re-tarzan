#include "tarzan_ghidra_types.hpp"

// Address: 0x0048E3C0
// Label: CPlayerHero::UpdateYoungLandingRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungLandingRecovery(void)

{
  short shortValue;
  char resultFlag;
  
  shortValue = g_PlayerActionState;
  if (g_PlayerPickupInteractionFlags != 0x4000) {
    if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
    }
    g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
    if (g_PlayerFacingCurrentCollisionSurface != '\0') {
      if (((ram0x0051cdca & 0x2000) == 0) && (g_PlayerActionState != 0x30)) {
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0x30;
        (*(code *)g_YoungEnterJumpDamageHandlerPtr)();
      }
      if (g_PlayerDamageInvulnerabilityTicks == 0) {
        g_PlayerDamageInvulnerabilityTicks = 0x3c;
        g_PlayerDamageFlashTicks = 0x3c;
      }
      return;
    }
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
        g_PlayerActionState = 5;
        g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x0048e491. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterTarzanMovingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x0048e4ae. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTarzanStandingJumpHandlerPtr)();
      return;
    }
    if (g_PlayerCurrentAnimationId != 0x18) {
      if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
        if (g_PlayerCurrentCollisionMode != 0) {
          if (g_PlayerCurrentCollisionMode < 3) {
            resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
            shortValue = g_PlayerActionState;
            if (((resultFlag == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
               (g_PlayerCollisionFacingFlags == '\0')) {
              g_PlayerActionState = 1;
              g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x0048e53c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
              (*(code *)g_YoungEnterTarzanMoveForwardHandlerPtr)();
              return;
            }
          }
          else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
            g_PlayerActionState = 0xe;
            g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x0048e4fb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            (*(code *)g_YoungEnterTouchSurfaceOnSurfingHandlerPtr)();
            return;
          }
        }
      }
      shortValue = g_PlayerActionState;
      if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
         ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
        if (g_PlayerCurrentCollisionMode == 2) {
          g_PlayerActionState = 3;
          g_PreviousPlayerActionState = shortValue;
                    /* WARNING: Could not recover jumptable at 0x0048e5cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)g_YoungEnterTarzanTurnAroundHandlerPtr)();
          return;
        }
        if ((g_PlayerInputHeldMask & 0x80) == 0) {
          g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + 0x2d;
        }
        else {
          g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + -0x2d;
        }
      }
    }
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  shortValue = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = shortValue;
    (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

