#include "tarzan_ghidra_types.hpp"

// Address: 0x004922E0
// Label: CPlayerHero::UpdateYoungSwingMoveToPreviousSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungSwingMoveToPreviousSegment(void)

{
  int value;
  undefined2 value3;
  int value2;
  undefined4 value4;
  
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
  }
  value3 = g_PlayerActionState;
  if ((g_PlayerInputHeldMask & 0x200000) != 0) {
    g_PlayerActionState = 0x1c;
    g_PreviousPlayerActionState = value3;
    (*(code *)g_YoungEnterSwingReleaseHandlerPtr)();
    return;
  }
  if ((g_CurrentSwingEntity != 0) && (value = *(int *)(g_CurrentSwingEntity + 0x38), value != 0)) {
    CPlayerHero::UpdateMovementAndCollision(1);
    value2 = CPlayerHero::AdvanceAnimationScript();
    if (value2 == 8) {
      g_PlayerSwingTransitionStep = g_PlayerSwingTransitionStep + 1;
      g_CurrentSwingSegmentIndex = g_CurrentSwingSegmentIndex + -1;
      if (g_CurrentSwingSegmentIndex < 3) {
        g_CurrentSwingSegmentIndex = 2;
        if (g_PlayerAnimationSurfaceSide == '\0') {
          value4 = 0x45;
        }
        else {
          value4 = 0x44;
        }
        CPlayerHero::PlayAnimation(value4);
      }
      if ((g_PlayerInputHeldMask & 0x10) == 0) {
        if (g_PlayerAnimationSurfaceSide == '\0') {
          value4 = 0x45;
        }
        else {
          value4 = 0x44;
        }
        CPlayerHero::PlayAnimation(value4);
      }
    }
    UpdatePlayerOnSwing(g_CurrentSwingEntity);
    *(int *)(g_PlayerMotionState + 0x20) =
         *(int *)(g_PlayerMotionState + 0x20) + *(int *)(g_PlayerMotionState + 0x24);
    if (*(int *)(g_PlayerMotionState + 0x2c) < *(int *)(g_PlayerMotionState + 0x20)) {
      *(int *)(g_PlayerMotionState + 0x20) = *(int *)(g_PlayerMotionState + 0x2c);
    }
    *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
         *(int *)(g_PlayerEntitySceneObjectData + 0xc) + *(int *)(g_PlayerMotionState + 0x20);
    value3 = g_PlayerActionState;
    if (*(int *)(value + 0x98) < *(int *)(g_PlayerEntitySceneObjectData + 0xc)) {
      g_PlayerActionState = 7;
      g_PreviousPlayerActionState = value3;
      (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
    }
  }
  return;
}

