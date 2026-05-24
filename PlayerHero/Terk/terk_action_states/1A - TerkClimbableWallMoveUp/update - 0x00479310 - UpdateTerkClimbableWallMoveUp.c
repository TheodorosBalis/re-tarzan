/*
State 0x1A Update: CPlayerHero::UpdateTerkClimbableWallMoveUp
Address: 0x00479310
*/


void CPlayerHero__UpdateTerkClimbableWallMoveUp(void)

{
  undefined2 uVar1;
  int iVar2;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  iVar2 = CPlayerHero__AdvanceAnimationScript();
  if (iVar2 == 8) {
    *(int *)(g_PlayerSceneEntryData + 0xc) = *(int *)(g_PlayerSceneEntryData + 0xc) + -0xa0;
    uVar1 = g_PlayerActionState;
    if (*(int *)(g_PlayerSceneEntryData + 0xc) - g_PlayerInteractionCollisionBaseY < 0x50) {
      *(int *)(g_PlayerSceneEntryData + 0xc) = g_PlayerInteractionCollisionBaseY;
      g_PreviousPlayerActionState = g_PlayerActionState;
      if (((byte)g_PlayerInputHeldMask & 0x10) == 0) {
        g_PlayerActionState = 0x19;
                    /* WARNING: Could not recover jumptable at 0x00479385. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)PTR_CPlayerHero__EnterTerkClimbableWallIdle_0050c210)();
        return;
      }
      g_PlayerActionState = 0x1d;
                    /* WARNING: Could not recover jumptable at 0x004793a2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkClimbableWallTopOut_0050c230)();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x10) == 0) {
      g_PlayerActionState = 0x19;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x004793c8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkClimbableWallIdle_0050c210)();
      return;
    }
  }
  return;
}


