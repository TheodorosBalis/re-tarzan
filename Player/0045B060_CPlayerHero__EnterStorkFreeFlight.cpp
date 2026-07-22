#include "tarzan_ghidra_types.hpp"

// Address: 0x0045B060
// Label: CPlayerHero::EnterStorkFreeFlight
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterStorkFreeFlight(void)

{
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 5;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xffffffe8;
  *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 6;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x76) = *g_PlayerEntitySceneObjectData;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
  *(undefined2 *)(g_PlayerAnimationState + 0x1c) = 0x33;
  g_PlayerCurrentAnimationId = 1;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_StorkFreeFlightAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

