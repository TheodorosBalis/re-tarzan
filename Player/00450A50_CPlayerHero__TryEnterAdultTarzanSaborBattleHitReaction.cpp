#include "tarzan_ghidra_types.hpp"

// Address: 0x00450A50
// Label: CPlayerHero::TryEnterAdultTarzanSaborBattleHitReaction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::TryEnterAdultTarzanSaborBattleHitReaction(void)

{
  if (g_SaborPlayerHitReactionFlag != 0) {
    g_SaborPlayerHitReactionFlag = 0;
    PlayAudioById(0x89,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    CPlayerHero::SetAdultTarzanActionState(0x36);
    return 1;
  }
  return 0;
}

