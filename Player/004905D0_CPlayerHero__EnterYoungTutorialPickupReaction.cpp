#include "tarzan_ghidra_types.hpp"

// Address: 0x004905D0
// Label: CPlayerHero::EnterYoungTutorialPickupReaction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungTutorialPickupReaction(void)

{
  if ((uint)*(byte *)(g_PlayerEntitySceneObject + 0x75) ==
      *(uint *)(&g_TutorialPickupReactionSurfaceSideTable + g_ActiveTutorialPickupId * 0x30)) {
    CPlayerHero::PlayAnimation(0x94);
    return;
  }
  CPlayerHero::PlayAnimation(0x93);
  return;
}

