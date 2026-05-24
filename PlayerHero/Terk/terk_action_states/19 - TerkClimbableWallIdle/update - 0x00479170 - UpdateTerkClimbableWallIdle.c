/*
State 0x19 Update: CPlayerHero::UpdateTerkClimbableWallIdle
Address: 0x00479170
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateTerkClimbableWallIdle(void)

{
  undefined2 uVar1;
  
  CPlayerHero__UpdateMovementAndCollision(1);
  CPlayerHero__AdvanceAnimationScript();
  uVar1 = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (((byte)g_PlayerInputHeldMask & 0x10) != 0) {
      if (*(int *)(g_PlayerSceneEntryData + 0xc) - g_PlayerInteractionCollisionBaseY < 0x50) {
        *(int *)(g_PlayerSceneEntryData + 0xc) = g_PlayerInteractionCollisionBaseY;
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0x1d;
                    /* WARNING: Could not recover jumptable at 0x004791c3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)PTR_CPlayerHero__EnterTerkClimbableWallTopOut_0050c230)();
        return;
      }
      g_PlayerActionState = 0x1a;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x004791e0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkClimbableWallMoveUp_0050c218)();
      return;
    }
    if ((((byte)g_PlayerInputHeldMask & 0x40) != 0) &&
       (*(int *)(g_PlayerSceneEntryData + 0xc) - g_PlayerInteractionCollisionBaseY <
        g_PlayerInteractionCollisionHeightRange)) {
      g_PlayerActionState = 0x1b;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x0047921c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkClimbableWallMoveDown_0050c220)();
      return;
    }
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_PlayerActionState = 0x1c;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00479245. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkClimbableWallJumpOff_0050c228)();
      return;
    }
  }
  return;
}


