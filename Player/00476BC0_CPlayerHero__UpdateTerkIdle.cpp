#include "tarzan_ghidra_types.hpp"

// Address: 0x00476BC0
// Label: CPlayerHero::UpdateTerkIdle
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTerkIdle(void)

{
  undefined2 value2;
  char resultFlag;
  short shortValue;
  int value;
  bool flagByte;
  
  value2 = g_PlayerActionState;
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      g_PlayerActionState = 8;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_TerkEnterAirborneDamageHandlerPtr)();
      if (g_PlayerDamageInvulnerabilityTicks != 0) {
        return;
      }
      g_PlayerDamageFlashTicks = 0x3c;
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      return;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      CPlayerHero::ApplyDamageContactPushback();
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0xf;
                    /* WARNING: Could not recover jumptable at 0x00476c30. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterGroundDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero::ApplyDamageContactPushback();
  }
  value2 = g_PlayerActionState;
  if (((g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 6;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00476c71. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterStandingJumpHandlerPtr)();
    return;
  }
  if (((((g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionMode == 2)) &&
      (resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface(), value2 = g_PlayerActionState,
      resultFlag == '\0')) &&
     (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0 && (g_PlayerCollisionFacingFlags == '\0'))
     )) {
    g_PlayerActionState = 1;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00476cc4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterMoveForwardHandlerPtr)();
    return;
  }
  value2 = g_PlayerActionState;
  if ((((g_PlayerSequenceFlags & 0xf000) == 0) &&
      ((g_CameraRelativeTurnInputMask & g_PlayerInputHeldMask) != 0)) &&
     (g_PlayerCurrentCollisionMode == 2)) {
    g_PlayerActionState = 3;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00476d0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterTurnAroundHandlerPtr)();
    return;
  }
  if ((g_PlayerSequenceFlags & 0xf000) == 0) {
    if ((g_PlayerInputPressedMask & 0x100000) != 0) {
      g_PlayerActionState = 0x13;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00476d3a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*_g_TerkEnterIdleHandlerPtr)();
      return;
    }
    if ((g_PlayerInputHeldMask & 0x80000) != 0) {
      g_PlayerActionState = 0xd;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00476d68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterBlockHandlerPtr)();
      return;
    }
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00476d96. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterFallingHandlerPtr)();
    return;
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if ((value != 0) &&
     (shortValue = g_PlayerIdleFidgetDelayTicks + -1, flagByte = g_PlayerIdleFidgetDelayTicks < 0,
     g_PlayerIdleFidgetDelayTicks = shortValue, flagByte)) {
    value = RandomModulo(3);
    if (value == 1) {
      g_PlayerCurrentAnimationId = 6;
      *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkIdleFidgetAnimationScript;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero::AdvanceAnimationScript();
      return;
    }
    if (value != 2) {
      g_PlayerCurrentAnimationId = 5;
      *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkIdleLookAnimationScript;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero::AdvanceAnimationScript();
      return;
    }
    g_PlayerCurrentAnimationId = 4;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkIdleAnimationScript;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
  return;
}

