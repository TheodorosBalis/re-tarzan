#include "tarzan_ghidra_types.hpp"

// Address: 0x0048FD80
// Label: CPlayerHero::EnterYoungWaterTurn
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungWaterTurn(void)

{
  CPlayerHero::PlayAnimation(0x78);
  g_PlayerTiltControlEnabled = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 1;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  return;
}

