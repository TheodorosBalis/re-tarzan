#include "tarzan_ghidra_types.hpp"

// Address: 0x00455AC0
// Label: CPlayerHero::EnterStampedeJump
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterStampedeJump(void)

{
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 1;
  g_PlayerCurrentAnimationId = 2;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_StampedeJumpAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x4e;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 5;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
  return;
}

