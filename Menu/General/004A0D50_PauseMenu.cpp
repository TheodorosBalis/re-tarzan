#include "tarzan_ghidra_types.hpp"

// Address: 0x004A0D50
// Label: PauseMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool PauseMenu(void)

{
  uint value;
  uint value2;
  
  if ((g_PauseMenuInitializedFlag & 1) == 0) {
    g_PauseMenuInitializedFlag = g_PauseMenuInitializedFlag | 1;
    g_PauseMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_PAUSED_00516390);
  }
  if (g_PauseMenuState == 0) {
    g_PauseMenuState = 2;
    g_PauseMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_PAUSED_00516390);
  }
  else if (g_PauseMenuState == 2) {
    value = GetUserInputInMenuAndProcessSound(1);
    value2 = value & 0x8000;
    if ((value2 == 0) && ((value & 1) != 0)) {
      g_PauseMenuCursor = SelectPreviousEnabledMenuItem(g_PauseMenuCursor,&PTR_s_PAUSED_00516390);
    }
    if ((value2 == 0) && ((value & 2) != 0)) {
      g_PauseMenuCursor = SelectNextEnabledMenuItem(g_PauseMenuCursor,&PTR_s_PAUSED_00516390);
    }
    if ((value2 == 0) && ((value & 0x20) != 0)) {
      g_PauseMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_PauseMenuState = 0x57;
    }
    if (*(short *)(&g_PauseMenuEntryIdTable + g_PauseMenuCursor * 8) == 0x16) {
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        g_PauseMenuState = 0x57;
      }
    }
    else if (((*(short *)(&g_PauseMenuEntryIdTable + g_PauseMenuCursor * 8) == 0x17) && (value2 == 0)
             ) && ((value & 0x10) != 0)) {
      CMenu::PauseMenu_RequestExitToWorldMap();
      g_PauseMenuState = 0x57;
    }
  }
  else if (g_PauseMenuState == 0x57) {
    EnsureHudPanelsStayVisible();
    g_PauseMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_PAUSED_00516390,g_PauseMenuCursor);
  return g_PauseMenuState != 0;
}

