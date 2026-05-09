/*
State 0x3A Enter: CPlayerHero::EnterYoungTutorialPickupFinalPose
Address: 0x00490DD0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00490DD0_CPlayerHero__EnterYoungTutorialPickupFinalPose.c
*/


void CPlayerHero__EnterYoungTutorialPickupFinalPose(void)

{
  DAT_0053a2d0 = 0;
  DAT_0053a2e4 = *(undefined4 *)(&DAT_00515240 + DAT_0053a2dc * 0x30);
  DAT_0053a2cc = *(undefined4 *)(&DAT_00515244 + DAT_0053a2dc * 0x30);
  CPlayerHero__PlayAnimation(0x9f);
  return;
}


