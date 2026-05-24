/*
State 0x11 Enter: CPlayerHero::EnterTerkCrouch
Address: 0x00477AB0
*/


void CPlayerHero__EnterTerkCrouch(void)

{
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  if ((g_PreviousPlayerActionState < 2) || (3 < g_PreviousPlayerActionState)) {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x10;
    g_PlayerCurrentAnimationId = 0x21;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2c4;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
  }
  else {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x10;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x10;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  *(undefined2 *)(g_PlayerSceneEntry + 0x142) = 0xa0;
  return;
}


