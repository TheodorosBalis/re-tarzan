#include "tarzan_ghidra_types.hpp"

// Address: 0x004A0C00
// Label: ExitGameConfirmationMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool ExitGameConfirmationMenu(void)

{
  uint value;
  uint value2;
  
  if ((g_ExitGameConfirmationMenuInitializedFlag & 1) == 0) {
    g_ExitGameConfirmationMenuInitializedFlag = g_ExitGameConfirmationMenuInitializedFlag | 1;
    g_ExitGameConfirmationMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&PTR_s_EXIT_GAME_NOW__00516310);
  }
  if (g_ExitGameConfirmationMenuState == 0) {
    g_ExitGameConfirmationMenuState = 2;
    g_ExitGameConfirmationMenuCursor =
         SelectPreviousEnabledMenuItem(0,&PTR_s_EXIT_GAME_NOW__00516310);
  }
  else if (g_ExitGameConfirmationMenuState == 2) {
    value = GetUserInputInMenuAndProcessSound(1);
    value2 = value & 0x8000;
    if ((value2 == 0) && ((value & 1) != 0)) {
      g_ExitGameConfirmationMenuCursor =
           SelectPreviousEnabledMenuItem
                     (g_ExitGameConfirmationMenuCursor,&PTR_s_EXIT_GAME_NOW__00516310);
    }
    if ((value2 == 0) && ((value & 2) != 0)) {
      g_ExitGameConfirmationMenuCursor =
           SelectNextEnabledMenuItem
                     (g_ExitGameConfirmationMenuCursor,&PTR_s_EXIT_GAME_NOW__00516310);
    }
    if ((value2 == 0) && ((value & 0x20) != 0)) {
      g_ExitGameConfirmationMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_ExitGameConfirmationMenuState = 0x57;
    }
    if (*(short *)(&g_ExitGameConfirmationMenuEntryIdTable + g_ExitGameConfirmationMenuCursor * 8)
        == 4) {
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        ExitAfterFatalErrorCleanup();
        g_ExitGameConfirmationMenuState = 0x57;
      }
    }
    else if (((*(short *)(&g_ExitGameConfirmationMenuEntryIdTable +
                         g_ExitGameConfirmationMenuCursor * 8) == 5) && (value2 == 0)) &&
            ((value & 0x10) != 0)) {
      g_ExitGameConfirmationMenuState = 0x57;
    }
  }
  else if (g_ExitGameConfirmationMenuState == 0x57) {
    g_ExitGameConfirmationMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_EXIT_GAME_NOW__00516310,g_ExitGameConfirmationMenuCursor);
  return g_ExitGameConfirmationMenuState != 0;
}

