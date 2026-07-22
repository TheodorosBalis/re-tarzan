#include "tarzan_ghidra_types.hpp"

// Address: 0x0046F4E0
// Label: CPlayerHero::UpdateAdultTarzanFreeMovementForward
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanFreeMovementForward(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  uint value3;
  uint value4;
  uint value5;
  uint value6;
  
  value2 = g_PlayerActionState;
  if (g_PlayerCurrentCollisionMode != 1) {
    g_PlayerActionState = 1;
    CPlayerHero::UpdateAdultTarzanMoveForward();
    return;
  }
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((*( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) & 0x1000) != 0) {
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
      g_PlayerActionState = 0xb;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterPlayerDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero::ApplyDamageContactPushback();
  }
  value2 = g_PlayerActionState;
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
      (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) &&
     ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    if (g_PlayerCurrentCollisionMode == 1) {
      g_PlayerActionState = 0x46;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterFreeMovementMovingJumpHandlerPtr)();
      return;
    }
    if (g_PlayerCurrentCollisionMode == 2) {
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterMovingJumpHandlerPtr)();
      return;
    }
  }
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
      (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) &&
     (((g_PlayerPowerFruitInventoryFlags & 0x10) != 0 && ((g_PlayerInputHeldMask & 0x1000000) != 0))
     )) {
    g_PlayerActionState = 0x2a;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterStabHighHandlerPtr)();
    CPlayerHero::PlayAdultTarzanAnimation(0x85);
    return;
  }
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
      (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) &&
     (((g_PlayerPowerFruitInventoryFlags & 0x10) != 0 && ((g_PlayerInputHeldMask & 0x2000000) != 0))
     )) {
    g_PlayerActionState = 0x2b;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterStabLowHandlerPtr)();
    CPlayerHero::PlayAdultTarzanAnimation(0x89);
    return;
  }
  if (((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
       (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) && (g_HudPowerFruitSelectorScene != 0)
      ) && ((g_PlayerInputHeldMask & 0x400000) != 0)) {
    g_PlayerActionState = 0x28;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterThrowHighHandlerPtr)();
    CPlayerHero::PlayAdultTarzanAnimation(0x7a);
    return;
  }
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
      (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) &&
     ((g_HudPowerFruitSelectorScene != 0 && ((g_PlayerInputHeldMask & 0x800000) != 0)))) {
    g_PlayerActionState = 0x29;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterThrowLowHandlerPtr)();
    CPlayerHero::PlayAdultTarzanAnimation(0x7f);
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 7) {
    CPlayerHero::PlayAdultTarzanAnimation(4);
  }
  else if (value == 0xd) {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
  }
  value2 = g_PlayerActionState;
  if ((g_PlayerInputHeldMask & g_CameraFollowFlags) == 0) {
    g_PlayerActionState = 0x42;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterFreeMovementStopHandlerPtr)();
  }
  else if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (g_PlayerCurrentCollisionMode == 1) {
      value6 = g_PlayerInputHeldMask & 0x20;
      if (value6 != 0) {
        g_PlayerMoveHeadingAngle = 0xc00 - g_CameraYaw;
      }
      value5 = g_PlayerInputHeldMask & 0x80;
      if (value5 != 0) {
        g_PlayerMoveHeadingAngle = 0x400 - g_CameraYaw;
      }
      value4 = g_PlayerInputHeldMask & 0x10;
      if (value4 != 0) {
        g_PlayerMoveHeadingAngle = 0x800 - g_CameraYaw;
      }
      value3 = g_PlayerInputHeldMask & 0x40;
      if (value3 != 0) {
        g_PlayerMoveHeadingAngle = -g_CameraYaw;
      }
      if ((value4 != 0) && (value5 != 0)) {
        g_PlayerMoveHeadingAngle = 0x600 - g_CameraYaw;
      }
      if ((value4 != 0) && (value6 != 0)) {
        g_PlayerMoveHeadingAngle = 0xa00 - g_CameraYaw;
      }
      if (value3 != 0) {
        if (value5 != 0) {
          g_PlayerMoveHeadingAngle = 0x200 - g_CameraYaw;
        }
        if ((value3 != 0) && (value6 != 0)) {
          g_PlayerMoveHeadingAngle = 0xe00 - g_CameraYaw;
        }
      }
    }
    else if ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterTurnAroundHandlerPtr)();
    }
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
  }
  value2 = g_PlayerActionState;
  if (g_PlayerCollisionFacingFlags != '\0') {
    g_PlayerActionState = 0x42;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterFreeMovementStopHandlerPtr)();
  }
  return;
}

