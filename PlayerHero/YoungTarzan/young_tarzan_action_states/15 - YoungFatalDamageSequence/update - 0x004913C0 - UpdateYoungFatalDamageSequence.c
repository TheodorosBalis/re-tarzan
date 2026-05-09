/*
State 0x15 Update: CPlayerHero::UpdateYoungFatalDamageSequence
Address: 0x004913C0
*/


void CPlayerHero__UpdateYoungFatalDamageSequence(void)

{
  int iVar1;
  
  CPlayerHero_AdvanceAnimationScript();
  if (*(char *)(g_PlayerMotionState + 0xd) == '\0') {
    *(int *)(g_PlayerMotionState + 0x20) =
         *(int *)(g_PlayerMotionState + 0x20) + *(int *)(g_PlayerMotionState + 0x24);
    if (*(int *)(g_PlayerMotionState + 0x2c) < *(int *)(g_PlayerMotionState + 0x20)) {
      *(int *)(g_PlayerMotionState + 0x20) = *(int *)(g_PlayerMotionState + 0x2c);
    }
    iVar1 = *(int *)(g_PlayerSceneEntryData + 0xc) + *(int *)(g_PlayerMotionState + 0x20);
  }
  else {
    *(int *)(g_PlayerMotionState + 0x20) =
         *(int *)(g_PlayerMotionState + 0x20) - *(int *)(g_PlayerMotionState + 0x28);
    if (*(int *)(g_PlayerMotionState + 0x20) < 1) {
      *(undefined4 *)(g_PlayerMotionState + 0x20) = 0;
      *(byte *)(g_PlayerMotionState + 0xd) = ~*(byte *)(g_PlayerMotionState + 0xd);
    }
    iVar1 = *(int *)(g_PlayerSceneEntryData + 0xc) - *(int *)(g_PlayerMotionState + 0x20);
  }
  *(int *)(g_PlayerSceneEntryData + 0xc) = iVar1;
  iVar1 = *(int *)(g_PlayerMotionState + 0x10);
  if (iVar1 < 0) {
    *(int *)(g_PlayerMotionState + 0x10) = *(int *)(g_PlayerMotionState + 0x18) + iVar1;
    if (0 < *(int *)(g_PlayerMotionState + 0x10)) {
LAB_0043610a:
      *(undefined4 *)(g_PlayerMotionState + 0x10) = 0;
    }
  }
  else {
    *(int *)(g_PlayerMotionState + 0x10) = iVar1 - *(int *)(g_PlayerMotionState + 0x18);
    if (*(int *)(g_PlayerMotionState + 0x10) < 0) goto LAB_0043610a;
  }
  iVar1 = *(int *)(g_PlayerMotionState + 0x30);
  if (iVar1 < 0) {
    *(int *)(g_PlayerMotionState + 0x30) = *(int *)(g_PlayerMotionState + 0x38) + iVar1;
    if (*(int *)(g_PlayerMotionState + 0x30) < 1) goto LAB_00436144;
  }
  else {
    *(int *)(g_PlayerMotionState + 0x30) = iVar1 - *(int *)(g_PlayerMotionState + 0x38);
    if (-1 < *(int *)(g_PlayerMotionState + 0x30)) goto LAB_00436144;
  }
  *(undefined4 *)(g_PlayerMotionState + 0x30) = 0;
LAB_00436144:
  *(int *)(g_PlayerSceneEntryData + 8) =
       *(int *)(g_PlayerSceneEntryData + 8) + *(int *)(g_PlayerMotionState + 0x10);
  *(int *)(g_PlayerSceneEntryData + 0x10) =
       *(int *)(g_PlayerSceneEntryData + 0x10) + *(int *)(g_PlayerMotionState + 0x30);
  return;
}

