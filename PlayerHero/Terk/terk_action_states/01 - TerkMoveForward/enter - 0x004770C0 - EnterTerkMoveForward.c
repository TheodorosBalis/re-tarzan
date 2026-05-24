/*
State 0x01 Enter: CPlayerHero::EnterTerkMoveForward
Address: 0x004770C0
*/


void CPlayerHero__EnterTerkMoveForward(void)

{
  undefined *puVar1;
  
  if ((g_PreviousPlayerActionState < 2) ||
     ((3 < g_PreviousPlayerActionState && (g_PreviousPlayerActionState != 0xe)))) {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
    g_PlayerCurrentAnimationId = 1;
    puVar1 = PTR_DAT_0050c244;
  }
  else {
    *(undefined4 *)(g_PlayerMotionState + 0x10) = 0x30;
    g_PlayerCurrentAnimationId = 2;
    puVar1 = PTR_DAT_0050c248;
  }
  *(undefined **)(g_PlayerAnimationState + 0xc) = puVar1;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x40;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 6;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0;
  return;
}


