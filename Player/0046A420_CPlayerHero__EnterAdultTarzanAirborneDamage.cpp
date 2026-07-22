#include "tarzan_ghidra_types.hpp"

// Address: 0x0046A420
// Label: CPlayerHero::EnterAdultTarzanAirborneDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanAirborneDamage(void)

{
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  CPlayerHero::PlayAdultTarzanAnimation(0x10);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x70;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 8;
  g_PlayerTargetMoveSpeed = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x6c;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  return;
}

