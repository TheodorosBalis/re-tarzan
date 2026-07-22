#include "tarzan_ghidra_types.hpp"

// Address: 0x0046C590
// Label: CPlayerHero::UpdateAdultTarzanClimbableEdgeGrab
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanClimbableEdgeGrab(void)

{
  undefined2 value;
  char resultFlag;
  
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

