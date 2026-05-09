/*
State 0x2D Enter: CPlayerHero::EnterYoungClimbableWallMoveUp
Address: 0x0048FA90
*/


void CPlayerHero__EnterYoungClimbableWallMoveUp(void)

{
  undefined4 uVar1;
  
  if (DAT_0051ce40 == '\0') {
    uVar1 = 0x82;
  }
  else {
    uVar1 = 0x83;
  }
  CPlayerHero__PlayAnimation(uVar1);
  *(int *)(g_PlayerSceneEntryData + 0xc) = *(int *)(g_PlayerSceneEntryData + 0xc) + 0x70;
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
  return;
}


