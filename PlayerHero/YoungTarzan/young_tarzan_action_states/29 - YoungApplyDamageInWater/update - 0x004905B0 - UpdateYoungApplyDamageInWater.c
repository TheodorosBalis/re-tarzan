/*
State 0x29 Update: CPlayerHero::UpdateYoungApplyDamageInWater
Address: 0x004905B0
*/


void CPlayerHero__UpdateYoungApplyDamageInWater(void)

{
  CPlayerHero__AdvanceAnimationScript();
  CPlayerHero__SpawnYoungWaterAttachmentEffects();
  CPlayerHero__UpdateMovementAndCollision(1);
  return;
}


