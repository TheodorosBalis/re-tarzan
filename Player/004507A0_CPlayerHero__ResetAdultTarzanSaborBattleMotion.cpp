#include "tarzan_ghidra_types.hpp"

// Address: 0x004507A0
// Label: CPlayerHero::ResetAdultTarzanSaborBattleMotion
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::ResetAdultTarzanSaborBattleMotion(void)

{
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  return;
}

