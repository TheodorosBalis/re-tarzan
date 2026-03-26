// Address: 0x0043FA20

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu__SelectMovie_Render(undefined4 param_1)

{
  int iVar1;
  
  ReleaseMenuTextBlockIfUnused(0x50df3c,0);
  ReleaseMenuTextBlockIfUnused(0x4ef1a4,0);
  if ((-1 < _g_SelectMovieState) && (_g_SelectMovieState < 3)) {
    iVar1 = _g_SelectedMovieIndex * 0x1c;
    if ((*(int *)(&g_SelectMovieEntryRequiredFlagIndex + iVar1) == -1) ||
       (((DAT_00534010 & 0x10000) != 0 ||
        (((&g_SelectMovieEntryRequiredFlagMask)[iVar1] &
         *(byte *)((int)&DAT_00534030 + *(int *)(&g_SelectMovieEntryRequiredFlagIndex + iVar1))) !=
         0)))) {
      _DAT_0053132c = *(undefined2 *)(iVar1 + 0x4ef1e8);
    }
    else {
      _DAT_0053132c = *(undefined2 *)(iVar1 + 0x4ef1e4);
    }
    RenderMenuSceneHierarchy(0x531320);
    DAT_0051c4dc = 0x280;
    RenderMenuSceneHierarchy(&g_JaneMenuScene);
    RenderMenuUiBlockEntry(0x4ef1a4,&DAT_00533bd8,3,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
    RenderMenuUiBlockEntry(0x4ef1a4,&DAT_00533bd8,1,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
    RenderMenuUiBlockEntry
              (0x50df3c,&DAT_00533bd8,*(undefined4 *)(iVar1 + 0x4ef1f4),
               *(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
    if (*(int *)(iVar1 + 0x4ef1f8) != -1) {
      RenderMenuUiBlockEntry
                (0x50df3c,&DAT_00533bd8,*(int *)(iVar1 + 0x4ef1f8),
                 *(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
    }
    RenderMenuFontBlockAndChildText(param_1);
  }
  return;
}


