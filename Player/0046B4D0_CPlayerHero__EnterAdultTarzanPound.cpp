#include "tarzan_ghidra_types.hpp"

// Address: 0x0046B4D0
// Label: CPlayerHero::EnterAdultTarzanPound
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanPound(void)

{
  CPlayerHero::PlayAdultTarzanAnimation(0x1f);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  PlayAudioById(0x49,(int *)&g_PlayerLoopingSoundHandle,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  return;
}

