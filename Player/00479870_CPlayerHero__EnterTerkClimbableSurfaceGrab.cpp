#include "tarzan_ghidra_types.hpp"

// Address: 0x00479870
// Label: CPlayerHero::EnterTerkClimbableSurfaceGrab
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkClimbableSurfaceGrab(void)

{
  undefined2 value;
  char resultFlag;
  
  g_PlayerCurrentAnimationId = 0x2f;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkClimbableSurfaceGrabAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  g_PlayerLatchedInteractionCollisionSurface = g_PlayerInteractionCollisionSurface;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  g_PlayerSwingTransitionStep = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
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

