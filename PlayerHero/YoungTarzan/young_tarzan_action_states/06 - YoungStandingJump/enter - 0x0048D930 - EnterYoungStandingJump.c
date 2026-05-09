/*
State 0x06 Enter: CPlayerHero::EnterYoungTarzanStandingJump
Address: 0x0048D930
*/


void CPlayerHero__EnterYoungTarzanStandingJump(void)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  uVar1 = g_PlayerActionState;
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  if (g_PreviousPlayerActionState == 0) {
    uVar2 = 0xd;
  }
  else {
    if ((g_PreviousPlayerActionState == 3) &&
       (((g_CameraFollowFlags | g_CameraRelativeTurnInputMask) & g_PlayerInputHeldMask) != 0)) {
      g_PlayerActionState = 5;
      g_PreviousPlayerActionState = uVar1;
      /* table enter state 0x05 -> CPlayerHero::EnterYoungTarzanMovingJump */
  CPlayerHero__EnterYoungTarzanMovingJump();
      return;
    }
    uVar2 = 0xe;
  }
  CPlayerHero__PlayAnimation(uVar2);
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


