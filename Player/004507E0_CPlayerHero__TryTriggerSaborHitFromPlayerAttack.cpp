#include "tarzan_ghidra_types.hpp"

// Address: 0x004507E0
// Label: CPlayerHero::TryTriggerSaborHitFromPlayerAttack
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::TryTriggerSaborHitFromPlayerAttack(void)

{
  char resultFlag;
  
  if (((g_SaborBattlePhase < 7) || (10 < g_SaborBattlePhase)) && (g_SaborHitProcessedFlag == 0)) {
    resultFlag = DoEntitySceneObjectAttachmentBoxesOverlapByFlags
                      (g_PlayerEntitySceneObject,0x400,*(undefined4 *)(g_SaborBattleEntity + 0x38),
                       0x200);
    if (resultFlag != '\0') {
      SetSaborBattlePhase(7);
      g_PlayerAttackOverlapsSaborFlag = 1;
    }
  }
  return;
}

