#include "tarzan_ghidra_types.hpp"

// Address: 0x0048F9B0
// Label: CPlayerHero::EnterYoungClimbableWallMoveDown
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungClimbableWallMoveDown(void)

{
  if (g_PlayerAnimationSurfaceSide == '\0') {
    CPlayerHero::PlayAnimation(0x80);
    return;
  }
  CPlayerHero::PlayAnimation(0x81);
  return;
}

