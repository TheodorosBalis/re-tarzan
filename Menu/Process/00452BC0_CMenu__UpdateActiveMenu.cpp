#include "tarzan_ghidra_types.hpp"

// Address: 0x00452BC0
// Label: CMenu::UpdateActiveMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

undefined4 CMenu::UpdateActiveMenu(void)

{
  TotalGameLoopTicks = TotalGameLoopTicks + 1;
  UpdateMainMenuRequests();
  ProcessMenuButtonSequences();
  if (g_CurrentMenu == (int *)0x0) {
    if (g_NextMenu == (int *)0x0) {
      return 1;
    }
  }
  else if (g_CurrentMenu == g_NextMenu) goto run_current_menu;
  if ((FadeBrightness == 0) && (3 < FadeStatus)) {
    if ((g_CurrentMenu != (int *)0x0) && (*g_CurrentMenu != 0)) {
      ReleasePalettedTextureBlockIfUnused(*g_CurrentMenu + 4,0xffffffff);
    }
    g_CurrentMenu = g_NextMenu;
    if (g_NextMenu[6] != -1) {
      PlayAudioById(g_NextMenu[6],(int *)0,(undefined4 *)0);
    }
    if ((code *)g_CurrentMenu[5] != (code *)0x0) {
      (*(code *)g_CurrentMenu[5])(g_CurrentMenu);
    }
    InitiateFade(1,0x400);
    TimeIDLEinMenu = 0;
  }
  if (g_CurrentMenu != g_NextMenu) {
    return 1;
  }
run_current_menu:
  if ((code *)g_CurrentMenu[4] != (code *)0x0) {
    (*(code *)g_CurrentMenu[4])(g_CurrentMenu);
  }
  return 1;
}

