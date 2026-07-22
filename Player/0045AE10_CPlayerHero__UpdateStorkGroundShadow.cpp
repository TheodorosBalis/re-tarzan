#include "tarzan_ghidra_types.hpp"

// Address: 0x0045AE10
// Label: CPlayerHero::UpdateStorkGroundShadow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateStorkGroundShadow(void)

{
  if (g_PlayerSpecialModeGroundShadowSceneObject != 0) {
    *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x14) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
    *(int *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x18) =
         *(int *)(g_PlayerEntitySceneObject + 0x18) + g_StorkTerrainVerticalOffset;
    *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0x1c) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c);
    *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0xa8) = 0x157c;
    *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0xac) = 0x157c;
    *(undefined4 *)(g_PlayerSpecialModeGroundShadowSceneObject + 0xb0) = 0x157c;
  }
  return;
}

