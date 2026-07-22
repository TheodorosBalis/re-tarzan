#include "tarzan_ghidra_types.hpp"

// Address: 0x004783F0
// Label: CPlayerHero::EnterTerkAirborneDamage
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkAirborneDamage(void)

{
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  g_PlayerCurrentAnimationId = 0xf;
  *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkAirborneDamageAnimationScript;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero::AdvanceAnimationScript();
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 7;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 8;
  g_PlayerTargetMoveSpeed = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x68;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  return;
}

