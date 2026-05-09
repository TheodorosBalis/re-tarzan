/*
State 0x02 Update: CPlayerHero::UpdateYoungTarzanStopForwardMovement
Address: 0x0048D680
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungTarzanStopForwardMovement(void)

{
  undefined2 uVar1;
  char cVar2;
  
  CPlayerHero_UpdateMovementAndCollision(1);
  uVar1 = g_PlayerActionState;
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (DAT_0051cd1c != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x29 -> CPlayerHero::EnterYoungApplyDamageInWater */
        CPlayerHero__EnterYoungApplyDamageInWater();
        return;
      }
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0x30;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x30 -> CPlayerHero::EnterYoungApplyDamageOnJumping */
        CPlayerHero__EnterYoungApplyDamageOnJumping();
        if (g_PlayerDamageInvulnerabilityTicks == 0) {
          g_PlayerDamageInvulnerabilityTicks = 0x3c;
          g_PlayerDamageFlashTicks = 0x3c;
        }
        return;
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x13 -> CPlayerHero::EnterYoungApplyDamageOnTreeSurfing */
      CPlayerHero__EnterYoungApplyDamageOnTreeSurfing();
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x29 -> CPlayerHero::EnterYoungApplyDamageInWater */
        CPlayerHero__EnterYoungApplyDamageInWater();
        return;
      }
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0xc;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x0C -> CPlayerHero::EnterYoungPlayerDamage */
        CPlayerHero__EnterYoungPlayerDamage();
        return;
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x13 -> CPlayerHero::EnterYoungApplyDamageOnTreeSurfing */
      CPlayerHero__EnterYoungApplyDamageOnTreeSurfing();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero_ApplyDamageContactPushback();
  }
  cVar2 = CPlayerHero_TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
    CPlayerHero__EnterYoungTarzanFalling();
  }
  uVar1 = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (g_PlayerCurrentCollisionMode != 0) {
      if (g_PlayerCurrentCollisionMode < 3) {
        cVar2 = CPlayerHero_IsFacingCurrentCollisionSurface();
        uVar1 = g_PlayerActionState;
        if (((cVar2 == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 1;
          g_PreviousPlayerActionState = uVar1;
          /* table enter state 0x01 -> CPlayerHero::EnterYoungTarzanMoveForward */
          CPlayerHero__EnterYoungTarzanMoveForward();
        }
      }
      else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 0xe;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x0E -> CPlayerHero::EnterYoungTouchSurfaceOnSurfing */
        CPlayerHero__EnterYoungTouchSurfaceOnSurfing();
      }
    }
  }
  uVar1 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) {
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
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
    if (g_PlayerCurrentCollisionMode == 2) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x03 -> CPlayerHero::EnterYoungTarzanTurnAround */
      CPlayerHero__EnterYoungTarzanTurnAround();
    }
    else if ((g_PlayerInputHeldMask & 0x80) == 0) {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + 0x2d;
    }
    else {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + -0x2d;
    }
  }
  CPlayerHero_AdvanceAnimationScript();
  return;
}

