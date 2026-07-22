#include "tarzan_ghidra_types.hpp"

// Address: 0x00453290
// Label: CMenu::CheatMenu_UpdateLevelSelect
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::CheatMenu_UpdateLevelSelect(void)

{
  char resultFlag;
  short shortValue;
  int menuIndex;
  uint value;
  uint value2;
  int menuIndex2;
  undefined4 *dataCursor;
  int menuIndex3;
  short *value3;
  char *stringCursor;
  char *stringCursor2;
  char localState [64];
  
  menuIndex = 0;
  g_HudTextRendererState = 1;
  if (_g_CheatMenuLevelSelectMode == 0) {
    g_CheatMenuLastLevelGroupIndex = 0;
    menuIndex3 = 0;
    _g_CheatMenuLevelSelectPage = 0;
    dataCursor = (undefined4 *)&g_CheatMenuLevelSelectPage;
    value3 = (short *)0x4f2190;
    do {
      shortValue = *value3;
      *(short *)(&g_CheatMenuLevelSelectCursor + (menuIndex + menuIndex3) * 2) = shortValue;
      if (shortValue == -1) {
        if (0 < menuIndex3) {
LAB_004537e5:
          g_CheatMenuLastLevelGroupIndex = g_CheatMenuLastLevelGroupIndex + 1;
          menuIndex = menuIndex + 9;
          dataCursor = dataCursor + 1;
          menuIndex3 = 0;
          *dataCursor = 0;
        }
      }
      else {
        menuIndex3 = menuIndex3 + 1;
        if (7 < menuIndex3) {
          *(undefined2 *)(&g_CheatMenuLevelSelectCursor + (menuIndex3 + menuIndex) * 2) = 0xffff;
          goto LAB_004537e5;
        }
      }
      value3 = value3 + 1;
      if (0x4f21c7 < (int)value3) {
        *(undefined2 *)
         (&g_CheatMenuLevelSelectCursor + (menuIndex3 + g_CheatMenuLastLevelGroupIndex * 9) * 2) = 0xffff
        ;
        if (menuIndex3 == 0) {
          g_CheatMenuLastLevelGroupIndex = g_CheatMenuLastLevelGroupIndex + -1;
        }
        _g_CheatMenuLevelSelectMode = 1;
        g_CheatMenuCurrentLevelGroupIndex = 0;
        return;
      }
    } while( true );
  }
  if (_g_CheatMenuLevelSelectMode != 1) {
    g_HudTextRendererState = 1;
    return;
  }
  localState[1] = 0;
  menuIndex = 0x78;
  localState[0] = (char)g_CheatMenuCurrentLevelGroupIndex + 'A';
  menuIndex3 = 0;
  do {
    menuIndex2 = g_CheatMenuCurrentLevelGroupIndex;
    switch((uint)*(ushort *)
                  (&g_CheatMenuLevelSelectCursor +
                  (menuIndex3 + g_CheatMenuCurrentLevelGroupIndex * 9) * 2)) {
    case 0xff00:
      value = 0xffffffff;
      stringCursor2 = s_Stork_Ride_bonus_a_004f2580;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff01:
      value = 0xffffffff;
      stringCursor2 = s_Stork_Ride_bonus_b_004f256c;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff02:
      value = 0xffffffff;
      stringCursor2 = s_Stork_Ride_bonus_c_004f2558;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff03:
      value = 0xffffffff;
      stringCursor2 = s_Stork_Ride_bonus_d_004f2544;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff04:
      value = 0xffffffff;
      stringCursor2 = s_Jungle_Cruise_bonus_a_004f252c;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff05:
      value = 0xffffffff;
      stringCursor2 = s_Jungle_Cruise_bonus_b_004f2514;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff06:
      value = 0xffffffff;
      stringCursor2 = s_Jungle_Cruise_bonus_c_004f24fc;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff07:
      value = 0xffffffff;
      stringCursor2 = s_Jungle_Cruise_bonus_d_004f24e4;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff08:
      value = 0xffffffff;
      stringCursor2 = s_tree_surfing_bonus_a_004f25dc;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff09:
      value = 0xffffffff;
      stringCursor2 = s_tree_surfing_bonus_b_004f25c4;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff0a:
      value = 0xffffffff;
      stringCursor2 = s_tree_surfing_bonus_c_004f25ac;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff0b:
      value = 0xffffffff;
      stringCursor2 = s_tree_surfing_bonus_d_004f2594;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff0c:
      value = 0xffffffff;
      stringCursor2 = s_doofah_bonus_a_004f24d4;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff0d:
      value = 0xffffffff;
      stringCursor2 = s_doofah_bonus_b_004f24c4;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff0e:
      value = 0xffffffff;
      stringCursor2 = s_doofah_bonus_c_004f24b4;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    case 0xff0f:
      value = 0xffffffff;
      stringCursor2 = s_doofah_bonus_d_004f24a4;
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
      break;
    default:
      value = 0xffffffff;
      stringCursor2 = (&g_CheatMenuLevelNameTable)
                [*(ushort *)
                  (&g_CheatMenuLevelSelectCursor +
                  (menuIndex3 + g_CheatMenuCurrentLevelGroupIndex * 9) * 2)];
      do {
        stringCursor = stringCursor2;
        if (value == 0) break;
        value = value - 1;
        stringCursor = stringCursor2 + 1;
        resultFlag = *stringCursor2;
        stringCursor2 = stringCursor;
      } while (resultFlag != '\0');
      value = ~value;
      stringCursor = stringCursor + -value;
    }
    stringCursor2 = localState;
    for (value2 = value >> 2; value2 != 0; value2 = value2 - 1) {
      *(undefined4 *)stringCursor2 = *(undefined4 *)stringCursor;
      stringCursor = stringCursor + 4;
      stringCursor2 = stringCursor2 + 4;
    }
    menuIndex2 = *(int *)(&g_CheatMenuLevelSelectPage + menuIndex2 * 4);
    for (value = value & 3; value != 0; value = value - 1) {
      *stringCursor2 = *stringCursor;
      stringCursor = stringCursor + 1;
      stringCursor2 = stringCursor2 + 1;
    }
    if (menuIndex3 == menuIndex2) {
      DrawEntitySpriteFontString(0xd2,menuIndex,localState,0x80808080);
    }
    DrawEntitySpriteFontString(0xd2,menuIndex,localState,0xffffff);
    menuIndex2 = g_CheatMenuCurrentLevelGroupIndex;
    value = g_PlayerInputPressedMask;
    menuIndex3 = menuIndex3 + 1;
    menuIndex = menuIndex + 0xc;
  } while (*(short *)(&g_CheatMenuLevelSelectCursor +
                     (menuIndex3 + g_CheatMenuCurrentLevelGroupIndex * 9) * 2) != -1);
  if (((g_PlayerInputPressedMask & 0x10) != 0) &&
     (0 < *(int *)(&g_CheatMenuLevelSelectPage + g_CheatMenuCurrentLevelGroupIndex * 4))) {
    *(int *)(&g_CheatMenuLevelSelectPage + g_CheatMenuCurrentLevelGroupIndex * 4) =
         *(int *)(&g_CheatMenuLevelSelectPage + g_CheatMenuCurrentLevelGroupIndex * 4) + -1;
  }
  if (((value & 0x40) != 0) &&
     (*(short *)(&g_CheatMenuLevelSelectFlags +
                (*(int *)(&g_CheatMenuLevelSelectPage + menuIndex2 * 4) + menuIndex2 * 9) * 2) != -1)) {
    *(int *)(&g_CheatMenuLevelSelectPage + menuIndex2 * 4) =
         *(int *)(&g_CheatMenuLevelSelectPage + menuIndex2 * 4) + 1;
  }
  if (((value & 0x80) != 0) && (0 < menuIndex2)) {
    menuIndex2 = menuIndex2 + -1;
    g_CheatMenuCurrentLevelGroupIndex = menuIndex2;
  }
  if (((value & 0x20) != 0) && (menuIndex2 < g_CheatMenuLastLevelGroupIndex)) {
    menuIndex2 = menuIndex2 + 1;
    g_CheatMenuCurrentLevelGroupIndex = menuIndex2;
  }
  if ((value & 0x4008) == 0) {
    return;
  }
  menuIndex = *(int *)(&g_CheatMenuLevelSelectPage + menuIndex2 * 4) + menuIndex2 * 9;
  switch(*(undefined2 *)(&g_CheatMenuLevelSelectCursor + menuIndex * 2)) {
  case 0xff00:
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x0e';
    goto LAB_0045373d;
  case 0xff01:
    g_CurrentCheckpointId = 1;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x0e';
    break;
  case 0xff02:
    g_CurrentCheckpointId = 2;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x0e';
    break;
  case 0xff03:
    g_CurrentCheckpointId = 3;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x0e';
    break;
  case 0xff04:
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x0f';
    goto LAB_0045373d;
  case 0xff05:
    g_CurrentCheckpointId = 1;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x0f';
    break;
  case 0xff06:
    g_CurrentCheckpointId = 2;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x0f';
    break;
  case 0xff07:
    g_CurrentCheckpointId = 3;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x0f';
    break;
  case 0xff08:
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x10';
    goto LAB_0045373d;
  case 0xff09:
    g_CurrentCheckpointId = 1;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x10';
    break;
  case 0xff0a:
    g_CurrentCheckpointId = 2;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x10';
    break;
  case 0xff0b:
    g_CurrentCheckpointId = 3;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x10';
    break;
  case 0xff0c:
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x11';
    goto LAB_0045373d;
  case 0xff0d:
    g_CurrentCheckpointId = 1;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x11';
    break;
  case 0xff0e:
    g_CurrentCheckpointId = 2;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x11';
    break;
  case 0xff0f:
    g_CurrentCheckpointId = 3;
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = '\x11';
    break;
  default:
    *( undefined1 *)((int)&g_LevelTransitionContext + 2) = (&g_CheatMenuLevelSelectCursor)[menuIndex * 2];
LAB_0045373d:
    g_CurrentCheckpointId = 0;
  }
  g_SelectedLevelIndex =
       FindLevelTransitionEntryIndex((int)*( undefined1 *)((int)&g_LevelTransitionContext + 2),g_CurrentCheckpointId);
  g_PendingTransitionPayload = 0;
  *( undefined1 *)((int)&g_LevelTransitionContext + 3) =
       (&g_LevelTransitionTypeBySlot)[*( undefined1 *)((int)&g_LevelTransitionContext + 1) * 2];
  ResetBackgroundMusicPlaybackStateThunk(&DAT_00c46070);
  InitiateFade(2,0x100);
  MenuState = 2;
  return;
}

