#include "tarzan_ghidra_types.hpp"

// Address: 0x00460640
// Label: CPlayerHero::UpdateAdultTarzanElephantFatalDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanElephantFatalDamage(void)

{
  undefined2 value2;
  int value;
  
  CPlayerHero::ApplyAdultTarzanElephantForwardMotionXZ();
  CPlayerHero::ApproachAdultTarzanElephantForwardSpeed();
  value = CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  if (value == 1) {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00460669. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_g_AdultTarzanElephantTerminalWaitEnterHandlerPtr)();
    return;
  }
  if ((g_AdultTarzanElephantEntitySceneObject != 0) &&
     (*(byte *)(g_PlayerEntitySceneObject + 0x74) < 0x24)) {
    CPlayerHero::AdvanceAdultTarzanElephantAnimationFrames(0x23);
  }
  return;
}

