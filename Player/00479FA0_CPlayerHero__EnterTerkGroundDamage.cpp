#include "tarzan_ghidra_types.hpp"

// Address: 0x00479FA0
// Label: CPlayerHero::EnterTerkGroundDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkGroundDamage(void)

{
  undefined2 value;
  char resultFlag;
  
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  g_PlayerCurrentAnimationId = 0x1f;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkGroundDamageAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  *(undefined2 *)(g_PlayerEntitySceneObject + 0x142) = 0x100;
  g_PlayerDamageInvulnerabilityTicks = 0x3c;
  g_PlayerDamageFlashTicks = 0x3c;
  CPlayerHero::ApplyDamageContactPushback();
  CPlayerHero::UpdateMovementAndCollision(1);
  resultFlag = CPlayerHero::TrySnapToNearbyGround();
  value = g_PlayerActionState;
  if (resultFlag == '\0') {
    g_PlayerActionState = 10;
    g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0047a08e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_TerkEnterFallingHandlerPtr)();
    return;
  }
  return;
}

