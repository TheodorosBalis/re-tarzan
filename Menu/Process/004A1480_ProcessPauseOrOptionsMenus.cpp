#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1480
// Label: ProcessPauseOrOptionsMenus
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ProcessPauseOrOptionsMenus(void)

{
  int menuIndex;
  code *stringCursor;
  
  if (g_OptionsMenuStatus == 0) {
    g_ActiveOptionsMenuHandler = (code *)0x0;
    stringCursor = (code *)ResolveOptionsMenuHandlerById(g_PendingOptionsMenuId);
    if (stringCursor != (code *)0xffffffff) {
      g_ActiveOptionsMenuHandler = stringCursor;
    }
    g_ActiveOptionsMenuId = g_PendingOptionsMenuId;
    g_PendingOptionsMenuId = 0;
    if (g_ActiveOptionsMenuHandler != (code *)0x0) {
      g_OptionsMenuStatus = 2;
      InitSoundAndNewGameStateFile(0xac);
      PlaySoundID(0xac,100,0,0,0x3fb33333);
      menuIndex = g_BrightnessPercent;
      if (0x19 < g_BrightnessPercent) {
        menuIndex = 0x19;
      }
      BuildBrightnessLookupTable(menuIndex);
    }
  }
  else if (g_OptionsMenuStatus == 2) {
    if ((g_ActiveOptionsMenuHandler == (code *)0x0) ||
       (menuIndex = (*g_ActiveOptionsMenuHandler)(), menuIndex == 0)) {
      bIsPaused = 1;
      g_OptionsMenuStatus = 3;
      return;
    }
  }
  else if ((g_OptionsMenuStatus == 3) && (menuIndex = DrawOptionsMenu(0,0xffffffff), menuIndex == 0)) {
    if (g_ReturnOptionsMenuId != 0) {
      SetOptionsMenu(g_ReturnOptionsMenuId);
    }
    g_OptionsMenuStatus = 0;
    if (g_PendingOptionsMenuId == 0) {
      BuildBrightnessLookupTable(g_BrightnessPercent);
    }
    CaptureKInputsInBuffer();
  }
  if ((g_OptionsMenuStatus == 0) && (g_PendingOptionsMenuId == 0)) {
    bIsPaused = 0;
    return;
  }
  bIsPaused = 1;
  return;
}

