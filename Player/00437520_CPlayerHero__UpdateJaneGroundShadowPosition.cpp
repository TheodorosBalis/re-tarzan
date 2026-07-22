#include "tarzan_ghidra_types.hpp"

// Address: 0x00437520
// Label: CPlayerHero::UpdateJaneGroundShadowPosition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateJaneGroundShadowPosition(void)

{
  if (g_JaneGroundShadowEntitySceneObject != 0) {
    *(undefined4 *)(g_JaneGroundShadowEntitySceneObject + 0x14) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x14);
    *(int *)(g_JaneGroundShadowEntitySceneObject + 0x18) =
         *(int *)(g_PlayerEntitySceneObject + 0x58) + *(int *)(g_PlayerEntitySceneObject + 0x18);
    *(undefined4 *)(g_JaneGroundShadowEntitySceneObject + 0x1c) =
         *(undefined4 *)(g_PlayerEntitySceneObject + 0x1c);
  }
  return;
}

