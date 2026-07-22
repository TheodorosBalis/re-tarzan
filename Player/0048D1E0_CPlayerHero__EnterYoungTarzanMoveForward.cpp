#include "tarzan_ghidra_types.hpp"

// Address: 0x0048D1E0
// Label: CPlayerHero::EnterYoungTarzanMoveForward
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungTarzanMoveForward(void)

{
  switch(g_PreviousPlayerActionState) {
  case 2:
  case 3:
    CPlayerHero::PlayAnimation(2);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x18;
    break;
  default:
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    CPlayerHero::PlayAnimation(1);
    break;
  case 9:
    CPlayerHero::PlayAnimation(3);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x18;
    break;
  case 0x22:
    CPlayerHero::PlayAnimation(0x74);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 3;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 3;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  return;
}

