#include "tarzan_ghidra_types.hpp"

// Address: 0x004710F0
// Label: CPlayerHero::UpdateTarzanSurfingWithJaneStaticPose
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateTarzanSurfingWithJaneStaticPose(void)

{
  CPlayerHero::UpdateMovementAndCollision(1);
  CPlayerHero::AdvanceAnimationScript();
  return;
}

