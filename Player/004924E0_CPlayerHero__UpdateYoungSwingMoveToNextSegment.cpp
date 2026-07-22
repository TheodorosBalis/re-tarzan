#include "tarzan_ghidra_types.hpp"

// Address: 0x004924E0
// Label: CPlayerHero::UpdateYoungSwingMoveToNextSegment
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateYoungSwingMoveToNextSegment(void)

{
  undefined2 value2;
  int value;
  undefined4 value3;
  
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
  }
  value2 = g_PlayerActionState;
  if ((g_PlayerInputHeldMask & 0x200000) != 0) {
    g_PlayerActionState = 0x1c;
    g_PreviousPlayerActionState = value2;
                    /* WARNING: Could not recover jumptable at 0x00492522. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*(code *)g_YoungEnterSwingReleaseHandlerPtr)();
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
        if (0xc < g_CurrentSwingSegmentIndex) {
          g_CurrentSwingSegmentIndex = 0xd;
          if (g_PlayerAnimationSurfaceSide == '\0') {
            value3 = 0x4b;
          }
          else {
            value3 = 0x4a;
          }
          CPlayerHero::PlayAnimation(value3);
        }
        if ((g_PlayerInputHeldMask & 0x40) == 0) {
          if (g_PlayerAnimationSurfaceSide == '\0') {
            value3 = 0x4b;
          }
          else {
            value3 = 0x4a;
          }
          CPlayerHero::PlayAnimation(value3);
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

