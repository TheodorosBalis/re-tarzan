/*
State 0x11 Update: CPlayerHero::UpdateYoungTarzanFalling
Address: 0x0048DF20
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048DF20_CPlayerHero__UpdateYoungTarzanFalling.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungTarzanFalling(void)

{
  short sVar1;
  char cVar2;
  int iVar3;
  undefined4 uVar4;
  
  cVar2 = CPlayerHero__IsOnTreeSurfingSurface();
  if (cVar2 != '\0') {
    g_PreviousPlayerActionState = g_PlayerActionState;
    g_PlayerActionState = 0x24;
    /* table enter state 0x24 -> CPlayerHero::EnterYoungDiveAnimation */
  CPlayerHero__EnterYoungDiveAnimation();
    return;
  }
  if (g_PlayerActionState == 0x11) {
    *(int *)(g_PlayerSceneEntry + 0xa8) = *(int *)(g_PlayerSceneEntry + 0xa8) + -0x40;
    if (*(int *)(g_PlayerSceneEntry + 0xa8) < 0x1001) {
      *(undefined4 *)(g_PlayerSceneEntry + 0xa8) = 0x1000;
    }
    *(undefined4 *)(g_PlayerSceneEntry + 0xb0) = *(undefined4 *)(g_PlayerSceneEntry + 0xa8);
    *(undefined4 *)(g_PlayerSceneEntry + 0xac) = *(undefined4 *)(g_PlayerSceneEntry + 0xb0);
  }
  if (g_PlayerInteractionLockFlags == 0x4000) goto LAB_0048e0d7;
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
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
  if (((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
       (((g_PlayerInputHeldMask & 0x400000) != 0 || ((g_PlayerInputHeldMask & 0x3800000) != 0)))) &&
      ((DAT_0051ce04 != '\0' || (*(char *)(g_PlayerMotionState + 0xd) == '\0')))) &&
     ((DAT_0051cdf0 != 0x8d && (DAT_0051cdf0 != 0x91)))) {
    if (((g_PlayerInputHeldMask & 0x400000) == 0) && ((g_PlayerInputHeldMask & 0x800000) == 0)) {
      if ((DAT_0051cd16 & 0x10) == 0) goto LAB_0048e08c;
      uVar4 = 0x91;
    }
    else {
      uVar4 = 0x8d;
    }
    CPlayerHero__PlayAnimation(uVar4);
  }
LAB_0048e08c:
  cVar2 = TryStartPlayerAttachmentInteraction();
  if (cVar2 != '\0') {
    return;
  }
  if ((g_PlayerInteractionLockFlags & 0x8000) != 0) {
    g_PlayerInteractionLockFlags = 0x4000;
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 0x10;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 0x10;
    g_PlayerTargetMoveSpeed = 0;
  }
LAB_0048e0d7:
  CPlayerHero__UpdateJumpArcVerticalMotion(0);
  CPlayerHero__UpdateRunInputAndMovement();
  cVar2 = CPlayerHero__IsOnTreeSurfingSurface();
  sVar1 = g_PlayerActionState;
  if ((cVar2 != '\0') && (0 < *(int *)(g_PlayerSceneEntryData + 0xc))) {
    g_PlayerActionState = 0x25;
    g_PreviousPlayerActionState = sVar1;
    /* table enter state 0x25 -> CPlayerHero::EnterYoungInWater */
  CPlayerHero__EnterYoungInWater();
    return;
  }
  cVar2 = CPlayerHero__TryResolveGroundContactSnap();
  sVar1 = g_PlayerActionState;
  if (cVar2 != '\0') {
    g_PlayerActionState = 9;
    g_PreviousPlayerActionState = sVar1;
    /* table enter state 0x09 -> CPlayerHero::EnterYoungLandingRecovery */
  CPlayerHero__EnterYoungLandingRecovery();
    return;
  }
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  if (iVar3 == 4) {
    FUN_0043fc90(0,0,0,0xf,0x11);
  }
  else if (iVar3 == 8) {
    if (DAT_005314ac != 0) {
      *(undefined2 *)(DAT_005314ac + 0x48) = 7;
    }
    DAT_005314ac = 0;
    return;
  }
  return;
}


