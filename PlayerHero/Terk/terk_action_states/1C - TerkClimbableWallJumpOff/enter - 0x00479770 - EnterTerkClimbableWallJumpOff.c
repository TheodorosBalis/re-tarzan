/*
State 0x1C Enter: CPlayerHero::EnterTerkClimbableWallJumpOff
Address: 0x00479770
*/


void CPlayerHero__EnterTerkClimbableWallJumpOff(void)

{
  if (*(char *)(g_PlayerSceneEntry + 0x75) == '\0') {
    g_PlayerCurrentAnimationId = 0x2e;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2f8;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 0x2d;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2f4;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  return;
}


