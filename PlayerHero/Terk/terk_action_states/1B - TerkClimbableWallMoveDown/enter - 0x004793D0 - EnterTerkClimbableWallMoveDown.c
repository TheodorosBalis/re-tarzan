/*
State 0x1B Enter: CPlayerHero::EnterTerkClimbableWallMoveDown
Address: 0x004793D0
*/


void CPlayerHero__EnterTerkClimbableWallMoveDown(void)

{
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if (g_PlayerCurrentAnimationId != 0x24) {
    if (g_PlayerCurrentAnimationId != 0x25) {
      g_PlayerCurrentAnimationId = 0x27;
      *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2dc;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero__AdvanceAnimationScript();
      return;
    }
    g_PlayerCurrentAnimationId = 0x2b;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2ec;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 0x2a;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2e8;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  return;
}


