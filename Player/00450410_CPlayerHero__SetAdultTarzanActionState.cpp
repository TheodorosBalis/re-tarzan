#include "tarzan_ghidra_types.hpp"

// Address: 0x00450410
// Label: CPlayerHero::SetAdultTarzanActionState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::SetAdultTarzanActionState(int arg1)

{
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = (undefined2)arg1;
                    /* WARNING: Could not recover jumptable at 0x00450426. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&g_AdultTarzanActionStateEnterColumn)[arg1 * 2])();
  return;
}

