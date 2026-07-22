#include "tarzan_ghidra_types.hpp"

// Address: 0x00469840
// Label: CPlayerHero::EnterAdultTarzanMoveForward
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanMoveForward(void)

{
  switch(g_PreviousPlayerActionState) {
  case 2:
  case 3:
    CPlayerHero::PlayAdultTarzanAnimation(2);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
    break;
  default:
    CPlayerHero::PlayAdultTarzanAnimation(1);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    break;
  case 9:
    CPlayerHero::PlayAdultTarzanAnimation(3);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
    break;
  case 0x21:
    CPlayerHero::PlayAdultTarzanAnimation(0x70);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  return;
}

