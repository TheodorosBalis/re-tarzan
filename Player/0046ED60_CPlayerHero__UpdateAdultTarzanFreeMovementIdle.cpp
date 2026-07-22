#include "tarzan_ghidra_types.hpp"

// Address: 0x0046ED60
// Label: CPlayerHero::UpdateAdultTarzanFreeMovementIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanFreeMovementIdle(void)

{
  undefined2 value2;
  char resultFlag;
  short shortValue;
  uint value3;
  int value;
  uint value4;
  uint value5;
  uint value6;
  bool flagByte;
  
  value2 = g_PlayerActionState;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((*( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 5) {
        g_PlayerActionState = 0x12;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterTreeSurfingObstacleDamageHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x2e;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
      if (g_PlayerDamageInvulnerabilityTicks != 0) {
        return;
      }
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      if (g_PlayerCurrentCollisionMode == 2) {
        CPlayerHero::ApplyDamageContactPushback();
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0xb;
        (*(code *)g_AdultTarzanEnterPlayerDamageHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode == 5) {
        g_PlayerActionState = 0x12;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterSurfingModeHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0xb;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterPlayerDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero::ApplyDamageContactPushback();
  }
  value2 = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (g_PlayerCurrentCollisionMode == 1) {
      if (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) &&
         (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 0x41;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterFreeMovementForwardHandlerPtr)();
        return;
      }
    }
    else if (g_PlayerCurrentCollisionMode == 2) {
      resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
      value2 = g_PlayerActionState;
      if (((resultFlag == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
         (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 1;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterMoveForwardHandlerPtr)();
        return;
      }
    }
    else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
      g_PlayerActionState = 0xd;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterTreeSurfingHandlerPtr)();
      return;
    }
  }
  value2 = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (g_PlayerCurrentCollisionMode == 1) {
      value6 = g_PlayerInputHeldMask & 0x20;
      if (value6 != 0) {
        g_PlayerMoveHeadingAngle = 0xc00 - g_CameraYaw;
      }
      value5 = g_PlayerInputHeldMask & 0x80;
      if (value5 != 0) {
        g_PlayerMoveHeadingAngle = 0x400 - g_CameraYaw;
      }
      value3 = g_PlayerInputHeldMask & 0x10;
      if (value3 != 0) {
        g_PlayerMoveHeadingAngle = 0x800 - g_CameraYaw;
      }
      value4 = g_PlayerInputHeldMask & 0x40;
      if (value4 != 0) {
        g_PlayerMoveHeadingAngle = -g_CameraYaw;
      }
      if (value3 != 0) {
        if (value5 != 0) {
          g_PlayerMoveHeadingAngle = 0x600 - g_CameraYaw;
        }
        if ((value3 != 0) && (value6 != 0)) {
          g_PlayerMoveHeadingAngle = 0xa00 - g_CameraYaw;
        }
      }
      if (value4 != 0) {
        if (value5 != 0) {
          g_PlayerMoveHeadingAngle = 0x200 - g_CameraYaw;
        }
        if ((value4 != 0) && (value6 != 0)) {
          g_PlayerMoveHeadingAngle = 0xe00 - g_CameraYaw;
        }
      }
    }
    else if ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterTurnAroundHandlerPtr)();
      return;
    }
  }
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
      (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) &&
     ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    *(ushort *)(g_PlayerAnimationState + 0x1e) = *(ushort *)(g_PlayerAnimationState + 0x1e) & 0xfeff
    ;
    value2 = g_PlayerActionState;
    if (g_PlayerCurrentCollisionMode == 1) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) == 0) {
        g_PlayerActionState = 0x45;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterFreeMovementStandingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x46;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterFreeMovementMovingJumpHandlerPtr)();
      return;
    }
    if (g_PlayerCurrentCollisionMode == 2) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) == 0) {
        g_PlayerActionState = 6;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterStandingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterMovingJumpHandlerPtr)();
      return;
    }
  }
  value2 = g_PlayerActionState;
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
      (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) &&
     ((g_PlayerInputPressedMask & 0x100000) != 0)) {
    g_PlayerActionState = 0x2c;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterPoundHandlerPtr)();
    return;
  }
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
      (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) &&
     ((g_HudPowerFruitSelectorScene != 0 && ((g_PlayerInputHeldMask & 0x400000) != 0)))) {
    g_PlayerActionState = 0x28;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterThrowHighHandlerPtr)();
    return;
  }
  resultFlag = CPlayerHero::TryEnterAdultTarzanThrowLow();
  if (((resultFlag == '\0') && (resultFlag = CPlayerHero::TryEnterAdultTarzanStabHigh(), resultFlag == '\0')) &&
     (resultFlag = CPlayerHero::TryEnterAdultTarzanStabLow(), resultFlag == '\0')) {
    CPlayerHero::UpdateMovementAndCollision(1);
    resultFlag = CPlayerHero::TrySnapToNearbyGround();
    value2 = g_PlayerActionState;
    if (resultFlag == '\0') {
      g_PlayerActionState = 7;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
      return;
    }
    value = CPlayerHero::AdvanceAnimationScript();
    if ((value != 0) &&
       (shortValue = g_PlayerIdleFidgetDelayTicks + -1, flagByte = g_PlayerIdleFidgetDelayTicks < 0,
       g_PlayerIdleFidgetDelayTicks = shortValue, flagByte)) {
      CPlayerHero::PlayAdultTarzanAnimation(0x9e);
    }
  }
  return;
}

