/*
State 0x06 Update: CPlayerHero::UpdateYoungTarzanAirborneMovement
Address: 0x0048DBB0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungTarzanAirborneMovement(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  
  cVar1 = TryStartPlayerAttachmentInteraction();
  if (cVar1 != '\0') {
    return;
  }
  if ((g_PlayerInteractionLockFlags & 0x8000) != 0) {
    g_PlayerInteractionLockFlags = 0x4000;
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 0x10;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x10;
    g_PlayerTargetMoveSpeed = 0;
  }
  CPlayerHero_UpdateRunInputAndMovement();
  CPlayerHero_TrySnapDownToGround();
  if (DAT_0051cd1c != '\0') {
    if (((ram0x0051cdca & 0x2000) == 0) && (g_PlayerActionState != 0x30)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x30;
      /* table enter state 0x30 -> CPlayerHero::EnterYoungApplyDamageOnJumping */
      CPlayerHero__EnterYoungApplyDamageOnJumping();
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
    }
  }
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     (((g_PlayerInputHeldMask & 0x400000) != 0 || ((g_PlayerInputHeldMask & 0x3800000) != 0)))) {
    if ((g_PlayerJumpArcActive == '\0') && (*(char *)(g_PlayerMotionState + 0xd) != '\0'))
    goto LAB_0048dd3c;
    if ((DAT_0051cdf0 != 0x8d) && (DAT_0051cdf0 != 0x91)) {
      if (((g_PlayerInputHeldMask & 0x400000) == 0) && ((g_PlayerInputHeldMask & 0x800000) == 0)) {
        if ((DAT_0051cd16 & 0x10) == 0) goto LAB_0048dcd5;
        uVar3 = 0x91;
      }
      else {
        uVar3 = 0x8d;
      }
      CPlayerHero_PlayAnimation(uVar3);
    }
  }
LAB_0048dcd5:
  if (g_PlayerJumpArcActive != '\0') {
    iVar2 = CPlayerHero_TryClampJumpArcToSurfaceCeiling(0xa0);
    if (iVar2 != 0) {
      *(int *)(g_PlayerSceneEntryData + 0xc) = iVar2;
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 7;
      /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
      CPlayerHero__EnterYoungTarzanFalling();
      g_PlayerJumpArcActive = '\0';
    }
    if ((g_PlayerActionState == 0x30) || (g_PlayerActionState == 0x31)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    CPlayerHero_UpdateJumpArcVerticalMotion(uVar3);
  }
LAB_0048dd3c:
  iVar2 = CPlayerHero_AdvanceAnimationScript();
  if (iVar2 == 4) {
    InstantiateRuntimeEntryByTypeAtPosition(0,0,0,0xf,0x11);
  }
  else if (iVar2 == 8) {
    if (DAT_005314ac != 0) {
      *(undefined2 *)(DAT_005314ac + 0x48) = 7;
    }
    DAT_005314ac = 0;
    return;
  }
  return;
}

