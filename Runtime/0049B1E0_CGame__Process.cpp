#include "tarzan_ghidra_types.hpp"

// Address: 0x0049B1E0
// Label: CGame::Process
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CGame::Process(void)

{
  int value;
  undefined4 value2;
  
  _GameProcessCounter = _GameProcessCounter + 1;
  DoNothing1();
  DrawHardwareInfoOverlayAtStartup();
  ProcessPauseOrOptionsMenus();
  ManageAudioStream();
  UpdateBackgroundMusic();
  DoNothing2();
  ProcessPendingChunkStream();
  value = IsGamePaused();
  if (value != 0) {
LAB_0049b277:
    if (bShouldNotProcessMore != 0) {
      return;
    }
    if (bIsOnGameIntro != 0) {
      bIsOnGameIntro = 0;
      ProcessGameIntro();
    }
    value = IsGamePaused();
    if ((value == 0) || (bIsOnTransition != 0)) {
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
  bShouldNotProcessMore = value;
  if (bLastTimeCrashed == 0) {
    if ((bGameInitSuccess == 0) && (bCDErrorSet == 0)) {
      SetOptionsMenu(9);
      bShouldNotProcessMore = 1;
      bCDErrorSet = 1;
      return;
    }
    value = VerifyGraphicsMode();
    if ((value != 0) || (IsDisplayOptionSupported != 0)) goto LAB_0049b277;
    value2 = 10;
  }
  else {
    value2 = 0xb;
  }
  SetOptionsMenu(value2);
  bShouldNotProcessMore = 1;
  return;
}

