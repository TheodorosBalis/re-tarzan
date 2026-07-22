#include "tarzan_ghidra_types.hpp"

// Address: 0x004A11F0
// Label: RescanCdPromptMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool RescanCdPromptMenu(void)

{
  short shortValue;
  uint value;
  uint value2;
  
  if ((g_RescanCdPromptMenu_Global_00723D30 & 1) == 0) {
    g_RescanCdPromptMenu_Global_00723D30 = g_RescanCdPromptMenu_Global_00723D30 | 1;
    g_RescanCdPromptMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&PTR_s_TO_PLAY_TARZAN_00516428);
  }
  if (g_RescanCdPromptMenuState == 0) {
    g_RescanCdPromptMenuState = 2;
  }
  else if (g_RescanCdPromptMenuState == 2) {
    value = GetUserInputInMenuAndProcessSound(1);
    value2 = value & 0x8000;
    if ((value2 == 0) && ((value & 1) != 0)) {
      g_RescanCdPromptMenuCursor =
           SelectPreviousEnabledMenuItem(g_RescanCdPromptMenuCursor,&PTR_s_TO_PLAY_TARZAN_00516428);
    }
    if ((value2 == 0) && ((value & 2) != 0)) {
      g_RescanCdPromptMenuCursor =
           SelectNextEnabledMenuItem(g_RescanCdPromptMenuCursor,&PTR_s_TO_PLAY_TARZAN_00516428);
    }
    shortValue = *(short *)(&g_RescanCdPromptMenuEntryIdTable + g_RescanCdPromptMenuCursor * 8);
    if (shortValue == 0x13) {
      if ((value2 != 0) || ((value & 0x10) == 0)) goto LAB_004a12f9;
      IsGameRunningOnCD();
      value = bGameInitSuccess;
    }
    else {
      if (shortValue != 0x14) {
        if (((shortValue == 0x15) && (value2 == 0)) && ((value & 0x10) != 0)) {
          ExitAfterFatalErrorCleanup();
        }
        goto LAB_004a12f9;
      }
      if (value2 != 0) goto LAB_004a12f9;
      value = value & 0x10;
    }
    if (value != 0) {
      g_RescanCdPromptMenuState = 0x57;
    }
  }
  else if (g_RescanCdPromptMenuState == 0x57) {
    g_RescanCdPromptMenuState = 0;
  }
LAB_004a12f9:
  DrawOptionsMenu(&PTR_s_TO_PLAY_TARZAN_00516428,g_RescanCdPromptMenuCursor);
  return g_RescanCdPromptMenuState != 0;
}

