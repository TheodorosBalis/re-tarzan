/*
State 0x32 Update: CPlayerHero::UpdateYoungThrow
Address: 0x0048EC60
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungThrow(void)

{
  short sVar1;
  char cVar2;
  int iVar3;
  
  sVar1 = g_PlayerActionState;
  if (DAT_0051cd1c == '\0') {
LAB_0048ed49:
    sVar1 = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
       ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
      if (g_PlayerCurrentCollisionMode == 2) {
        g_PlayerActionState = 3;
        g_PreviousPlayerActionState = sVar1;
        /* table enter state 0x03 -> CPlayerHero::EnterYoungTarzanTurnAround */
        CPlayerHero__EnterYoungTarzanTurnAround();
        DAT_005314ac = 0;
        return;
      }
      if ((g_PlayerInputHeldMask & 0x80) == 0) {
        g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + 0x2d;
      }
      else {
        g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + -0x2d;
      }
    }
    if ((((DAT_0051cdf0 == 0x87) || (DAT_0051cdf0 == 0x8c)) &&
        ((_g_PlayerSequenceFlags & 0xf000) == 0)) && (g_PlayerCurrentCollisionMode != 0)) {
      if (g_PlayerCurrentCollisionMode < 3) {
        cVar2 = CPlayerHero_IsFacingCurrentCollisionSurface();
        sVar1 = g_PlayerActionState;
        if (((cVar2 == '\0') && ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0)) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 1;
          g_PreviousPlayerActionState = sVar1;
          /* table enter state 0x01 -> CPlayerHero::EnterYoungTarzanMoveForward */
          CPlayerHero__EnterYoungTarzanMoveForward();
          return;
        }
      }
      else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 0xe;
        g_PreviousPlayerActionState = sVar1;
        /* table enter state 0x0E -> CPlayerHero::EnterYoungTouchSurfaceOnSurfing */
        CPlayerHero__EnterYoungTouchSurfaceOnSurfing();
        return;
      }
    }
    sVar1 = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) {
        g_PlayerActionState = 5;
        g_PreviousPlayerActionState = sVar1;
        /* table enter state 0x05 -> CPlayerHero::EnterYoungTarzanMovingJump */
        CPlayerHero__EnterYoungTarzanMovingJump();
        return;
      }
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = sVar1;
      /* table enter state 0x06 -> CPlayerHero::EnterYoungTarzanStandingJump */
      CPlayerHero__EnterYoungTarzanStandingJump();
      return;
    }
    CPlayerHero_UpdateMovementAndCollision(1);
    iVar3 = CPlayerHero_AdvanceAnimationScript();
    if (iVar3 == 4) {
      InstantiateRuntimeEntryByTypeAtPosition(0,0,0,0xf,0x11);
    }
    else {
      if (iVar3 == 8) {
        if (DAT_005314ac != 0) {
          *(undefined2 *)(DAT_005314ac + 0x48) = 7;
        }
        DAT_005314ac = 0;
        return;
      }
      if (iVar3 == 0x12) {
        if (g_PlayerActionState == 0x32) {
          if ((g_PlayerInputHeldMask & 0x400000) != 0) {
            *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
            return;
          }
          if ((g_PlayerInputHeldMask & 0x800000) != 0) {
            CPlayerHero_PlayAnimation(0x88);
            g_PlayerActionState = 0x33;
            return;
          }
          CPlayerHero_PlayAnimation(0x87);
          return;
        }
        if (g_PlayerActionState == 0x33) {
          if ((g_PlayerInputHeldMask & 0x800000) != 0) {
            *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
            return;
          }
          if ((g_PlayerInputHeldMask & 0x400000) != 0) {
            CPlayerHero_PlayAnimation(0x84);
            g_PlayerActionState = 0x32;
            return;
          }
          CPlayerHero_PlayAnimation(0x8c);
          return;
        }
      }
    }
    return;
  }
  if ((ram0x0051cdca & 0x1000) == 0) {
    if (g_PlayerDamageInvulnerabilityTicks != 0) {
      g_PlayerCollisionFacingFlags = '\x01';
      CPlayerHero_ApplyDamageContactPushback();
      goto LAB_0048ed49;
    }
    if (g_PlayerCurrentCollisionMode != 4) {
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0xc;
        g_PreviousPlayerActionState = sVar1;
        /* table enter state 0x0C -> CPlayerHero::EnterYoungPlayerDamage */
        CPlayerHero__EnterYoungPlayerDamage();
        return;
      }
      goto LAB_0048ecff;
    }
  }
  else if (g_PlayerCurrentCollisionMode != 4) {
    if (g_PlayerCurrentCollisionMode != 5) {
      g_PlayerActionState = 0x30;
      g_PreviousPlayerActionState = sVar1;
      /* table enter state 0x30 -> CPlayerHero::EnterYoungApplyDamageOnJumping */
      CPlayerHero__EnterYoungApplyDamageOnJumping();
      if (g_PlayerDamageInvulnerabilityTicks != 0) {
        return;
      }
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
      return;
    }
LAB_0048ecff:
    g_PlayerActionState = 0x13;
    g_PreviousPlayerActionState = sVar1;
    /* table enter state 0x13 -> CPlayerHero::EnterYoungApplyDamageOnTreeSurfing */
    CPlayerHero__EnterYoungApplyDamageOnTreeSurfing();
    return;
  }
  g_PlayerActionState = 0x29;
  g_PreviousPlayerActionState = sVar1;
  /* table enter state 0x29 -> CPlayerHero::EnterYoungApplyDamageInWater */
  CPlayerHero__EnterYoungApplyDamageInWater();
  return;
}

