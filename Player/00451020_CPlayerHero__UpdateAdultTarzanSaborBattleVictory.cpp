#include "tarzan_ghidra_types.hpp"

// Address: 0x00451020
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleVictory
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSaborBattleVictory(void)

{
  undefined2 value2;
  int value;
  
  if (g_SaborBattleVictorySequenceStartedFlag == 0) {
    value = CPlayerHero::AdvanceAnimationScript();
    if (value != 0) {
      *g_PlayerEntitySceneObjectData = 0x7ba;
      g_SaborBattleVictorySequenceStartedFlag = 1;
      return;
    }
  }
  else {
    *g_PlayerEntitySceneObjectData = *g_PlayerEntitySceneObjectData + 1;
    if (*g_PlayerEntitySceneObjectData == 0x7bd) {
      PlayAudioById(0x49,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    if (*g_PlayerEntitySceneObjectData == 0x7f0) {
      PlayAudioById(0x40,(int *)g_PlayerEntitySceneObject + 0x104,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    }
    value2 = g_PlayerActionState;
    if (0x827 < *g_PlayerEntitySceneObjectData) {
      g_PlayerActionState = 0;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanActionStateEnterColumn)();
      if (((byte)g_SaborDefeatedEncounterFlags & 4) != 0) {
        *( undefined2 *)((int)&g_LevelTransitionRequestFlags + 0) = 0x8001;
      }
    }
  }
  return;
}

