/*
State 0x19 Update: CPlayerHero::UpdateYoungSwingMoveToPreviousSegment
Address: 0x004922E0
Source: C:\Users\Proxi\TarzanREVERSEDCodex\ghidra_export\young_state_forced_all_decomp\004922E0_CPlayerHero__UpdateYoungSwingMoveToPreviousSegment.c
*/


void CPlayerHero__UpdateYoungSwingMoveToPreviousSegment(void)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((g_CameraRelativeTurnInputMask & g_PlayerInputPressedMask) != 0) {
    *(byte *)(g_PlayerSceneEntry + 0x75) = ~*(byte *)(g_PlayerSceneEntry + 0x75);
  }
  uVar2 = g_PlayerActionState;
  if ((g_PlayerInputHeldMask & 0x200000) != 0) {
    g_PlayerActionState = 0x1c;
    g_PreviousPlayerActionState = uVar2;
    /* table enter state 0x1C -> CPlayerHero::EnterYoungSwingRelease */
  CPlayerHero__EnterYoungSwingRelease();
    return;
  }
  if ((g_CurrentSwingRuntimeEntry != 0) &&
     (iVar1 = *(int *)(g_CurrentSwingRuntimeEntry + 0x38), iVar1 != 0)) {
    CPlayerHero__UpdateMovementAndCollision(1);
    iVar3 = CPlayerHero__AdvanceAnimationScript();
    if (iVar3 == 8) {
      DAT_0051ce80 = DAT_0051ce80 + 1;
      g_CurrentSwingSegmentIndex = g_CurrentSwingSegmentIndex + -1;
      if (g_CurrentSwingSegmentIndex < 3) {
        g_CurrentSwingSegmentIndex = 2;
        if (DAT_0051ce40 == '\0') {
          uVar4 = 0x45;
        }
        else {
          uVar4 = 0x44;
        }
        CPlayerHero__PlayAnimation(uVar4);
      }
      if ((g_PlayerInputHeldMask & 0x10) == 0) {
        if (DAT_0051ce40 == '\0') {
          uVar4 = 0x45;
        }
        else {
          uVar4 = 0x44;
        }
        CPlayerHero__PlayAnimation(uVar4);
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
    uVar2 = g_PlayerActionState;
    if (*(int *)(iVar1 + 0x98) < *(int *)(g_PlayerSceneEntryData + 0xc)) {
      g_PlayerActionState = 7;
      g_PreviousPlayerActionState = uVar2;
      /* table enter state 0x07 -> CPlayerHero::EnterYoungTarzanFalling */
  CPlayerHero__EnterYoungTarzanFalling();
    }
  }
  return;
}


