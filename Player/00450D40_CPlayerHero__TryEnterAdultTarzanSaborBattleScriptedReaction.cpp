#include "tarzan_ghidra_types.hpp"

// Address: 0x00450D40
// Label: CPlayerHero::TryEnterAdultTarzanSaborBattleScriptedReaction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CPlayerHero::TryEnterAdultTarzanSaborBattleScriptedReaction(void)

{
  if (g_SaborPlayerReactionAFlag != 0) {
    g_SaborPlayerReactionAFlag = 0;
    CPlayerHero::SetAdultTarzanActionState(0x3a);
    return 1;
  }
  if (g_SaborPlayerReactionBFlag != 0) {
    g_SaborPlayerReactionBFlag = 0;
    CPlayerHero::SetAdultTarzanActionState(0x3b);
    return 1;
  }
  return 0;
}

