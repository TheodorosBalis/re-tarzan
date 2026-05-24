/*
State 0x1D Update: CPlayerHero::UpdateTerkClimbableWallTopOut
Address: 0x00479620
*/


void CPlayerHero__UpdateTerkClimbableWallTopOut(void)

{
  int iVar1;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  CPlayerHero__TrySnapDownToGround();
  if (g_PlayerJumpArcActive != '\0') {
    iVar1 = CPlayerHero__TryClampJumpArcToSurfaceCeiling(0x14e);
    if (iVar1 != 0) {
      *(int *)(g_PlayerSceneEntryData + 0xc) = iVar1;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 10;
      (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
      g_PlayerJumpArcActive = '\0';
    }
    CPlayerHero__UpdateJumpArcVerticalMotion(0);
  }
  iVar1 = CPlayerHero__AdvanceAnimationScript();
  if (iVar1 == 8) {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x20;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 4;
  }
  return;
}


