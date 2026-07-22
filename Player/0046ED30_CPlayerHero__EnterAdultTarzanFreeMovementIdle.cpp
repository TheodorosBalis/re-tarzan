#include "tarzan_ghidra_types.hpp"

// Address: 0x0046ED30
// Label: CPlayerHero::EnterAdultTarzanFreeMovementIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanFreeMovementIdle(void)

{
  short shortValue;
  
  CPlayerHero::PlayAdultTarzanAnimation(0x9d);
  shortValue = RandomModulo(10);
  g_PlayerIdleFidgetDelayTicks = shortValue + 5;
  g_PlayerTiltControlEnabled = 0;
  return;
}

