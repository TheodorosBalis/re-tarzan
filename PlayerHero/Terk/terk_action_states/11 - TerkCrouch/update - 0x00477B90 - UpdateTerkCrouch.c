/*
State 0x11 Update: CPlayerHero::UpdateTerkCrouch
Address: 0x00477B90
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateTerkCrouch(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      goto LAB_00477c63;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      CPlayerHero__ApplyDamageContactPushback();
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0xf;
                    /* WARNING: Could not recover jumptable at 0x00477bda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkGroundDamage_0050c1c0)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero__ApplyDamageContactPushback();
  }
  uVar1 = g_PlayerActionState;
  if ((*(int *)(g_PlayerSceneEntry + 300) == -0x7fffffff) ||
     (0xff < *(int *)(g_PlayerSceneEntryData + 0xc) - *(int *)(g_PlayerSceneEntry + 300))) {
    if ((g_PlayerInputHeldMask & 0x80000) == 0) {
      g_PlayerActionState = 0x12;
      g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00477c3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkCrouchLook_0050c1d8)();
      return;
    }
    if (g_PlayerFacingCurrentCollisionSurface != '\0') {
      if ((ram0x0051cdca & 0x1000) != 0) {
        g_PreviousPlayerActionState = g_PlayerActionState;
LAB_00477c63:
        g_PlayerActionState = 8;
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
                    /* WARNING: Could not recover jumptable at 0x00477cb4. Too many branches */
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
      (*(code *)PTR_CPlayerHero__EnterTerkStandingJump_0050c178)();
      *(undefined2 *)(g_PlayerSceneEntry + 0x142) = 0x100;
      return;
    }
    if (((g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = uVar1;
      (*DAT_0050c170)();
      *(undefined2 *)(g_PlayerSceneEntry + 0x142) = 0x100;
      return;
    }
    if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) goto LAB_00477d94;
    g_PreviousPlayerActionState = g_PlayerActionState;
  }
  else {
    if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) goto LAB_00477d94;
    g_PreviousPlayerActionState = g_PlayerActionState;
  }
  g_PlayerActionState = 0x12;
  (*(code *)PTR_CPlayerHero__EnterTerkCrouchLook_0050c1d8)();
LAB_00477d94:
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  if (iVar3 == 7) {
    g_PlayerCurrentAnimationId = 0x20;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2c0;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
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
  if (g_PlayerCollisionFacingFlags == '\0') {
    return;
  }
  g_PlayerActionState = 0x12;
  g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x00477e23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CPlayerHero__EnterTerkCrouchLook_0050c1d8)();
  return;
}


