/*
State 0x06 Enter: CPlayerHero::EnterTerkStandingJump
Address: 0x00478110
*/


void CPlayerHero__EnterTerkStandingJump(void)

{
  undefined2 uVar1;
  
  uVar1 = g_PlayerActionState;
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  if (g_PreviousPlayerActionState == 0) {
    g_PlayerCurrentAnimationId = 0xd;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c274;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  }
  else {
    if (g_PreviousPlayerActionState == 3) {
      if (((g_CameraFollowFlags | g_CameraRelativeTurnInputMask) & g_PlayerInputHeldMask) != 0) {
        g_PlayerActionState = 5;
        g_PreviousPlayerActionState = uVar1;
                    /* WARNING: Could not recover jumptable at 0x0047818e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        (*DAT_0050c170)();
        return;
      }
      g_PlayerCurrentAnimationId = 0xd;
      *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c274;
    }
    else {
      g_PlayerCurrentAnimationId = 0xd;
      *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c274;
    }
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  }
  CPlayerHero__AdvanceAnimationScript();
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


