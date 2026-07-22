#include "tarzan_ghidra_types.hpp"

// Address: 0x0048DB30
// Label: CPlayerHero::EnterYoungApplyDamageOnJumping
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungApplyDamageOnJumping(void)

{
  CPlayerHero::PlayAnimation(0x10);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 7;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 4;
  g_PlayerTargetMoveSpeed = 0x20;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x4e;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  return;
}

