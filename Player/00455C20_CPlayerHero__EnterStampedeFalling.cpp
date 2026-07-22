#include "tarzan_ghidra_types.hpp"

// Address: 0x00455C20
// Label: CPlayerHero::EnterStampedeFalling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterStampedeFalling(void)

{
  g_PlayerCurrentAnimationId = 3;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_StampedeFallingAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x10;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 4;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  return;
}

