/*
State 0x0B Enter: CPlayerHero::EnterYoungBlock
Address: 0x0048E5E0
*/


void CPlayerHero__EnterYoungBlock(void)

{
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  CPlayerHero__PlayAnimation(0x1a);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  return;
}


