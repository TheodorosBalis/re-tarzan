#include "tarzan_ghidra_types.hpp"

// Address: 0x0046FEB0
// Label: CPlayerHero::UpdateAdultTarzanFreeMovementAirborne
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanFreeMovementAirborne(void)

{
  short shortValue;
  uint value2;
  int value;
  uint value3;
  uint value4;
  uint value5;
  undefined4 value6;
  
  CPlayerHero::UpdateRunInputAndMovement();
  shortValue = g_PlayerActionState;
  if ((g_CameraRelativeTurnInputMask != 0) && ((_g_PlayerSequenceFlags & 0xf000) == 0)) {
    if (g_PlayerCurrentCollisionMode == 1) {
      value5 = g_PlayerInputHeldMask & 0x20;
      if (value5 != 0) {
        g_PlayerMoveHeadingAngle = 0xc00 - g_CameraYaw;
      }
      value4 = g_PlayerInputHeldMask & 0x80;
      if (value4 != 0) {
        g_PlayerMoveHeadingAngle = 0x400 - g_CameraYaw;
      }
      value3 = g_PlayerInputHeldMask & 0x10;
      if (value3 != 0) {
        g_PlayerMoveHeadingAngle = 0x800 - g_CameraYaw;
      }
      value2 = g_PlayerInputHeldMask & 0x40;
      if (value2 != 0) {
        g_PlayerMoveHeadingAngle = -g_CameraYaw;
      }
      if ((value3 != 0) && (value4 != 0)) {
        g_PlayerMoveHeadingAngle = 0x600 - g_CameraYaw;
      }
      if ((value3 != 0) && (value5 != 0)) {
        g_PlayerMoveHeadingAngle = 0xa00 - g_CameraYaw;
      }
      if (value2 != 0) {
        if (value4 != 0) {
          g_PlayerMoveHeadingAngle = 0x200 - g_CameraYaw;
        }
        if ((value2 != 0) && (value5 != 0)) {
          g_PlayerMoveHeadingAngle = 0xe00 - g_CameraYaw;
        }
      }
    }
    else if ((g_CameraRelativeTurnInputMask & g_PlayerInputHeldMask) != 0) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_AdultTarzanEnterTurnAroundHandlerPtr)();
    }
  }
  CPlayerHero::TrySnapDownToGround();
  if ((g_PlayerFacingCurrentCollisionSurface != '\0') &&
     ((*( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) & 0x200) == 0)) {
    if (((*( undefined2 *)((int)&g_PlayerSurfaceTriggerPacket + 2) & 0x2000) == 0) && (g_PlayerActionState != 0x2e)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0x2e;
      (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
    }
  }
  if (((((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
         (((ushort)g_PlayerSurfaceTriggerPacket & 0x800) == 0)) &&
        (g_HudPowerFruitSelectorScene != 0)) &&
       (((g_PlayerInputHeldMask & 0x400000) != 0 || ((g_PlayerInputHeldMask & 0x3800000) != 0)))) &&
      ((g_PlayerJumpArcActive != '\0' || (*(char *)(g_PlayerMotionState + 0xd) == '\0')))) &&
     ((g_PlayerCurrentAnimationId != 0x81 && (g_PlayerCurrentAnimationId != 0x8a)))) {
    if (((g_PlayerInputHeldMask & 0x400000) == 0) && ((g_PlayerInputHeldMask & 0x800000) == 0)) {
      if ((g_PlayerPowerFruitInventoryFlags & 0x10) == 0) goto LAB_004700c3;
      g_PlayerAttackHitSfxPlayed = 0;
      value6 = 0x8a;
    }
    else {
      value6 = 0x81;
    }
    CPlayerHero::PlayAdultTarzanAnimation(value6);
  }
LAB_004700c3:
  CPlayerHero::UpdateJumpArcVerticalMotion(1);
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 4) {
    CEntities::SpawnEntityByTypeAtPosition(0,0,0,0xf,0x11);
  }
  else if (value == 8) {
    if (g_PlayerHeldThrowableEntity != 0) {
      *(undefined2 *)(g_PlayerHeldThrowableEntity + 0x48) = 7;
    }
    g_PlayerHeldThrowableEntity = 0;
    return;
  }
  return;
}

