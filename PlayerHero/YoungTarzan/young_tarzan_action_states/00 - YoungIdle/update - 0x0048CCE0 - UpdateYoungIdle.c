/*
State 0x00 Update: CPlayerHero::UpdateYoungTarzanIdle
Address: 0x0048CCE0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungTarzanIdle(void)

{
  undefined2 uVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  ushort uVar5;
  bool bVar6;
  
  uVar1 = g_PlayerActionState;
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
        if (g_PlayerDamageInvulnerabilityTicks != 0) {
          return;
        }
        g_PlayerDamageInvulnerabilityTicks = 0x3c;
        g_PlayerDamageFlashTicks = 0x3c;
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
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero_ApplyDamageContactPushback();
  }
  uVar1 = g_PlayerActionState;
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
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
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionMode != 0)) {
    if (g_PlayerCurrentCollisionMode < 3) {
      cVar2 = CPlayerHero_IsFacingCurrentCollisionSurface();
      uVar1 = g_PlayerActionState;
      if (((cVar2 == '\0') && ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0)) &&
         (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 1;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x01 -> CPlayerHero::EnterYoungTarzanMoveForward */
        CPlayerHero__EnterYoungTarzanMoveForward();
        return;
      }
    }
    else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
      g_PlayerActionState = 0xe;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x0E -> CPlayerHero::EnterYoungTouchSurfaceOnSurfing */
      CPlayerHero__EnterYoungTouchSurfaceOnSurfing();
      return;
    }
  }
  uVar1 = g_PlayerActionState;
  uVar5 = g_PlayerSequenceFlags & 0xf000;
  if ((uVar5 == 0) && ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
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
  if (uVar5 == 0) {
    if ((g_PlayerInputPressedMask & 0x100000) != 0) {
      g_PlayerActionState = 0x2f;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x2F -> CPlayerHero::EnterYoungPound */
      CPlayerHero__EnterYoungPound();
      return;
    }
    if ((g_PlayerInputHeldMask & 0x80000) != 0) {
      g_PlayerActionState = 10;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x0A -> CPlayerHero::EnterYoungBlock */
      CPlayerHero__EnterYoungBlock();
      return;
    }
  }
  if (((uVar5 == 0) && ((DAT_0051cd16 & 0x10) != 0)) && ((g_PlayerInputHeldMask & 0x1000000) != 0))
  {
    g_PlayerActionState = 0x34;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x34 -> CPlayerHero::EnterYoungStabAnimation */
    CPlayerHero__EnterYoungStabAnimation();
    return;
  }
  if (uVar5 == 0) {
    if (((DAT_0051cd16 & 0x10) != 0) && ((g_PlayerInputHeldMask & 0x2000000) != 0)) {
      g_PlayerActionState = 0x35;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x35 -> CPlayerHero::EnterYoungAlternativeStabAnimation */
      CPlayerHero__EnterYoungAlternativeStabAnimation();
      return;
    }
    if ((g_PlayerInputHeldMask & 0x400000) != 0) {
      g_PlayerActionState = 0x32;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x32 -> CPlayerHero::EnterYoungThrowHigh */
      CPlayerHero__EnterYoungThrowHigh();
      return;
    }
    if ((g_PlayerInputHeldMask & 0x800000) != 0) {
      g_PlayerActionState = 0x33;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x33 -> CPlayerHero::EnterYoungThrowLow */
      CPlayerHero__EnterYoungThrowLow();
      return;
    }
  }
  CPlayerHero_UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero_TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 != '\0') {
    iVar4 = CPlayerHero_AdvanceAnimationScript();
    if ((iVar4 != 0) &&
       (sVar3 = g_PlayerIdleFidgetDelayTicks + -1, bVar6 = g_PlayerIdleFidgetDelayTicks < 0,
       g_PlayerIdleFidgetDelayTicks = sVar3, bVar6)) {
      CPlayerHero_PlayAnimation(4);
    }
    return;
  }
  g_PlayerActionState = 7;
  g_PreviousPlayerActionState = uVar1;
  /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
  return;
}

