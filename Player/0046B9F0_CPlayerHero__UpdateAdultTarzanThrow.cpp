#include "tarzan_ghidra_types.hpp"

// Address: 0x0046B9F0
// Label: CPlayerHero::UpdateAdultTarzanThrow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanThrow(void)

{
  short shortValue;
  char resultFlag;
  uint value2;
  int value;
  uint value3;
  uint value4;
  uint value5;
  
  shortValue = g_PlayerActionState;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((*( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) & 0x1000) != 0) {
      if (g_PlayerCurrentCollisionMode == 5) {
        g_PlayerActionState = 0x12;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_AdultTarzanEnterTreeSurfingObstacleDamageHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0x2e;
      g_PreviousPlayerActionState = shortValue;
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
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_YoungEnterSurfingModeHandlerPtr)();
        return;
      }
      g_PlayerActionState = 0xb;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_AdultTarzanEnterPlayerDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero::ApplyDamageContactPushback();
  }
  shortValue = g_PlayerActionState;
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if (g_PlayerCurrentCollisionMode == 1) {
      value5 = g_PlayerInputHeldMask & 0x20;
      if (value5 != 0) {
        g_PlayerMoveHeadingAngle = 0xc00 - g_CameraYaw;
      }
      value4 = g_PlayerInputHeldMask & 0x80;
      if (value4 != 0) {
        g_PlayerMoveHeadingAngle = 0x400 - g_CameraYaw;
      }
      value2 = g_PlayerInputHeldMask & 0x10;
      if (value2 != 0) {
        g_PlayerMoveHeadingAngle = 0x800 - g_CameraYaw;
      }
      value3 = g_PlayerInputHeldMask & 0x40;
      if (value3 != 0) {
        g_PlayerMoveHeadingAngle = -g_CameraYaw;
      }
      if (value2 != 0) {
        if (value4 != 0) {
          g_PlayerMoveHeadingAngle = 0x600 - g_CameraYaw;
        }
        if ((value2 != 0) && (value5 != 0)) {
          g_PlayerMoveHeadingAngle = 0xa00 - g_CameraYaw;
        }
      }
      if (value3 != 0) {
        if (value4 != 0) {
          g_PlayerMoveHeadingAngle = 0x200 - g_CameraYaw;
        }
        if ((value3 != 0) && (value5 != 0)) {
          g_PlayerMoveHeadingAngle = 0xe00 - g_CameraYaw;
        }
      }
    }
    else if ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_AdultTarzanEnterTurnAroundHandlerPtr)();
      g_PlayerHeldThrowableEntity = 0;
      return;
    }
  }
  if (((g_PlayerCurrentAnimationId == 0x7b) || (g_PlayerCurrentAnimationId == 0x80)) &&
     ((_g_PlayerSequenceFlags & 0xf000) == 0)) {
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
      if (((resultFlag == '\0') && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
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
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  shortValue = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = shortValue;
    (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 4) {
    CEntities::SpawnEntityByTypeAtPosition(0,0,0,0xf,0x11);
  }
  else {
    if (value == 8) {
      if (g_PlayerHeldThrowableEntity != 0) {
        *(undefined2 *)(g_PlayerHeldThrowableEntity + 0x48) = 7;
      }
      g_PlayerHeldThrowableEntity = 0;
      return;
    }
    if (value == 0x12) {
      if (g_PlayerActionState == 0x28) {
        if ((g_PlayerInputHeldMask & 0x400000) == 0) {
          if ((g_PlayerInputHeldMask & 0x800000) == 0) {
            CPlayerHero::PlayAdultTarzanAnimation(0x7b);
            return;
          }
          CPlayerHero::PlayAdultTarzanAnimation(0x7c);
          g_PlayerActionState = 0x29;
          return;
        }
      }
      else if ((g_PlayerActionState == 0x29) && ((g_PlayerInputHeldMask & 0x800000) == 0)) {
        if ((g_PlayerInputHeldMask & 0x400000) == 0) {
          CPlayerHero::PlayAdultTarzanAnimation(0x80);
          return;
        }
        CPlayerHero::PlayAdultTarzanAnimation(0x78);
        g_PlayerActionState = 0x28;
        return;
      }
    }
  }
  return;
}

