// Address: 0x0043F7E0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu__SelectMovie_ProcessInput(void)

{
  if ((MenuKeyPressed & MenuKeyJustReleased & 0x1000) != 0) {
    LoadSoundFileAndInitAudio(0xaa,0,0);
    _g_SelectMovieState = 2;
    InitiateFade(2,0x80);
  }
  if ((MenuKeyPressed & MenuKeyJustReleased & 0x80) != 0) {
    LoadSoundFileAndInitAudio(0xab,0,0);
    if ((int)_g_SelectedMovieIndex < 1) {
      _g_SelectedMovieIndex = 0x12;
    }
    else {
      _g_SelectedMovieIndex = _g_SelectedMovieIndex - 1;
    }
  }
  if ((MenuKeyPressed & MenuKeyJustReleased & 0x20) != 0) {
    LoadSoundFileAndInitAudio(0xab,0,0);
    if (_g_SelectedMovieIndex < 0x12) {
      _g_SelectedMovieIndex = _g_SelectedMovieIndex + 1;
    }
    else {
      _g_SelectedMovieIndex = 0;
    }
  }
  if ((MenuKeyPressed & MenuKeyJustReleased & 0x4000) != 0) {
    if (((*(int *)(&g_SelectMovieEntryRequiredFlagIndex + _g_SelectedMovieIndex * 0x1c) != -1) &&
        ((DAT_00534010 & 0x10000) == 0)) &&
       (((&g_SelectMovieEntryRequiredFlagMask)[_g_SelectedMovieIndex * 0x1c] &
        *(byte *)((int)&DAT_00534030 +
                 *(int *)(&g_SelectMovieEntryRequiredFlagIndex + _g_SelectedMovieIndex * 0x1c))) ==
        0)) {
      LoadSoundFileAndInitAudio(0xaa,0,0);
      return;
    }
    LoadSoundFileAndInitAudio(0xac,0,0);
    _g_SelectMovieState = 1;
    InitiateFade(2,0x100);
    InitCinematic_stub(&DAT_00c46070);
  }
  return;
}


