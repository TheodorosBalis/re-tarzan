/*
State 0x05 Enter: CPlayerHero::EnterYoungTarzanMovingJump
Address: 0x0048DA10
*/


void CPlayerHero__EnterYoungTarzanMovingJump(void)

{
  CPlayerHero_PlayAnimation(0xc);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x4e;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 5;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 4;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
  g_PlayerTargetMoveSpeed = 0x2e;
  return;
}

