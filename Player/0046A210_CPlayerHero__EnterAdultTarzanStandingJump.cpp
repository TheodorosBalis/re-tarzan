#include "tarzan_ghidra_types.hpp"

// Address: 0x0046A210
// Label: CPlayerHero::EnterAdultTarzanStandingJump
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterAdultTarzanStandingJump(void)

{
  undefined2 value;
  undefined4 value2;
  
  value = g_PlayerActionState;
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  if (g_PreviousPlayerActionState == 0) {
    value2 = 0xd;
  }
  else {
    if ((g_PreviousPlayerActionState == 3) &&
       (((g_CameraFollowFlags | g_CameraRelativeTurnInputMask) & g_PlayerInputHeldMask) != 0)) {
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0046a272. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_AdultTarzanEnterMovingJumpHandlerPtr)();
      return;
    }
    value2 = 0xe;
  }
  CPlayerHero::PlayAdultTarzanAnimation(value2);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x6c;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x70;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 8;
  g_PlayerTargetMoveSpeed = 0x40;
  return;
}

