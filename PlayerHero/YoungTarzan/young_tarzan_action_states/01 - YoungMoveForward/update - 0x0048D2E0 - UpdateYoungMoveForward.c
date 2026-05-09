/*
State 0x01 Update: CPlayerHero::UpdateYoungTarzanMoveForward
Address: 0x0048D2E0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungTarzanMoveForward(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
  uVar1 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 5;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x05 -> CPlayerHero::EnterYoungTarzanMovingJump */
  CPlayerHero__EnterYoungTarzanMovingJump();
    return;
  }
  if (DAT_0051cd1c == '\0') {
    if ((((_g_PlayerSequenceFlags & 0xf000) == 0) && ((DAT_0051cd16 & 0x10) != 0)) &&
       ((g_PlayerInputHeldMask & 0x1000000) != 0)) {
      g_PlayerActionState = 0x34;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x34 -> CPlayerHero::EnterYoungStabAnimation */
  CPlayerHero__EnterYoungStabAnimation();
      CPlayerHero__PlayAnimation(0x8f);
    }
    else {
      if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
        if (((DAT_0051cd16 & 0x10) != 0) && ((g_PlayerInputHeldMask & 0x2000000) != 0)) {
          g_PlayerActionState = 0x35;
          g_PreviousPlayerActionState = uVar1;
          /* table enter state 0x35 -> CPlayerHero::EnterYoungAlternativeStabAnimation */
  CPlayerHero__EnterYoungAlternativeStabAnimation();
          CPlayerHero__PlayAnimation(0x92);
          return;
        }
        if ((g_PlayerInputHeldMask & 0x400000) != 0) {
          g_PlayerActionState = 0x32;
          g_PreviousPlayerActionState = uVar1;
          /* table enter state 0x32 -> CPlayerHero::EnterYoungThrowHigh */
  CPlayerHero__EnterYoungThrowHigh();
          CPlayerHero__PlayAnimation(0x86);
          return;
        }
        if ((g_PlayerInputHeldMask & 0x800000) != 0) {
          g_PlayerActionState = 0x33;
          g_PreviousPlayerActionState = uVar1;
          /* table enter state 0x33 -> CPlayerHero::EnterYoungThrowLow */
  CPlayerHero__EnterYoungThrowLow();
          CPlayerHero__PlayAnimation(0x8b);
          return;
        }
      }
      iVar3 = CPlayerHero__AdvanceAnimationScript();
      if (iVar3 == 7) {
        CPlayerHero__PlayAnimation(3);
      }
      else if (iVar3 == 0xd) {
        *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x18;
      }
      uVar1 = g_PlayerActionState;
      if ((g_PlayerInputHeldMask & (g_CameraFollowFlags | g_CameraRelativeTurnInputMask)) == 0) {
        g_PlayerActionState = 2;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x02 -> CPlayerHero::EnterYoungTarzanStopForwardMovement */
  CPlayerHero__EnterYoungTarzanStopForwardMovement();
      }
      else if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
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
      CPlayerHero__UpdateMovementAndCollision(1);
      cVar2 = CPlayerHero__TrySnapToNearbyGround();
      uVar1 = g_PlayerActionState;
      if (cVar2 == '\0') {
        g_PlayerActionState = 7;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
      }
      uVar1 = g_PlayerActionState;
      if (g_PlayerCollisionFacingFlags != '\0') {
        g_PlayerActionState = 2;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x02 -> CPlayerHero::EnterYoungTarzanStopForwardMovement */
  CPlayerHero__EnterYoungTarzanStopForwardMovement();
        return;
      }
    }
  }
  else {
    if ((ram0x0051cdca & 0x1000) == 0) {
      if (g_PlayerCurrentCollisionMode == 2) {
        g_PlayerActionState = 0xc;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x0C -> CPlayerHero::EnterYoungPlayerDamage */
  CPlayerHero__EnterYoungPlayerDamage();
        return;
      }
      if (g_PlayerCurrentCollisionMode == 5) {
        g_PlayerActionState = 0x13;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x13 -> CPlayerHero::EnterYoungApplyDamageOnTreeSurfing */
  CPlayerHero__EnterYoungApplyDamageOnTreeSurfing();
        return;
      }
      g_PlayerActionState = 0xc;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x0C -> CPlayerHero::EnterYoungPlayerDamage */
  CPlayerHero__EnterYoungPlayerDamage();
      return;
    }
    g_PlayerActionState = 0x30;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x30 -> CPlayerHero::EnterYoungApplyDamageOnJumping */
  CPlayerHero__EnterYoungApplyDamageOnJumping();
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
      return;
    }
  }
  return;
}


