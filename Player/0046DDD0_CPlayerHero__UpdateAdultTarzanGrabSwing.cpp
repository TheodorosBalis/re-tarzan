#include "tarzan_ghidra_types.hpp"

// Address: 0x0046DDD0
// Label: CPlayerHero::UpdateAdultTarzanGrabSwing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateAdultTarzanGrabSwing(void)

{
  if (g_CurrentSwingEntity != 0) {
    UpdatePlayerOnSwing(g_CurrentSwingEntity);
  }
  CPlayerHero::UpdateMovementAndCollision(0);
  CPlayerHero::AdvanceAnimationScript();
  return;
}

