#include "tarzan_ghidra_types.hpp"

// Address: 0x00477B90
// Label: CPlayerHero::UpdateTerkCrouch
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTerkCrouch(void)

{
  undefined2 value2;
  char resultFlag;
  int value;
  
  if (g_PlayerFacingCurrentCollisionSurface != '\0') {
    if ((ram0x0051cdca & 0x1000) != 0) {
      g_PreviousPlayerActionState = g_PlayerActionState;
      goto LAB_00477c63;
    }
    if (g_PlayerDamageInvulnerabilityTicks == 0) {
      CPlayerHero::ApplyDamageContactPushback();
      g_PreviousPlayerActionState = g_PlayerActionState;
      g_PlayerActionState = 0xf;
                    /* WARNING: Could not recover jumptable at 0x00477bda. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterGroundDamageHandlerPtr)();
      return;
    }
    g_PlayerCollisionFacingFlags = '\x01';
    CPlayerHero::ApplyDamageContactPushback();
  }
  value2 = g_PlayerActionState;
  if ((*(int *)(g_PlayerEntitySceneObject + 300) == -0x7fffffff) ||
     (0xff < *(int *)(g_PlayerEntitySceneObjectData + 0xc) -
             *(int *)(g_PlayerEntitySceneObject + 300))) {
    if ((g_PlayerInputHeldMask & 0x80000) == 0) {
      g_PlayerActionState = 0x12;
      g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00477c3c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_TerkEnterCrouchLookHandlerPtr)();
      return;
    }
    if (g_PlayerFacingCurrentCollisionSurface != '\0') {
      if ((ram0x0051cdca & 0x1000) != 0) {
        g_PreviousPlayerActionState = g_PlayerActionState;
LAB_00477c63:
        g_PlayerActionState = 8;
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
                    /* WARNING: Could not recover jumptable at 0x00477cb4. Too many branches */
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
      (*(code *)g_TerkEnterStandingJumpHandlerPtr)();
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x100;
      return;
    }
    if (((g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = value2;
      (*g_TerkEnterMovingJumpHandlerPtr)();
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x100;
      return;
    }
    if ((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) goto LAB_00477d94;
    g_PreviousPlayerActionState = g_PlayerActionState;
  }
  else {
    if ((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0) goto LAB_00477d94;
    g_PreviousPlayerActionState = g_PlayerActionState;
  }
  g_PlayerActionState = 0x12;
  (*(code *)g_TerkEnterCrouchLookHandlerPtr)();
LAB_00477d94:
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 7) {
    g_PlayerCurrentAnimationId = 0x20;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkCrouchIdleAnimationScript;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
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
  if (g_PlayerCollisionFacingFlags == '\0') {
    return;
  }
  g_PlayerActionState = 0x12;
  g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00477e23. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)g_TerkEnterCrouchLookHandlerPtr)();
  return;
}

