/*
State 0x2B Enter: CPlayerHero::EnterYoungClimbableWallIdle
Address: 0x0048F870
*/


void CPlayerHero__EnterYoungClimbableWallIdle(void)

{
  undefined4 uVar1;
  
  if (DAT_0051ce40 == '\0') {
    uVar1 = 0x7f;
  }
  else {
    uVar1 = 0x7e;
  }
  CPlayerHero__PlayAnimation(uVar1);
  if (g_PreviousPlayerActionState == 0x2d) {
    *(int *)(g_PlayerSceneEntryData + 0xc) = *(int *)(g_PlayerSceneEntryData + 0xc) + -0x70;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  g_PlayerTiltControlEnabled = 0;
  return;
}


