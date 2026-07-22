#include "tarzan_ghidra_types.hpp"

// Address: 0x00437960
// Label: CPlayerHero::EnterJaneFalling
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterJaneFalling(void)

{
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 8;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 6;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x76) = *g_PlayerEntitySceneObjectData;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
  *(undefined2 *)(g_PlayerAnimationState + 0x1c) = 0x24;
  if (g_PreviousPlayerActionState != 3) {
    g_PlayerCurrentAnimationId = 5;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneFallingAnimationScriptPtr;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 6;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_JanePostJumpFallingAnimationScriptPtr;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  g_PlayerActionState = 5;
  return;
}

