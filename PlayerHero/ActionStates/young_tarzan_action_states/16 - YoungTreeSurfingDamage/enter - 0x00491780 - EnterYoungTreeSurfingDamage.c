/*
State 0x16 Enter: CPlayerHero::EnterYoungTreeSurfingDamage
Address: 0x00491780
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00491780_CPlayerHero__EnterYoungTreeSurfingDamage.c
*/


void CPlayerHero__EnterYoungTreeSurfingDamage(void)

{
  CPlayerHero__PlayAnimation(0x2c);
  DetachEntitySoundHandle(&DAT_0051ce90);
  QueuePlayerDamageEvent(0,6);
  FUN_004abce0(0,2,0x10);
  return;
}


