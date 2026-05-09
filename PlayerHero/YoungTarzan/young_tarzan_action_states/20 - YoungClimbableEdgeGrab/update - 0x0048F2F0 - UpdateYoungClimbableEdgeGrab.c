/*
State 0x20 Update: CPlayerHero::UpdateYoungClimbableEdgeGrab
Address: 0x0048F2F0
*/


void CPlayerHero__UpdateYoungClimbableEdgeGrab(void)

{
  undefined2 uVar1;
  char cVar2;
  
  CPlayerHero_UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero_TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
    CPlayerHero__EnterYoungTarzanFalling();
  }
  CPlayerHero_AdvanceAnimationScript();
  return;
}

