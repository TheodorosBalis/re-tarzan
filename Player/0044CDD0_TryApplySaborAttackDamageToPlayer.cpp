#include "tarzan_ghidra_types.hpp"

// Address: 0x0044CDD0
// Label: TryApplySaborAttackDamageToPlayer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void TryApplySaborAttackDamageToPlayer(undefined4 arg1)

{
  char resultFlag;
  uint value;
  
  resultFlag = DoesSaborAttackAttachmentHitPlayer(arg1);
  if (resultFlag != '\0') {
    QueuePlayerDamageEvent
              (g_SaborBattleEntity,
               (int)*(short *)(&g_SaborContactDamageByEncounterAndDifficulty +
                              (_g_CurrentSaborEncounterIndex * 3 +
                              (int)*( undefined1 *)((int)&g_LevelTransitionContext + 1)) * 2));
    CPlayerHero::SetAdultTarzanActionState(0x3c);
    value = NextRandomValue();
    if ((value & 1) != 0) {
      PlayAudioById(0x85,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
      g_SaborAttackHitPlayerFlag = 1;
      return;
    }
    PlayAudioById(0x86,(int *)0,(undefined4 *)g_PlayerEntitySceneObject + 0x14);
    g_SaborAttackHitPlayerFlag = 1;
  }
  return;
}

