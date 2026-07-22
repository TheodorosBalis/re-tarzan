#include "tarzan_ghidra_types.hpp"

// Address: 0x00477860
// Label: CPlayerHero::UpdateTerkBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateTerkBlock(void)

{
  undefined2 value;
  char resultFlag;
  
  value = g_PlayerActionState;
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     (((((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0 && ((g_PlayerInputHeldMask & 0x40) != 0)
        ) || (((g_CameraFollowFlags & g_PlayerInputHeldMask) != 0 &&
              (*(short *)(g_PlayerContactSurfaceThisFrame + 0x12) < 0x100)))) &&
      (g_PlayerCollisionFacingFlags == '\0')))) {
    g_PlayerActionState = 0x11;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x004778de. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterCrouchHandlerPtr)();
    return;
  }
  if ((*(int *)(g_PlayerEntitySceneObject + 300) == -0x7fffffff) ||
     (0xff < *(int *)(g_PlayerEntitySceneObjectData + 0xc) -
             *(int *)(g_PlayerEntitySceneObject + 300))) {
    if (g_PlayerFacingCurrentCollisionSurface != '\0') {
      if ((ram0x0051cdca & 0x1000) != 0) {
        g_PlayerActionState = 8;
        g_PreviousPlayerActionState = value;
        (*(code *)g_TerkEnterAirborneDamageHandlerPtr)();
        if (g_PlayerDamageInvulnerabilityTicks == 0) {
          g_PlayerDamageInvulnerabilityTicks = 0x3c;
          g_PlayerDamageFlashTicks = 0x3c;
        }
        return;
      }
      if (g_PlayerDamageInvulnerabilityTicks == 0) {
        CPlayerHero::ApplyDamageContactPushback();
        g_PreviousPlayerActionState = g_PlayerActionState;
        g_PlayerActionState = 0xf;
                    /* WARNING: Could not recover jumptable at 0x0047798a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*(code *)g_TerkEnterGroundDamageHandlerPtr)();
        return;
      }
      g_PlayerCollisionFacingFlags = '\x01';
      CPlayerHero::ApplyDamageContactPushback();
    }
    value = g_PlayerActionState;
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && ((g_PlayerInputPressedMask & 0x200000) != 0)) {
      g_PlayerActionState = 6;
      g_PreviousPlayerActionState = value;
      (*(code *)g_TerkEnterStandingJumpHandlerPtr)();
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x100;
      return;
    }
    if ((g_PlayerCurrentAnimationId == 0x1b) && ((g_PlayerInputHeldMask & 0x80000) == 0)) {
      g_PlayerCurrentAnimationId = 0x1c;
      *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkBlockReleaseAnimationScript;
      *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
      *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
      CPlayerHero::AdvanceAnimationScript();
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x100;
    }
  }
  else if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
          (((g_PlayerInputHeldMask & g_CameraRelativeTurnInputMask) != 0 &&
           (g_PlayerCurrentCollisionMode == 2)))) {
    g_PlayerActionState = 3;
    g_PreviousPlayerActionState = value;
    (*(code *)g_TerkEnterTurnAroundHandlerPtr)();
  }
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = value;
    (*(code *)g_TerkEnterFallingHandlerPtr)();
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

