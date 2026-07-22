#include "tarzan_ghidra_types.hpp"

// Address: 0x0046DEC0
// Label: CPlayerHero::UpdateAdultTarzanSwinging
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::UpdateAdultTarzanSwinging(void)

{
  undefined2 value2;
  int value;
  
  value2 = g_PlayerActionState;
  if (g_CurrentSwingEntity == 0) {
    if ((_g_PlayerSequenceFlags & 0xf000) != 0) goto LAB_0046dffb;
    if (g_PlayerCurrentCollisionSurface != 0) {
      if ((g_PlayerInputHeldMask & 0x200000) != 0) {
        g_PlayerActionState = 7;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
        return;
      }
      if (((g_PlayerInputHeldMask & g_CameraFollowFlags) != 0) &&
         ((*(byte *)(g_PlayerCurrentCollisionSurface + 0x14) & 0x10) != 0)) {
        g_PlayerActionState = 0x1c;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterSwingToClimbableSurfaceHandlerPtr)();
        return;
      }
    }
  }
  else {
    if ((_g_PlayerSequenceFlags & 0xf000) == 0) {
      if (((g_PlayerInputHeldMask & 0x10) != 0) && (2 < g_CurrentSwingSegmentIndex)) {
        g_PlayerActionState = 0x18;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterSwingMoveToPreviousSegmentHandlerPtr)();
LAB_0046df6d:
        *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
        *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
        return;
      }
      if (((g_PlayerInputHeldMask & 0x40) != 0) &&
         (g_CurrentSwingSegmentIndex < g_MaxSwingSegmentIndex)) {
        g_PlayerActionState = 0x1a;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterSwingMoveToNextSegmentHandlerPtr)();
        goto LAB_0046df6d;
      }
      if ((g_PlayerInputPressedMask & 0x200000) != 0) {
        g_PlayerActionState = 0x1b;
        g_PreviousPlayerActionState = value2;
        (*(code *)g_AdultTarzanEnterSwingReleaseHandlerPtr)();
        goto LAB_0046df6d;
      }
    }
    if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
       ((g_PlayerInputPressedMask & g_CameraFollowFlags) != 0)) {
      g_PlayerActionState = 0x1e;
      g_PreviousPlayerActionState = value2;
      (*(code *)g_AdultTarzanEnterSwingPumpHandlerPtr)();
      *(undefined2 *)(g_PlayerEntitySceneObject + 0x78) = 0;
      *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
      return;
    }
    UpdatePlayerOnSwing(g_CurrentSwingEntity);
  }
  if (((_g_PlayerSequenceFlags & 0xf000) == 0) &&
     ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0)) {
    *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
  }
LAB_0046dffb:
  value = CPlayerHero::AdvanceAnimationScript();
  if ((0x3e < value) && (value < 0x41)) {
    if (*(byte *)(g_PlayerEntitySceneObject + 0x75) != g_PlayerFacingBeforeSwing) {
      *(byte *)(g_PlayerEntitySceneObject + 0x75) = ~*(byte *)(g_PlayerEntitySceneObject + 0x75);
      *(ushort *)(g_PlayerEntitySceneObject + 0xa2) =
           *(ushort *)(g_PlayerEntitySceneObject + 0xa2) ^ 0x800;
    }
    CPlayerHero::PlayAdultTarzanAnimation(value);
  }
  CPlayerHero::UpdateMovementAndCollision(0);
  return;
}

