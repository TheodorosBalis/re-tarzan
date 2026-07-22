#include "tarzan_ghidra_types.hpp"

// Address: 0x0046EAD0
// Label: CPlayerHero::EnterAdultTarzanSwingToClimbableSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanSwingToClimbableSurface(void)

{
  if (g_PlayerAnimationSurfaceSide == '\0') {
    CPlayerHero::PlayAdultTarzanAnimation(0x52);
    return;
  }
  CPlayerHero::PlayAdultTarzanAnimation(0x56);
  return;
}

