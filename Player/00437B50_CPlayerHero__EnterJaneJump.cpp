#include "tarzan_ghidra_types.hpp"

// Address: 0x00437B50
// Label: CPlayerHero::EnterJaneJump
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterJaneJump(void)

{
  g_PlayerCurrentAnimationId = 4;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneJumpAnimationScriptPtr;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x42;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = *(undefined4 *)(g_PlayerMotionState + 0x10);
  if ((_g_PlayerSequenceFlags & 0x2000) != 0) {
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x84;
  }
  return;
}

