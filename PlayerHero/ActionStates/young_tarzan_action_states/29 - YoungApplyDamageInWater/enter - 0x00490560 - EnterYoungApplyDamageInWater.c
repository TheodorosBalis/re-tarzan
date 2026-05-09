/*
State 0x29 Enter: CPlayerHero::EnterYoungApplyDamageInWater
Address: 0x00490560
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00490560_CPlayerHero__EnterYoungApplyDamageInWater.c
*/


void CPlayerHero__EnterYoungApplyDamageInWater(void)

{
  CPlayerHero__PlayAnimation(0x7c);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  g_PlayerDamageFlashTicks = 0x3c;
  return;
}


