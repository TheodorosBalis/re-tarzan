#include "tarzan_ghidra_types.hpp"

// Address: 0x004905B0
// Label: CPlayerHero::UpdateYoungApplyDamageInWater
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungApplyDamageInWater(void)

{
  CPlayerHero::AdvanceAnimationScript();
  CPlayerHero::SpawnYoungWaterAttachmentEffects();
  CPlayerHero::UpdateMovementAndCollision(1);
  return;
}

