#include "tarzan_ghidra_types.hpp"

// Address: 0x00492040
// Label: CPlayerHero::UpdateYoungSwinging
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateYoungSwinging(void)

{
  undefined2 value2;
  int value;
  
  value2 = g_PlayerActionState;
  if (g_CurrentSwingEntity == 0) {
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) && (g_PlayerCurrentCollisionSurface != 0)) {
      if ((g_PlayerInputHeldMask & 0x200000) != 0) {
        g_PlayerActionState = 7;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterTarzanFallingHandlerPtr)();
        return;
      }
      if (((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) &&
         ((*(byte *)(g_PlayerCurrentCollisionSurface + 0x14) & 0x10) != 0)) {
        g_PlayerActionState = 0x1d;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterSwingToClimbableSurfaceHandlerPtr)();
        return;
      }
    }
  }
  else {
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      if (((g_PlayerInputHeldMask & 0x10) != 0) && (2 < g_CurrentSwingSegmentIndex)) {
        g_PlayerActionState = 0x19;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterSwingMoveToPreviousSegmentHandlerPtr)();
LAB_004920ea:
        *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
        *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
        return;
      }
      if (((g_PlayerInputHeldMask & 0x40) != 0) && (g_CurrentSwingSegmentIndex < 0xd)) {
        g_PlayerActionState = 0x1b;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterSwingMoveToNextSegmentHandlerPtr)();
        goto LAB_004920ea;
      }
      if ((g_PlayerInputPressedMask & 0x200000) != 0) {
        g_PlayerActionState = 0x1c;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_YoungEnterSwingReleaseHandlerPtr)();
        goto LAB_004920ea;
      }
    }
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
       ((g_PlayerInputPressedMask & g_CameraFollowFlags) != 0)) {
      g_PlayerActionState = 0x1f;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_YoungEnterSwingPumpHandlerPtr)();
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
      *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
      return;
    }
    UpdatePlayerOnSwing(g_CurrentSwingEntity);
  }
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
  }
  value = CPlayerHero::AdvanceAnimationScript();
  if ((0x3c < value) && (value < 0x3f)) {
    if (*(byte *)(g_PlayerEntitySceneObject + 0x75) != g_PlayerFacingBeforeSwing) {
      *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
      *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
           *(ushort *)(g_PlayerEntitySceneObject + 0xa2) ^ 0x800;
    }
    CPlayerHero::PlayAnimation(value);
  }
  CPlayerHero::UpdateMovementAndCollision(0);
  return;
}

