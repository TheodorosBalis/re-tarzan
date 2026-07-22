#include "tarzan_ghidra_types.hpp"

// Address: 0x0049F260
// Label: DrawOptionsMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 DrawOptionsMenu(undefined4 *menu,int menuItem)

{
  undefined4 *dataCursor;
  int menuIndex3;
  int menuIndex4;
  int menuIndex5;
  int menuIndex6;
  undefined2 upperWord;
  char resultFlag;
  uint value;
  uint value2;
  undefined4 *dataCursor2;
  int menuIndex;
  int menuIndex2;
  char *stringCursor;
  char *stringCursor2;
  int localState2;
  int localState;
  
  if (g_CurrentOptionsMenuTextList != menu) {
    if (g_PreviousOptionsMenuTextList == (undefined4 *)0x0) {
      g_PreviousOptionsMenuTextList = g_CurrentOptionsMenuTextList;
    }
    g_CurrentOptionsMenuTextList = menu;
    if (g_PreviousOptionsMenuTextList == (undefined4 *)0x0) goto LAB_0049f2a0;
    g_OptionsMenuTransitionPercent = 100;
  }
  if (g_PreviousOptionsMenuTextList != (undefined4 *)0x0) {
    menu = g_PreviousOptionsMenuTextList;
  }
LAB_0049f2a0:
  if (menu == (undefined4 *)0x0) {
    return 0;
  }
  localState2 = 0;
  menuIndex = 0;
  stringCursor = (char *)*menu;
  dataCursor2 = menu;
  while (stringCursor != (char *)0x0) {
    value = 0xffffffff;
    do {
      if (value == 0) break;
      value = value - 1;
      resultFlag = *stringCursor;
      stringCursor = stringCursor + 1;
    } while (resultFlag != '\0');
    if (menuIndex < (int)(~value - 1)) {
      menuIndex = ~value - 1;
    }
    dataCursor = dataCursor2 + 2;
    dataCursor2 = dataCursor2 + 2;
    localState2 = localState2 + 1;
    stringCursor = (char *)*dataCursor;
  }
  menuIndex3 = GetWindowWidth_stub2();
  menuIndex3 = menuIndex3 * (menuIndex + 4);
  menuIndex = GetWindowWidth_Stub();
  menuIndex = menuIndex * (localState2 + 4);
  menuIndex4 = GetWindowWidth();
  menuIndex2 = (menuIndex4 - menuIndex3) / 2;
  menuIndex5 = GetWindowHeight();
  menuIndex5 = (menuIndex5 - menuIndex) / 2;
  if (g_PreviousOptionsMenuTextList == (undefined4 *)0x0) {
    g_OptionsMenuTransitionPercent = g_OptionsMenuTransitionPercent + 0x1c;
    if (99 < g_OptionsMenuTransitionPercent) {
      g_OptionsMenuTransitionPercent = 100;
    }
  }
  else {
    g_OptionsMenuTransitionPercent = g_OptionsMenuTransitionPercent + -0x1c;
    if (g_OptionsMenuTransitionPercent < 1) {
      g_PreviousOptionsMenuTextList = (undefined4 *)0x0;
      g_OptionsMenuTransitionPercent = 0;
    }
  }
  localState = g_OptionsMenuTransitionPercent;
  menuIndex6 = IsHardware3DGraphicsMode();
  if ((menuIndex6 == 0) && (localState < 0x32)) {
    localState = 0;
  }
  value = (localState * 0xff) / 100;
  value = value | ((value * 0x100 | value) << 8 | value) << 8;
  if (localState != 0) {
    menuIndex6 = GetWindowWidth_Stub();
    localState = menuIndex5 + menuIndex6 * 2;
    if (0 < localState2) {
      do {
        stringCursor = (char *)*menu;
        menuIndex6 = GetWindowWidth_stub2();
        value2 = 0xffffffff;
        stringCursor2 = stringCursor;
        do {
          if (value2 == 0) break;
          value2 = value2 - 1;
          resultFlag = *stringCursor2;
          stringCursor2 = stringCursor2 + 1;
        } while (resultFlag != '\0');
        DrawOptionsMenuScaledText(menuIndex4 - menuIndex6 * (~value2 - 1) >> 1,localState,stringCursor,value,0);
        menuIndex6 = GetWindowWidth_Stub();
        localState = localState + menuIndex6;
        menu = menu + 2;
        localState2 = localState2 + -1;
      } while (localState2 != 0);
    }
  }
  if (g_OptionsMenuTransitionPercent == 100) {
    menuIndex4 = GetWindowWidth_Stub();
    if (-1 < menuItem) {
      resultFlag = g_OptionsMenuVolumePreviewTicks;
      if (g_OptionsMenuCursorPulse < '\x10') {
        resultFlag = g_OptionsMenuVolumePreviewTicks << 1;
      }
      g_OptionsMenuCursorPulse = g_OptionsMenuCursorPulse + resultFlag;
      if (g_OptionsMenuCursorPulse < ' ') {
        if (g_OptionsMenuCursorPulse < '\0') {
          g_OptionsMenuCursorPulse = '\0';
          g_OptionsMenuVolumePreviewTicks = '\x01';
        }
      }
      else {
        g_OptionsMenuCursorPulse = '\x1f';
        g_OptionsMenuVolumePreviewTicks = -1;
      }
      menuIndex6 = GetWindowWidth_Stub();
      menuIndex4 = menuIndex6 * menuItem + -1 + menuIndex5 + menuIndex4 * 2;
      menuIndex6 = menuIndex3 / 2;
      menuIndex5 = GetWindowWidth_Stub(1,0xda,CONCAT22((short)(menuIndex3 >> 0x1f),
                                                  (short)g_OptionsMenuCursorPulse),0xf,0xf,value,1,0
                                  ,1,0);
      menuIndex5 = GetWindowWidth_stub2(menuIndex5 + 1);
      menuIndex5 = GetWindowWidth_stub2(menuIndex4,menuIndex6 - menuIndex5);
      DrawTexturedQuad(menuIndex5 + menuIndex2);
      menuIndex5 = GetWindowWidth_Stub(CONCAT22(upperWord,(short)g_OptionsMenuCursorPulse) + 1,0xda,
                                  -CONCAT22(upperWord,(short)g_OptionsMenuCursorPulse),0xf,0xf,
                                  value,1,0,1,0);
      menuIndex5 = GetWindowWidth_stub2(menuIndex5 + 1);
      DrawTexturedQuad(menuIndex6 + menuIndex2,menuIndex4,menuIndex6 - menuIndex5);
    }
  }
  DrawOptionsMenuBackdrop_Stub
            ((float)(g_OptionsMenuTransitionPercent * menuIndex3) * _g_FloatVolumeFadeStep,
             (float)(g_OptionsMenuTransitionPercent * menuIndex) * _g_FloatVolumeFadeStep);
  return 1;
}

