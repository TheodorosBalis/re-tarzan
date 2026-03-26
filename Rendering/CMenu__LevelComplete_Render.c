// Address: 0x0045EA00

void CMenu__LevelComplete_Render(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  DAT_0051c4dc = 900;
  ReleaseMenuTextBlockIfUnused(0x4ed35c,0xffffffff);
  ReleaseMenuTextBlockIfUnused(0x4ed37c,0xffffffff);
  puVar1 = &g_LevelCompleteScoreSceneEntries;
  iVar2 = 0x14;
  do {
    RenderMenuSceneHierarchy(puVar1);
    puVar1 = puVar1 + 0x144;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  CMenu__LevelComplete_UpdateRewardBurstSystem(&g_LevelCompleteRewardBurstSystem);
  uStack_8 = 0;
  uStack_4 = 0xfffffff8;
  if (g_LevelCompleteInputMode == 0) {
    uVar3 = 1;
  }
  else {
    uVar3 = 2;
  }
  RenderMenuUiBlockEntry
            (&g_LevelCompleteTextAnchor,&uStack_8,uVar3,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,
             0);
  RenderMenuUiBlockEntry
            (&g_LevelCompleteTextAnchor,&uStack_8,0,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  ReleaseMenuTextBlockIfUnused(&g_LevelCompleteTextAnchor,2);
  ReleaseMenuTextBlockIfUnused(0x4ed37c,2);
  return;
}


