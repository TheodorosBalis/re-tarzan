/*
State 0x29 Update: CPlayerHero::UpdateYoungApplyDamageInWater
Address: 0x004905B0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\004905B0_CPlayerHero__UpdateYoungApplyDamageInWater.c
*/


void CPlayerHero__UpdateYoungApplyDamageInWater(void)

{
  CPlayerHero__AdvanceAnimationScript();
  CPlayerHero__SpawnYoungWaterAttachmentEffects();
  CPlayerHero__UpdateMovementAndCollision(1);
  return;
}


