/*
State 0x0E Enter: CPlayerHero::EnterTerkSoftGroundDamage
Address: 0x00479F40
*/


void CPlayerHero__EnterTerkSoftGroundDamage(void)

{
  g_PlayerCurrentAnimationId = 0x1d;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c2b4;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  return;
}


