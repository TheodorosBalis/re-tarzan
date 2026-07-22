#include "tarzan_ghidra_types.hpp"

// Address: 0x0045EA00
// Label: CMenu::LevelComplete_Render
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void CMenu::LevelComplete_Render(void)

{
  undefined *dataCursor;
  int menuIndex;
  undefined4 value;
  undefined4 localState2;
  undefined4 localState;
  
  g_CameraEyeDistanceFromFocus = 900;
  ReleasePalettedTextureBlockIfUnused(0x4ed35c,0xffffffff);
  ReleasePalettedTextureBlockIfUnused(0x4ed37c,0xffffffff);
  dataCursor = &g_LevelCompleteScoreEntitySceneObjects;
  menuIndex = 0x14;
  do {
    RenderSceneHierarchy(dataCursor);
    dataCursor = dataCursor + 0x144;
    menuIndex = menuIndex + -1;
  } while (menuIndex != 0);
  CMenu::LevelComplete_UpdateRewardBurstSystem(&g_LevelCompleteRewardBurstSystem);
  localState2 = 0;
  localState = 0xfffffff8;
  if (g_LevelCompleteInputMode == 0) {
    value = 1;
  }
  else {
    value = 2;
  }
  RenderMenuUiBlockEntry
            (&g_LevelCompleteTextAnchor,&localState2,value,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,
             0);
  RenderMenuUiBlockEntry
            (&g_LevelCompleteTextAnchor,&localState2,0,*(int *)(g_ActiveMenuContext + 0x1c) + 0x40,0);
  ReleasePalettedTextureBlockIfUnused(&g_LevelCompleteTextAnchor,2);
  ReleasePalettedTextureBlockIfUnused(0x4ed37c,2);
  return;
}

