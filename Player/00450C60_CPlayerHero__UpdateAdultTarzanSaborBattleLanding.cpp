#include "tarzan_ghidra_types.hpp"

// Address: 0x00450C60
// Label: CPlayerHero::UpdateAdultTarzanSaborBattleLanding
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSaborBattleLanding(void)

{
  int value;
  
  value = CPlayerHero::AdvanceAnimationScript();
  if (value != 0) {
    CPlayerHero::SetAdultTarzanActionState(0x34);
  }
  return;
}

