#include "tarzan_ghidra_types.hpp"

// Address: 0x004A0210
// Label: GameplayOptionsMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool GameplayOptionsMenu(void)

{
  undefined **dataCursor;
  uint value;
  uint value2;
  undefined **dataCursor2;
  char *localState [3];
  
  if ((g_GameplayOptionsMenuInitializedFlag & 1) == 0) {
    g_GameplayOptionsMenuInitializedFlag = g_GameplayOptionsMenuInitializedFlag | 1;
    g_GameplayOptionsMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&g_GameplayOptionsMenuEntryTable);
  }
  if (g_GameplayOptionsMenuState == 0) {
    g_GameplayOptionsMenuState = 2;
  }
  else if (g_GameplayOptionsMenuState == 2) {
    value = GetUserInputInMenuAndProcessSound(1);
    value2 = value & 0x8000;
    if ((value2 == 0) && ((value & 1) != 0)) {
      g_GameplayOptionsMenuCursor =
           SelectPreviousEnabledMenuItem
                     (g_GameplayOptionsMenuCursor,&g_GameplayOptionsMenuEntryTable);
    }
    if ((value2 == 0) && ((value & 2) != 0)) {
      g_GameplayOptionsMenuCursor =
           SelectNextEnabledMenuItem(g_GameplayOptionsMenuCursor,&g_GameplayOptionsMenuEntryTable);
    }
    if ((value2 == 0) && ((value & 0x20) != 0)) {
      g_GameplayOptionsMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_GameplayOptionsMenuState = 0x57;
    }
    if ((&g_GameplayOptionsMenuEntryIdTable)[g_GameplayOptionsMenuCursor * 4] == 0x3d) {
      if (value2 == 0) {
        if ((value & 4) != 0) {
          _g_GameDifficulty = _g_GameDifficulty + -1;
        }
        if ((value & 8) != 0) {
          _g_GameDifficulty = _g_GameDifficulty + 1;
        }
      }
      if (_g_GameDifficulty < 0) {
        _g_GameDifficulty = 0;
      }
      else if (2 < _g_GameDifficulty) {
        _g_GameDifficulty = 2;
      }
    }
    else if ((((&g_GameplayOptionsMenuEntryIdTable)[g_GameplayOptionsMenuCursor * 4] == 0x57) &&
             (value2 == 0)) && ((value & 0x10) != 0)) {
      g_GameplayOptionsMenuState = 0x57;
    }
  }
  else if (g_GameplayOptionsMenuState == 0x57) {
    g_GameplayOptionsMenuState = 0;
  }
  localState[0] = &DAT_005175e0;
  localState[1] = s_MEDIUM_005175d8;
  localState[2] = &DAT_005175d0;
  if (g_GameplayOptionsMenuEntryTable != (undefined *)0x0) {
    dataCursor2 = &g_GameplayOptionsMenuEntryTable;
    do {
      if (*(short *)(dataCursor2 + 1) == 0x3d) {
        SetOptionsMenuEntryValueText(dataCursor2,localState[_g_GameDifficulty]);
      }
      dataCursor = dataCursor2 + 2;
      dataCursor2 = dataCursor2 + 2;
    } while (*dataCursor != (undefined *)0x0);
  }
  DrawOptionsMenu(&g_GameplayOptionsMenuEntryTable,g_GameplayOptionsMenuCursor);
  return g_GameplayOptionsMenuState != 0;
}

