#include "tarzan_ghidra_types.hpp"

// Address: 0x0047EDA0
// Label: ProcessMainMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 ProcessMainMenu(void)

{
  switch(MenuState) {
  case 0:
  case 1:
    CMenu::UpdateActiveMenu();
    return 1;
  case 2:
    if ((FadeBrightness == 0) && (3 < FadeStatus)) {
      LoadGameLevel();
      return 1;
    }
    break;
  case 3:
    if ((FadeBrightness == 0) && (3 < FadeStatus)) {
      RemoveOptionsGraphicsBlocks();
      RemoveMainMenuSelections();
      HideLoadGameHeaderGraphics();
      LoadAndHandleECM(0x8010,0);
      SetActiveMenuContext(&g_MenuSceneContext);
      BuildLoadGameHeaderGraphics();
      BuildMainMenuSelections();
      BuildOptionsGraphicsBlocks();
      SelectBackgroundMusicTrackForLevel(0);
      InitiateFade(1,0x200);
      Empty_menu_stub(&DAT_00c46070);
      MenuState = 0;
    }
  }
  return 1;
}

