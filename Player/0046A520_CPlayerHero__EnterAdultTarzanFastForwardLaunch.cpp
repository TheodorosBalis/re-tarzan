#include "tarzan_ghidra_types.hpp"

// Address: 0x0046A520
// Label: CPlayerHero::EnterAdultTarzanFastForwardLaunch
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanFastForwardLaunch(void)

{
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  DetachEntitySoundHandle(&g_PlayerLoopingSoundHandle);
  CPlayerHero::PlayAdultTarzanAnimation(0xf);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x70;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 8;
  g_PlayerTargetMoveSpeed = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0xd0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  return;
}

