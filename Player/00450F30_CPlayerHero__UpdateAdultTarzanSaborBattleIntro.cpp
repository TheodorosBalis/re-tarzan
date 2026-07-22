#include "tarzan_ghidra_types.hpp"

// Address: 0x00450F30
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleIntro
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanSaborBattleIntro(void)

{
  int value;
  
  value = CPlayerHero::AdvanceAnimationScript();
  if (value != 0) {
    if (value != 0x13) {
      CPlayerHero::SetAdultTarzanActionState(0x34);
      CPlayerHero::AdvanceAnimationScript();
      g_SaborBattleStartWaitFrames = 0;
      SetSaborBattlePhase(1);
      g_SaborPlayerHitReactionFlag = 0;
      g_SaborPlayerReactionAFlag = 0;
      g_SaborPlayerReactionBFlag = 0;
      g_SaborArenaLeftBoundaryBlockedFlag = 0;
      g_SaborArenaRightBoundaryBlockedFlag = 0;
      return;
    }
    *(int *)(g_PlayerEntitySceneObjectData + 4) = g_WorldEntitySceneObjectArrayBase + 0x138;
    _g_PlayerHeroMode = 3;
    CPlayerHero::ClearPowerFruitDrawWindow();
  }
  return;
}

