/*
State 0x17 Enter: CPlayerHero::EnterYoungGrabSwing
Address: 0x00491EA0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\00491EA0_CPlayerHero__EnterYoungGrabSwing.c
*/


void CPlayerHero__EnterYoungGrabSwing(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (g_CurrentSwingRuntimeEntry == 0) {
    uVar2 = 0x50;
  }
  else {
    iVar1 = *(int *)(g_CurrentSwingRuntimeEntry + 0x38);
    if (iVar1 != 0) {
      *(undefined4 *)(g_PlayerSceneEntry + 0x110) = *(undefined4 *)(iVar1 + 0x110);
      *(undefined4 *)(g_PlayerSceneEntry + 0x10c) = *(undefined4 *)(iVar1 + 0x10c);
    }
    iVar1 = FindRuntimeEntityAttachmentByFlags(g_CurrentSwingRuntimeEntry,0x8000000);
    if (iVar1 != 0) {
      *(undefined2 *)(iVar1 + 0xe) = 4;
      *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x20) >> 1;
    }
    uVar2 = 0x3c;
  }
  CPlayerHero__PlayAnimation(uVar2);
  *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
  g_PlayerTargetMoveSpeed = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x14) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
  *(undefined4 *)(g_PlayerMotionState + 0x24) = 0;
  DAT_0051ce80 = 0;
  CPlayerHero__AdvanceAnimationScript();
  CPlayerHero__UpdateMovementAndCollision(0);
  return;
}


