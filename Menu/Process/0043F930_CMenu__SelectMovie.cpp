#include "tarzan_ghidra_types.hpp"

// Address: 0x0043F930
// Label: CMenu::SelectMovie
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::SelectMovie(void)

{
  int menuIndex;
  
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
      SelectBackgroundMusicTrackForLevel(0);
    }
  }
  else if (((_g_SelectMovieState == 2) && (FadeBrightness == 0)) && (3 < FadeStatus)) {
    CMenu::SelectMovie_ReleaseResources();
    BuildMainMenuSelections();
    BuildOptionsGraphicsBlocks();
    LoadMenuGraphicBlock(&LoadGame_SelectLevelLabels);
    _g_SelectMovieState = 3;
    CMenu::RequestMenuChangeWithFade(&g_MenuDescriptor_Options);
  }
  g_CameraEyeDistanceFromFocus = 0x280;
  AdvanceMenuIdleScriptCursor(&DAT_0051d0f8,&g_JaneMenuScene);
  menuIndex = RandomModulo(0x15e);
  if (menuIndex == 0) {
    menuIndex = RandomModulo(8);
    SetMenuIdleScriptOverride(&DAT_0051d0f8,(&g_JaneMenuRandomIdleScriptTable)[menuIndex]);
  }
  if (_g_JaneMenuIdleScript_Field0004 == 0) {
    SetMenuIdleScriptOverride(&DAT_0051d0f8,&DAT_004ed200);
  }
  return;
}

