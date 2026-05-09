/*
State 0x23 Enter: CPlayerHero::EnterYoungClimbableSurfaceJumpOff
Address: 0x0048F5E0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048F5E0_CPlayerHero__EnterYoungClimbableSurfaceJumpOff.c
*/


void CPlayerHero__EnterYoungClimbableSurfaceJumpOff(void)

{
  if (*(char *)(g_PlayerSceneEntry + 0x75) == '\0') {
    CPlayerHero__PlayAnimation(0x72);
    return;
  }
  CPlayerHero__PlayAnimation(0x6e);
  return;
}


