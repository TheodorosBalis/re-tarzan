#include "tarzan_ghidra_types.hpp"

// Address: 0x00469D40
// Label: CPlayerHero::EnterAdultTarzanStopForwardMovement
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanStopForwardMovement(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  if (*(int *)(g_PlayerMotionState + 0x10) < 0x40) {
    g_PlayerActionState = 0;
    g_PreviousPlayerActionState = value;
    (*(code *)g_AdultTarzanActionStateEnterColumn)();
  }
  else {
    CPlayerHero::PlayAdultTarzanAnimation(9);
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  return;
}

