/*
State 0x22 Enter: CPlayerHero::EnterYoungClimbableEdgePullUp
Address: 0x0048F430
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048F430_CPlayerHero__EnterYoungClimbableEdgePullUp.c
*/


void CPlayerHero__EnterYoungClimbableEdgePullUp(void)

{
  switch(DAT_0051cdf0) {
  case 0x6b:
  case 0x6c:
    CPlayerHero__PlayAnimation(0x6d);
    return;
  default:
    CPlayerHero__PlayAnimation(0x73);
    return;
  case 0x6f:
  case 0x70:
    CPlayerHero__PlayAnimation(0x71);
    return;
  }
}


