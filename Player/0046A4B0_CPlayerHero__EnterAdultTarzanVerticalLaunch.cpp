#include "tarzan_ghidra_types.hpp"

// Address: 0x0046A4B0
// Label: CPlayerHero::EnterAdultTarzanVerticalLaunch
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanVerticalLaunch(void)

{
  CPlayerHero::PlayAdultTarzanAnimation(0x11);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 7;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x70;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0xc0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  return;
}

