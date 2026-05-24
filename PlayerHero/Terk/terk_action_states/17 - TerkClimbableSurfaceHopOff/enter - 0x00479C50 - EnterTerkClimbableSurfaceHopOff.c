/*
State 0x17 Enter: CPlayerHero::EnterTerkClimbableSurfaceHopOff
Address: 0x00479C50
*/


void CPlayerHero__EnterTerkClimbableSurfaceHopOff(void)

{
  if (*(char *)(g_PlayerSceneEntry + 0x75) == '\0') {
    g_PlayerCurrentAnimationId = 0x37;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c31c;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 0x33;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c30c;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  return;
}


