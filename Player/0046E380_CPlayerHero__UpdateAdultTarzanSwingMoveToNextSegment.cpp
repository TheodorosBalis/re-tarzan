#include "tarzan_ghidra_types.hpp"

// Address: 0x0046E380
// Label: CPlayerHero::UpdateAdultTarzanSwingMoveToNextSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanSwingMoveToNextSegment(void)

{
  undefined2 value2;
  int value;
  undefined4 value3;
  
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0)) {
    *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
  }
  value2 = g_PlayerActionState;
  if ((g_PlayerInputHeldMask & 0x200000) != 0) {
    g_PlayerActionState = 0x1b;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x0046e3cc. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_AdultTarzanEnterSwingReleaseHandlerPtr)();
    return;
  }
  if (g_CurrentSwingEntity != 0) {
    value = CEntities::FindEntityAttachmentByFlags(g_CurrentSwingEntity,0x8000000);
    if (value != 0) {
      CPlayerHero::UpdateMovementAndCollision(1);
      value = CPlayerHero::AdvanceAnimationScript();
      if (value == 8) {
        g_PlayerSwingTransitionStep = g_PlayerSwingTransitionStep + 1;
        g_CurrentSwingSegmentIndex = g_CurrentSwingSegmentIndex + 1;
        if (g_MaxSwingSegmentIndex <= g_CurrentSwingSegmentIndex) {
          g_CurrentSwingSegmentIndex = g_MaxSwingSegmentIndex;
          if (g_PlayerAnimationSurfaceSide == '\0') {
            value3 = 0x4d;
          }
          else {
            value3 = 0x4c;
          }
          CPlayerHero::PlayAdultTarzanAnimation(value3);
        }
        if ((g_PlayerInputHeldMask & 0x40) == 0) {
          if (g_PlayerAnimationSurfaceSide == '\0') {
            value3 = 0x4d;
          }
          else {
            value3 = 0x4c;
          }
          CPlayerHero::PlayAdultTarzanAnimation(value3);
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
    }
  }
  return;
}

