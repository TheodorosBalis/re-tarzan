#include "tarzan_ghidra_types.hpp"

// Address: 0x0048D0F0
// Label: CPlayerHero::UpdateYoungTarzanTurnAround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungTarzanTurnAround(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  value2 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048d12f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTarzanMovingJumpHandlerPtr)();
      return;
    }
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048d14c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterTarzanStandingJumpHandlerPtr)();
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value == 6) {
    if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
      g_PlayerActionState = 1;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterTarzanMoveForwardHandlerPtr)();
    }
  }
  else if (value == 0xd) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x18;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048d1d3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
    return;
  }
  return;
}

