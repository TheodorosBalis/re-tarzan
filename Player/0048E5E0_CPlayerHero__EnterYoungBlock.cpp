#include "tarzan_ghidra_types.hpp"

// Address: 0x0048E5E0
// Label: CPlayerHero::EnterYoungBlock
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungBlock(void)

{
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  CPlayerHero::PlayAnimation(0x1a);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  return;
}

