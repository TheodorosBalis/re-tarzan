#include "tarzan_ghidra_types.hpp"

// Address: 0x0045BCC0
// Label: CPlayerHero::UpdateStorkPostImpactFalling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStorkPostImpactFalling(void)

{
  undefined2 value2;
  int value;
  
  CPlayerHero::IntegrateStorkVerticalMotion();
  value2 = g_PlayerActionState;
  if ((g_StorkTerrainCollisionFlags & 2) != 0) {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0045bce3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_StorkEnterLandingRecoveryHandlerPtr)();
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value != 0) {
    *(undefined **)(g_PlayerAnimationState + 0xc) = &DAT_00503c9c;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  }
  return;
}

