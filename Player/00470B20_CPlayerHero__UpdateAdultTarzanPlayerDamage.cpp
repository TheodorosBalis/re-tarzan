#include "tarzan_ghidra_types.hpp"

// Address: 0x00470B20
// Label: CPlayerHero::UpdateAdultTarzanPlayerDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanPlayerDamage(void)

{
  undefined2 value;
  char resultFlag;
  uint value2;
  uint value3;
  uint value4;
  uint value5;
  
  CPlayerHero::ApplyDamageContactPushback();
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value;
    (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
  }
  if (g_PlayerCurrentAnimationId == 0x22) {
    if ((((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerSurfaceTriggerPacket & 0x800) == 0))
       && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      *(ushort *)(g_PlayerAnimationState + 0x1e) =
           *(ushort *)(g_PlayerAnimationState + 0x1e) & 0xfeff;
      value = g_PlayerActionState;
      if (g_PlayerCurrentCollisionMode == 1) {
        if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
          g_PlayerActionState = 0x46;
          g_PreviousPlayerActionState = value;
          (*(code *)g_AdultTarzanEnterFreeMovementMovingJumpHandlerPtr)();
          return;
        }
        g_PlayerActionState = 0x45;
        g_PreviousPlayerActionState = value;
        (*(code *)g_AdultTarzanEnterFreeMovementStandingJumpHandlerPtr)();
        return;
      }
      if (g_PlayerCurrentCollisionMode == 2) {
        if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) {
          g_PlayerActionState = 5;
          g_PreviousPlayerActionState = value;
          (*(code *)g_AdultTarzanEnterMovingJumpHandlerPtr)();
          return;
        }
        g_PlayerActionState = 6;
        g_PreviousPlayerActionState = value;
        (*(code *)g_AdultTarzanEnterStandingJumpHandlerPtr)();
        return;
      }
    }
    value = g_PlayerActionState;
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
        g_PreviousPlayerActionState = value;
        (*(code *)g_AdultTarzanEnterTurnAroundHandlerPtr)();
        return;
      }
    }
    if (g_PlayerCurrentCollisionMode == 0) {
      if ((_g_PlayerSequenceFlags & 0xf000) != 0) goto LAB_00470e2d;
      if ((g_PlayerInputHeldMask & 0x80000) != 0) {
        g_PlayerActionState = 10;
        g_PreviousPlayerActionState = value;
        (*(code *)g_AdultTarzanEnterBlockHandlerPtr)();
        return;
      }
    }
    if ((((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerSurfaceTriggerPacket & 0x800) == 0))
       && ((g_PlayerInputPressedMask & 0x100000) != 0)) {
      g_PlayerActionState = 0x2c;
      g_PreviousPlayerActionState = value;
      (*(code *)g_AdultTarzanEnterPoundHandlerPtr)();
      return;
    }
  }
  else {
    if ((g_PlayerInputPressedMask & 0x200000) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
    }
    if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
      g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
    }
    g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  }
LAB_00470e2d:
  CPlayerHero::AdvanceAnimationScript();
  return;
}

