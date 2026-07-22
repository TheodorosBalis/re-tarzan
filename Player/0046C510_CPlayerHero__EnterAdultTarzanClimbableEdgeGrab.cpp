#include "tarzan_ghidra_types.hpp"

// Address: 0x0046C510
// Label: CPlayerHero::EnterAdultTarzanClimbableEdgeGrab
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanClimbableEdgeGrab(void)

{
  undefined2 value;
  char resultFlag;
  
  CPlayerHero::PlayAdultTarzanAnimation(0x66);
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
    g_PlayerActionState = 7;
    g_PreviousPlayerActionState = value;
    (*(code *)g_AdultTarzanEnterFallOrKnockbackHandlerPtr)();
  }
  CPlayerHero::AdvanceAnimationScript();
  return;
}

