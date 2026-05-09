/*
State 0x2F Update: CPlayerHero::UpdateYoungPound
Address: 0x0048E860
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048E860_CPlayerHero__UpdateYoungPound.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungPound(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
  uVar1 = g_PlayerActionState;
  if (DAT_0051cd1c != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
LAB_0048e949:
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x29 -> CPlayerHero::EnterYoungApplyDamageInWater */
  CPlayerHero__EnterYoungApplyDamageInWater();
        DetachEntitySoundHandle(&DAT_0051ce90);
        return;
      }
      if (g_PlayerCurrentCollisionMode == 5) {
LAB_0048e91e:
        g_PlayerActionState = 0x13;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x13 -> CPlayerHero::EnterYoungApplyDamageOnTreeSurfing */
  CPlayerHero__EnterYoungApplyDamageOnTreeSurfing();
        DetachEntitySoundHandle(&DAT_0051ce90);
        return;
      }
      g_PlayerActionState = 0x30;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x30 -> CPlayerHero::EnterYoungApplyDamageOnJumping */
  CPlayerHero__EnterYoungApplyDamageOnJumping();
      if (g_PlayerDamageInvulnerabilityTicks == 0) {
        g_PlayerDamageInvulnerabilityTicks = 0x3c;
        g_PlayerDamageFlashTicks = 0x3c;
        DetachEntitySoundHandle(&DAT_0051ce90);
        return;
      }
      goto LAB_0048eb17;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      if (g_PlayerCurrentCollisionMode != 4) {
        if (g_PlayerCurrentCollisionMode != 5) {
          g_PlayerActionState = 0xc;
          g_PreviousPlayerActionState = uVar1;
          /* table enter state 0x0C -> CPlayerHero::EnterYoungPlayerDamage */
  CPlayerHero__EnterYoungPlayerDamage();
          DetachEntitySoundHandle(&DAT_0051ce90);
          return;
        }
        goto LAB_0048e91e;
      }
      goto LAB_0048e949;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero__ApplyDamageContactPushback();
  }
  uVar1 = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (g_PlayerCurrentCollisionMode != 0) {
      if (g_PlayerCurrentCollisionMode < 3) {
        cVar2 = CPlayerHero__IsFacingCurrentCollisionSurface();
        uVar1 = g_PlayerActionState;
        if (((cVar2 == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 1;
          g_PreviousPlayerActionState = uVar1;
          /* table enter state 0x01 -> CPlayerHero::EnterYoungTarzanMoveForward */
  CPlayerHero__EnterYoungTarzanMoveForward();
          DetachEntitySoundHandle(&DAT_0051ce90);
          return;
        }
      }
      else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 0xe;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x0E -> CPlayerHero::EnterYoungTouchSurfaceOnSurfing */
  CPlayerHero__EnterYoungTouchSurfaceOnSurfing();
        DetachEntitySoundHandle(&DAT_0051ce90);
        return;
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
      DetachEntitySoundHandle(&DAT_0051ce90);
      return;
    }
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x06 -> CPlayerHero::EnterYoungTarzanStandingJump */
  CPlayerHero__EnterYoungTarzanStandingJump();
    DetachEntitySoundHandle(&DAT_0051ce90);
    return;
  }
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputHeldMask & 0x80000) != 0)) {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x0A -> CPlayerHero::EnterYoungBlock */
  CPlayerHero__EnterYoungBlock();
    DetachEntitySoundHandle(&DAT_0051ce90);
    return;
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 != '\0') {
    iVar3 = CPlayerHero__AdvanceAnimationScript();
    if ((iVar3 == 8) && ((g_PlayerInputHeldMask & 0x100000) == 0)) {
      DetachEntitySoundHandle(&DAT_0051ce90);
      CPlayerHero__PlayAnimation(0x1f);
    }
    return;
  }
  g_PlayerActionState = 7;
  g_PreviousPlayerActionState = uVar1;
  /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
LAB_0048eb17:
  DetachEntitySoundHandle(&DAT_0051ce90);
  return;
}


