#include "tarzan_ghidra_types.hpp"

// Address: 0x00450C40
// Label: CPlayerHero::EnterAdultTarzanSaborBattleLanding
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanSaborBattleLanding(void)

{
  CPlayerHero::PlayAdultTarzanSaborBattleAnimation(0x95);
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  return;
}

