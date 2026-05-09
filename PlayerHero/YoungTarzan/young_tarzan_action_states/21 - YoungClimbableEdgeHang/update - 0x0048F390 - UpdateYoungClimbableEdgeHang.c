/*
State 0x21 Update: CPlayerHero::UpdateYoungClimbableEdgeHang
Address: 0x0048F390
*/


void CPlayerHero__UpdateYoungClimbableEdgeHang(void)

{
  undefined2 uVar1;
  char cVar2;
  
  uVar1 = g_PlayerActionState;
  if (((g_PlayerSequenceFlags & 0xf000) == 0) &&
     (((g_CameraFollowFlags | 0x10) & g_PlayerInputHeldMask) != 0)) {
    g_PlayerActionState = 0x22;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x22 -> CPlayerHero::EnterYoungClimbableEdgePullUp */
    CPlayerHero__EnterYoungClimbableEdgePullUp();
    return;
  }
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 0x23;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x23 -> CPlayerHero::EnterYoungClimbableSurfaceJumpOff */
    CPlayerHero__EnterYoungClimbableSurfaceJumpOff();
    return;
  }
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

