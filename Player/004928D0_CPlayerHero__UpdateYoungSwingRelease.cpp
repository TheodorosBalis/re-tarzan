#include "tarzan_ghidra_types.hpp"

// Address: 0x004928D0
// Label: CPlayerHero::UpdateYoungSwingRelease
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungSwingRelease(void)

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

