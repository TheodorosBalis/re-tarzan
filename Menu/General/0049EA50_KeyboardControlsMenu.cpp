#include "tarzan_ghidra_types.hpp"

// Address: 0x0049EA50
// Label: KeyboardControlsMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool KeyboardControlsMenu(void)

{
  undefined **dataCursor;
  uint value;
  uint value2;
  int menuIndex;
  int menuIndex2;
  undefined **dataCursor2;
  undefined4 *dataCursor3;
  undefined4 value3;
  
  if ((g_KeyboardControlsMenuInitializedFlag & 1) == 0) {
    g_KeyboardControlsMenuInitializedFlag = g_KeyboardControlsMenuInitializedFlag | 1;
    g_KeyboardControlsMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&g_KeyboardControlsMenuCursor);
  }
  switch(g_KeyboardControlsMenuState) {
  case 0:
    g_KeyboardControlsMenuState = 2;
    break;
  case 2:
    value = GetUserInputInMenuAndProcessSound(1);
    value2 = value & 0x8000;
    if ((value2 == 0) && ((value & 1) != 0)) {
      g_KeyboardControlsMenuCursor =
           SelectPreviousEnabledMenuItem(g_KeyboardControlsMenuCursor,&g_KeyboardControlsMenuCursor)
      ;
    }
    if (value2 == 0) {
      if ((value & 2) != 0) {
        g_KeyboardControlsMenuCursor =
             SelectNextEnabledMenuItem(g_KeyboardControlsMenuCursor,&g_KeyboardControlsMenuCursor);
      }
      if ((value & 0x20) != 0) {
        g_KeyboardControlsMenuState = 0x57;
      }
    }
    if (g_PendingOptionsMenuId != 0) {
      g_KeyboardControlsMenuState = 0x57;
    }
    switch((int)(short)(&g_KeyboardControlsMenuRebindState)[g_KeyboardControlsMenuCursor * 4]) {
    case 0x1e:
      if ((value2 == 0) && ((value & 0x1c) != 0)) {
        g_KeyboardBindingSetIndex = (uint)(g_KeyboardBindingSetIndex == 0);
      }
      break;
    case 0x1f:
    case 0x20:
    case 0x21:
    case 0x22:
    case 0x23:
    case 0x24:
    case 0x25:
    case 0x26:
    case 0x27:
    case 0x28:
    case 0x29:
    case 0x2a:
    case 0x2b:
      if ((value2 == 0) && ((value & 0x1c) != 0)) {
        g_KeyboardControlsMenuState = 0x1d;
        _g_PendingKeyboardBindingActionId =
             (int)(short)(&g_KeyboardControlsMenuRebindState)[g_KeyboardControlsMenuCursor * 4];
      }
      break;
    case 0x2c:
      if ((value2 == 0) && ((value & 0x10) != 0)) {
        if (g_KeyboardControlsMenuCursor == (undefined *)0x0) goto LAB_0049ef20;
        dataCursor2 = &g_KeyboardControlsMenuCursor;
        do {
          switch(*(undefined2 *)(dataCursor2 + 1)) {
          case 0x1f:
            dataCursor3 = &g_CfgKeyboardBindingUp;
            value3 = g_DefaultKeyboardBindingUp;
            break;
          case 0x20:
            dataCursor3 = &g_CfgKeyboardBindingDown;
            value3 = g_DefaultKeyboardBindingDown;
            break;
          case 0x21:
            dataCursor3 = &g_CfgKeyboardBindingLeft;
            value3 = g_DefaultKeyboardBindingLeft;
            break;
          case 0x22:
            dataCursor3 = &g_CfgKeyboardBindingRight;
            value3 = g_DefaultKeyboardBindingRight;
            break;
          case 0x23:
            dataCursor3 = &g_CfgKeyboardBindingAction0;
            value3 = g_DefaultKeyboardBindingAction0;
            break;
          case 0x24:
            dataCursor3 = &g_CfgKeyboardBindingAction1;
            value3 = g_DefaultKeyboardBindingAction1;
            break;
          case 0x25:
            dataCursor3 = &g_CfgKeyboardBindingAction2;
            value3 = g_DefaultKeyboardBindingAction2;
            break;
          case 0x26:
            dataCursor3 = &g_CfgKeyboardBindingAction3;
            value3 = g_DefaultKeyboardBindingAction3;
            break;
          case 0x27:
            dataCursor3 = &g_CfgKeyboardBindingAction4;
            value3 = g_DefaultKeyboardBindingAction4;
            break;
          case 0x28:
            dataCursor3 = &g_CfgKeyboardBindingAction5;
            value3 = g_DefaultKeyboardBindingAction5;
            break;
          case 0x29:
            dataCursor3 = &g_CfgKeyboardBindingAction6;
            value3 = g_DefaultKeyboardBindingAction6;
            break;
          case 0x2a:
            dataCursor3 = &g_CfgKeyboardBindingAction7;
            value3 = g_DefaultKeyboardBindingAction7;
            break;
          case 0x2b:
            dataCursor3 = &g_CfgKeyboardBindingAction8;
            value3 = g_DefaultKeyboardBindingAction8;
            break;
          default:
            goto switchD_0049eba2_default;
          }
          AssignUniqueKeyBinding(dataCursor3,value3);
switchD_0049eba2_default:
          dataCursor = dataCursor2 + 2;
          dataCursor2 = dataCursor2 + 2;
        } while (*dataCursor != (undefined *)0x0);
      }
      break;
    case 0x57:
      if (value2 == 0) {
        value = value & 0x10;
        goto LAB_0049ed9b;
      }
    }
    break;
  case 0x1d:
    value2 = GetUserInputInMenuAndProcessSound(1);
    value = g_PendingOptionsMenuId;
    if ((value2 & 0x8000) == 0) {
      menuIndex2 = 0;
      if ((value2 & 0x40) == 0) {
        dataCursor2 = &g_KeyboardControlsMenuOptionTable;
        do {
          if ((*dataCursor2 != (undefined *)0x0) && (menuIndex = IsControlBindingPressed(menuIndex2), menuIndex != 0)
             ) {
            value = g_PendingOptionsMenuId;
            if (menuIndex2 < 0x100) goto LAB_0049ecff;
            break;
          }
          dataCursor2 = dataCursor2 + 1;
          menuIndex2 = menuIndex2 + 1;
          value = g_PendingOptionsMenuId;
        } while ((int)dataCursor2 < 0x516b70);
        goto LAB_0049ed9b;
      }
LAB_0049ecff:
      switch((&g_KeyboardControlsMenuRebindState)[g_KeyboardControlsMenuCursor * 4]) {
      case 0x1f:
        dataCursor3 = &g_CfgKeyboardBindingUp;
        break;
      case 0x20:
        dataCursor3 = &g_CfgKeyboardBindingDown;
        break;
      case 0x21:
        dataCursor3 = &g_CfgKeyboardBindingLeft;
        break;
      case 0x22:
        dataCursor3 = &g_CfgKeyboardBindingRight;
        break;
      case 0x23:
        dataCursor3 = &g_CfgKeyboardBindingAction0;
        break;
      case 0x24:
        dataCursor3 = &g_CfgKeyboardBindingAction1;
        break;
      case 0x25:
        dataCursor3 = &g_CfgKeyboardBindingAction2;
        break;
      case 0x26:
        dataCursor3 = &g_CfgKeyboardBindingAction3;
        break;
      case 0x27:
        dataCursor3 = &g_CfgKeyboardBindingAction4;
        break;
      case 0x28:
        dataCursor3 = &g_CfgKeyboardBindingAction5;
        break;
      case 0x29:
        dataCursor3 = &g_CfgKeyboardBindingAction6;
        break;
      case 0x2a:
        dataCursor3 = &g_CfgKeyboardBindingAction7;
        break;
      case 0x2b:
        dataCursor3 = &g_CfgKeyboardBindingAction8;
        break;
      default:
        goto switchD_0049ed15_default;
      }
      AssignUniqueKeyBinding(dataCursor3,menuIndex2);
switchD_0049ed15_default:
      g_KeyboardControlsMenuState = 2;
      value = g_PendingOptionsMenuId;
    }
LAB_0049ed9b:
    if (value != 0) {
      g_KeyboardControlsMenuState = 0x57;
    }
    break;
  case 0x57:
    g_KeyboardControlsMenuState = 0;
  }
  if (g_KeyboardControlsMenuCursor != (undefined *)0x0) {
    dataCursor2 = &g_KeyboardControlsMenuCursor;
    do {
      switch(*(undefined2 *)(dataCursor2 + 1)) {
      case 0x1e:
        LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_KeyboardBindingSetIndex + 1);
        SetOptionsMenuEntryValueText(dataCursor2,&DAT_00723d38);
        break;
      case 0x1f:
        menuIndex2 = g_CfgKeyboardBindingUp;
        goto LAB_0049eeda;
      case 0x20:
        SetOptionsMenuEntryValueText
                  (dataCursor2,(&g_KeyboardControlsMenuOptionTable)[g_CfgKeyboardBindingDown]);
        break;
      case 0x21:
        SetOptionsMenuEntryValueText
                  (dataCursor2,(&g_KeyboardControlsMenuOptionTable)[g_CfgKeyboardBindingLeft]);
        break;
      case 0x22:
        menuIndex2 = g_CfgKeyboardBindingRight;
        goto LAB_0049eeda;
      case 0x23:
        SetOptionsMenuEntryValueText
                  (dataCursor2,(&g_KeyboardControlsMenuOptionTable)[g_CfgKeyboardBindingAction0]);
        break;
      case 0x24:
        SetOptionsMenuEntryValueText
                  (dataCursor2,(&g_KeyboardControlsMenuOptionTable)[g_CfgKeyboardBindingAction1]);
        break;
      case 0x25:
        menuIndex2 = g_CfgKeyboardBindingAction2;
        goto LAB_0049eeda;
      case 0x26:
        SetOptionsMenuEntryValueText
                  (dataCursor2,(&g_KeyboardControlsMenuOptionTable)[g_CfgKeyboardBindingAction3]);
        break;
      case 0x27:
        SetOptionsMenuEntryValueText
                  (dataCursor2,(&g_KeyboardControlsMenuOptionTable)[g_CfgKeyboardBindingAction4]);
        break;
      case 0x28:
        menuIndex2 = g_CfgKeyboardBindingAction5;
        goto LAB_0049eeda;
      case 0x29:
        SetOptionsMenuEntryValueText
                  (dataCursor2,(&g_KeyboardControlsMenuOptionTable)[g_CfgKeyboardBindingAction6]);
        break;
      case 0x2a:
        SetOptionsMenuEntryValueText
                  (dataCursor2,(&g_KeyboardControlsMenuOptionTable)[g_CfgKeyboardBindingAction7]);
        break;
      case 0x2b:
        menuIndex2 = g_CfgKeyboardBindingAction8;
LAB_0049eeda:
        SetOptionsMenuEntryValueText(dataCursor2,(&g_KeyboardControlsMenuOptionTable)[menuIndex2]);
      }
      dataCursor = dataCursor2 + 2;
      dataCursor2 = dataCursor2 + 2;
    } while (*dataCursor != (undefined *)0x0);
  }
LAB_0049ef20:
  if (g_KeyboardControlsMenuState == 0x1d) {
    SetOptionsMenuEntryValueText
              (&g_KeyboardControlsMenuCursor + g_KeyboardControlsMenuCursor * 2,
               s_PRESS_KEY__005175a0);
  }
  DrawOptionsMenu(&g_KeyboardControlsMenuCursor,g_KeyboardControlsMenuCursor);
  return g_KeyboardControlsMenuState != 0;
}

