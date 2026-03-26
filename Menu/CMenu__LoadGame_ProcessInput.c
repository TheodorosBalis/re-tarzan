// Address: 0x00438D00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu__LoadGame_ProcessInput(void)

{
  int iVar1;
  
  if (_g_LoadGameSelectionState == 0) {
    if (((ram0x00534026 & 0x8000) == 0) || (FadeBrightness == 0)) {
      if (((MenuKeyPressed & MenuKeyJustReleased & 0x80) != 0) && (0 < (int)_CurrentSelectedLevel))
      {
        LoadSoundFileAndInitAudio(0xab,0,0);
        _CurrentSelectedLevel = _CurrentSelectedLevel - 1;
      }
      if (((MenuKeyPressed & MenuKeyJustReleased & 0x20) != 0) && (_CurrentSelectedLevel < 0xc)) {
        LoadSoundFileAndInitAudio(0xab,0,0);
        _CurrentSelectedLevel = _CurrentSelectedLevel + 1;
      }
      if ((MenuKeyPressed & MenuKeyJustReleased & 0x4000) != 0) {
        iVar1 = TestBitInWordArray(*(undefined4 *)
                                    (&g_LevelBitIndexTable + _CurrentSelectedLevel * 0xc),
                                   (int)g_LevelTransitionContext._1_1_);
        if (iVar1 != 0) {
          LoadSoundFileAndInitAudio(0xac,0,0);
          _g_LoadGameSelectionState = 1;
          InitiateFade(2,0x100);
          InitCinematic_stub(&DAT_00c46070);
          return;
        }
        LoadSoundFileAndInitAudio(0xaa,0,0);
      }
      return;
    }
  }
  else if (_g_LoadGameSelectionState == 1) {
    if ((FadeBrightness == 0) && (3 < FadeStatus)) {
      _g_LoadGameSelectionState = 0;
      SelectLevelAndStartWorldTransition
                (*(undefined4 *)(&g_LevelBitIndexTable + _CurrentSelectedLevel * 0xc),0);
      return;
    }
  }
  else if (((_g_LoadGameSelectionState == 2) && (FadeBrightness == 0)) && (3 < FadeStatus)) {
    _g_LoadGameSelectionState = 3;
    return;
  }
  return;
}


