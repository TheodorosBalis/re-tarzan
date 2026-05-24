/*
State 0x1A Enter: CPlayerHero::EnterTerkClimbableWallMoveUp
Address: 0x00479250
*/


void CPlayerHero__EnterTerkClimbableWallMoveUp(void)

{
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if (g_PlayerCurrentAnimationId != 0x24) {
    if (g_PlayerCurrentAnimationId != 0x25) {
      g_PlayerCurrentAnimationId = 0x26;
      *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2d8;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero__AdvanceAnimationScript();
      return;
    }
    g_PlayerCurrentAnimationId = 0x28;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2e0;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 0x29;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2e4;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  return;
}


