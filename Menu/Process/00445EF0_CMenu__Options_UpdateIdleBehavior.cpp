#include "tarzan_ghidra_types.hpp"

// Address: 0x00445EF0
// Label: CMenu::Options_UpdateIdleBehavior
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::Options_UpdateIdleBehavior(void)

{
  int menuIndex;
  
  g_CameraEyeDistanceFromFocus = 0x280;
  menuIndex = RandomModulo(0x78);
  if (menuIndex == 0x3c) {
    _g_SelectMovieIdleEventCounter = 7;
  }
  AdvanceMenuIdleScriptCursor(&g_SelectMovieIdleScriptCursor,&g_PorterMenuScene);
  if ((300 < TimeIDLEinMenu) && (g_SelectMovieIdleScriptPending == 0)) {
    menuIndex = RandomModulo(0xdc);
    if (menuIndex == 100) {
      menuIndex = RandomModulo(5);
      SetMenuIdleScriptOverride
                (&g_SelectMovieIdleScriptCursor,(&g_SelectMovieIdleVoiceTable)[menuIndex]);
    }
  }
  if (TimeIDLEinMenu < 0x50) {
    g_OptionsMenuIdleToggle = 0;
    return;
  }
  menuIndex = RandomModulo((-(g_OptionsMenuIdleToggle != 0) & 100U) + 0x14);
  if (menuIndex == 5) {
    g_OptionsMenuIdleToggle = (uint)(g_OptionsMenuIdleToggle == 0);
  }
  return;
}

