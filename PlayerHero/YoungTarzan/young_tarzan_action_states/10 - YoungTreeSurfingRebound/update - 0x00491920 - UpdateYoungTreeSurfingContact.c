/*
State 0x10 Update: CPlayerHero::UpdateYoungTreeSurfingContact
Address: 0x00491920
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungTreeSurfingContact(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar3 = DAT_0051ce84;
  DAT_0051ce84 = 0;
  uVar4 = *(uint *)(*(int *)(g_PlayerSceneEntry + 0x114) + 0x14) & 0xf;
  *(int *)(g_PlayerSceneEntry + 0xa8) = *(int *)(g_PlayerSceneEntry + 0xa8) + 0x80;
  if (0x16ff < *(int *)(g_PlayerSceneEntry + 0xa8)) {
    *(undefined4 *)(g_PlayerSceneEntry + 0xa8) = 0x1700;
  }
  *(undefined4 *)(g_PlayerSceneEntry + 0xb0) = *(undefined4 *)(g_PlayerSceneEntry + 0xa8);
  *(undefined4 *)(g_PlayerSceneEntry + 0xac) = *(undefined4 *)(g_PlayerSceneEntry + 0xb0);
  CPlayerHero__AdvanceAnimationScript();
  uVar1 = g_PlayerActionState;
  g_PlayerSurfaceLeanScale = 200;
  _DAT_0051cdf4 = 400;
  if ((_g_PlayerSequenceFlags & 0x8000) != 0) {
    g_PlayerActionState = 0x15;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x15 -> CPlayerHero::EnterYoungFatalDamageSequence */
  CPlayerHero__EnterYoungFatalDamageSequence();
    return;
  }
  switch(g_PlayerActionState) {
  case 0xe:
    cVar2 = FUN_004917d0(uVar4);
    if (((cVar2 != '\0') || (cVar2 = FUN_00491840(uVar4), cVar2 != '\0')) ||
       (cVar2 = FUN_00491890(uVar4), uVar1 = g_PlayerActionState, cVar2 != '\0')) goto LAB_00491dfb;
    if (DAT_0051cd1c != '\0') {
      if ((ram0x0051cdca & 0x1000) == 0) {
        if (g_PlayerDamageInvulnerabilityTicks != 0) {
          g_PlayerCollisionFacingFlags = '\x01';
          CPlayerHero__ApplyDamageContactPushback();
          goto LAB_00491ae2;
        }
        if (g_PlayerCurrentCollisionMode == 4) goto LAB_00491a58;
        if (g_PlayerCurrentCollisionMode != 5) {
          g_PlayerActionState = 0xc;
          g_PreviousPlayerActionState = uVar1;
          /* table enter state 0x0C -> CPlayerHero::EnterYoungPlayerDamage */
  CPlayerHero__EnterYoungPlayerDamage();
          goto LAB_00491dfb;
        }
      }
      else {
        if (g_PlayerCurrentCollisionMode == 4) {
LAB_00491a58:
          g_PlayerActionState = 0x29;
          g_PreviousPlayerActionState = uVar1;
          /* table enter state 0x29 -> CPlayerHero::EnterYoungApplyDamageInWater */
  CPlayerHero__EnterYoungApplyDamageInWater();
          goto LAB_00491dfb;
        }
        if (g_PlayerCurrentCollisionMode != 5) {
          g_PreviousPlayerActionState = g_PlayerActionState;
LAB_00491c5c:
          g_PlayerActionState = 0x30;
          /* table enter state 0x30 -> CPlayerHero::EnterYoungApplyDamageOnJumping */
  CPlayerHero__EnterYoungApplyDamageOnJumping();
          if (g_PlayerDamageInvulnerabilityTicks == 0) {
            g_PlayerDamageInvulnerabilityTicks = 0x3c;
            g_PlayerDamageFlashTicks = 0x3c;
          }
          goto LAB_00491dfb;
        }
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x13 -> CPlayerHero::EnterYoungApplyDamageOnTreeSurfing */
  CPlayerHero__EnterYoungApplyDamageOnTreeSurfing();
      goto LAB_00491dfb;
    }
LAB_00491ae2:
    uVar1 = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      g_PlayerActionState = 0x10;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x10 -> CPlayerHero::EnterYoungTreeSurfingRebound */
  CPlayerHero__EnterYoungTreeSurfingRebound();
      goto LAB_00491dfb;
    }
    FUN_004916a0();
    uVar1 = g_PlayerActionState;
    if ((((byte)g_PlayerInputHeldMask & 0x40) != 0) && (g_PlayerLateralSurfaceOffset == 0)) {
      g_PlayerActionState = 0xf;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x0F -> CPlayerHero::EnterYoungTreeSurfingResume */
  CPlayerHero__EnterYoungTreeSurfingResume();
      _DAT_0053a2c0 = 0x19;
      goto LAB_00491dfb;
    }
    if (iVar3 != DAT_0051ce84) {
      if (DAT_0051ce84 == 1) {
        uVar5 = 0x30;
      }
      else if (DAT_0051ce84 == 2) {
        uVar5 = 0x33;
      }
      else if (iVar3 == 1) {
        uVar5 = 0x32;
      }
      else if (iVar3 == 2) {
        uVar5 = 0x35;
      }
      else {
        uVar5 = 0x23;
      }
      CPlayerHero__PlayAnimation(uVar5);
    }
    if (0xa0 < DAT_0051ce00) {
      DAT_0051ce00 = DAT_0051ce00 + -0x10;
      if (DAT_0051ce00 < 0xa0) {
        DAT_0051ce00 = 0xa0;
      }
      goto LAB_00491dfb;
    }
    break;
  case 0xf:
    cVar2 = FUN_004917d0(uVar4);
    if ((cVar2 != '\0') || (cVar2 = FUN_00491840(uVar4), uVar1 = g_PlayerActionState, cVar2 != '\0')
       ) goto LAB_00491dfb;
    if (DAT_0051cd1c != '\0') {
      if ((ram0x0051cdca & 0x1000) == 0) {
        if (g_PlayerDamageInvulnerabilityTicks != 0) {
          g_PlayerCollisionFacingFlags = '\x01';
          CPlayerHero__ApplyDamageContactPushback();
          goto LAB_00491d19;
        }
        if (g_PlayerCurrentCollisionMode == 4) goto LAB_00491ceb;
        if (g_PlayerCurrentCollisionMode != 5) {
          g_PlayerActionState = 0xc;
          g_PreviousPlayerActionState = uVar1;
          /* table enter state 0x0C -> CPlayerHero::EnterYoungPlayerDamage */
  CPlayerHero__EnterYoungPlayerDamage();
          goto LAB_00491dfb;
        }
      }
      else {
        if (g_PlayerCurrentCollisionMode == 4) {
LAB_00491ceb:
          g_PlayerActionState = 0x29;
          g_PreviousPlayerActionState = uVar1;
          /* table enter state 0x29 -> CPlayerHero::EnterYoungApplyDamageInWater */
  CPlayerHero__EnterYoungApplyDamageInWater();
          goto LAB_00491dfb;
        }
        if (g_PlayerCurrentCollisionMode != 5) {
          g_PreviousPlayerActionState = g_PlayerActionState;
          goto LAB_00491c5c;
        }
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x13 -> CPlayerHero::EnterYoungApplyDamageOnTreeSurfing */
  CPlayerHero__EnterYoungApplyDamageOnTreeSurfing();
      goto LAB_00491dfb;
    }
LAB_00491d19:
    uVar1 = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      g_PlayerActionState = 0x10;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x10 -> CPlayerHero::EnterYoungTreeSurfingRebound */
  CPlayerHero__EnterYoungTreeSurfingRebound();
      goto LAB_00491dfb;
    }
    FUN_004916a0();
    uVar1 = g_PlayerActionState;
    DAT_0051ce00 = DAT_0051ce00 + -0x10;
    if (DAT_0051ce00 < 0x60) {
      DAT_0051ce00 = 0x60;
    }
    if ((((DAT_0051cdf0 == 0x2e) || (DAT_0051cdf0 == 0x37)) || (DAT_0051cdf0 == 0x3a)) &&
       (((byte)g_PlayerInputHeldMask & 0x40) == 0)) {
      g_PlayerActionState = 0xe;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x0E -> CPlayerHero::EnterYoungTouchSurfaceOnSurfing */
  CPlayerHero__EnterYoungTouchSurfaceOnSurfing();
    }
  case 0x16:
    if (DAT_0051ce00 < 0x40) {
      DAT_0051ce00 = 0x40;
    }
    iVar3 = 4;
LAB_00491dcd:
    if (g_PlayerLateralSurfaceOffset != 0) {
      if (g_PlayerLateralSurfaceOffset < 0) {
        g_PlayerLateralSurfaceOffset = g_PlayerLateralSurfaceOffset + 1;
      }
      else {
        g_PlayerLateralSurfaceOffset = g_PlayerLateralSurfaceOffset + -1;
      }
    }
    DAT_0051ce00 = DAT_0051ce00 + -0x10;
    if (DAT_0051ce00 < iVar3) {
      DAT_0051ce00 = iVar3;
    }
    goto LAB_00491dfb;
  case 0x10:
    cVar2 = FUN_00491840(uVar4);
    if (cVar2 == '\0') {
      FUN_00491890(uVar4);
    }
  default:
    goto LAB_00491dfb;
  case 0x12:
    break;
  case 0x13:
  case 0x14:
    iVar3 = 0x60;
    goto LAB_00491dcd;
  }
  if ((DAT_0051ce00 < 0xa0) && (DAT_0051ce00 = DAT_0051ce00 + 0x10, 0xa0 < DAT_0051ce00)) {
    DAT_0051ce00 = 0xa0;
  }
LAB_00491dfb:
  *(int *)(g_PlayerMotionState + 0x1c) = DAT_0051ce00;
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 0x11;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x11 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
    DetachEntitySoundHandle(&DAT_0051ce90);
  }
  uVar1 = g_PlayerActionState;
  if (g_PlayerCollisionFacingFlags != '\0') {
    g_PlayerActionState = 2;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x02 -> CPlayerHero::EnterYoungTarzanStopForwardMovement */
  CPlayerHero__EnterYoungTarzanStopForwardMovement();
  }
  return;
}


