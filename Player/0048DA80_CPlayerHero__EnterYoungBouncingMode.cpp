#include "tarzan_ghidra_types.hpp"

// Address: 0x0048DA80
// Label: CPlayerHero::EnterYoungBouncingMode
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungBouncingMode(void)

{
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  CPlayerHero::PlayAnimation(0xf);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 7;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 4;
  g_PlayerBounceChainCount = g_PlayerBounceChainCount + 1;
  g_PlayerTargetMoveSpeed = 0x20;
  if (3 < g_PlayerBounceChainCount) {
    g_PlayerBounceChainCount = 3;
  }
  *(int *)(g_PlayerMotionState + 0x20) = g_PlayerBounceChainCount * 8 + 0x70;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  return;
}

