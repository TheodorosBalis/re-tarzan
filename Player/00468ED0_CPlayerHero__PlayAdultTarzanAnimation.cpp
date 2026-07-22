#include "tarzan_ghidra_types.hpp"

// Address: 0x00468ED0
// Label: CPlayerHero::PlayAdultTarzanAnimation
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::PlayAdultTarzanAnimation(int arg1)

{
  if ((g_PlayerPowerFruitInventoryFlags & 0x10) == 0) {
    *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 0;
  }
  else {
    *(undefined4 *)(g_PlayerEntitySceneObject + 0x70) = 1;
  }
  g_PlayerCurrentAnimationId = (undefined2)arg1;
  *(undefined **)(g_PlayerAnimationState + 0xc) = (&g_AdultTarzanAnimationScriptPtrTable)[arg1];
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  return;
}

