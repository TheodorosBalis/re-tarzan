#include "tarzan_ghidra_types.hpp"

// Address: 0x0045BEA0
// Label: CPlayerHero::UpdateStorkLandingRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStorkLandingRecovery(void)

{
  undefined2 value2;
  int value;
  
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value == 0) {
    return;
  }
  if (g_StorkImpactAnimationVariant == 2) {
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0045bec7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_StorkEnterGroundedRecoveryWaitHandlerPtr)();
    return;
  }
  g_PlayerActionState = 0;
  g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0045bee4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)g_StorkActionStateTable)();
  return;
}

