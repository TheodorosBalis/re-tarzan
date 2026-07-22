#include "tarzan_ghidra_types.hpp"

// Address: 0x00450DE0
// Label: CPlayerHero::EnterAdultTarzanSaborBattleReactionB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanSaborBattleReactionB(void)

{
  CPlayerHero::PlayAdultTarzanSaborBattleAnimation(0x98);
  g_PlayerAttackOverlapsSaborFlag = 0;
  return;
}

