/*
State 0x27 Enter: CPlayerHero::EnterYoungWaterTurn
Address: 0x0048FD80
*/


void CPlayerHero__EnterYoungWaterTurn(void)

{
  CPlayerHero_PlayAnimation(0x78);
  g_PlayerTiltControlEnabled = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 1;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  return;
}

