/*
State 0x34 Update: CPlayerHero::UpdateYoungStabAnimation
Address: 0x0048F0D0
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungStabAnimation(void)

{
  undefined2 uVar1;
  
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
        if (g_PlayerDamageInvulnerabilityTicks == 0) {
          g_PlayerDamageInvulnerabilityTicks = 0x3c;
          g_PlayerDamageFlashTicks = 0x3c;
        }
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
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0xc;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x0C -> CPlayerHero::EnterYoungPlayerDamage */
  CPlayerHero__EnterYoungPlayerDamage();
        return;
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x13 -> CPlayerHero::EnterYoungApplyDamageOnTreeSurfing */
  CPlayerHero__EnterYoungApplyDamageOnTreeSurfing();
      return;
    }
    g_PlayerCollisionFacingFlags = 1;
    CPlayerHero__ApplyDamageContactPushback();
  }
  uVar1 = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
        g_PlayerActionState = 5;
        g_PreviousPlayerActionState = uVar1;
        /* table enter state 0x05 -> CPlayerHero::EnterYoungTarzanMovingJump */
  CPlayerHero__EnterYoungTarzanMovingJump();
        return;
      }
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x06 -> CPlayerHero::EnterYoungTarzanStandingJump */
  CPlayerHero__EnterYoungTarzanStandingJump();
      return;
    }
  }
  else if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  CPlayerHero__AdvanceAnimationScript();
  return;
}


