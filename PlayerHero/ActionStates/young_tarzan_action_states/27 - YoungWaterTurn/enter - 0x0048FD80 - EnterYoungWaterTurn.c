/*
State 0x27 Enter: CPlayerHero::EnterYoungWaterTurn
Address: 0x0048FD80
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048FD80_CPlayerHero__EnterYoungWaterTurn.c
*/


void CPlayerHero__EnterYoungWaterTurn(void)

{
  CPlayerHero__PlayAnimation(0x78);
  g_PlayerTiltControlEnabled = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 1;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  return;
}


