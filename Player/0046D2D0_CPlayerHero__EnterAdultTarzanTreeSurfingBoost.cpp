#include "tarzan_ghidra_types.hpp"

// Address: 0x0046D2D0
// Label: CPlayerHero::EnterAdultTarzanTreeSurfingBoost
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterAdultTarzanTreeSurfingBoost(void)

{
  *(undefined1 *)(g_PlayerEntitySceneObject + 0x75) = 0;
  PlayAudioById(0x78,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  CPlayerHero::PlayAdultTarzanAnimation(0x2b);
  PlayAudioById(0x79,(int *)&g_PlayerLoopingSoundHandle,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xa0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0xa0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  _g_TarzanTreeSurfingJumpSurfaceState = 0xffffffff;
  return;
}

