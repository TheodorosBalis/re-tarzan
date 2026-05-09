/*
State 0x28 Update: CPlayerHero::UpdateYoungSwimForward
Address: 0x00490380
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00490380_CPlayerHero__UpdateYoungSwimForward.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungSwimForward(void)

{
  undefined2 uVar1;
  int iVar2;
  
  uVar1 = g_PlayerActionState;
  if (DAT_0051cd1c != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x29 -> CPlayerHero::EnterYoungApplyDamageInWater */
  CPlayerHero__EnterYoungApplyDamageInWater();
        return;
      }
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0x30;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x30 -> CPlayerHero::EnterYoungApplyDamageOnJumping */
  CPlayerHero__EnterYoungApplyDamageOnJumping();
        if (g_PlayerDamageInvulnerabilityTicks != 0) {
          return;
        }
        g_PlayerDamageFlashTicks = 0x3c;
        g_PlayerDamageInvulnerabilityTicks = 0x3c;
        return;
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x13 -> CPlayerHero::EnterYoungApplyDamageOnTreeSurfing */
  CPlayerHero__EnterYoungApplyDamageOnTreeSurfing();
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x29 -> CPlayerHero::EnterYoungApplyDamageInWater */
  CPlayerHero__EnterYoungApplyDamageInWater();
        return;
      }
      if (g_PlayerCurrentCollisionMode == 5) {
        g_PlayerActionState = 0x13;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x13 -> CPlayerHero::EnterYoungApplyDamageOnTreeSurfing */
  CPlayerHero__EnterYoungApplyDamageOnTreeSurfing();
        return;
      }
      g_PlayerActionState = 0xc;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x0C -> CPlayerHero::EnterYoungPlayerDamage */
  CPlayerHero__EnterYoungPlayerDamage();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero__ApplyDamageContactPushback();
  }
  CPlayerHero__AdvanceAnimationScript();
  CPlayerHero__SpawnYoungWaterAttachmentEffects();
  if (g_PlayerAirMovePitchAngle != 0) {
    iVar2 = GetWrappedSignedAngleDelta12Bit(g_PlayerAirMovePitchAngle,0);
    if ((iVar2 >> 3 ^ iVar2 >> 0x1f) - (iVar2 >> 0x1f) < 2) {
      g_PlayerAirMovePitchAngle = 0;
    }
    else {
      g_PlayerAirMovePitchAngle = g_PlayerAirMovePitchAngle + (short)(iVar2 >> 3);
    }
    *(ushort *)(g_PlayerSceneEntry + 0xa4) = *(ushort *)(g_PlayerSceneEntry + 0xa4) & 0xfff;
  }
  uVar1 = g_PlayerActionState;
  g_PlayerAirMovePitchAngle = g_PlayerAirMovePitchAngle & 0xfff;
  if (((byte)g_PlayerInputHeldMask & 0xf0) == 0) {
    g_PlayerActionState = 0x27;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x27 -> CPlayerHero::EnterYoungWaterTurn */
  CPlayerHero__EnterYoungWaterTurn();
  }
  else {
    CPlayerHero__SteerYoungAirMoveHeadingTowardInput();
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  uVar1 = g_PlayerActionState;
  if (g_PlayerCollisionFacingFlags == '\0') {
    return;
  }
  g_PlayerActionState = 0x27;
  g_PreviousPlayerActionState = uVar1;
  /* table enter state 0x27 -> CPlayerHero::EnterYoungWaterTurn */
  CPlayerHero__EnterYoungWaterTurn();
  return;
}


