#include "tarzan_ghidra_types.hpp"

// Address: 0x00450FB0
// Label: CPlayerHero::EnterAdultTarzanSaborBattleVictory
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterAdultTarzanSaborBattleVictory(void)

{
  undefined4 value;
  
  CPlayerHero::ResetAdultTarzanSaborBattleMotion();
  g_PendingAdultTarzanActionState = 0;
  _g_PlayerHeroMode = 1;
  CPlayerHero::PlayAdultTarzanSaborBattleAnimation(0x9c);
  *(int *)(g_PlayerEntitySceneObjectData + 4) = g_WorldEntitySceneObjectArrayBase + 0xd0;
  _g_PlayerHeroMode = 1;
  value = CEntities::SpawnEntityByTypeAtPosition
                    (*(undefined4 *)(g_PlayerEntitySceneObjectData + 8),
                     *(undefined4 *)(g_PlayerEntitySceneObjectData + 0xc),
                     *(undefined4 *)(g_PlayerEntitySceneObjectData + 0x10),0x29,0x11);
  ConfigureSaborBattleVictoryEntity(value);
  g_SaborBattleVictorySequenceStartedFlag = 0;
  return;
}

