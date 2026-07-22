#include "tarzan_ghidra_types.hpp"

// Address: 0x0046CA00
// Label: CPlayerHero::EnterAdultTarzanClimbableWallGrab
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanClimbableWallGrab(void)

{
  g_PlayerLatchedInteractionCollisionSurface = g_PlayerInteractionCollisionSurface;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  g_PlayerSwingTransitionStep = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  CPlayerHero::PlayAdultTarzanAnimation(0x71);
  CPlayerHero::AdvanceAnimationScript();
  g_PlayerTiltControlEnabled = 0;
  return;
}

