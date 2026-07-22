#include "tarzan_ghidra_types.hpp"

// Address: 0x00455A70
// Label: CPlayerHero::EnterStampedeScriptedFinishAnimation
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterStampedeScriptedFinishAnimation(void)

{
  g_PlayerCurrentAnimationId = 0;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_StampedeYoungTarzanAnimationScriptPtrTable;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

