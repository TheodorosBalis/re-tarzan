// Address: 0x0047ECE0

void LoadGameLevel(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0x0;
  if (-1 < g_SelectedLevelIndex) {
    iVar1 = (int)g_SelectedLevelIndex;
    g_LevelTransitionContext._2_1_ = *(undefined1 *)(&g_LevelTransitionEntries + iVar1 * 0xf);
    puVar2 = &g_LevelTransitionEntries + iVar1 * 0xf;
    DAT_0053402c = -(uint)((&DAT_004f266c)[iVar1 * 0xf] != 0xffffffff) &
                   (&DAT_004f266c)[iVar1 * 0xf];
  }
  g_LoadTransitionFlags._0_2_ = 0;
  LoadFonts(&PTR_DAT_0050df58,&DAT_00c46024);
  GetUserInputsAndZeroGlobals();
  SetActiveMenuContext(&g_MenuSceneContext);
  if (puVar2 != (undefined4 *)0x0) {
    if (g_PendingTransitionPayload == 0) {
      ProcessMovieClipOrLogo(puVar2[3],10000,0,0x1000);
    }
    if (puVar2[2] != -1) {
      SetActiveMenuContext(&g_MenuSceneContext);
      ProcessLevelLogo((&PTR_DAT_004f2c80)[puVar2[2] & 0xffff3fff]);
    }
  }
  TransitionToWorldOrMenu(1);
  return;
}


