#include "tarzan_ghidra_types.hpp"

// Address: 0x004797F0
// Label: CPlayerHero::UpdateTerkClimbableWallJumpOff
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::UpdateTerkClimbableWallJumpOff(void)

{
  int value;
  
  value = CPlayerHero::AdvanceAnimationScript();
  if (value == 8) {
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x80;
    g_PlayerTargetMoveSpeed = 0x80;
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x40;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 8;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
    *(undefined4 *)(g_PlayerMotionState + 0x24) = 8;
    *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  }
  CPlayerHero::UpdateJumpArcVerticalMotion(0);
  return;
}

