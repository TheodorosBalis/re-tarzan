#include "tarzan_ghidra_types.hpp"

// Address: 0x00491920
// Label: CPlayerHero::UpdateYoungTreeSurfingContact
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungTreeSurfingContact(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  uint value3;
  undefined4 value4;
  
  value = g_PlayerTreeSurfingLateralThresholdSide;
  g_PlayerTreeSurfingLateralThresholdSide = 0;
  value3 = *(uint *)(*(int *)(g_PlayerEntitySceneObject + 0x114) + 0x14) & 0xf;
  *(int *)(g_PlayerEntitySceneObject + 0xa8) = *(int *)(g_PlayerEntitySceneObject + 0xa8) + 0x80;
  if (0x16ff < *(int *)(g_PlayerEntitySceneObject + 0xa8)) {
    *(undefined4 *)(g_PlayerEntitySceneObject + 0xa8) = 0x1700;
  }
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xb0) =
       *(undefined4 *)(g_PlayerEntitySceneObject + 0xa8);
  *(undefined4 *)(g_PlayerEntitySceneObject + 0xac) =
       *(undefined4 *)(g_PlayerEntitySceneObject + 0xb0);
  CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  g_PlayerSurfaceLeanScale = 200;
  _g_PlayerAnimationPlaybackFrame = 400;
  if ((_g_PlayerSequenceFlags & 0x8000) != 0) {
    g_PlayerActionState = 0x15;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_YoungEnterFatalDamageSequenceHandlerPtr)();
    return;
  }
  switch(g_PlayerActionState) {
  case 0xe:
    resultFlag = CPlayerHero::TryHandleYoungTreeSurfingHazardCue1To4(value3);
    if (((resultFlag != '\0') ||
        (resultFlag = CPlayerHero::TryHandleYoungTreeSurfingHazardCue5To7(value3), resultFlag != '\0')) ||
       (resultFlag = CPlayerHero::TryHandleYoungTreeSurfingDamageCue8To10(value3),
       value2 = g_PlayerActionState, resultFlag != '\0')) goto LAB_00491dfb;
    if (g_PlayerFacingCurrentCollisionSurface != '\0') {
      if ((ram0x0051cdca & 0x1000) == 0) {
        if (g_PlayerDamageInvulnerabilityTicks != 0) {
          g_PlayerCollisionFacingFlags = '\x01';
          CPlayerHero::ApplyDamageContactPushback();
          goto LAB_00491ae2;
        }
        if (g_PlayerCurrentCollisionMode == 4) goto LAB_00491a58;
        if (g_PlayerCurrentCollisionMode != 5) {
          g_PlayerActionState = 0xc;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_YoungEnterPlayerDamageHandlerPtr)();
          goto LAB_00491dfb;
        }
      }
      else {
        if (g_PlayerCurrentCollisionMode == 4) {
LAB_00491a58:
          g_PlayerActionState = 0x29;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
          goto LAB_00491dfb;
        }
        if (g_PlayerCurrentCollisionMode != 5) {
          g_PreviousPlayerActionState = g_PlayerActionState;
LAB_00491c5c:
          g_PlayerActionState = 0x30;
          (*(code *)g_YoungEnterJumpDamageHandlerPtr)();
          if (g_PlayerDamageInvulnerabilityTicks == 0) {
            g_PlayerDamageInvulnerabilityTicks = 0x3c;
            g_PlayerDamageFlashTicks = 0x3c;
          }
          goto LAB_00491dfb;
        }
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
      goto LAB_00491dfb;
    }
LAB_00491ae2:
    value2 = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      g_PlayerActionState = 0x10;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterTreeSurfingReboundHandlerPtr)();
      goto LAB_00491dfb;
    }
    CPlayerHero::UpdateYoungTreeSurfingLateralOffset();
    value2 = g_PlayerActionState;
    if ((((byte)g_PlayerInputHeldMask & 0x40) != 0) && (g_PlayerLateralSurfaceOffset == 0)) {
      g_PlayerActionState = 0xf;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterTreeSurfingResumeHandlerPtr)();
      _g_TreeSurfingReboundTimer = 0x19;
      goto LAB_00491dfb;
    }
    if (value != g_PlayerTreeSurfingLateralThresholdSide) {
      if (g_PlayerTreeSurfingLateralThresholdSide == 1) {
        value4 = 0x30;
      }
      else if (g_PlayerTreeSurfingLateralThresholdSide == 2) {
        value4 = 0x33;
      }
      else if (value == 1) {
        value4 = 0x32;
      }
      else if (value == 2) {
        value4 = 0x35;
      }
      else {
        value4 = 0x23;
      }
      CPlayerHero::PlayAnimation(value4);
    }
    if (0xa0 < g_PlayerSurfaceMotionSpeed) {
      g_PlayerSurfaceMotionSpeed = g_PlayerSurfaceMotionSpeed + -0x10;
      if (g_PlayerSurfaceMotionSpeed < 0xa0) {
        g_PlayerSurfaceMotionSpeed = 0xa0;
      }
      goto LAB_00491dfb;
    }
    break;
  case 0xf:
    resultFlag = CPlayerHero::TryHandleYoungTreeSurfingHazardCue1To4(value3);
    if ((resultFlag != '\0') ||
       (resultFlag = CPlayerHero::TryHandleYoungTreeSurfingHazardCue5To7(value3),
       value2 = g_PlayerActionState, resultFlag != '\0')) goto LAB_00491dfb;
    if (g_PlayerFacingCurrentCollisionSurface != '\0') {
      if ((ram0x0051cdca & 0x1000) == 0) {
        if (g_PlayerDamageInvulnerabilityTicks != 0) {
          g_PlayerCollisionFacingFlags = '\x01';
          CPlayerHero::ApplyDamageContactPushback();
          goto LAB_00491d19;
        }
        if (g_PlayerCurrentCollisionMode == 4) goto LAB_00491ceb;
        if (g_PlayerCurrentCollisionMode != 5) {
          g_PlayerActionState = 0xc;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_YoungEnterPlayerDamageHandlerPtr)();
          goto LAB_00491dfb;
        }
      }
      else {
        if (g_PlayerCurrentCollisionMode == 4) {
LAB_00491ceb:
          g_PlayerActionState = 0x29;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_YoungEnterWaterDamageHandlerPtr)();
          goto LAB_00491dfb;
        }
        if (g_PlayerCurrentCollisionMode != 5) {
          g_PreviousPlayerActionState = g_PlayerActionState;
          goto LAB_00491c5c;
        }
      }
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterTreeSurfingDamageHandlerPtr)();
      goto LAB_00491dfb;
    }
LAB_00491d19:
    value2 = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      g_PlayerActionState = 0x10;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterTreeSurfingReboundHandlerPtr)();
      goto LAB_00491dfb;
    }
    CPlayerHero::UpdateYoungTreeSurfingLateralOffset();
    value2 = g_PlayerActionState;
    g_PlayerSurfaceMotionSpeed = g_PlayerSurfaceMotionSpeed + -0x10;
    if (g_PlayerSurfaceMotionSpeed < 0x60) {
      g_PlayerSurfaceMotionSpeed = 0x60;
    }
    if ((((g_PlayerCurrentAnimationId == 0x2e) || (g_PlayerCurrentAnimationId == 0x37)) ||
        (g_PlayerCurrentAnimationId == 0x3a)) && (((byte)g_PlayerInputHeldMask & 0x40) == 0)) {
      g_PlayerActionState = 0xe;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterTouchSurfaceOnSurfingHandlerPtr)();
    }
  case 0x16:
    if (g_PlayerSurfaceMotionSpeed < 0x40) {
      g_PlayerSurfaceMotionSpeed = 0x40;
    }
    value = 4;
LAB_00491dcd:
    if (g_PlayerLateralSurfaceOffset != 0) {
      if (g_PlayerLateralSurfaceOffset < 0) {
        g_PlayerLateralSurfaceOffset = g_PlayerLateralSurfaceOffset + 1;
      }
      else {
        g_PlayerLateralSurfaceOffset = g_PlayerLateralSurfaceOffset + -1;
      }
    }
    g_PlayerSurfaceMotionSpeed = g_PlayerSurfaceMotionSpeed + -0x10;
    if (g_PlayerSurfaceMotionSpeed < value) {
      g_PlayerSurfaceMotionSpeed = value;
    }
    goto LAB_00491dfb;
  case 0x10:
    resultFlag = CPlayerHero::TryHandleYoungTreeSurfingHazardCue5To7(value3);
    if (resultFlag == '\0') {
      CPlayerHero::TryHandleYoungTreeSurfingDamageCue8To10(value3);
    }
  default:
    goto LAB_00491dfb;
  case 0x12:
    break;
  case 0x13:
  case 0x14:
    value = 0x60;
    goto LAB_00491dcd;
  }
  if ((g_PlayerSurfaceMotionSpeed < 0xa0) &&
     (g_PlayerSurfaceMotionSpeed = g_PlayerSurfaceMotionSpeed + 0x10,
     0xa0 < g_PlayerSurfaceMotionSpeed)) {
    g_PlayerSurfaceMotionSpeed = 0xa0;
  }
LAB_00491dfb:
  *(int *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 0x11;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_YoungEnterTarzanFallingAltHandlerPtr)();
    DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
  }
  value2 = g_PlayerActionState;
  if (g_PlayerCollisionFacingFlags != '\0') {
    g_PlayerActionState = 2;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_YoungEnterTarzanStopForwardMovementHandlerPtr)();
  }
  return;
}

