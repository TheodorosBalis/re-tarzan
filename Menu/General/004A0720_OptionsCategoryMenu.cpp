#include "tarzan_ghidra_types.hpp"

// Address: 0x004A0720
// Label: OptionsCategoryMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool OptionsCategoryMenu(void)

{
  uint value;
  uint value2;
  
  if ((g_OptionsCategoryMenuInitializedFlag & 1) == 0) {
    g_OptionsCategoryMenuInitializedFlag = g_OptionsCategoryMenuInitializedFlag | 1;
    g_OptionsCategoryMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_OPTIONS_MENU_00516530)
    ;
  }
  switch(g_OptionsCategoryMenuState) {
  case 0:
    g_OptionsCategoryMenuState = 2;
    break;
  case 2:
    value = GetUserInputInMenuAndProcessSound(1);
    value2 = value & 0x8000;
    if ((value2 == 0) && ((value & 1) != 0)) {
      g_OptionsCategoryMenuCursor =
           SelectPreviousEnabledMenuItem(g_OptionsCategoryMenuCursor,&PTR_s_OPTIONS_MENU_00516530);
    }
    if (value2 == 0) {
      if ((value & 2) != 0) {
        g_OptionsCategoryMenuCursor =
             SelectNextEnabledMenuItem(g_OptionsCategoryMenuCursor,&PTR_s_OPTIONS_MENU_00516530);
      }
      if ((value & 0x10) != 0) {
        g_OptionsCategoryMenuState =
             (int)*(short *)(&g_OptionsCategoryMenuEntryIdTable + g_OptionsCategoryMenuCursor * 8);
      }
    }
    if ((value2 == 0) && ((value & 0x20) != 0)) {
      g_OptionsCategoryMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_OptionsCategoryMenuState = 0x57;
    }
    break;
  case 0x18:
    SetOptionsMenuAndReturnHere(3);
    g_OptionsCategoryMenuState = 0x57;
    break;
  case 0x19:
    SetOptionsMenuAndReturnHere(4);
    g_OptionsCategoryMenuState = 0x57;
    break;
  case 0x1a:
    SetOptionsMenuAndReturnHere(7);
    g_OptionsCategoryMenuState = 0x57;
    break;
  case 0x1b:
    SetOptionsMenuAndReturnHere(6);
    g_OptionsCategoryMenuState = 0x57;
    break;
  case 0x1c:
    SetOptionsMenuAndReturnHere(5);
    g_OptionsCategoryMenuState = 0x57;
    break;
  case 0x57:
    g_OptionsCategoryMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_OPTIONS_MENU_00516530,g_OptionsCategoryMenuCursor);
  return g_OptionsCategoryMenuState != 0;
}

