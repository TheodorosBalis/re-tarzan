#include "tarzan_ghidra_types.hpp"

// Address: 0x00490E20
// Label: CPlayerHero::UpdateYoungTutorialPickupReturnIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungTutorialPickupReturnIdle(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00490e6c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value == 5) {
    g_PlayerActionState = 0;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00490e91. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungTarzanActionStateTable)();
    return;
  }
  return;
}

