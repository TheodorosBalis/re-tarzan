#include "tarzan_ghidra_types.hpp"

// Address: 0x0046D4E0
// Label: CPlayerHero::EnterAdultTarzanTreeSurfingBrake
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanTreeSurfingBrake(void)

{
  CPlayerHero::PlayAdultTarzanAnimation(0x2f);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
  return;
}

