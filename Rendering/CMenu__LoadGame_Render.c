// Address: 0x004390A0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu__LoadGame_Render(void)

{
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = 0;
  uStack_4 = 0;
  RenderMenuUiBlockEntry
            (0x4ed37c,&uStack_8,(_g_LoadGameMenuEntryFlag != 0) + '\b',
             *(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  RenderMenuUiBlockEntry(0x4ed37c,&uStack_8,0x1b,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  RenderMenuUiBlockEntry(0x4ed35c,&uStack_8,0,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  func_0x00439030();
  RenderMenuSceneHierarchy(&g_JaneMenuScene);
  ReleaseMenuTextBlockIfUnused(0x4ed37c,2);
  ReleaseMenuTextBlockIfUnused(0x4ed35c,2);
  if (-1 < g_SelectedLevelIndex) {
    ReleaseMenuTextBlockIfUnused(&g_LevelCompleteTextAnchor,2);
  }
  RenderLoadGameSelectedLevelPreview();
  return;
}


