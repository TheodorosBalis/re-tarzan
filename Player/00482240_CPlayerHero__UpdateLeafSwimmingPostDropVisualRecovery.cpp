#include "tarzan_ghidra_types.hpp"

// Address: 0x00482240
// Label: CPlayerHero::UpdateLeafSwimmingPostDropVisualRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateLeafSwimmingPostDropVisualRecovery(void)

{
  if (g_LeafSwimmingWaterfallDropActive != 0) {
    *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x24) = 0x700;
    _g_LeafSwimmingWaterfallSurfaceIndex = 0x10;
    g_LeafSwimmingWaterfallDropActive = 0;
    return;
  }
  *(int *)(g_PlayerEntitySceneObjectData + 0x24) =
       (0x1000 - *(int *)(g_PlayerEntitySceneObjectData + 0x24) >> 4) +
       *(int *)(g_PlayerEntitySceneObjectData + 0x24);
  if (*(int *)(g_PlayerEntitySceneObject + 0xa8) < 0x1400) {
    *(int *)(g_PlayerEntitySceneObject + 0xa8) = *(int *)(g_PlayerEntitySceneObject + 0xa8) + 0x40;
    *(int *)(g_PlayerEntitySceneObject + 0xac) = *(int *)(g_PlayerEntitySceneObject + 0xac) + 0x40;
    *(int *)(g_PlayerEntitySceneObject + 0xb0) = *(int *)(g_PlayerEntitySceneObject + 0xb0) + 0x40;
  }
  return;
}

