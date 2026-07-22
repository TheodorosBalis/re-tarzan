#include "tarzan_ghidra_types.hpp"

// Address: 0x004A0920
// Label: TarzanActionGameMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool TarzanActionGameMenu(void)

{
  uint value;
  uint value2;
  
  if ((g_TarzanActionGameMenuInitializedFlag & 1) == 0) {
    g_TarzanActionGameMenuInitializedFlag = g_TarzanActionGameMenuInitializedFlag | 1;
    g_MainMenuActionGameLabel =
         SelectNextEnabledMenuItem(0xffffffff,&PTR_s_TARZAN_ACTION_GAME_00516498);
  }
  if (g_TarzanActionGameMenuState == 0) {
    g_MainMenuActionGameLabel = SelectPreviousEnabledMenuItem(0,&PTR_s_TARZAN_ACTION_GAME_00516498);
    g_TarzanActionGameMenuState = 2;
  }
  else if (g_TarzanActionGameMenuState == 2) {
    value = GetUserInputInMenuAndProcessSound(1);
    value2 = value & 0x8000;
    if ((value2 == 0) && ((value & 1) != 0)) {
      g_MainMenuActionGameLabel =
           SelectPreviousEnabledMenuItem
                     (g_MainMenuActionGameLabel,&PTR_s_TARZAN_ACTION_GAME_00516498);
    }
    if ((value2 == 0) && ((value & 2) != 0)) {
      g_MainMenuActionGameLabel =
           SelectNextEnabledMenuItem(g_MainMenuActionGameLabel,&PTR_s_TARZAN_ACTION_GAME_00516498);
    }
    if ((value2 == 0) && ((value & 0x20) != 0)) {
      g_TarzanActionGameMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_TarzanActionGameMenuState = 0x57;
    }
    switch(*(undefined2 *)(&g_TarzanActionGameMenuEntryIdTable + g_MainMenuActionGameLabel * 8)) {
    case 7:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        SetOptionsMenu(2);
        g_TarzanActionGameMenuState = 0x57;
      }
      break;
    case 8:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        SetOptionsMenu(8);
        g_TarzanActionGameMenuState = 0x57;
      }
      break;
    case 9:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        SetOptionsMenu(0xd);
        g_TarzanActionGameMenuState = 0x57;
      }
      break;
    case 10:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        RequestGraphicsModeChange(1);
        g_TarzanActionGameMenuState = 0x57;
      }
      break;
    case 0xb:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        RequestGraphicsModeChange(2);
        g_TarzanActionGameMenuState = 0x57;
      }
      break;
    case 0xc:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        RequestGraphicsModeChange(3);
        g_TarzanActionGameMenuState = 0x57;
      }
      break;
    case 0xd:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        RequestGraphicsModeChange(4);
        g_TarzanActionGameMenuState = 0x57;
      }
      break;
    case 0xe:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        RequestGraphicsModeChange(5);
        g_TarzanActionGameMenuState = 0x57;
      }
      break;
    case 0x57:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        g_TarzanActionGameMenuState = 0x57;
      }
    }
  }
  else if (g_TarzanActionGameMenuState == 0x57) {
    g_TarzanActionGameMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_TARZAN_ACTION_GAME_00516498,g_MainMenuActionGameLabel);
  return g_TarzanActionGameMenuState != 0;
}

