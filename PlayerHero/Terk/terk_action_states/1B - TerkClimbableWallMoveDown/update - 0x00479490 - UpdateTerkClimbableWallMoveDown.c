/*
State 0x1B Update: CPlayerHero::UpdateTerkClimbableWallMoveDown
Address: 0x00479490
*/


void CPlayerHero__UpdateTerkClimbableWallMoveDown(void)

{
  undefined2 uVar1;
  int iVar2;
  
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  iVar2 = CPlayerHero__AdvanceAnimationScript();
  if (iVar2 == 8) {
    *(int *)(g_PlayerSceneEntryData + 0xc) = *(int *)(g_PlayerSceneEntryData + 0xc) + 0xa0;
    uVar1 = g_PlayerActionState;
    if (g_PlayerInteractionCollisionHeightRange <
        *(int *)(g_PlayerSceneEntryData + 0xc) - g_PlayerInteractionCollisionBaseY) {
      *(int *)(g_PlayerSceneEntryData + 0xc) =
           g_PlayerInteractionCollisionHeightRange + g_PlayerInteractionCollisionBaseY;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x19;
                    /* WARNING: Could not recover jumptable at 0x0047950d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkClimbableWallIdle_0050c210)();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x40) == 0) {
      g_PlayerActionState = 0x19;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00479533. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkClimbableWallIdle_0050c210)();
      return;
    }
  }
  return;
}


