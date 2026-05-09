/*
State 0x03 Update: CPlayerHero::UpdateYoungTarzanTurnAround
Address: 0x0048D0F0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungTarzanTurnAround(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
  uVar1 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x05 -> CPlayerHero::EnterYoungTarzanMovingJump */
  CPlayerHero__EnterYoungTarzanMovingJump();
      return;
    }
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x06 -> CPlayerHero::EnterYoungTarzanStandingJump */
  CPlayerHero__EnterYoungTarzanStandingJump();
    return;
  }
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  uVar1 = g_PlayerActionState;
  if (iVar3 == 6) {
    if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
      g_PlayerActionState = 1;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x01 -> CPlayerHero::EnterYoungTarzanMoveForward */
  CPlayerHero__EnterYoungTarzanMoveForward();
    }
  }
  else if (iVar3 == 0xd) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x18;
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
    return;
  }
  return;
}


