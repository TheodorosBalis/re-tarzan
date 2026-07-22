#include "tarzan_ghidra_types.hpp"

// Address: 0x0046C630
// Label: CPlayerHero::UpdateAdultTarzanClimbableEdgeHang
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanClimbableEdgeHang(void)

{
  undefined2 value;
  char resultFlag;
  
  value = g_PlayerActionState;
  if (((g_PlayerSequenceFlags & 0xf000) == 0) &&
     (((g_CameraFollowFlags | 0x10) & g_PlayerInputHeldMask) != 0)) {
    g_PlayerActionState = 0x21;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0046c669. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterClimbableEdgePullUpHandlerPtr)();
    return;
  }
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 0x22;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0046c695. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterClimbableSurfaceJumpOffHandlerPtr)();
    return;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value;
    (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

