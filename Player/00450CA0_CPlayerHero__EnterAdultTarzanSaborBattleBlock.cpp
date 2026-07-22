#include "tarzan_ghidra_types.hpp"

// Address: 0x00450CA0
// Label: CPlayerHero::EnterAdultTarzanSaborBattleBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanSaborBattleBlock(void)

{
  PlayAudioById(0x88,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
  CPlayerHero::PlayAdultTarzanSaborBattleAnimation(0x96);
  return;
}

