// Address: 0x00438F50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu__LoadGame(void)

{
  CMenu__LoadGame_ProcessInput();
  if (_g_LoadGameExitPending == 0) {
    if (_g_LoadGameState == 5) {
      _g_LoadGameTimer = _g_LoadGameTimer + -1;
      if ((_g_LoadGameTimer < 1) || ((MenuKeyPressed & MenuKeyJustReleased & 0x1000) != 0)) {
        _g_LoadGameState = 0;
      }
    }
    else {
      _g_LoadGameSelectionTemp = 0xffffffff;
      if (_g_LoadGameState == 4) {
        _g_LoadGameTimer = 0x78;
        _g_LoadGameState = 5;
        return;
      }
      _g_LoadGameState = 0;
      if ((MenuKeyPressed & MenuKeyJustReleased & 0x1000) != 0) {
        CMenu__LoadGame_BeginExitTransition(0);
        return;
      }
    }
  }
  else {
    _g_LoadGameTimer = _g_LoadGameTimer + -1;
    if (_g_LoadGameTimer == 0) {
      CMenu__LoadGame_ReleaseResources();
      if ((-1 < g_SelectedLevelIndex) && ((short)g_LoadTransitionFlags == -0x7fff)) {
        RequestMenuTransitionWithFade(&g_MenuDescriptor_LevelComplete);
        return;
      }
      RequestMenuTransitionWithFade(&PTR_MainMenu_MainFont_004f1fc0);
      return;
    }
  }
  return;
}


