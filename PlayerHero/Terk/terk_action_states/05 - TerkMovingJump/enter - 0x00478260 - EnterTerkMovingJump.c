/*
State 0x05 Enter: CPlayerHero::EnterTerkMovingJump
Address: 0x00478260
*/


void CPlayerHero__EnterTerkMovingJump(void)

{
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  g_PlayerCurrentAnimationId = 0xc;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c270;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x68;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 7;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 8;
  g_PlayerTargetMoveSpeed = 0x40;
  return;
}


