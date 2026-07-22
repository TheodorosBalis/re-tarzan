#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1040
// Label: UnsupportedDisplaySettingsMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool UnsupportedDisplaySettingsMenu(void)

{
  uint value;
  int menuIndex;
  uint value2;
  
  if ((g_UnsupportedDisplaySettingsMenuInitializedFlag & 1) == 0) {
    g_UnsupportedDisplaySettingsMenuInitializedFlag =
         g_UnsupportedDisplaySettingsMenuInitializedFlag | 1;
    g_UnsupportedDisplaySettingsMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&PTR_s_THE_GAME_CANNOT_RUN_IN_THIS_005163b8);
  }
  if (g_UnsupportedDisplaySettingsMenuState == 0) {
    g_UnsupportedDisplaySettingsMenuState = 2;
  }
  else if (g_UnsupportedDisplaySettingsMenuState == 2) {
    value = GetUserInputInMenuAndProcessSound(1);
    value2 = value & 0x8000;
    if ((value2 == 0) && ((value & 1) != 0)) {
      g_UnsupportedDisplaySettingsMenuCursor =
           SelectPreviousEnabledMenuItem
                     (g_UnsupportedDisplaySettingsMenuCursor,
                      &PTR_s_THE_GAME_CANNOT_RUN_IN_THIS_005163b8);
    }
    if ((value2 == 0) && ((value & 2) != 0)) {
      g_UnsupportedDisplaySettingsMenuCursor =
           SelectNextEnabledMenuItem
                     (g_UnsupportedDisplaySettingsMenuCursor,
                      &PTR_s_THE_GAME_CANNOT_RUN_IN_THIS_005163b8);
    }
    if ((value2 == 0) && ((value & 0x20) != 0)) {
      g_UnsupportedDisplaySettingsMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_UnsupportedDisplaySettingsMenuState = 0x57;
    }
    menuIndex = VerifyGraphicsMode();
    if ((menuIndex != 0) || (IsDisplayOptionSupported != 0)) {
      g_UnsupportedDisplaySettingsMenuState = 0x57;
    }
    switch(*(undefined2 *)
            (&g_UnsupportedDisplaySettingsMenuEntryIdTable +
            g_UnsupportedDisplaySettingsMenuCursor * 8)) {
    case 0xf:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        RequestGraphicsModeChange(1);
        g_UnsupportedDisplaySettingsMenuState = 0x57;
      }
      break;
    case 0x10:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        RequestGraphicsModeChange(2);
        g_UnsupportedDisplaySettingsMenuState = 0x57;
      }
      break;
    case 0x11:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        RequestGraphicsModeChange(3);
        g_UnsupportedDisplaySettingsMenuState = 0x57;
      }
      break;
    case 0x12:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        RequestGraphicsModeChange(4);
        g_UnsupportedDisplaySettingsMenuState = 0x57;
      }
    }
  }
  else if (g_UnsupportedDisplaySettingsMenuState == 0x57) {
    g_UnsupportedDisplaySettingsMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_THE_GAME_CANNOT_RUN_IN_THIS_005163b8,g_UnsupportedDisplaySettingsMenuCursor
                 );
  return g_UnsupportedDisplaySettingsMenuState != 0;
}

