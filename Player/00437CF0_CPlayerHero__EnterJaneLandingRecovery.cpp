#include "tarzan_ghidra_types.hpp"

// Address: 0x00437CF0
// Label: CPlayerHero::EnterJaneLandingRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterJaneLandingRecovery(void)

{
  *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 6;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x76) = *g_PlayerEntitySceneObjectData;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
  *(undefined2 *)(g_PlayerAnimationState + 0x1c) = 0x55;
  g_PlayerCurrentAnimationId = 7;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneLandingRecoveryAnimationScriptPtr;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  return;
}

