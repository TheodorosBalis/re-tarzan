/* Address: 0x0043F930 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::SelectMovie(void)

{
  int iVar1;
  
  if (_g_SelectMovieState == 0) {
    if (((ram0x00534026 & 0x8000) == 0) || (FadeBrightness == 0)) {
      CMenu::SelectMovie_ProcessInput();
    }
  }
  else if (_g_SelectMovieState == 1) {
    if ((FadeBrightness == 0) && (3 < FadeStatus)) {
      LoadAndHandleECM(*(uint *)(&g_SelectMovieEntryTable + _g_SelectedMovieIndex * 0x1c) &
                       0xffff3fff,0);
      SetActiveMenuContext(&g_MenuSceneContext);
      _g_SelectMovieState = 0;
      InitiateFade(1,0x100);
      SelectECMfileAndInitAudio(0);
    }
  }
  else if (((_g_SelectMovieState == 2) && (FadeBrightness == 0)) && (3 < FadeStatus)) {
    CMenu::SelectMovie_ReleaseResources();
    ShowLoadGameIcons();
    InitSharedMenuIconSets();
    ShowMenuGraphicBlock(&PTR_DAT_004ed378);
    _g_SelectMovieState = 3;
    RequestMenuTransitionWithFade(&g_MenuDescriptor_SelectMovie);
  }
  DAT_0051c4dc = 0x280;
  AdvanceMenuIdleScriptCursor(&DAT_0051d0f8,&DAT_0051cfb0);
  iVar1 = RandomModulo(0x15e);
  if (iVar1 == 0) {
    iVar1 = RandomModulo(8);
    SetMenuIdleScriptOverride(&DAT_0051d0f8,(&PTR_DAT_004ed330)[iVar1]);
  }
  if (_DAT_0051d0fc == 0) {
    SetMenuIdleScriptOverride(&DAT_0051d0f8,&DAT_004ed200);
  }
  return;
}

