/*
State 0x09 Enter: CPlayerHero::EnterTerkLongJump
Address: 0x00478590
*/


void CPlayerHero__EnterTerkLongJump(void)

{
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  g_PlayerCurrentAnimationId = 0xe;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c278;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 7;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0xa0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 8;
  g_PlayerTargetMoveSpeed = 0xa0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 200;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  return;
}


