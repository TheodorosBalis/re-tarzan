#include "tarzan_ghidra_types.hpp"

// Address: 0x00450870
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSaborBattleIdle(void)

{
  char resultFlag;
  
  resultFlag = CPlayerHero::TryEnterAdultTarzanSaborBattleMovement();
  if (resultFlag == '\0') {
    resultFlag = CPlayerHero::TryEnterAdultTarzanSaborBattleHitReaction();
    if (resultFlag == '\0') {
      resultFlag = CPlayerHero::TryEnterAdultTarzanSaborBattleBlock();
      if (resultFlag == '\0') {
        resultFlag = CPlayerHero::TryEnterAdultTarzanSaborBattleScriptedReaction();
        if (resultFlag == '\0') {
          CPlayerHero::AdvanceAnimationScript();
          return;
        }
      }
    }
  }
  return;
}

