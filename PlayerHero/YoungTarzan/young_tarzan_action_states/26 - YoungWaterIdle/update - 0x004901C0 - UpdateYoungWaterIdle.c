/*
State 0x26 Update: CPlayerHero::UpdateYoungWaterIdle
Address: 0x004901C0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungWaterIdle(void)

{
  undefined2 uVar1;
  
  uVar1 = g_PlayerActionState;
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) && (((byte)g_PlayerInputHeldMask & 0xf0) != 0)) &&
     (g_PlayerCollisionFacingFlags == '\0')) {
    g_PlayerActionState = 0x28;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x28 -> CPlayerHero::EnterYoungSwimForward */
    CPlayerHero__EnterYoungSwimForward();
    return;
  }
  CPlayerHero_SteerYoungAirMoveHeadingFromHorizontalInput();
  CPlayerHero_UpdateMovementAndCollision(1);
  CPlayerHero_AdvanceAnimationScript();
  CPlayerHero_SpawnYoungWaterAttachmentEffects();
  return;
}

