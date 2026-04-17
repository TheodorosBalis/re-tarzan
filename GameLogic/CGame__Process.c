// Address: 0x0049B1E0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CGame__Process(void)

{
  int iVar1;
  undefined4 uVar2;
  
  _GameProcessCounter = _GameProcessCounter + 1;
  DoNothing1();
  DrawGraphicsTexIfNeeded();
  ProcessPauseOrOptionsMenus();
  UpdateAudioInGameOrOptions();
  UpdateBackgroundMusic();
  DoNothing2();
  ProcessPendingChunkStream();
  iVar1 = IsGamePaused();
  if (iVar1 != 0) {
LAB_0049b277:
    if (bShouldNotProcessMore != 0) {
      return;
    }
    if (bIsOnGameIntro != 0) {
      bIsOnGameIntro = 0;
      ProcessGameIntro();
    }
    iVar1 = IsGamePaused();
    if ((iVar1 == 0) || (bIsOnTransition != 0)) {
      UpdateGameLoopFlag(1);
      ProcessWorldOrMenu();
      UpdateGameLoopFlag(0);
      if (bIsOnTransition != 0) {
        bIsOnTransition = 0;
        return;
      }
    }
    if (bIsFrameRendered == 0) {
      RenderWorldOrMenu();
    }
    bIsOnTransition = 0;
    return;
  }
  bShouldNotProcessMore = iVar1;
  if (bLastTimeCrashed == 0) {
    if ((bGameInitSuccess == 0) && (bCDErrorSet == 0)) {
      SetOptionsMenu(9);
      bShouldNotProcessMore = 1;
      bCDErrorSet = 1;
      return;
    }
    iVar1 = VerifyGraphicsMode();
    if ((iVar1 != 0) || (IsDisplayOptionSupported != 0)) goto LAB_0049b277;
    uVar2 = 10;
  }
  else {
    uVar2 = 0xb;
  }
  SetOptionsMenu(uVar2);
  bShouldNotProcessMore = 1;
  return;
}


