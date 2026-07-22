#include "tarzan_ghidra_types.hpp"

// Address: 0x004711D0
// Label: CPlayerHero::UpdateTarzanSurfingWithJaneAirborne
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTarzanSurfingWithJaneAirborne(void)

{
  undefined2 value;
  char resultFlag;
  
  resultFlag = TryStartPlayerAttachmentInteraction();
  if (resultFlag != '\0') {
    return;
  }
  CPlayerHero::UpdateJumpArcVerticalMotion(0);
  CPlayerHero::UpdateRunInputAndMovement();
  resultFlag = CPlayerHero::TryResolveGroundContactSnap();
  value = g_PlayerActionState;
  if (resultFlag != '\0') {
    g_PlayerActionState = 9;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x00471206. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*_g_JaneSurfingAirborneAnimationScript)();
    return;
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

