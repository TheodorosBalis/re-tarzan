#include "tarzan_ghidra_types.hpp"

// Address: 0x0048EC60
// Label: CPlayerHero::UpdateYoungThrow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungThrow(void)

{
  short shortValue;
  char resultFlag;
  int value;
  
  shortValue = g_PlayerActionState;
  if (g_PlayerFacingCurrentCollisionSurface == '\0') {
LAB_0048ed49:
    shortValue = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
       ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) {
      if (g_PlayerCurrentCollisionMode == 2) {
        g_PlayerActionState = 3;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_YoungEnterTarzanTurnAroundHandlerPtr)();
        g_PlayerHeldThrowableEntity = 0;
        return;
      }
      if ((g_PlayerInputHeldMask & 0x80) == 0) {
        g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + 0x2d;
      }
      else {
        g_PlayerMoveHeadingAngle = g_PlayerMoveHeadingAngle + -0x2d;
      }
    }
    if ((((g_PlayerCurrentAnimationId == 0x87) || (g_PlayerCurrentAnimationId == 0x8c)) &&
        ((_g_PlayerSequenceFlags & 0xf000) == 0)) && (g_PlayerCurrentCollisionMode != 0)) {
      if (g_PlayerCurrentCollisionMode < 3) {
        resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface();
        shortValue = g_PlayerActionState;
        if (((resultFlag == '\0') && ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0)) &&
           (g_PlayerCollisionFacingFlags == '\0')) {
          g_PlayerActionState = 1;
          g_PreviousPlayerActionState = shortValue;
          (*(code *)g_YoungEnterTarzanMoveForwardHandlerPtr)();
          return;
        }
      }
      else if ((g_PlayerCurrentCollisionMode == 5) && (g_PlayerCollisionFacingFlags == '\0')) {
        g_PlayerActionState = 0xe;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_YoungEnterTouchSurfaceOnSurfingHandlerPtr)();
        return;
      }
    }
    shortValue = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) {
        g_PlayerActionState = 5;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_YoungEnterTarzanMovingJumpHandlerPtr)();
        return;
      }
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_YoungEnterTarzanStandingJumpHandlerPtr)();
      return;
    }
    CPlayerHero::UpdateMovementAndCollision(1);
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
        if (g_PlayerActionState == 0x32) {
          if ((g_PlayerInputHeldMask & 0x400000) != 0) {
            *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
            return;
          }
          if ((g_PlayerInputHeldMask & 0x800000) != 0) {
            CPlayerHero::PlayAnimation(0x88);
            g_PlayerActionState = 0x33;
            return;
          }
          CPlayerHero::PlayAnimation(0x87);
          return;
        }
        if (g_PlayerActionState == 0x33) {
          if ((g_PlayerInputHeldMask & 0x800000) != 0) {
            *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
            return;
          }
          if ((g_PlayerInputHeldMask & 0x400000) != 0) {
            CPlayerHero::PlayAnimation(0x84);
            g_PlayerActionState = 0x32;
            return;
          }
          CPlayerHero::PlayAnimation(0x8c);
          return;
        }
      }
    }
    return;
  }
  if ((ram0x0051cdca & 0x1000) == 0) {
    if (g_PlayerDamageInvulnerabilityTicks != 0) {
      g_PlayerCollisionFacingFlags = '\x01';
      CPlayerHero::ApplyDamageContactPushback();
      goto LAB_0048ed49;
    }
    if (g_PlayerCurrentCollisionMode != 4) {
      if (g_PlayerCurrentCollisionMode != 5) {
        g_PlayerActionState = 0xc;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_YoungEnterPlayerDamageHandlerPtr)();
        return;
      }
      goto LAB_0048ecff;
    }
  }
  else if (g_PlayerCurrentCollisionMode != 4) {
    if (g_PlayerCurrentCollisionMode != 5) {
      g_PlayerActionState = 0x30;
      g_PreviousPlayerActionState = shortValue;
      (*(code *)g_YoungEnterJumpDamageHandlerPtr)();
      if (g_PlayerDamageInvulnerabilityTicks != 0) {
        return;
      }
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
      return;
    }
LAB_0048ecff:
    g_PlayerActionState = 0x13;
    g_PreviousPlayerActionState = shortValue;
    (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
    return;
  }
  g_PlayerActionState = 0x29;
  g_PreviousPlayerActionState = shortValue;
  (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
  return;
}

