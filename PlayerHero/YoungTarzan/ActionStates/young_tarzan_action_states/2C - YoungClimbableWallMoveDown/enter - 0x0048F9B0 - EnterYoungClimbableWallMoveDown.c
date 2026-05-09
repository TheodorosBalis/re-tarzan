/*
State 0x2C Enter: CPlayerHero::EnterYoungClimbableWallMoveDown
Address: 0x0048F9B0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048F9B0_CPlayerHero__EnterYoungClimbableWallMoveDown.c
*/


void CPlayerHero__EnterYoungClimbableWallMoveDown(void)

{
  if (DAT_0051ce40 == '\0') {
    CPlayerHero__PlayAnimation(0x80);
    return;
  }
  CPlayerHero__PlayAnimation(0x81);
  return;
}


