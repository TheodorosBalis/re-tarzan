#include "tarzan_ghidra_types.hpp"

// Address: 0x0048CCE0
// Label: CPlayerHero::UpdateYoungTarzanIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungTarzanIdle(void)

{
  undefined2 value2;
  char resultFlag;
  short shortValue;
  int value;
  ushort value3;
  bool flagByte;
  
  value2 = g_PlayerActionState;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048cd7a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0x30;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterJumpDamageHandlerPtr)();
        if (g_PlayerDamageInvulnerabilityTicks != 0) {
          return;
        }
        g_PlayerDamageInvulnerabilityTicks = 0x3c;
        g_PlayerDamageFlashTicks = 0x3c;
        return;
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048cd5d. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      if (g_PlayerCurrentCollisionMode == 4) {
        g_PlayerActionState = 0x29;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048cde9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode == 5) {
        g_PlayerActionState = 0x13;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048cdcc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0xc;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048cdaf. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterPlayerDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero::ApplyDamageContactPushback();
  }
  value2 = g_PlayerActionState;
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    if ((g_CameraFollowFlags & g_PlayerInputHeldMask) == 0) {
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048ce59. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTarzanStandingJumpHandlerPtr)();
      return;
    }
    g_PlayerActionState = 5;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048ce3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterTarzanMovingJumpHandlerPtr)();
    return;
  }
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionMode != 0)) {
    if (g_PlayerCurrentCollisionMode < 3) {
      resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
      value2 = g_PlayerActionState;
      if (((resultFlag == '\0') && ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0)) &&
         (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 1;
        g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048ceda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_YoungEnterTarzanMoveForwardHandlerPtr)();
        return;
      }
    }
    else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
      g_PlayerActionState = 0xe;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048ce98. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTouchSurfaceOnSurfingHandlerPtr)();
      return;
    }
  }
  value2 = g_PlayerActionState;
  value3 = g_PlayerSequenceFlags & 0xf000;
  if ((value3 == 0) && ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
    if (g_PlayerCurrentCollisionMode == 2) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048cf6a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTarzanTurnAroundHandlerPtr)();
      return;
    }
    if ((g_PlayerInputHeldMask & 0x80) == 0) {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + 0x2d;
    }
    else {
      g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + -0x2d;
    }
  }
  if (value3 == 0) {
    if ((g_PlayerInputPressedMask & 0x100000) != 0) {
      g_PlayerActionState = 0x2f;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048cf43. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterPoundHandlerPtr)();
      return;
    }
    if ((g_PlayerInputHeldMask & 0x80000) != 0) {
      g_PlayerActionState = 10;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048cf92. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterBlockHandlerPtr)();
      return;
    }
  }
  if (((value3 == 0) && ((g_PlayerPowerFruitInventoryFlags & 0x10) != 0)) &&
     ((g_PlayerInputHeldMask & 0x1000000) != 0)) {
    g_PlayerActionState = 0x34;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048cfc5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterStabHandlerPtr)();
    return;
  }
  if (value3 == 0) {
    if (((g_PlayerPowerFruitInventoryFlags & 0x10) != 0) &&
       ((g_PlayerInputHeldMask & 0x2000000) != 0)) {
      g_PlayerActionState = 0x35;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048cff3. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterAltStabHandlerPtr)();
      return;
    }
    if ((g_PlayerInputHeldMask & 0x400000) != 0) {
      g_PlayerActionState = 0x32;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048d01b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterThrowHighHandlerPtr)();
      return;
    }
    if ((g_PlayerInputHeldMask & 0x800000) != 0) {
      g_PlayerActionState = 0x33;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048d045. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterThrowLowHandlerPtr)();
      return;
    }
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag != '\0') {
    value = CPlayerHero::AdvanceAnimationScript();
    if ((value != 0) &&
       (shortValue = g_PlayerIdleFidgetDelayTicks + -1, flagByte = g_PlayerIdleFidgetDelayTicks < 0,
       g_PlayerIdleFidgetDelayTicks = shortValue, flagByte)) {
      CPlayerHero::PlayAnimation(4);
    }
    return;
  }
  g_PlayerActionState = 7;
  g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0048d075. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
  return;
}

