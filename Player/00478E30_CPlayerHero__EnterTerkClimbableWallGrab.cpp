#include "tarzan_ghidra_types.hpp"

// Address: 0x00478E30
// Label: CPlayerHero::EnterTerkClimbableWallGrab
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkClimbableWallGrab(void)

{
  g_PlayerLatchedInteractionCollisionSurface = g_PlayerInteractionCollisionSurface;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  g_PlayerSwingTransitionStep = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  *(int *)(g_PlayerEntitySceneObjectData + 0xc) =
       ((*(int *)(g_PlayerEntitySceneObjectData + 0xc) - g_PlayerInteractionCollisionBaseY) / 0xa0)
       * 0xa0 + g_PlayerInteractionCollisionBaseY;
  g_PlayerCurrentAnimationId = 0x23;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableWallGrabAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  g_PlayerTiltControlEnabled = 0;
  g_PlayerAnimationSurfaceSide = (-(*(char *)(g_PlayerEntitySceneObject + 0x75) != '\0') & 1U) - 1;
  return;
}

