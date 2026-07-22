#include "tarzan_ghidra_types.hpp"

// Address: 0x00436D10
// Label: CPlayerHero::ShowGroundShadow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ShowGroundShadow(void)

{
  if (g_PlayerGroundShadowProbeEntitySceneObject != 0) {
    *(byte *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xf) =
         *(byte *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xf) | 0x80;
  }
  return;
}

