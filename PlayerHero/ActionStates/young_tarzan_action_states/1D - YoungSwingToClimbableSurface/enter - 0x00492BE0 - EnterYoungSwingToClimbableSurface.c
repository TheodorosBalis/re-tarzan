/*
State 0x1D Enter: CPlayerHero::EnterYoungSwingToClimbableSurface
Address: 0x00492BE0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00492BE0_CPlayerHero__EnterYoungSwingToClimbableSurface.c
*/


void CPlayerHero__EnterYoungSwingToClimbableSurface(void)

{
  if (DAT_0051ce40 == '\0') {
    CPlayerHero__PlayAnimation(0x53);
    return;
  }
  CPlayerHero__PlayAnimation(0x57);
  return;
}


