#include "tarzan_ghidra_types.hpp"

// Address: 0x00450AC0
// Label: CPlayerHero::EnterAdultTarzanSaborBattleJump
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanSaborBattleJump(void)

{
  CPlayerHero::PlayAdultTarzanSaborBattleAnimation(0x94);
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x6c;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x70;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 1;
  return;
}

