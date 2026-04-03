
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu__MainMenu(undefined4 param_1)

{
  if (1000 < TimeIDLEinMenu) {
    TimeIDLEinMenu = 0;
    if (_IDLECutsceneHasPlayed == 0) {
      _IDLECutsceneHasPlayed = 1;
      ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
      InitiateFade(2,0x100);
      MenuState = 3;
      CMenu__ProcessOnInputs(param_1);
      return;
    }
    _IDLECutsceneHasPlayed = 0;
    _ClipPlaybackID = _ClipPlaybackID + 1;
    if (2 < _ClipPlaybackID) {
      _ClipPlaybackID = 0;
    }
    g_SelectedLevelIndex = FUN_0047eca0(*(undefined4 *)(_ClipPlaybackID * 0xc + 0x502d60),0);
    DAT_0053402c = *(undefined4 *)(_ClipPlaybackID * 0xc + 0x502d64);
    g_PendingTransitionPayload = *(undefined4 *)(_ClipPlaybackID * 0xc + 0x502d68);
    ResetBackgroundMusicPlaybackState(&DAT_00c46070);
    InitiateFade(2,0x100);
    MenuState = 2;
  }
  CMenu__ProcessOnInputs(param_1);
  return;
}

