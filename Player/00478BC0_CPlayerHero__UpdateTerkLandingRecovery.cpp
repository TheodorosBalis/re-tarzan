#include "tarzan_ghidra_types.hpp"

// Address: 0x00478BC0
// Label: CPlayerHero::UpdateTerkLandingRecovery
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTerkLandingRecovery(void)

{
  short shortValue;
  char resultFlag;
  int value;
  
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    shortValue = g_PlayerActionState;
    if (((ram0x0051cdca & 0x2000) == 0) && (g_PlayerActionState != 8)) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 8;
      (*(code *)g_TerkEnterAirborneDamageHandlerPtr)();
      shortValue = g_PlayerActionState;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageFlashTicks = 0x3c;
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
    }
    g_PlayerActionState = shortValue;
    if (g_PlayerFacingCurrentCollisionSurface != '\0') {
      if ((unique0x100000f2 & 0x1000) == 0) {
        if (g_PlayerDamageInvulnerabilityTicks == 0) {
          CPlayerHero::ApplyDamageContactPushback();
          g_PreviousPlayerActionState = g_PlayerActionState;
          g_PlayerActionState = 0xf;
          (*(code *)g_TerkEnterGroundDamageHandlerPtr)();
        }
        else {
          g_PlayerCollisionFacingFlags = '\x01';
          CPlayerHero::ApplyDamageContactPushback();
        }
      }
      else {
        g_PlayerActionState = 8;
        g_PreviousPlayerActionState = shortValue;
        (*(code *)g_TerkEnterAirborneDamageHandlerPtr)();
        if (g_PlayerDamageInvulnerabilityTicks == 0) {
          g_PlayerDamageInvulnerabilityTicks = 0x3c;
          g_PlayerDamageFlashTicks = 0x3c;
        }
      }
    }
  }
  shortValue = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = shortValue;
    (*(code *)g_TerkEnterStandingJumpHandlerPtr)();
    return;
  }
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
      ((g_CameraRelativeTurnInputMask & g_PlayerInputHeldMask) != 0)) &&
     (g_PlayerCurrentCollisionMode == 2)) {
    g_PlayerActionState = 3;
    g_PreviousPlayerActionState = shortValue;
    (*(code *)g_TerkEnterTurnAroundHandlerPtr)();
    return;
  }
  if ((((_g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionMode == 2)) &&
     ((resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface(), shortValue = g_PlayerActionState,
      resultFlag == '\0' &&
      (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0 && (g_PlayerCollisionFacingFlags == '\0')
       ))))) {
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = shortValue;
    (*(code *)g_TerkEnterMoveForwardHandlerPtr)();
    return;
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  shortValue = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = shortValue;
    (*(code *)g_TerkEnterFallingHandlerPtr)();
  }
  value = CPlayerHero::AdvanceAnimationScript();
  shortValue = g_PlayerActionState;
  if (((value == 0x11) && ((_g_PlayerSequenceFlags & 0xf000) == 0)) &&
     ((g_PlayerInputHeldMask & 0x80000) != 0)) {
    g_PlayerActionState = 0xd;
    g_PreviousPlayerActionState = shortValue;
    (*(code *)g_TerkEnterBlockHandlerPtr)();
    g_PlayerCurrentAnimationId = 0x1a;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkLandingRecoveryEndTiming;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
  }
  return;
}

