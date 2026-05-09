/*
State 0x28 Enter: CPlayerHero::EnterYoungSwimForward
Address: 0x00490300
*/


void CPlayerHero__EnterYoungSwimForward(void)

{
  int iVar1;
  
  if (g_PreviousPlayerActionState == 0x25) {
    CPlayerHero__PlayAnimation(0x7b);
  }
  else {
    CPlayerHero__PlayAnimation(0x7a);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 4;
    iVar1 = CPlayerHero__SteerYoungAirMoveHeadingTowardInput();
    if (0x400 < iVar1) {
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    }
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 1;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  g_PlayerTiltControlEnabled = 1;
  return;
}


