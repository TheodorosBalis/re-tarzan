#include "tarzan_ghidra_types.hpp"

// Address: 0x0046E790
// Label: CPlayerHero::UpdateAdultTarzanSwingRelease
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanSwingRelease(void)

{
  int value;
  
  CPlayerHero::UpdateMovementAndCollision(1);
  CPlayerHero::UpdateJumpArcVerticalMotion(0);
  CPlayerHero::TrySnapDownToGround();
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 0xe) {
    g_PlayerJumpArcActive = 1;
  }
  return;
}

