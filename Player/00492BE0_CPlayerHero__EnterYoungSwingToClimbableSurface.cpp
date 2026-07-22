#include "tarzan_ghidra_types.hpp"

// Address: 0x00492BE0
// Label: CPlayerHero::EnterYoungSwingToClimbableSurface
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungSwingToClimbableSurface(void)

{
  if (g_PlayerAnimationSurfaceSide == '\0') {
    CPlayerHero::PlayAnimation(0x53);
    return;
  }
  CPlayerHero::PlayAnimation(0x57);
  return;
}

