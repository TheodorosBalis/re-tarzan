#include "tarzan_ghidra_types.hpp"

// Address: 0x0048E820
// Label: CPlayerHero::EnterYoungPound
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungPound(void)

{
  CPlayerHero::PlayAnimation(0x1e);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  PlayAudioById(10,(int *)&g_PlayerLoopingSoundHandle,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  return;
}

