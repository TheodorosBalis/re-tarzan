/*
State 0x12 Enter: CPlayerHero::EnterTerkCrouchLook
Address: 0x00477E30
*/


void CPlayerHero__EnterTerkCrouchLook(void)

{
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  g_PlayerCurrentAnimationId = 0x22;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2c8;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  return;
}


