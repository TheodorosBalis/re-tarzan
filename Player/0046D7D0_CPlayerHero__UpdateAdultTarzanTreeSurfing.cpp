#include "tarzan_ghidra_types.hpp"

// Address: 0x0046D7D0
// Label: CPlayerHero::UpdateAdultTarzanTreeSurfing
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanTreeSurfing(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  uint value3;
  undefined4 value4;
  
  value = g_PlayerTreeSurfingLateralThresholdSide;
  g_PlayerTreeSurfingLateralThresholdSide = 0;
  value3 = *(uint *)(*(int *)(g_PlayerEntitySceneObject + 0x114) + 0x14) & 0xf;
  CPlayerHero::AdvanceAnimationScript();
  value2 = g_PlayerActionState;
  g_PlayerSurfaceLeanScale = 200;
  _g_PlayerAnimationPlaybackFrame = 400;
  if ((_g_PlayerSequenceFlags & 0x8000) != 0) {
    g_PlayerActionState = 0x14;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterTreeSurfingFatalDamageHandlerPtr)();
    return;
  }
  switch(g_PlayerActionState) {
  case 0xd:
    resultFlag = CPlayerHero::TryApplyAdultTarzanTreeSurfingEdgeDamage(value3);
    if (((resultFlag != '\0') ||
        (resultFlag = CPlayerHero::TryApplyAdultTarzanTreeSurfingCenterDamage(value3), resultFlag != '\0')) ||
       (resultFlag = CPlayerHero::TryEnterAdultTarzanTreeSurfingCrash(value3), value2 = g_PlayerActionState
       , resultFlag != '\0')) goto LAB_0046dc85;
    if (g_PlayerFacingCurrentCollisionSurface != '\0') {
      if ((ram0x0051cdca & 0x1000) != 0) {
        if (g_PlayerCurrentCollisionMode == 5) {
          g_PlayerActionState = 0x12;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_AdultTarzanEnterTreeSurfingObstacleDamageHandlerPtr)();
          goto LAB_0046dc85;
        }
        g_PreviousPlayerActionState = g_PlayerActionState;
LAB_0046dadd:
        g_PlayerActionState = 0x2e;
        (*(code *)g_AdultTarzanEnterAirborneDamageHandlerPtr)();
        if (g_PlayerDamageInvulnerabilityTicks == 0) {
          g_PlayerDamageInvulnerabilityTicks = 0x3c;
          g_PlayerDamageFlashTicks = 0x3c;
        }
        goto LAB_0046dc85;
      }
      if (g_PlayerDamageInvulnerabilityTicks == 0) {
        if (g_PlayerCurrentCollisionMode == 2) {
          CPlayerHero::ApplyDamageContactPushback();
          g_PreviousPlayerActionState = g_PlayerActionState;
          g_PlayerActionState = 0xb;
          (*(code *)g_AdultTarzanEnterPlayerDamageHandlerPtr)();
          goto LAB_0046dc85;
        }
        if (g_PlayerCurrentCollisionMode == 5) {
          g_PlayerActionState = 0x12;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_YoungEnterSurfingModeHandlerPtr)();
          goto LAB_0046dc85;
        }
LAB_0046db73:
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0xb;
        (*(code *)g_AdultTarzanEnterPlayerDamageHandlerPtr)();
        goto LAB_0046dc85;
      }
      g_PlayerCollisionFacingFlags = '\x01';
      CPlayerHero::ApplyDamageContactPushback();
    }
    value2 = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      g_PlayerActionState = 0xf;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterTreeSurfingJumpHandlerPtr)();
      goto LAB_0046dc85;
    }
    CPlayerHero::UpdateAdultTarzanTreeSurfingLateralOffset();
    value2 = g_PlayerActionState;
    if ((((byte)g_PlayerInputHeldMask & 0x40) != 0) && (g_PlayerLateralSurfaceOffset == 0)) {
      g_PlayerActionState = 0xe;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterTreeSurfingBrakeHandlerPtr)();
      _g_TarzanTreeSurfingJumpSurfaceState = 0x19;
      goto LAB_0046dc85;
    }
    if (value != g_PlayerTreeSurfingLateralThresholdSide) {
      if (g_PlayerTreeSurfingLateralThresholdSide == 1) {
        value4 = 0x32;
      }
      else if (g_PlayerTreeSurfingLateralThresholdSide == 2) {
        value4 = 0x35;
      }
      else if (value == 1) {
        value4 = 0x34;
      }
      else if (value == 2) {
        value4 = 0x37;
      }
      else {
        value4 = 0x25;
      }
      CPlayerHero::PlayAdultTarzanAnimation(value4);
    }
    if (0xa0 < g_PlayerSurfaceMotionSpeed) {
      g_PlayerSurfaceMotionSpeed = g_PlayerSurfaceMotionSpeed + -0x10;
      if (g_PlayerSurfaceMotionSpeed < 0xa0) {
        g_PlayerSurfaceMotionSpeed = 0xa0;
      }
      goto LAB_0046dc85;
    }
    break;
  case 0xe:
    resultFlag = CPlayerHero::TryApplyAdultTarzanTreeSurfingEdgeDamage(value3);
    if ((resultFlag != '\0') ||
       (resultFlag = CPlayerHero::TryApplyAdultTarzanTreeSurfingCenterDamage(value3),
       value2 = g_PlayerActionState, resultFlag != '\0')) goto LAB_0046dc85;
    if (g_PlayerFacingCurrentCollisionSurface != '\0') {
      if ((ram0x0051cdca & 0x1000) != 0) {
        if (g_PlayerCurrentCollisionMode == 5) {
          g_PlayerActionState = 0x12;
          g_PreviousPlayerActionState = value2;
          (*(code *)g_AdultTarzanEnterTreeSurfingObstacleDamageHandlerPtr)();
          goto LAB_0046dc85;
        }
        g_PreviousPlayerActionState = g_PlayerActionState;
        goto LAB_0046dadd;
      }
      if (g_PlayerDamageInvulnerabilityTicks == 0) {
        if (g_PlayerCurrentCollisionMode != 2) {
          if (g_PlayerCurrentCollisionMode == 5) {
            g_PlayerActionState = 0x12;
            g_PreviousPlayerActionState = value2;
            (*(code *)g_YoungEnterSurfingModeHandlerPtr)();
          }
          else {
            g_PlayerActionState = 0xb;
            g_PreviousPlayerActionState = value2;
            (*(code *)g_AdultTarzanEnterPlayerDamageHandlerPtr)();
          }
          goto LAB_0046dc85;
        }
        CPlayerHero::ApplyDamageContactPushback();
        goto LAB_0046db73;
      }
      g_PlayerCollisionFacingFlags = '\x01';
      CPlayerHero::ApplyDamageContactPushback();
    }
    value2 = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      g_PlayerActionState = 0xf;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterTreeSurfingJumpHandlerPtr)();
      goto LAB_0046dc85;
    }
    CPlayerHero::UpdateAdultTarzanTreeSurfingLateralOffset();
    value2 = g_PlayerActionState;
    g_PlayerSurfaceMotionSpeed = g_PlayerSurfaceMotionSpeed + -0x10;
    if (g_PlayerSurfaceMotionSpeed < 0x80) {
      g_PlayerSurfaceMotionSpeed = 0x80;
    }
    if ((((g_PlayerCurrentAnimationId == 0x30) || (g_PlayerCurrentAnimationId == 0x39)) ||
        (g_PlayerCurrentAnimationId == 0x3c)) && (((byte)g_PlayerInputHeldMask & 0x40) == 0)) {
      g_PlayerActionState = 0xd;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterTreeSurfingHandlerPtr)();
    }
  case 0x15:
    if (g_PlayerSurfaceMotionSpeed < 0x40) {
      g_PlayerSurfaceMotionSpeed = 0x40;
    }
    value = 4;
LAB_0046dc57:
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
    goto LAB_0046dc85;
  case 0xf:
    resultFlag = CPlayerHero::TryApplyAdultTarzanTreeSurfingCenterDamage(value3);
    if (resultFlag == '\0') {
      CPlayerHero::TryEnterAdultTarzanTreeSurfingCrash(value3);
    }
  default:
    goto LAB_0046dc85;
  case 0x11:
    break;
  case 0x12:
  case 0x13:
    value = 0x80;
    goto LAB_0046dc57;
  }
  if ((g_PlayerSurfaceMotionSpeed < 0xa0) &&
     (g_PlayerSurfaceMotionSpeed = g_PlayerSurfaceMotionSpeed + 0x10,
     0xa0 < g_PlayerSurfaceMotionSpeed)) {
    g_PlayerSurfaceMotionSpeed = 0xa0;
  }
LAB_0046dc85:
  *(int *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 0x10;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterFallingHandlerPtr)();
    DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
  }
  value2 = g_PlayerActionState;
  if (g_PlayerCollisionFacingFlags != '\0') {
    g_PlayerActionState = 2;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_AdultTarzanEnterStopForwardMovementHandlerPtr)();
  }
  return;
}

