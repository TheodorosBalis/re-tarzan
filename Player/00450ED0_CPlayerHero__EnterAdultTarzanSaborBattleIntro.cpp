#include "tarzan_ghidra_types.hpp"

// Address: 0x00450ED0
// Label: CPlayerHero::EnterAdultTarzanSaborBattleIntro
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterAdultTarzanSaborBattleIntro(void)

{
  InitializeSaborBattle();
  CPlayerHero::PlayAdultTarzanSaborBattleAnimation(0x9b);
  CPlayerHero::ClearPowerFruitDrawWindow();
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined1 *)(g_PlayerEntitySceneObject + 0x75) = 0xff;
  if (*(short *)(&g_SaborEncounterInitialFacingTable + _g_CurrentSaborEncounterIndex * 2) == 0) {
    *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
  }
  CPlayerHero::UpdateGroundShadowOnCurrentSurface();
  return;
}

