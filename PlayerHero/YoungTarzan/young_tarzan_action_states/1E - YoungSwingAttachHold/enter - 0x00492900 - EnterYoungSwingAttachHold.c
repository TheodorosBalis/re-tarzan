/*
State 0x1E Enter: CPlayerHero::EnterYoungSwingAttachHold
Address: 0x00492900
*/


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CPlayerHero__EnterYoungSwingAttachHold(void)

{
  int iVar1;
  int iVar2;
  
  if (g_CurrentSwingRuntimeEntry != 0) {
    iVar1 = *(int *)(g_CurrentSwingRuntimeEntry + 0x38);
    if (iVar1 != 0) {
      *(undefined4 *)(g_PlayerSceneEntry + 0x110) = *(undefined4 *)(iVar1 + 0x110);
      *(undefined4 *)(g_PlayerSceneEntry + 0x10c) = *(undefined4 *)(iVar1 + 0x10c);
    }
    iVar1 = FindRuntimeEntityAttachmentByFlags(g_CurrentSwingRuntimeEntry,0x8000000);
    if (iVar1 != 0) {
      iVar2 = *(int *)(iVar1 + 0x20) >> 3;
      *(undefined2 *)(iVar1 + 0xe) = 2;
      if (iVar2 < *(int *)(iVar1 + 0x14)) {
        *(int *)(iVar1 + 0x14) = iVar2;
      }
    }
  }
  *(undefined2 *)(g_PlayerSceneEntry + 0x78) = 0;
  *(undefined2 *)(g_PlayerAnimationState + 0x1e) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  _DAT_0051cdd8 = 10;
  return;
}


