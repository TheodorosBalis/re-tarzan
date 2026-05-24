/*
State 0x13 Update: CPlayerHero::UpdateTerkPound
Address: 0x00477630
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateTerkPound(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
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
                    /* WARNING: Could not recover jumptable at 0x004776a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkGroundDamage_0050c1c0)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero__ApplyDamageContactPushback();
  }
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if ((((g_PlayerCurrentCollisionMode == 2) &&
         (cVar2 = CPlayerHero__IsFacingCurrentCollisionSurface(), uVar1 = g_PlayerActionState,
         cVar2 == '\0')) && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
       (g_PlayerCollisionFacingFlags == '\0')) {
      g_PlayerActionState = 1;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00477702. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkMoveForward_0050c150)();
      return;
    }
    uVar1 = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00477735. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkStandingJump_0050c178)();
      return;
    }
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = uVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
  }
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  if ((iVar3 == 8) && ((g_PlayerInputHeldMask & 0x100000) == 0)) {
    g_PlayerCurrentAnimationId = 0x18;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2a0;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    return;
  }
  return;
}


