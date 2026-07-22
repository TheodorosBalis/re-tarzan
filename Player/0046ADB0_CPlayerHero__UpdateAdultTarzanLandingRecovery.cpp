#include "tarzan_ghidra_types.hpp"

// Address: 0x0046ADB0
// Label: CPlayerHero::UpdateAdultTarzanLandingRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanLandingRecovery(void)

{
  short shortValue;
  char resultFlag;
  uint value;
  uint value2;
  uint value3;
  uint value4;
  
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if ((g_PlayerFacingCurrentCollisionSurface != '\0') &&
     ((*( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) & 0x200) == 0)) {
    if ((*( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) & 0x2000) == 0) {
      if (g_PlayerActionState != 0x2e) {
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0x2e;
        (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
      }
      if (g_PlayerDamageInvulnerabilityTicks != 0) {
        return;
      }
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
    }
  }
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
      (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) &&
     ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    *(ushort *)(g_PlayerAnimationState + 0x1e) = *(ushort *)(g_PlayerAnimationState + 0x1e) & 0xfeff
    ;
    shortValue = g_PlayerActionState;
    if (g_PlayerCurrentCollisionMode == 1) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) == 0) {
        g_PlayerActionState = 0x45;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_AdultTarzanEnterFreeMovementStandingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x46;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_AdultTarzanEnterFreeMovementMovingJumpHandlerPtr)();
      return;
    }
    if (g_PlayerCurrentCollisionMode == 2) {
      if ((g_CameraFollowFlags & g_PlayerInputHeldMask) == 0) {
        g_PlayerActionState = 6;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_AdultTarzanEnterStandingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_AdultTarzanEnterMovingJumpHandlerPtr)();
      return;
    }
  }
  shortValue = g_PlayerActionState;
  if (g_PlayerCurrentAnimationId != 0x1a) {
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      if (g_PlayerCurrentCollisionMode == 1) {
        if (((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 0x41;
          g_PreviousPlayerActionState = shortValue;
          (*(code *)g_AdultTarzanEnterFreeMovementForwardHandlerPtr)();
          return;
        }
      }
      else if (g_PlayerCurrentCollisionMode == 2) {
        resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
        shortValue = g_PlayerActionState;
        if (((resultFlag == '\0') && ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0)) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 1;
          g_PreviousPlayerActionState = shortValue;
          (*(code *)g_AdultTarzanEnterMoveForwardHandlerPtr)();
          return;
        }
      }
      else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 0xd;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_AdultTarzanEnterTreeSurfingHandlerPtr)();
        return;
      }
    }
    shortValue = g_PlayerActionState;
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      if (g_PlayerCurrentCollisionMode == 1) {
        value4 = g_PlayerInputHeldMask & 0x20;
        if (value4 != 0) {
          g_PlayerMoveHeadingAngle = 0xc00 - g_CameraYaw;
        }
        value3 = g_PlayerInputHeldMask & 0x80;
        if (value3 != 0) {
          g_PlayerMoveHeadingAngle = 0x400 - g_CameraYaw;
        }
        value = g_PlayerInputHeldMask & 0x10;
        if (value != 0) {
          g_PlayerMoveHeadingAngle = 0x800 - g_CameraYaw;
        }
        value2 = g_PlayerInputHeldMask & 0x40;
        if (value2 != 0) {
          g_PlayerMoveHeadingAngle = -g_CameraYaw;
        }
        if (value != 0) {
          if (value3 != 0) {
            g_PlayerMoveHeadingAngle = 0x600 - g_CameraYaw;
          }
          if ((value != 0) && (value4 != 0)) {
            g_PlayerMoveHeadingAngle = 0xa00 - g_CameraYaw;
          }
        }
        if (value2 != 0) {
          if (value3 != 0) {
            g_PlayerMoveHeadingAngle = 0x200 - g_CameraYaw;
          }
          if ((value2 != 0) && (value4 != 0)) {
            g_PlayerMoveHeadingAngle = 0xe00 - g_CameraYaw;
          }
        }
      }
      else if ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0) {
        g_PlayerActionState = 3;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_AdultTarzanEnterTurnAroundHandlerPtr)();
        return;
      }
    }
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      if ((g_PlayerInputHeldMask & 0x80000) != 0) {
        g_PlayerActionState = 10;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_AdultTarzanEnterBlockHandlerPtr)();
        return;
      }
      if (((((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0) &&
          (g_HudPowerFruitSelectorScene != 0)) && ((g_PlayerInputHeldMask & 0x400000) != 0)) {
        g_PlayerActionState = 0x28;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_AdultTarzanEnterThrowHighHandlerPtr)();
        return;
      }
      if (((((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0) &&
          ((g_PlayerPowerFruitInventoryFlags & 0x10) != 0)) &&
         ((g_PlayerInputHeldMask & 0x1000000) != 0)) {
        g_PlayerActionState = 0x2a;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_AdultTarzanEnterStabHighHandlerPtr)();
        return;
      }
    }
    resultFlag = CPlayerHero::TryEnterAdultTarzanStabLow();
    if (resultFlag != '\0') {
      return;
    }
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  shortValue = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = shortValue;
    (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

