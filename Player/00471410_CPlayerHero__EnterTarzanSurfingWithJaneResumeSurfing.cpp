#include "tarzan_ghidra_types.hpp"

// Address: 0x00471410
// Label: CPlayerHero::EnterTarzanSurfingWithJaneResumeSurfing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTarzanSurfingWithJaneResumeSurfing(void)

{
  g_PlayerCurrentAnimationId = 5;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_JaneSurfingResumeSurfAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  PlayAudioById(0x79,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  PlayAudioById(0x79,(int *)&g_PlayerLoopingSoundHandle,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xa0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0xa0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  _g_TarzanSurfingWithJaneActionPhaseValue = 0xffffffff;
  return;
}

