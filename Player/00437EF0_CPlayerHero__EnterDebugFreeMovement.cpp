#include "tarzan_ghidra_types.hpp"

// Address: 0x00437EF0
// Label: CPlayerHero::EnterDebugFreeMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterDebugFreeMovement(void)

{
  *g_PlayerEntitySceneObjectData = 0;
  g_PlayerBalanceWobbleTimer = 0;
  g_PlayerBalanceWobbleAmount = 0x20;
  return;
}

