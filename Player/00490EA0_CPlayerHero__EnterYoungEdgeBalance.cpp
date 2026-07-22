#include "tarzan_ghidra_types.hpp"

// Address: 0x00490EA0
// Label: CPlayerHero::EnterYoungEdgeBalance
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungEdgeBalance(void)

{
  *g_PlayerEntitySceneObjectData = 0x9d;
  g_PlayerBalanceWobbleTimer = 0;
  g_PlayerBalanceWobbleAmount = 0x20;
  return;
}

