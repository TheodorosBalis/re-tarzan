/*
State 0x29 Update: CPlayerHero::UpdateYoungApplyDamageInWater
Address: 0x004905B0
*/


void CPlayerHero__UpdateYoungApplyDamageInWater(void)

{
  CPlayerHero_AdvanceAnimationScript();
  CPlayerHero_SpawnYoungWaterAttachmentEffects();
  CPlayerHero_UpdateMovementAndCollision(1);
  return;
}

