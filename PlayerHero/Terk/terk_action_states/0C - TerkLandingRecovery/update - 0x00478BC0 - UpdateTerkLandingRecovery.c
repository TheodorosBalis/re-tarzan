/*
State 0x0C Update: CPlayerHero::UpdateTerkLandingRecovery
Address: 0x00478BC0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateTerkLandingRecovery(void)

{
  short sVar1;
  char cVar2;
  int iVar3;
  
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    sVar1 = g_PlayerActionState;
    if (((ram0x0051cdca & 0x2000) == 0) && (g_PlayerActionState != 8)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 8;
      (*(code *)PTR_CPlayerHero__EnterTerkAirborneDamage_0050c188)();
      sVar1 = g_PlayerActionState;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageFlashTicks = 0x3c;
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
    }
    g_PlayerActionState = sVar1;
    if (g_PlayerFacingCurrentCollisionSurface != '\0') {
      if ((unique0x100000f2 & 0x1000) == 0) {
        if (g_PlayerDamageInvulnerabilityTicks == 0) {
          CPlayerHero__ApplyDamageContactPushback();
          g_PreviousPlayerActionState = g_PlayerActionState;
          g_PlayerActionState = 0xf;
          (*(code *)PTR_CPlayerHero__EnterTerkGroundDamage_0050c1c0)();
        }
        else {
          g_PlayerCollisionFacingFlags = '\x01';
          CPlayerHero__ApplyDamageContactPushback();
        }
      }
      else {
        g_PlayerActionState = 8;
        g_PreviousPlayerActionState = sVar1;
        (*(code *)PTR_CPlayerHero__EnterTerkAirborneDamage_0050c188)();
        if (g_PlayerDamageInvulnerabilityTicks == 0) {
          g_PlayerDamageInvulnerabilityTicks = 0x3c;
          g_PlayerDamageFlashTicks = 0x3c;
        }
      }
    }
  }
  sVar1 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = sVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkStandingJump_0050c178)();
    return;
  }
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
      ((g_CameraRelativeTurnInputMask & g_PlayerInputHeldMask) != 0)) &&
     (g_PlayerCurrentCollisionMode == 2)) {
    g_PlayerActionState = 3;
    g_PreviousPlayerActionState = sVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkTurnAround_0050c160)();
    return;
  }
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionMode == 2)) &&
     ((cVar2 = CPlayerHero__IsFacingCurrentCollisionSurface(), sVar1 = g_PlayerActionState,
      cVar2 == '\0' &&
      (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0 && (g_PlayerCollisionFacingFlags == '\0')
       ))))) {
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = sVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkMoveForward_0050c150)();
    return;
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  sVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = sVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
  }
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  sVar1 = g_PlayerActionState;
  if (((iVar3 == 0x11) && ((_g_PlayerSequenceFlags & 0xf000) == 0)) &&
     ((g_PlayerInputHeldMask & 0x80000) != 0)) {
    g_PlayerActionState = 0xd;
    g_PreviousPlayerActionState = sVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkBlock_0050c1b0)();
    g_PlayerCurrentAnimationId = 0x1a;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2a8;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
  }
  return;
}


