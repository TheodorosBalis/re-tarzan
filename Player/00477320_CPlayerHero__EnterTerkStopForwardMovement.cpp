#include "tarzan_ghidra_types.hpp"

// Address: 0x00477320
// Label: CPlayerHero::EnterTerkStopForwardMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero::EnterTerkStopForwardMovement(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  g_InputPreviousMask = g_InputPreviousMask & 0xffefffff;
  if (*(int *)(g_PlayerMotionState + 0x10) < 0x40) {
    g_PlayerActionState = 0;
    g_PreviousPlayerActionState = value;
    (*(code *)g_TerkActionStateHandlerTable)();
  }
  else {
    g_PlayerCurrentAnimationId = 8;
    *(undefined4 *)(g_PlayerAnimationState + 0xc) = _g_TerkStopForwardMovementAnimationScript;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero::AdvanceAnimationScript();
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  return;
}

