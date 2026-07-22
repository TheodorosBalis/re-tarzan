#include "tarzan_ghidra_types.hpp"

// Address: 0x00470E50
// Label: CPlayerHero::UpdateAdultTarzanLevelIntroPose
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanLevelIntroPose(void)

{
  undefined2 value2;
  int value;
  
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value == 8) {
    g_PlayerActionState = 0x33;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00470e6f. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_g_AdultTarzanEnterLevelIntroFinishedHandlerPtr)();
    return;
  }
  return;
}

