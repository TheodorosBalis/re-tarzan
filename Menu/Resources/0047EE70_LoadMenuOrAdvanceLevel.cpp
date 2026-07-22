#include "tarzan_ghidra_types.hpp"

// Address: 0x0047EE70
// Label: LoadMenuOrAdvanceLevel
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void LoadMenuOrAdvanceLevel(void)

{
  int menuIndex;
  undefined4 *dataCursor;
  undefined4 value;
  
  dataCursor = &g_LevelCompleteTextAnchor;
  for (menuIndex = 7; menuIndex != 0; menuIndex = menuIndex + -1) {
    *dataCursor = 0;
    dataCursor = dataCursor + 1;
  }
  MenuState = 0;
  LoadFonts(&PTR_DAT_0050df58,&DAT_00c46024);
  ResetInputStateThunk();
  ResetEntitySoundSlotLists();
  if (((g_SelectedLevelIndex < '\0') ||
      ((&g_MenuLoadOrAdvanceLevelCallback)[g_SelectedLevelIndex * 0xf] != -1)) ||
     ((short)g_LevelTransitionRequestFlags != -0x7fff)) {
    value = 0x16;
  }
  else {
    value = 0x15;
  }
  SelectLevelAudioProfile(value);
  g_PendingTransitionPayload = 0;
  SetActiveMenuContext(&g_MenuSceneContext);
  ResetMenuModelSet(&LevelCompleteObjects);
  LoadNecessaryGSXFontsAndModels(&LevelCompleteObjects);
  ResetMenuModelSet(&ModelJane);
  LoadNecessaryGSXFontsAndModels(&ModelJane);
  LoadMenuGraphicBlock(&Options_SelectMovieLabels);
  LoadMenuOrAdvanceLevelNoOp();
  g_CurrentMenu = 0;
  if (-1 < g_SelectedLevelIndex) {
    if (((&g_MenuLoadOrAdvanceLevelCallback)[g_SelectedLevelIndex * 0xf] == -1) &&
       ((short)g_LevelTransitionRequestFlags == -0x7fff)) {
      g_SelectedLevelIndex = -1;
      ProcessMovieClipOrLogo(0x4020,0x1fe,0,0x1000);
      ProcessMovieClipOrLogo(0x4022,0x1fc,0,0x1000);
      ProcessMovieClipOrLogo(0x4023,0x1f7,0,0x1000);
      ProcessMovieClipOrLogo(0x401c,0x1ef,0,0x1000);
      ProcessMovieClipOrLogo(0x401d,0x1ea,0,0x1000);
      ProcessMovieClipOrLogo(0x401e,500,0,0x1000);
      ProcessMovieClipOrLogo(0x4030,0x1ea,0,0x1000);
      ProcessMovieClipOrLogo(0x4031,0x1ea,0,0x1000);
      ProcessMovieClipOrLogo(0x4024,500,0,0x1000);
      ProcessMovieClipOrLogo(0x4025,500,0,0x1000);
      ProcessMovieClipOrLogo(0x4029,500,0,0x1000);
      ProcessMovieClipOrLogo(0x402a,500,0,0x1000);
      ProcessMovieClipOrLogo(0x402f,500,0,0x1000);
      ProcessMovieClipOrLogo(0x402d,500,0,0x1000);
      ProcessMovieClipOrLogo(0x402e,500,0,0x1000);
      ProcessMovieClipOrLogo(0x401f,1000,0,0x1000);
    }
    if ((-1 < g_SelectedLevelIndex) && ((short)g_LevelTransitionRequestFlags == -0x7fff)) {
      g_LevelCompleteInputMode = (int)g_SelectedLevelIndex & 1;
      g_CurrentMenu = 0;
      g_NextMenu = &g_MenuDescriptor_LevelComplete;
      CMenu::LevelComplete_Enter();
      return;
    }
  }
  *( undefined1 *)((int)&g_LevelTransitionContext + 2) = 0x16;
  g_NextMenu = &g_MainMenuMainFontMenuEntry;
  EnterGameMenu();
  return;
}

