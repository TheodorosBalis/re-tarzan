/*
State 0x01 Update: CPlayerHero::UpdateTerkMoveForward
Address: 0x00477170
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateTerkMoveForward(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
  uVar1 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 5;
    g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x0047719b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_0050c170)();
    return;
  }
  if (g_PlayerFacingCurrentCollisionSurface == '\0') {
    iVar3 = CPlayerHero__AdvanceAnimationScript();
    if (iVar3 == 7) {
      g_PlayerCurrentAnimationId = 3;
      *(undefined4 *)(g_PlayerAnimationState + 0xc) = _DAT_0050c24c;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero__AdvanceAnimationScript();
    }
    uVar1 = g_PlayerActionState;
    if ((g_PlayerInputHeldMask & (g_CameraFollowFlags | g_CameraRelativeTurnInputMask)) == 0) {
      g_PlayerActionState = 2;
      g_PreviousPlayerActionState = uVar1;
      (*_DAT_0050c158)();
    }
    else if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
             ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) &&
            (g_PlayerCurrentCollisionMode == 2)) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = uVar1;
      (*(code *)PTR_CPlayerHero__EnterTerkTurnAround_0050c160)();
    }
    CPlayerHero__UpdateMovementAndCollision(1);
    cVar2 = CPlayerHero__TrySnapToNearbyGround();
    uVar1 = g_PlayerActionState;
    if (cVar2 == '\0') {
      g_PlayerActionState = 10;
      g_PreviousPlayerActionState = uVar1;
      (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
    }
    uVar1 = g_PlayerActionState;
    if (g_PlayerCollisionFacingFlags != '\0') {
      g_PlayerActionState = 2;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x0047730c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*_DAT_0050c158)();
      return;
    }
  }
  else {
    if ((ram0x0051cdca & 0x1000) == 0) {
      g_PlayerActionState = 0xf;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00477204. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkGroundDamage_0050c1c0)();
      return;
    }
    g_PlayerActionState = 8;
    g_PreviousPlayerActionState = uVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkAirborneDamage_0050c188)();
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
    }
  }
  return;
}


