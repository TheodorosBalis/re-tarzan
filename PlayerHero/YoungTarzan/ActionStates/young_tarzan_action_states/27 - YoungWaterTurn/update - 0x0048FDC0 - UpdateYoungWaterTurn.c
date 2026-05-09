/*
State 0x27 Update: CPlayerHero::UpdateYoungWaterTurn
Address: 0x0048FDC0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048FDC0_CPlayerHero__UpdateYoungWaterTurn.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungWaterTurn(void)

{
  undefined2 uVar1;
  
  uVar1 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
    if (g_PlayerCurrentCollisionMode == 2) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x03 -> CPlayerHero::EnterYoungTarzanTurnAround */
  CPlayerHero__EnterYoungTarzanTurnAround();
      return;
    }
    if ((g_PlayerInputHeldMask & 0x80) == 0) {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + 0x2d;
    }
    else {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + -0x2d;
    }
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  CPlayerHero__AdvanceAnimationScript();
  CPlayerHero__SpawnYoungWaterAttachmentEffects();
  return;
}


