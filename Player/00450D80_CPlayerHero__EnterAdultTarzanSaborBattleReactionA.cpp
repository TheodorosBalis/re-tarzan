#include "tarzan_ghidra_types.hpp"

// Address: 0x00450D80
// Label: CPlayerHero::EnterAdultTarzanSaborBattleReactionA
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanSaborBattleReactionA(void)

{
  CPlayerHero::PlayAdultTarzanSaborBattleAnimation(0x97);
  g_PlayerAttackOverlapsSaborFlag = 0;
  return;
}

