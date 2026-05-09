/*
State 0x09 Update: CPlayerHero::UpdateYoungLandingRecovery
Address: 0x0048E3C0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048E3C0_CPlayerHero__UpdateYoungLandingRecovery.c
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__UpdateYoungLandingRecovery(void)

{
  short sVar1;
  char cVar2;
  
  sVar1 = g_PlayerActionState;
  if (g_PlayerInteractionLockFlags != 0x4000) {
    if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
    }
    g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
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
      return;
    }
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
        g_PlayerActionState = 5;
        g_PreviousPlayerActionState = sVar1;
        /* table enter state 0x05 -> CPlayerHero::EnterYoungTarzanMovingJump */
  CPlayerHero__EnterYoungTarzanMovingJump();
        return;
      }
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = sVar1;
      /* table enter state 0x06 -> CPlayerHero::EnterYoungTarzanStandingJump */
  CPlayerHero__EnterYoungTarzanStandingJump();
      return;
    }
    if (DAT_0051cdf0 != 0x18) {
      if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
        if (g_PlayerCurrentCollisionMode != 0) {
          if (g_PlayerCurrentCollisionMode < 3) {
            cVar2 = CPlayerHero__IsFacingCurrentCollisionSurface();
            sVar1 = g_PlayerActionState;
            if (((cVar2 == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
               (g_PlayerCollisionFacingFlags == '\0')) {
              g_PlayerActionState = 1;
              g_PreviousPlayerActionState = sVar1;
              /* table enter state 0x01 -> CPlayerHero::EnterYoungTarzanMoveForward */
  CPlayerHero__EnterYoungTarzanMoveForward();
              return;
            }
          }
          else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
            g_PlayerActionState = 0xe;
            g_PreviousPlayerActionState = sVar1;
            /* table enter state 0x0E -> CPlayerHero::EnterYoungTouchSurfaceOnSurfing */
  CPlayerHero__EnterYoungTouchSurfaceOnSurfing();
            return;
          }
        }
      }
      sVar1 = g_PlayerActionState;
      if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
         ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
        if (g_PlayerCurrentCollisionMode == 2) {
          g_PlayerActionState = 3;
          g_PreviousPlayerActionState = sVar1;
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
    }
  }
  CPlayerHero__UpdateMovementAndCollision(1);
  cVar2 = CPlayerHero__TrySnapToNearbyGround();
  sVar1 = g_PlayerActionState;
  if (cVar2 == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = sVar1;
    /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
  }
  CPlayerHero__AdvanceAnimationScript();
  return;
}


