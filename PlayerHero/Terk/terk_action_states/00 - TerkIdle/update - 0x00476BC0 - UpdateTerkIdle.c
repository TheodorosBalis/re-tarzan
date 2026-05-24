/*
State 0x00 Update: CPlayerHero::UpdateTerkIdle
Address: 0x00476BC0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateTerkIdle(void)

{
  undefined2 uVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  bool bVar5;
  
  uVar1 = g_PlayerActionState;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      g_PlayerActionState = 8;
      g_PreviousPlayerActionState = uVar1;
      (*(code *)PTR_CPlayerHero__EnterTerkAirborneDamage_0050c188)();
      if (g_PlayerDamageInvulnerabilityTicks != 0) {
        return;
      }
      g_PlayerDamageFlashTicks = 0x3c;
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      CPlayerHero__ApplyDamageContactPushback();
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0xf;
                    /* WARNING: Could not recover jumptable at 0x00476c30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkGroundDamage_0050c1c0)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero__ApplyDamageContactPushback();
  }
  uVar1 = g_PlayerActionState;
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00476c71. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkStandingJump_0050c178)();
    return;
  }
  if (((((g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionMode == 2)) &&
      (cVar2 = CPlayerHero__IsFacingCurrentCollisionSurface(), uVar1 = g_PlayerActionState,
      cVar2 == '\0')) &&
     (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0 && (g_PlayerCollisionFacingFlags == '\0'))
     )) {
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00476cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkMoveForward_0050c150)();
    return;
  }
  uVar1 = g_PlayerActionState;
  if ((((g_PlayerSequenceFlags & 0xf000) == 0) &&
      ((g_CameraRelativeTurnInputMask & g_PlayerInputHeldMask) != 0)) &&
     (g_PlayerCurrentCollisionMode == 2)) {
    g_PlayerActionState = 3;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00476d0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkTurnAround_0050c160)();
    return;
  }
  if ((g_PlayerSequenceFlags & 0xf000) == 0) {
    if ((g_PlayerInputPressedMask & 0x100000) != 0) {
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00476d3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*_DAT_0050c1e0)();
      return;
    }
    if ((g_PlayerInputHeldMask & 0x80000) != 0) {
      g_PlayerActionState = 0xd;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00476d68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkBlock_0050c1b0)();
      return;
    }
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00476d96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
    return;
  }
  iVar4 = CPlayerHero__AdvanceAnimationScript();
  if ((iVar4 != 0) &&
     (sVar3 = g_PlayerIdleFidgetDelayTicks + -1, bVar5 = g_PlayerIdleFidgetDelayTicks < 0,
     g_PlayerIdleFidgetDelayTicks = sVar3, bVar5)) {
    iVar4 = RandomModulo(3);
    if (iVar4 == 1) {
      g_PlayerCurrentAnimationId = 6;
      *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c258;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero__AdvanceAnimationScript();
      return;
    }
    if (iVar4 != 2) {
      g_PlayerCurrentAnimationId = 5;
      *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c254;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero__AdvanceAnimationScript();
      return;
    }
    g_PlayerCurrentAnimationId = 4;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c250;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    return;
  }
  return;
}


