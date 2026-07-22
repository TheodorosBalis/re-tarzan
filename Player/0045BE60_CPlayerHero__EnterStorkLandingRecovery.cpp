#include "tarzan_ghidra_types.hpp"

// Address: 0x0045BE60
// Label: CPlayerHero::EnterStorkLandingRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterStorkLandingRecovery(void)

{
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  g_PlayerCurrentAnimationId = 10;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_StorkLandingRecoveryAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

