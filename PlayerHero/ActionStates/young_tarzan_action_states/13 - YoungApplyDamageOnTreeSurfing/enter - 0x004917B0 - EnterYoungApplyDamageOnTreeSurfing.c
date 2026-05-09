/*
State 0x13 Enter: CPlayerHero::EnterYoungApplyDamageOnTreeSurfing
Address: 0x004917B0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\004917B0_CPlayerHero__EnterYoungApplyDamageOnTreeSurfing.c
*/


void CPlayerHero__EnterYoungApplyDamageOnTreeSurfing(void)

{
  CPlayerHero__PlayAnimation(0x2b);
  DetachEntitySoundHandle(&DAT_0051ce90);
  FUN_004abce0(0,2,0x10);
  return;
}


