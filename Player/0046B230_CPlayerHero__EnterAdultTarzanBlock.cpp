#include "tarzan_ghidra_types.hpp"

// Address: 0x0046B230
// Label: CPlayerHero::EnterAdultTarzanBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanBlock(void)

{
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  CPlayerHero::PlayAdultTarzanAnimation(0x1b);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  return;
}

