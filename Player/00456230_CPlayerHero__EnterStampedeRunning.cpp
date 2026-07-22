#include "tarzan_ghidra_types.hpp"

// Address: 0x00456230
// Label: CPlayerHero::EnterStampedeRunning
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterStampedeRunning(void)

{
  g_PlayerCurrentAnimationId = 1;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_StampedeRunningAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 3;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 2;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x1000;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 0x1000;
  return;
}

