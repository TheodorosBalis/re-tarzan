/*
State 0x0A Update: CPlayerHero::UpdateTerkFalling
Address: 0x00478810
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateTerkFalling(void)

{
  short sVar1;
  char cVar2;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if (((ram0x0051cdca & 0x2000) == 0) && (g_PlayerActionState != 8)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 8;
      (*(code *)PTR_CPlayerHero__EnterTerkAirborneDamage_0050c188)();
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
    }
  }
  cVar2 = TryStartPlayerAttachmentInteraction();
  if (cVar2 != '\0') {
    return;
  }
  CPlayerHero__UpdateJumpArcVerticalMotion(0);
  CPlayerHero__UpdateRunInputAndMovement();
  cVar2 = CPlayerHero__TryResolveGroundContactSnap();
  sVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    CPlayerHero__AdvanceAnimationScript();
    return;
  }
  g_PlayerActionState = 0xc;
  g_PreviousPlayerActionState = sVar1;
                    /* WARNING: Could not recover jumptable at 0x004788c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CPlayerHero__EnterTerkLandingRecovery_0050c1a8)();
  return;
}


