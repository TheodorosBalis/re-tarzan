#include "tarzan_ghidra_types.hpp"

// Address: 0x004603E0
// Label: CPlayerHero::EnterAdultTarzanElephantRiderAction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanElephantRiderAction(void)

{
  g_PlayerCurrentAnimationId = 2;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_AdultTarzanElephantRiderActionAnimationScriptPtr
  ;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

