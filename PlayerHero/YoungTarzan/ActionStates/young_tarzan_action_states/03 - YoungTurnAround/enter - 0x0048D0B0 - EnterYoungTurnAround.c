/*
State 0x03 Enter: CPlayerHero::EnterYoungTarzanTurnAround
Address: 0x0048D0B0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048D0B0_CPlayerHero__EnterYoungTarzanTurnAround.c
*/


void CPlayerHero__EnterYoungTarzanTurnAround(void)

{
  undefined4 uVar1;
  
  if (g_PreviousPlayerActionState == 1) {
    uVar1 = 0xb;
  }
  else {
    uVar1 = 10;
  }
  CPlayerHero__PlayAnimation(uVar1);
  *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  return;
}


