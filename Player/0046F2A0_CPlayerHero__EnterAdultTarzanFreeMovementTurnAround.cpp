#include "tarzan_ghidra_types.hpp"

// Address: 0x0046F2A0
// Label: CPlayerHero::EnterAdultTarzanFreeMovementTurnAround
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanFreeMovementTurnAround(void)

{
  if (g_PreviousPlayerActionState != 0x41) {
    CPlayerHero::PlayAdultTarzanAnimation(10);
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    return;
  }
  CPlayerHero::PlayAdultTarzanAnimation(0xb);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  return;
}

