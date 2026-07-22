#include "tarzan_ghidra_types.hpp"

// Address: 0x0048D2E0
// Label: CPlayerHero::UpdateYoungTarzanMoveForward
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungTarzanMoveForward(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  value2 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 5;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048d30d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterTarzanMovingJumpHandlerPtr)();
    return;
  }
  if (g_PlayerFacingCurrentCollisionSurface == '\0') {
    if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
        ((g_PlayerPowerFruitInventoryFlags & 0x10) != 0)) &&
       ((g_PlayerInputHeldMask & 0x1000000) != 0)) {
      g_PlayerActionState = 0x34;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterStabHandlerPtr)();
      CPlayerHero::PlayAnimation(0x8f);
    }
    else {
      if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
        if (((g_PlayerPowerFruitInventoryFlags & 0x10) != 0) &&
           ((g_PlayerInputHeldMask & 0x2000000) != 0)) {
          g_PlayerActionState = 0x35;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_YoungEnterAltStabHandlerPtr)();
          CPlayerHero::PlayAnimation(0x92);
          return;
        }
        if ((g_PlayerInputHeldMask & 0x400000) != 0) {
          g_PlayerActionState = 0x32;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_YoungEnterThrowHighHandlerPtr)();
          CPlayerHero::PlayAnimation(0x86);
          return;
        }
        if ((g_PlayerInputHeldMask & 0x800000) != 0) {
          g_PlayerActionState = 0x33;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_YoungEnterThrowLowHandlerPtr)();
          CPlayerHero::PlayAnimation(0x8b);
          return;
        }
      }
      value = CPlayerHero::AdvanceAnimationScript();
      if (value == 7) {
        CPlayerHero::PlayAnimation(3);
      }
      else if (value == 0xd) {
        *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x18;
      }
      value2 = g_PlayerActionState;
      if ((g_PlayerInputHeldMask & (g_CameraFollowFlags | g_CameraRelativeTurnInputMask)) == 0) {
        g_PlayerActionState = 2;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterTarzanStopForwardMovementHandlerPtr)();
      }
      else if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
              ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
        if (g_PlayerCurrentCollisionMode == 2) {
          g_PlayerActionState = 3;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_YoungEnterTarzanTurnAroundHandlerPtr)();
        }
        else if ((g_PlayerInputHeldMask & 0x80) == 0) {
          g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + 0x2d;
        }
        else {
          g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + -0x2d;
        }
      }
      CPlayerHero::UpdateMovementAndCollision(1);
      resultFlag = CPlayerHero::TrySnapToNearbyGround();
      value2 = g_PlayerActionState;
      if (resultFlag == '\0') {
        g_PlayerActionState = 7;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
      }
      value2 = g_PlayerActionState;
      if (g_PlayerCollisionFacingFlags != '\0') {
        g_PlayerActionState = 2;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048d5cf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterTarzanStopForwardMovementHandlerPtr)();
        return;
      }
    }
  }
  else {
    if ((ram0x0051cdca & 0x1000) == 0) {
      if (g_PlayerCurrentCollisionMode == 2) {
        g_PlayerActionState = 0xc;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048d3c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterPlayerDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode == 5) {
        g_PlayerActionState = 0x13;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048d3ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0xc;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048d391. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterPlayerDamageHandlerPtr)();
      return;
    }
    g_PlayerActionState = 0x30;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_YoungEnterJumpDamageHandlerPtr)();
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
      return;
    }
  }
  return;
}

