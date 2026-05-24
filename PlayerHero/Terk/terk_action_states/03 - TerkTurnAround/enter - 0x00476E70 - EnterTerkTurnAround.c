/*
State 0x03 Enter: CPlayerHero::EnterTerkTurnAround
Address: 0x00476E70
*/


void CPlayerHero__EnterTerkTurnAround(void)

{
  undefined *puVar1;
  
  switch(g_PreviousPlayerActionState) {
  case 1:
    g_PlayerCurrentAnimationId = 0xb;
    puVar1 = puRam0050c26c;
    break;
  default:
    g_PlayerCurrentAnimationId = 9;
    puVar1 = PTR_DAT_0050c264;
    break;
  case 0xd:
  case 0x11:
  case 0x12:
    g_PlayerCurrentAnimationId = 10;
    *(undefined4 *)(g_PlayerAnimationState + 0xc) = uRam0050c268;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
    return;
  }
  *(undefined **)(g_PlayerAnimationState + 0xc) = puVar1;
  *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
  *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
  CPlayerHero__AdvanceAnimationScript();
  *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
  return;
}


