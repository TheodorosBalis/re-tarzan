/*
State 0x0E Update: CPlayerHero::UpdateTerkGroundDamage
Address: 0x0047A0A0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateTerkGroundDamage(void)

{
  undefined2 uVar1;
  char cVar2;
  int iVar3;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  CPlayerHero__ApplyDamageContactPushback();
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  uVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = uVar1;
    (*(code *)PTR_CPlayerHero__EnterTerkFalling_0050c198)();
  }
  iVar3 = CPlayerHero__AdvanceAnimationScript();
  if (iVar3 == 0) {
    return;
  }
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (g_PlayerCurrentCollisionMode == 2) {
      cVar2 = CPlayerHero__IsFacingCurrentCollisionSurface();
      g_PreviousPlayerActionState = g_PlayerActionState;
      if (((cVar2 == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
         (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 1;
                    /* WARNING: Could not recover jumptable at 0x0047a156. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)PTR_CPlayerHero__EnterTerkMoveForward_0050c150)();
        return;
      }
    }
    g_PreviousPlayerActionState = g_PlayerActionState;
    if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
        ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) &&
       (g_PlayerCurrentCollisionMode == 2)) {
      g_PlayerActionState = 3;
                    /* WARNING: Could not recover jumptable at 0x0047a19c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)PTR_CPlayerHero__EnterTerkTurnAround_0050c160)();
      return;
    }
  }
  g_PreviousPlayerActionState = g_PlayerActionState;
  g_PlayerActionState = 0;
                    /* WARNING: Could not recover jumptable at 0x0047a1b7. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)PTR_CPlayerHero__EnterTerkIdle_0050c148)();
  return;
}


