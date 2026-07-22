#include "tarzan_ghidra_types.hpp"

// Address: 0x00450AA0
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleHitReaction
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSaborBattleHitReaction(void)

{
  int value;
  
  value = CPlayerHero::AdvanceAnimationScript();
  if (value != 0) {
    CPlayerHero::SetAdultTarzanActionState(0x37);
  }
  return;
}

