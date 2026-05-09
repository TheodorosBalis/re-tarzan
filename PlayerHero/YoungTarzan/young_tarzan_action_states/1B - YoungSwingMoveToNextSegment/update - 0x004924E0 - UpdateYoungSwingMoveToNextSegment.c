/*
State 0x1B Update: CPlayerHero::UpdateYoungSwingMoveToNextSegment
Address: 0x004924E0
*/


void CPlayerHero__UpdateYoungSwingMoveToNextSegment(void)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
  }
  uVar1 = g_PlayerActionState;
  if ((g_PlayerInputHeldMask & 0x200000) != 0) {
    g_PlayerActionState = 0x1c;
    g_PreviousPlayerActionState = uVar1;
    /* table enter state 0x1C -> CPlayerHero::EnterYoungSwingRelease */
    CPlayerHero__EnterYoungSwingRelease();
    return;
  }
  if (g_CurrentSwingRuntimeEntry != 0) {
    iVar2 = FindRuntimeEntityAttachmentByFlags(g_CurrentSwingRuntimeEntry,0x8000000);
    if (iVar2 != 0) {
      CPlayerHero_UpdateMovementAndCollision(1);
      iVar2 = CPlayerHero_AdvanceAnimationScript();
      if (iVar2 == 8) {
        DAT_0051ce80 = DAT_0051ce80 + 1;
        g_CurrentSwingSegmentIndex = g_CurrentSwingSegmentIndex + 1;
        if (0xc < g_CurrentSwingSegmentIndex) {
          g_CurrentSwingSegmentIndex = 0xd;
          if (DAT_0051ce40 == '\0') {
            uVar3 = 0x4b;
          }
          else {
            uVar3 = 0x4a;
          }
          CPlayerHero_PlayAnimation(uVar3);
        }
        if ((g_PlayerInputHeldMask & 0x40) == 0) {
          if (DAT_0051ce40 == '\0') {
            uVar3 = 0x4b;
          }
          else {
            uVar3 = 0x4a;
          }
          CPlayerHero_PlayAnimation(uVar3);
        }
      }
      UpdatePlayerOnSwing(g_CurrentSwingRuntimeEntry);
      *(int *)(g_PlayerMotionState + 0x20) =
           *(int *)(g_PlayerMotionState + 0x20) + *(int *)(g_PlayerMotionState + 0x24);
      if (*(int *)(g_PlayerMotionState + 0x2c) < *(int *)(g_PlayerMotionState + 0x20)) {
        *(int *)(g_PlayerMotionState + 0x20) = *(int *)(g_PlayerMotionState + 0x2c);
      }
      *(int *)(g_PlayerSceneEntryData + 0xc) =
           *(int *)(g_PlayerSceneEntryData + 0xc) + *(int *)(g_PlayerMotionState + 0x20);
    }
  }
  return;
}

