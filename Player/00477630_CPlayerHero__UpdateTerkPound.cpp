#include "tarzan_ghidra_types.hpp"

// Address: 0x00477630
// Label: CPlayerHero::UpdateTerkPound
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTerkPound(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
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
                    /* WARNING: Could not recover jumptable at 0x004776a0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterGroundDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero::ApplyDamageContactPushback();
  }
  if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
    if ((((g_PlayerCurrentCollisionMode == 2) &&
         (resultFlag = CPlayerHero::IsFacingCurrentCollisionSurface(), value2 = g_PlayerActionState,
         resultFlag == '\0')) && ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0)) &&
       (g_PlayerCollisionFacingFlags == '\0')) {
      g_PlayerActionState = 1;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00477702. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterMoveForwardHandlerPtr)();
      return;
    }
    value2 = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00477735. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterStandingJumpHandlerPtr)();
      return;
    }
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value2 = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = value2;
    (*(code *)g_TerkEnterFallingHandlerPtr)();
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if ((value == 8) && ((g_PlayerInputHeldMask & 0x100000) == 0)) {
    g_PlayerCurrentAnimationId = 0x18;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkPoundImpactTiming;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
    return;
  }
  return;
}

