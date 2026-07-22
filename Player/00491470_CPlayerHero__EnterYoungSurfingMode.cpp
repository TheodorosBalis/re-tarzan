#include "tarzan_ghidra_types.hpp"

// Address: 0x00491470
// Label: CPlayerHero::EnterYoungSurfingMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterYoungSurfingMode(void)

{
  *(undefined1 *)(g_PlayerEntitySceneObject + 0x75) = 0;
  PlayAudioById(0x28,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  CPlayerHero::PlayAnimation(0x29);
  PlayAudioById(0x29,(int *)&g_PlayerLoopingSoundHandle,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xa0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0xa0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  _g_TreeSurfingReboundTimer = 0xffffffff;
  return;
}

