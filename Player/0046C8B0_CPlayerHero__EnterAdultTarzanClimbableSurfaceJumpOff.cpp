#include "tarzan_ghidra_types.hpp"

// Address: 0x0046C8B0
// Label: CPlayerHero::EnterAdultTarzanClimbableSurfaceJumpOff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanClimbableSurfaceJumpOff(void)

{
  if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
    CPlayerHero::PlayAdultTarzanAnimation(0x6e);
    return;
  }
  CPlayerHero::PlayAdultTarzanAnimation(0x6a);
  return;
}

