#include "tarzan_ghidra_types.hpp"

// Address: 0x00490300
// Label: CPlayerHero::EnterYoungSwimForward
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungSwimForward(void)

{
  int value;
  
  if (g_PreviousPlayerActionState == 0x25) {
    CPlayerHero::PlayAnimation(0x7b);
  }
  else {
    CPlayerHero::PlayAnimation(0x7a);
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 4;
    value = CPlayerHero::SteerYoungAirMoveHeadingTowardInput();
    if (0x400 < value) {
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    }
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 1;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  g_PlayerTiltControlEnabled = 1;
  return;
}

