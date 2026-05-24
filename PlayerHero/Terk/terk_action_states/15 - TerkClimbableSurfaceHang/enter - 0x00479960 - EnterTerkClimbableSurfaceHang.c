/*
State 0x15 Enter: CPlayerHero::EnterTerkClimbableSurfaceHang
Address: 0x00479960
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__EnterTerkClimbableSurfaceHang(void)

{
  undefined2 uVar1;
  
  uVar1 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && (((byte)g_PlayerInputHeldMask & 0x10) != 0)) {
    g_PlayerActionState = 0x16;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00479988. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkClimbableSurfacePullUp_0050c1f8)();
    return;
  }
  if (*(char *)(g_PlayerSceneEntry + 0x75) == '\0') {
    g_PlayerCurrentAnimationId = 0x34;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c310;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    return;
  }
  g_PlayerCurrentAnimationId = 0x30;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c300;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  return;
}


