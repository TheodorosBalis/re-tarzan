/*
State 0x31 Enter: CPlayerHero::EnterYoungBouncingMode
Address: 0x0048DA80
*/


void CPlayerHero__EnterYoungBouncingMode(void)

{
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  CPlayerHero_PlayAnimation(0xf);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 7;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 4;
  DAT_0051cebc = DAT_0051cebc + 1;
  g_PlayerTargetMoveSpeed = 0x20;
  if (3 < DAT_0051cebc) {
    DAT_0051cebc = 3;
  }
  *(int *)(g_PlayerMotionState + 0x20) = DAT_0051cebc * 8 + 0x70;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  return;
}

