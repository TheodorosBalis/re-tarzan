/*
State 0x15 Update: CPlayerHero::UpdateTerkClimbableSurfaceHang
Address: 0x00479A10
*/


void CPlayerHero__UpdateTerkClimbableSurfaceHang(void)

{
  undefined2 uVar1;
  char cVar2;
  
  uVar1 = g_PlayerActionState;
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && (((byte)g_PlayerInputHeldMask & 0x10) != 0)) {
    g_PlayerActionState = 0x16;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00479a3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkClimbableSurfacePullUp_0050c1f8)();
    return;
  }
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 0x17;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00479a68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkClimbableSurfaceHopOff_0050c200)();
    return;
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = uVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
  }
  CPlayerHero__AdvanceAnimationScript();
  return;
}


