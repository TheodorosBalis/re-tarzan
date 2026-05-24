/*
State 0x0A Enter: CPlayerHero::EnterTerkFalling
Address: 0x00478670
*/


void CPlayerHero__EnterTerkFalling(void)

{
  int iVar1;
  
  iVar1 = g_PlayerSceneEntry;
  if (*(int *)(g_PlayerSceneEntry + 0x60) != 0) {
    *(undefined4 *)(*(int *)(g_PlayerSceneEntry + 0x60) + 0x60) = 0;
  }
  *(undefined4 *)(iVar1 + 0x60) = 0;
  if ((g_PlayerInputPressedMask & 0x200000) != 0) {
    g_InputPreviousMask = g_InputPreviousMask & 0xffdfffff;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x80;
  g_PlayerTargetMoveSpeed = 0x80;
  *(undefined4 *)(g_PlayerMotionState + 0x18) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 8;
  *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0xf0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 8;
  *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
  switch(g_PreviousPlayerActionState) {
  case 5:
    g_PlayerCurrentAnimationId = 0x14;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c290;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    g_CurrentSwingRuntimeEntry = 0;
    g_PlayerActionState = 0xb;
    return;
  case 6:
  case 0x1c:
    g_PlayerCurrentAnimationId = 0x13;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c28c;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
    g_CurrentSwingRuntimeEntry = 0;
    return;
  case 7:
    goto code_r0x004787d7;
  default:
    g_PlayerCurrentAnimationId = 0x11;
    *(undefined **)(g_PlayerAnimationState + 0xc) = PTR_DAT_0050c284;
    *(undefined2 *)(g_PlayerAnimationState + 0x14) = 0xffff;
    *(undefined2 *)(g_PlayerAnimationState + 0x16) = 0xffff;
    CPlayerHero__AdvanceAnimationScript();
code_r0x004787d7:
    g_CurrentSwingRuntimeEntry = 0;
    return;
  case 0x1d:
    g_CurrentSwingRuntimeEntry = 0;
    g_PlayerActionState = 0x1e;
    return;
  }
}


