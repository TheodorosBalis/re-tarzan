/*
State 0x02 Enter: CPlayerHero::EnterYoungTarzanStopForwardMovement
Address: 0x0048D5E0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\0048D5E0_CPlayerHero__EnterYoungTarzanStopForwardMovement.c
*/


void CPlayerHero__EnterYoungTarzanStopForwardMovement(void)

{
  undefined2 uVar1;
  
  uVar1 = g_PlayerActionState;
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  if ((g_PlayerInputPressedMask & g_CameraRelativeTurnInputMask) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & ~(uint)g_CameraRelativeTurnInputMask;
  }
  if (*(int *)(g_PlayerMotionState + 0x10) < 0x20) {
    g_PlayerActionState = 0;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x00 -> CPlayerHero::EnterYoungTarzanIdle */
  CPlayerHero__EnterYoungTarzanIdle();
  }
  else {
    CPlayerHero__PlayAnimation(9);
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  return;
}


