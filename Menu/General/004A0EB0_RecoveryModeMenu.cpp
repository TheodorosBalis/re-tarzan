#include "tarzan_ghidra_types.hpp"

// Address: 0x004A0EB0
// Label: RecoveryModeMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool RecoveryModeMenu(void)

{
  short shortValue;
  uint value;
  uint value2;
  
  if ((g_RecoveryModeMenuInitializedFlag & 1) == 0) {
    g_RecoveryModeMenuInitializedFlag = g_RecoveryModeMenuInitializedFlag | 1;
    g_RecoveryModeMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_RECOVERY_MODE_00516338);
  }
  if (g_RecoveryModeMenuState == 0) {
    g_RecoveryModeMenuState = 2;
  }
  else if (g_RecoveryModeMenuState == 2) {
    value = GetUserInputInMenuAndProcessSound(1);
    value2 = value & 0x8000;
    if ((value2 == 0) && ((value & 1) != 0)) {
      g_RecoveryModeMenuCursor =
           SelectPreviousEnabledMenuItem(g_RecoveryModeMenuCursor,&PTR_s_RECOVERY_MODE_00516338);
    }
    if ((value2 == 0) && ((value & 2) != 0)) {
      g_RecoveryModeMenuCursor =
           SelectNextEnabledMenuItem(g_RecoveryModeMenuCursor,&PTR_s_RECOVERY_MODE_00516338);
    }
    shortValue = *(short *)(&g_RecoveryModeMenuEntryIdTable + g_RecoveryModeMenuCursor * 8);
    if (shortValue == 0x54) {
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        bLastTimeCrashed = 0;
        RequestGraphicsModeChange(7);
        g_RecoveryModeMenuState = 0x57;
      }
    }
    else if (shortValue == 0x55) {
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        bLastTimeCrashed = 0;
        g_CurrentDisplayModeIndex = 5;
        SetPreferredGraphicsMode(5);
        RequestGraphicsModeChange(g_CurrentDisplayModeIndex);
        g_RecoveryModeMenuState = 0x57;
      }
    }
    else if (((shortValue == 0x56) && (value2 == 0)) && ((value & 0x10) != 0)) {
      bLastTimeCrashed = 0;
      RequestGraphicsModeChange(5);
      SetOptionsMenu(5);
      g_RecoveryModeMenuState = 0x57;
    }
  }
  else if (g_RecoveryModeMenuState == 0x57) {
    g_RecoveryModeMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_RECOVERY_MODE_00516338,g_RecoveryModeMenuCursor);
  return g_RecoveryModeMenuState != 0;
}

