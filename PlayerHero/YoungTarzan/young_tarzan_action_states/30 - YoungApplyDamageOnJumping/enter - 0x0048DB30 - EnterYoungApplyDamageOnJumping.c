/*
State 0x30 Enter: CPlayerHero::EnterYoungApplyDamageOnJumping
Address: 0x0048DB30
*/


void CPlayerHero__EnterYoungApplyDamageOnJumping(void)

{
  CPlayerHero_PlayAnimation(0x10);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 7;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 4;
  g_PlayerTargetMoveSpeed = 0x20;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x4e;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  return;
}

