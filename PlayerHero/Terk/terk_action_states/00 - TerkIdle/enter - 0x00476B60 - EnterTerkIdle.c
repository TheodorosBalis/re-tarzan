/*
State 0x00 Enter: CPlayerHero::EnterTerkIdle
Address: 0x00476B60
*/


void CPlayerHero__EnterTerkIdle(void)

{
  short sVar1;
  
  g_PlayerCurrentAnimationId = 7;
  *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c25c;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  sVar1 = RandomModulo(10);
  g_PlayerIdleFidgetDelayTicks = sVar1 + 5;
  g_PlayerTiltControlEnabled = 0;
  *(undefined2 *)(g_PlayerSceneEntry + 0x142) = 0x100;
  return;
}


