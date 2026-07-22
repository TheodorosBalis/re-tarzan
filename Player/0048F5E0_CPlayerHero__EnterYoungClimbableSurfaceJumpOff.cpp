#include "tarzan_ghidra_types.hpp"

// Address: 0x0048F5E0
// Label: CPlayerHero::EnterYoungClimbableSurfaceJumpOff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungClimbableSurfaceJumpOff(void)

{
  if (*(char *)(g_PlayerEntitySceneObject + 0x75) == '\0') {
    CPlayerHero::PlayAnimation(0x72);
    return;
  }
  CPlayerHero::PlayAnimation(0x6e);
  return;
}

