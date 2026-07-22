#include "tarzan_ghidra_types.hpp"

// Address: 0x00436D00
// Label: CPlayerHero::HideGroundShadow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::HideGroundShadow(void)

{
  if (g_PlayerGroundShadowProbeEntitySceneObject != 0) {
    *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) =
         *(ushort *)(g_PlayerGroundShadowProbeEntitySceneObject + 0xe) & 0x7fff;
  }
  return;
}

