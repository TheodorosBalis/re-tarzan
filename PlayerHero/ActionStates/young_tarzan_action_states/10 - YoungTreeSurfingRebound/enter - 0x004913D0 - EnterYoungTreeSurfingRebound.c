/*
State 0x10 Enter: CPlayerHero::EnterYoungTreeSurfingRebound
Address: 0x004913D0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\004913D0_CPlayerHero__EnterYoungTreeSurfingRebound.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__EnterYoungTreeSurfingRebound(void)

{
  undefined4 uVar1;
  
  if (DAT_0051cdf0 == 0x2e) {
    uVar1 = 0x25;
  }
  else if (DAT_0051cdf0 == 0x31) {
    uVar1 = 0x26;
  }
  else if (DAT_0051cdf0 == 0x34) {
    uVar1 = 0x27;
  }
  else {
    uVar1 = 0x24;
  }
  CPlayerHero__PlayAnimation(uVar1);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0xe;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 0xf;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = DAT_0051ce00;
  _DAT_0053a2c0 = 0;
  g_PlayerTargetMoveSpeed = *(undefined4 *)(g_PlayerMotionState + 0x10);
  return;
}


