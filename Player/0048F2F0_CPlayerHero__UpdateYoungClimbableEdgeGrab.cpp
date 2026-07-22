#include "tarzan_ghidra_types.hpp"

// Address: 0x0048F2F0
// Label: CPlayerHero::UpdateYoungClimbableEdgeGrab
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungClimbableEdgeGrab(void)

{
  undefined2 value;
  char resultFlag;
  
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

