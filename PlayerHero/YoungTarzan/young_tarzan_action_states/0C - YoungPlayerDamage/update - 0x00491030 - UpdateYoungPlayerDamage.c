/*
State 0x0C Update: CPlayerHero::UpdateYoungPlayerDamage
Address: 0x00491030
*/


void CPlayerHero__UpdateYoungPlayerDamage(void)

{
  undefined2 uVar1;
  char cVar2;
  ushort uVar3;
  
  CPlayerHero_ApplyDamageContactPushback();
  CPlayerHero_UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero_TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
    CPlayerHero__EnterYoungTarzanFalling();
  }
  uVar1 = g_PlayerActionState;
  if (DAT_0051cdf0 == 0x21) {
    uVar3 = g_PlayerSequenceFlags & 0xf000;
    if ((uVar3 == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) == 0) {
        g_PlayerActionState = 6;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x06 -> CPlayerHero::EnterYoungTarzanStandingJump */
        CPlayerHero__EnterYoungTarzanStandingJump();
        return;
      }
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x05 -> CPlayerHero::EnterYoungTarzanMovingJump */
      CPlayerHero__EnterYoungTarzanMovingJump();
      return;
    }
    if ((uVar3 == 0) && ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
      if (g_PlayerCurrentCollisionMode == 2) {
        g_PlayerActionState = 3;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x03 -> CPlayerHero::EnterYoungTarzanTurnAround */
        CPlayerHero__EnterYoungTarzanTurnAround();
        return;
      }
      if ((g_PlayerInputHeldMask & 0x80) == 0) {
        g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + 0x2d;
      }
      else {
        g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + -0x2d;
      }
    }
    if (uVar3 == 0) {
      if ((g_PlayerInputHeldMask & 0x80000) != 0) {
        g_PlayerActionState = 10;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x0A -> CPlayerHero::EnterYoungBlock */
        CPlayerHero__EnterYoungBlock();
        return;
      }
      if ((g_PlayerInputPressedMask & 0x100000) != 0) {
        g_PlayerActionState = 0x2f;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x2F -> CPlayerHero::EnterYoungPound */
        CPlayerHero__EnterYoungPound();
        return;
      }
    }
  }
  else {
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
    }
    if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
    }
    g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  }
  CPlayerHero_AdvanceAnimationScript();
  return;
}

