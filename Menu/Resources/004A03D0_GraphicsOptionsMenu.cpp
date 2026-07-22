#include "tarzan_ghidra_types.hpp"

// Address: 0x004A03D0
// Label: GraphicsOptionsMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

bool GraphicsOptionsMenu(void)

{
  undefined **dataCursor;
  short shortValue;
  uint value;
  int menuIndex;
  uint value2;
  undefined **dataCursor2;
  
  if ((g_GraphicsOptionsMenuInitializedFlag & 1) == 0) {
    g_GraphicsOptionsMenuInitializedFlag = g_GraphicsOptionsMenuInitializedFlag | 1;
    g_GraphicsOptionsMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&g_GraphicsOptionsMenuEntryTable);
  }
  if (g_GraphicsOptionsMenuState == 0) {
    g_PendingGraphicsModeSelection = CurrentGraphicsMode();
    g_GraphicsOptionsMenuState = 2;
  }
  else if (g_GraphicsOptionsMenuState == 2) {
    value = GetUserInputInMenuAndProcessSound(1);
    value2 = value & 0x8000;
    if ((value2 == 0) && ((value & 1) != 0)) {
      g_GraphicsOptionsMenuCursor =
           SelectPreviousEnabledMenuItem
                     (g_GraphicsOptionsMenuCursor,&g_GraphicsOptionsMenuEntryTable);
    }
    if (value2 == 0) {
      if ((value & 2) != 0) {
        g_GraphicsOptionsMenuCursor =
             SelectNextEnabledMenuItem(g_GraphicsOptionsMenuCursor,&g_GraphicsOptionsMenuEntryTable)
        ;
      }
      if ((value & 0x20) != 0) {
        g_GraphicsOptionsMenuState = 0x57;
      }
    }
    if (g_PendingOptionsMenuId != 0) {
      g_GraphicsOptionsMenuState = 0x57;
    }
    menuIndex = GetGraphicsModeRevision();
    if (g_GraphicsOptionsMenuPendingMode != menuIndex) {
      g_GraphicsOptionsMenuPendingMode = GetGraphicsModeRevision();
      g_PendingGraphicsModeSelection = CurrentGraphicsMode();
    }
    switch((&g_GraphicsOptionsMenuEntryIdTable)[g_GraphicsOptionsMenuCursor * 4]) {
    case 0x3e:
      if (value2 == 0) {
        if ((value & 4) != 0) {
          g_PendingGraphicsModeSelection = g_PendingGraphicsModeSelection + -1;
        }
        if ((value & 8) != 0) {
          g_PendingGraphicsModeSelection = g_PendingGraphicsModeSelection + 1;
        }
        if ((value & 0x10) != 0) {
          RequestGraphicsModeChange(g_PendingGraphicsModeSelection);
        }
      }
      if (g_PendingGraphicsModeSelection < 1) {
        g_PendingGraphicsModeSelection = 1;
      }
      else if (5 < g_PendingGraphicsModeSelection) {
        g_PendingGraphicsModeSelection = 5;
      }
      break;
    case 0x3f:
      if ((value & 4) != 0) {
        g_BrightnessPercent = g_BrightnessPercent + -2;
      }
      if ((value & 8) != 0) {
        g_BrightnessPercent = g_BrightnessPercent + 2;
      }
      if (g_BrightnessPercent < 10) {
        g_BrightnessPercent = 10;
        BuildBrightnessLookupTable(10);
      }
      else {
        if (100 < g_BrightnessPercent) {
          g_BrightnessPercent = 100;
        }
        BuildBrightnessLookupTable(g_BrightnessPercent);
      }
      break;
    case 0x40:
      if ((value2 == 0) && ((value & 4) != 0)) {
        g_CurrentDisplayModeIndex = g_CurrentDisplayModeIndex + -1;
      }
      if ((value2 == 0) && ((value & 8) != 0)) {
        g_CurrentDisplayModeIndex = g_CurrentDisplayModeIndex + 1;
      }
      if (g_CurrentDisplayModeIndex < 1) {
        g_CurrentDisplayModeIndex = 1;
        SetPreferredGraphicsMode(1);
      }
      else {
        if (5 < g_CurrentDisplayModeIndex) {
          g_CurrentDisplayModeIndex = 5;
        }
        SetPreferredGraphicsMode(g_CurrentDisplayModeIndex);
      }
      break;
    case 0x57:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        g_GraphicsOptionsMenuState = 0x57;
      }
    }
  }
  else if (g_GraphicsOptionsMenuState == 0x57) {
    g_GraphicsOptionsMenuState = 0;
  }
  if (g_GraphicsOptionsMenuEntryTable != (undefined *)0x0) {
    dataCursor2 = &g_GraphicsOptionsMenuEntryTable;
    do {
      shortValue = *(short *)(dataCursor2 + 1);
      menuIndex = g_PendingGraphicsModeSelection;
      if (shortValue == 0x3e) {
LAB_004a06a3:
        SetOptionsMenuEntryValueText(dataCursor2,*(undefined4 *)(&stack0xffffffe0 + menuIndex * 4));
      }
      else if (shortValue == 0x3f) {
        LoadSFX(&DAT_00723d38,s__ld___005175c8,g_BrightnessPercent);
        SetOptionsMenuEntryValueText(dataCursor2,&DAT_00723d38);
      }
      else {
        menuIndex = g_CurrentDisplayModeIndex;
        if (shortValue == 0x40) goto LAB_004a06a3;
      }
      dataCursor = dataCursor2 + 2;
      dataCursor2 = dataCursor2 + 2;
    } while (*dataCursor != (undefined *)0x0);
  }
  DrawOptionsMenu(&g_GraphicsOptionsMenuEntryTable,g_GraphicsOptionsMenuCursor);
  return g_GraphicsOptionsMenuState != 0;
}

