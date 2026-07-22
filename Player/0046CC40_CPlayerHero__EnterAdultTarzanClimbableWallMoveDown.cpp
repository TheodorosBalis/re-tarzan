#include "tarzan_ghidra_types.hpp"

// Address: 0x0046CC40
// Label: CPlayerHero::EnterAdultTarzanClimbableWallMoveDown
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanClimbableWallMoveDown(void)

{
  if (g_PlayerAnimationSurfaceSide == '\0') {
    CPlayerHero::PlayAdultTarzanAnimation(0x74);
    return;
  }
  CPlayerHero::PlayAdultTarzanAnimation(0x75);
  return;
}

