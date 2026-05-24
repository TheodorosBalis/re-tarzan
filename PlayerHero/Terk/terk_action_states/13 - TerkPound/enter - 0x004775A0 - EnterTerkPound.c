/*
State 0x13 Enter: CPlayerHero::EnterTerkPound
Address: 0x004775A0
*/


void CPlayerHero__EnterTerkPound(void)

{
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  g_PlayerCurrentAnimationId = 0x17;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c29c;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  return;
}


