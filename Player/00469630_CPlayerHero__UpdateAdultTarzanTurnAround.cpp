#include "tarzan_ghidra_types.hpp"

// Address: 0x00469630
// Label: CPlayerHero::UpdateAdultTarzanTurnAround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanTurnAround(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerSurfaceTriggerPacket & 0x800) == 0)) &&
     ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    *(ushort *)(g_PlayerAnimationState + 0x1e) = *(ushort *)(g_PlayerAnimationState + 0x1e) & 0xfeff
    ;
    value2 = g_PlayerActionState;
    if (g_PlayerCurrentCollisionMode == 1) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
        g_PlayerActionState = 0x46;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x004696ee. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_AdultTarzanEnterFreeMovementMovingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x45;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046970b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterFreeMovementStandingJumpHandlerPtr)();
      return;
    }
    if (g_PlayerCurrentCollisionMode == 2) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
        g_PlayerActionState = 5;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x004696a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_AdultTarzanEnterMovingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x004696bf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterStandingJumpHandlerPtr)();
      return;
    }
  }
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value == 6) {
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      if (g_PlayerCurrentCollisionMode == 1) {
        if (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 0x41;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_AdultTarzanEnterFreeMovementForwardHandlerPtr)();
        }
      }
      else if (g_PlayerCurrentCollisionMode == 2) {
        resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
        value2 = g_PlayerActionState;
        if (((resultFlag == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 1;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_AdultTarzanEnterMoveForwardHandlerPtr)();
        }
      }
      else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 0xd;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterTreeSurfingHandlerPtr)();
      }
    }
  }
  else if (value == 0xd) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00469836. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
    return;
  }
  return;
}

