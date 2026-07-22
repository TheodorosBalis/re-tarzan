#include "tarzan_ghidra_types.hpp"

// Address: 0x00437D80
// Label: CPlayerHero::UpdateJaneLandingRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateJaneLandingRecovery(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  value2 = g_PlayerActionState;
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_PlayerActionState = 3;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00437da1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_g_JaneEnterJumpHandlerPtr)();
    return;
  }
  CPlayerHero::UpdateJaneRouteRelativeFacing();
  CPlayerHero::ApproachJaneForwardSpeed();
  CPlayerHero::ApplyJaneForwardMotionXZ();
  RefreshEntitySceneObjectNatureTerrainVerticalDelta(g_PlayerEntitySceneObject);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 4;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_JaneEnterFallingHandlerPtr)();
  }
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value != 0) {
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00437e09. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_JaneEnterIdleHandlerPtr)();
    return;
  }
  return;
}

