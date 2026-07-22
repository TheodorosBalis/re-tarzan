#include "tarzan_ghidra_types.hpp"

// Address: 0x004913D0
// Label: CPlayerHero::EnterYoungTreeSurfingRebound
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterYoungTreeSurfingRebound(void)

{
  undefined4 value;
  
  if (g_PlayerCurrentAnimationId == 0x2e) {
    value = 0x25;
  }
  else if (g_PlayerCurrentAnimationId == 0x31) {
    value = 0x26;
  }
  else if (g_PlayerCurrentAnimationId == 0x34) {
    value = 0x27;
  }
  else {
    value = 0x24;
  }
  CPlayerHero::PlayAnimation(value);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0xe;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 0xf;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = g_PlayerSurfaceMotionSpeed;
  _g_TreeSurfingReboundTimer = 0;
  g_PlayerTargetMoveSpeed = *(undefined4 *)(g_PlayerMotionState + 0x10);
  return;
}

