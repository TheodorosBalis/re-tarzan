#include "tarzan_ghidra_types.hpp"

// Address: 0x00436270
// Label: CPlayerHero::RefreshPowerFruitDrawWindow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::RefreshPowerFruitDrawWindow(void)

{
  if (_g_PlayerHeroMode == 1) {
    if ((g_PlayerPowerFruitInventoryFlags & 0x10) != 0) {
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 1;
      return;
    }
    *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 0;
  }
  else {
    if (_g_PlayerHeroMode == 2) {
      if ((g_PlayerPowerFruitInventoryFlags & 0x10) != 0) {
        *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 1;
        return;
      }
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 0;
      return;
    }
    if (_g_PlayerHeroMode == 3) {
      *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 0;
      return;
    }
  }
  return;
}

