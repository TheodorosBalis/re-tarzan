#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1320
// Label: TwoLineMessageMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool TwoLineMessageMenu(void)

{
  uint value;
  uint value2;
  
  if ((g_TwoLineMessageMenu_Global_00723D31 & 1) == 0) {
    g_TwoLineMessageMenu_Global_00723D31 = g_TwoLineMessageMenu_Global_00723D31 | 1;
    g_TwoLineMessageMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&g_TwoLineMessageMenuEntryTable);
  }
  if (g_TwoLineMessageMenuState == 0) {
    g_TwoLineMessageMenuState = 2;
  }
  else if (g_TwoLineMessageMenuState == 2) {
    value = GetUserInputInMenuAndProcessSound(1);
    value2 = value & 0x8000;
    if ((value2 == 0) && ((value & 1) != 0)) {
      g_TwoLineMessageMenuCursor =
           SelectPreviousEnabledMenuItem(g_TwoLineMessageMenuCursor,&g_TwoLineMessageMenuEntryTable)
      ;
    }
    if (value2 == 0) {
      if ((value & 2) != 0) {
        g_TwoLineMessageMenuCursor =
             SelectNextEnabledMenuItem(g_TwoLineMessageMenuCursor,&g_TwoLineMessageMenuEntryTable);
      }
      if ((value & 0x10) != 0) {
        g_TwoLineMessageMenuState =
             (int)*(short *)(&g_TwoLineMessageMenuEntryIdTable + g_TwoLineMessageMenuCursor * 8);
      }
    }
    if ((value2 == 0) && ((value & 0x20) != 0)) {
      g_TwoLineMessageMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_TwoLineMessageMenuState = 0x57;
    }
  }
  else if (g_TwoLineMessageMenuState == 0x57) {
    g_TwoLineMessageMenuState = 0;
  }
  DrawOptionsMenu(&g_TwoLineMessageMenuEntryTable,g_TwoLineMessageMenuCursor);
  return g_TwoLineMessageMenuState != 0;
}

