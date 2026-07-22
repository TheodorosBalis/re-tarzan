#include "tarzan_ghidra_types.hpp"

// Address: 0x00450840
// Label: CPlayerHero::EnterAdultTarzanSaborBattleIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanSaborBattleIdle(void)

{
  short shortValue;
  
  CPlayerHero::PlayAdultTarzanSaborBattleAnimation(0x90);
  shortValue = RandomModulo(10);
  g_PlayerIdleFidgetDelayTicks = shortValue + 5;
  g_PlayerTiltControlEnabled = 0;
  CPlayerHero::ResetAdultTarzanSaborBattleMotion();
  return;
}

