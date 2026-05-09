/*
State 0x01 Enter: CPlayerHero::EnterYoungTarzanMoveForward
Address: 0x0048D1E0
*/


void CPlayerHero__EnterYoungTarzanMoveForward(void)

{
  switch(g_PreviousPlayerActionState) {
  case 2:
  case 3:
    CPlayerHero__PlayAnimation(2);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x18;
    break;
  default:
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    CPlayerHero__PlayAnimation(1);
    break;
  case 9:
    CPlayerHero__PlayAnimation(3);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x18;
    break;
  case 0x22:
    CPlayerHero__PlayAnimation(0x74);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 3;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 3;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  return;
}


