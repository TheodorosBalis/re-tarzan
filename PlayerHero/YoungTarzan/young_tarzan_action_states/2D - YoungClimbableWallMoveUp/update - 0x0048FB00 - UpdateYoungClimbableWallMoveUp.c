/*
State 0x2D Update: CPlayerHero::UpdateYoungClimbableWallMoveUp
Address: 0x0048FB00
*/


void CPlayerHero__UpdateYoungClimbableWallMoveUp(void)

{
  undefined2 uVar1;
  int iVar2;
  
  CPlayerHero_UpdateMovementAndCollision(1);
  iVar2 = CPlayerHero_AdvanceAnimationScript();
  if (iVar2 == 8) {
    *(int *)(g_PlayerSceneEntryData + 0xc) = *(int *)(g_PlayerSceneEntryData + 0xc) + 0x70;
    uVar1 = g_PlayerActionState;
    if (g_PlayerInteractionCollisionHeightRange <=
        *(int *)(g_PlayerSceneEntryData + 0xc) - g_PlayerInteractionCollisionBaseY) {
      *(int *)(g_PlayerSceneEntryData + 0xc) =
           g_PlayerInteractionCollisionHeightRange + g_PlayerInteractionCollisionBaseY;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x2b;
      /* table enter state 0x2B -> CPlayerHero::EnterYoungClimbableWallIdle */
      CPlayerHero__EnterYoungClimbableWallIdle();
      return;
    }
    if (((byte)g_PlayerInputHeldMask & 0x40) == 0) {
      g_PlayerActionState = 0x2b;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x2B -> CPlayerHero::EnterYoungClimbableWallIdle */
      CPlayerHero__EnterYoungClimbableWallIdle();
      return;
    }
  }
  return;
}

