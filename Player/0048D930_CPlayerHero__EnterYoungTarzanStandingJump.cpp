#include "tarzan_ghidra_types.hpp"

// Address: 0x0048D930
// Label: CPlayerHero::EnterYoungTarzanStandingJump
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterYoungTarzanStandingJump(void)

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
                    /* WARNING: Could not recover jumptable at 0x0048d992. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)g_YoungEnterTarzanMovingJumpHandlerPtr)();
      return;
    }
    value2 = 0xe;
  }
  CPlayerHero::PlayAnimation(value2);
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x4e;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 5;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 4;
  g_PlayerTargetMoveSpeed = 0x20;
  return;
}

