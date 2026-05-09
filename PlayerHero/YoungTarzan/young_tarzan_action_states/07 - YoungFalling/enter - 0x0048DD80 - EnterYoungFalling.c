/*
State 0x07 Enter: CPlayerHero::EnterYoungTarzanFalling
Address: 0x0048DD80
*/


void CPlayerHero__EnterYoungTarzanFalling(void)

{
  int iVar1;
  undefined2 uVar2;
  char cVar3;
  
  iVar1 = g_PlayerSceneEntry;
  if (*(int *)(g_PlayerSceneEntry + 0x60) != 0) {
    *(undefined4 *)(*(int *)(g_PlayerSceneEntry + 0x60) + 0x60) = 0;
  }
  *(undefined4 *)(iVar1 + 0x60) = 0;
  cVar3 = CPlayerHero_IsOnTreeSurfingSurface();
  uVar2 = g_PlayerActionState;
  if (cVar3 == '\0') {
    if (g_PreviousPlayerActionState == 0x23) {
      CPlayerHero_PlayAnimation(0x11);
      return;
    }
    *(undefined4 *)(g_PlayerMotionState + 0x1c) = 0x30;
    g_PlayerTargetMoveSpeed = 0x30;
    *(undefined4 *)(g_PlayerMotionState + 0x18) = 4;
    *(undefined4 *)(g_PlayerMotionState + 0x14) = 2;
    *(undefined4 *)(g_PlayerMotionState + 0x20) = 0x10;
    *(undefined4 *)(g_PlayerMotionState + 0x2c) = 0x60;
    *(undefined4 *)(g_PlayerMotionState + 0x24) = 4;
    *(undefined1 *)(g_PlayerMotionState + 0xd) = 0;
    if ((DAT_0051cdf0 != 0x8d) && (DAT_0051cdf0 != 0x91)) {
      switch(g_PreviousPlayerActionState) {
      case 5:
        g_CurrentSwingRuntimeEntry = 0;
        g_PlayerActionState = 8;
        return;
      case 6:
      case 0x30:
      case 0x31:
        break;
      case 0xe:
      case 0x10:
        CPlayerHero_PlayAnimation(0x28);
        g_CurrentSwingRuntimeEntry = 0;
        g_PlayerActionState = 0x11;
        return;
      case 0x18:
      case 0x1d:
        if (g_CurrentSwingRuntimeEntry == 0) {
          if (DAT_0051ce40 == '\0') {
            CPlayerHero_PlayAnimation(0x5b);
            g_CurrentSwingRuntimeEntry = 0;
            return;
          }
          CPlayerHero_PlayAnimation(0x5c);
          g_CurrentSwingRuntimeEntry = 0;
          return;
        }
      default:
        CPlayerHero_PlayAnimation(0x11);
      }
    }
    g_CurrentSwingRuntimeEntry = 0;
    return;
  }
  g_PlayerActionState = 0x24;
  g_PreviousPlayerActionState = uVar2;
  /* table enter state 0x24 -> CPlayerHero::EnterYoungDiveAnimation */
  CPlayerHero__EnterYoungDiveAnimation();
  return;
}

