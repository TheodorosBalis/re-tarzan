#include "tarzan_ghidra_types.hpp"

// Address: 0x00477170
// Label: CPlayerHero::UpdateTerkMoveForward
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTerkMoveForward(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  value2 = g_PlayerActionState;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
    g_PlayerActionState = 5;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0047719b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*g_TerkEnterMovingJumpHandlerPtr)();
    return;
  }
  if (g_PlayerFacingCurrentCollisionSurface == '\0') {
    value = CPlayerHero::AdvanceAnimationScript();
    if (value == 7) {
      g_PlayerCurrentAnimationId = 3;
      *(undefined4 *)(g_PlayerAnimationState + 0xc) = _g_TerkMoveForwardStepTiming;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero::AdvanceAnimationScript();
    }
    value2 = g_PlayerActionState;
    if ((g_PlayerInputHeldMask & (g_CameraFollowFlags | g_CameraRelativeTurnInputMask)) == 0) {
      g_PlayerActionState = 2;
      g_PreviousPlayerActionState = value2;
      (*_g_TerkEnterStopForwardMovementHandlerPtr)();
    }
    else if ((((_g_PlayerSequenceFlags & 0xf000) == 0) &&
             ((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0)) &&
            (g_PlayerCurrentCollisionMode == 2)) {
      g_PlayerActionState = 3;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_TerkEnterTurnAroundHandlerPtr)();
    }
    CPlayerHero::UpdateMovementAndCollision(1);
    resultFlag = CPlayerHero::TrySnapToNearbyGround();
    value2 = g_PlayerActionState;
    if (resultFlag == '\0') {
      g_PlayerActionState = 10;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_TerkEnterFallingHandlerPtr)();
    }
    value2 = g_PlayerActionState;
    if (g_PlayerCollisionFacingFlags != '\0') {
      g_PlayerActionState = 2;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0047730c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*_g_TerkEnterStopForwardMovementHandlerPtr)();
      return;
    }
  }
  else {
    if ((ram0x0051cdca & 0x1000) == 0) {
      g_PlayerActionState = 0xf;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00477204. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterGroundDamageHandlerPtr)();
      return;
    }
    g_PlayerActionState = 8;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_TerkEnterAirborneDamageHandlerPtr)();
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      g_PlayerDamageInvulnerabilityTicks = 0x3c;
      g_PlayerDamageFlashTicks = 0x3c;
    }
  }
  return;
}

