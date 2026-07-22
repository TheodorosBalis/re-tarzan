#include "tarzan_ghidra_types.hpp"

// Address: 0x004377D0
// Label: CPlayerHero::EnterJaneRunning
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterJaneRunning(void)

{
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  g_PlayerCurrentAnimationId = 3;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneRunningAnimationScriptPtr;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

