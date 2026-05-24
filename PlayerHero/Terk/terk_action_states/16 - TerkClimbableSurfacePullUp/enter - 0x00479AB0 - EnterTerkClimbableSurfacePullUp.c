/*
State 0x16 Enter: CPlayerHero::EnterTerkClimbableSurfacePullUp
Address: 0x00479AB0
*/


void CPlayerHero__EnterTerkClimbableSurfacePullUp(void)

{
  switch(g_PlayerCurrentAnimationId) {
  case 0x30:
  case 0x31:
    g_PlayerCurrentAnimationId = 0x32;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c308;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    return;
  default:
    g_PlayerCurrentAnimationId = 0x38;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c320;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    return;
  case 0x34:
  case 0x35:
    g_PlayerCurrentAnimationId = 0x36;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c318;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    return;
  }
}


