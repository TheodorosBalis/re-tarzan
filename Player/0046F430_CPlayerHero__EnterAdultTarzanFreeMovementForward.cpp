#include "tarzan_ghidra_types.hpp"

// Address: 0x0046F430
// Label: CPlayerHero::EnterAdultTarzanFreeMovementForward
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanFreeMovementForward(void)

{
  if (1 < g_PreviousPlayerActionState) {
    if (g_PreviousPlayerActionState < 4) {
      CPlayerHero::PlayAdultTarzanAnimation(2);
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
      goto LAB_0046f48f;
    }
    if (g_PreviousPlayerActionState == 9) {
      CPlayerHero::PlayAdultTarzanAnimation(3);
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
      goto LAB_0046f48f;
    }
  }
  CPlayerHero::PlayAdultTarzanAnimation(1);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
LAB_0046f48f:
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  return;
}

