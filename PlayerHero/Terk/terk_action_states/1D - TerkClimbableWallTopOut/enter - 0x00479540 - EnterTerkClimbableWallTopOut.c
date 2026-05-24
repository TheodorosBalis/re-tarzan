/*
State 0x1D Enter: CPlayerHero::EnterTerkClimbableWallTopOut
Address: 0x00479540
*/


void CPlayerHero__EnterTerkClimbableWallTopOut(void)

{
  g_PlayerCurrentAnimationId = 0x2c;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2f0;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x58;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 7;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 8;
  g_PlayerTargetMoveSpeed = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerJumpArcActive = 0;
  return;
}


