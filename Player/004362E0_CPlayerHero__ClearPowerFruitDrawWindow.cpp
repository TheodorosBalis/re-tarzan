#include "tarzan_ghidra_types.hpp"

// Address: 0x004362E0
// Label: CPlayerHero::ClearPowerFruitDrawWindow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::ClearPowerFruitDrawWindow(void)

{
  if (_g_PlayerHeroMode == 1) {
    *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 0;
  }
  else if (_g_PlayerHeroMode != 2) {
    if (_g_PlayerHeroMode != 3) {
      return;
    }
    *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 0;
    return;
  }
  *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 0;
  return;
}

