#include "tarzan_ghidra_types.hpp"

// Address: 0x00450E00
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleReactionB
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSaborBattleReactionB(void)

{
  char resultFlag;
  int value;
  
  resultFlag = CPlayerHero::TryEnterAdultTarzanSaborBattleHitReaction();
  if (resultFlag == '\0') {
    CPlayerHero::TryTriggerSaborHitFromPlayerAttack();
    value = CPlayerHero::AdvanceAnimationScript();
    if (value != 0) {
      if (value != 99) {
        CPlayerHero::SetAdultTarzanActionState(0x34);
        return;
      }
      if (g_PlayerAttackOverlapsSaborFlag == 0) {
        *(undefined2 *)(g_PlayerAnimationState + 0x14) = 1;
      }
    }
  }
  return;
}

