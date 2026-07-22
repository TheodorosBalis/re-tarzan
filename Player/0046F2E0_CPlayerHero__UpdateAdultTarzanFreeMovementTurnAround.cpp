#include "tarzan_ghidra_types.hpp"

// Address: 0x0046F2E0
// Label: CPlayerHero::UpdateAdultTarzanFreeMovementTurnAround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanFreeMovementTurnAround(void)

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
                    /* WARNING: Could not recover jumptable at 0x0046f39e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_AdultTarzanEnterFreeMovementMovingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x45;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046f3bb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterFreeMovementStandingJumpHandlerPtr)();
      return;
    }
    if (g_PlayerCurrentCollisionMode == 2) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
        g_PlayerActionState = 5;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046f352. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_AdultTarzanEnterMovingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046f36f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterStandingJumpHandlerPtr)();
      return;
    }
  }
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if ((value == 6) && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) {
    g_PlayerActionState = 0x41;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterFreeMovementForwardHandlerPtr)();
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046f424. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
    return;
  }
  return;
}

