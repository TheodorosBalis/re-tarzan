/*
State 0x1E Update: CPlayerHero::UpdateTerkClimbableFall
Address: 0x00479700
*/


void CPlayerHero__UpdateTerkClimbableFall(void)

{
  undefined2 uVar1;
  char cVar2;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  CPlayerHero__UpdateJumpArcVerticalMotion(0);
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TryResolveGroundContactSnap();
  uVar1 = g_PlayerActionState;
  if (cVar2 != '\0') {
    g_PlayerActionState = 0xc;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00479763. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkLandingRecovery_0050c1a8)();
    return;
  }
  CPlayerHero__AdvanceAnimationScript();
  return;
}


