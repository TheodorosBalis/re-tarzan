#include "tarzan_ghidra_types.hpp"

// Address: 0x00478110
// Label: CPlayerHero::EnterTerkStandingJump
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CPlayerHero::EnterTerkStandingJump(void)

{
  undefined2 value;
  
  value = g_PlayerActionState;
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  if (g_PreviousPlayerActionState == 0) {
    g_PlayerCurrentAnimationId = 0xd;
    *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkStandingJumpAnimationScript;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  }
  else {
    if (g_PreviousPlayerActionState == 3) {
      if (((g_CameraFollowFlags | g_CameraRelativeTurnInputMask) & g_PlayerInputHeldMask) != 0) {
        g_PlayerActionState = 5;
        g_PreviousPlayerActionState = value;
                    /* WARNING: Could not recover jumptable at 0x0047818e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*g_TerkEnterMovingJumpHandlerPtr)();
        return;
      }
      g_PlayerCurrentAnimationId = 0xd;
      *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkStandingJumpAnimationScript;
    }
    else {
      g_PlayerCurrentAnimationId = 0xd;
      *(undefined **)(g_PlayerAnimationState + 0xc) = g_TerkStandingJumpAnimationScript;
    }
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  }
  CPlayerHero::AdvanceAnimationScript();
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0xff;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x68;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 7;
  *(undefined4 *)(g_PlayerMotionState + 0x28) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 8;
  g_PlayerTargetMoveSpeed = 0x40;
  return;
}

