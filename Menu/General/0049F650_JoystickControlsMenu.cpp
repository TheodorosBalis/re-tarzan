#include "tarzan_ghidra_types.hpp"

// Address: 0x0049F650
// Label: JoystickControlsMenu
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Type propagation algorithm not settling */

bool JoystickControlsMenu(void)

{
  undefined **dataCursor;
  short shortValue;
  bool flagByte;
  int menuIndex2;
  uint value2;
  uint value3;
  uint value4;
  int menuIndex3;
  undefined *dataCursor3;
  int menuIndex;
  undefined **dataCursor2;
  uint value;
  
  if ((g_JoystickControlsMenuInitializedFlag & 1) == 0) {
    g_JoystickControlsMenuInitializedFlag = g_JoystickControlsMenuInitializedFlag | 1;
    g_JoystickControlsMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&g_JoystickControlsMenuEntryTable);
  }
  menuIndex = 0;
  menuIndex2 = g_SelectedJoystickIndex;
  if (g_JoystickControlsMenuState == 0) {
    g_JoystickControlsMenuState = 2;
  }
  else if (g_JoystickControlsMenuState == 2) {
    shortValue = (&g_JoystickControlsMenu_Global_00516654)[g_JoystickControlsMenuCursor * 4];
    if ((((((shortValue == 0x2f) || (shortValue == 0x30)) || (shortValue == 0x31)) ||
         ((shortValue == 0x32 || (shortValue == 0x33)))) || (shortValue == 0x34)) ||
       (((shortValue == 0x35 || (shortValue == 0x36)) || (shortValue == 0x37)))) {
      flagByte = true;
    }
    else {
      flagByte = false;
    }
    value2 = GetUserInputInMenuAndProcessSound(!flagByte);
    value = value2 & 0x8000;
    if ((value == 0) && ((value2 & 1) != 0)) {
      g_JoystickControlsMenuCursor =
           SelectPreviousEnabledMenuItem
                     (g_JoystickControlsMenuCursor,&g_JoystickControlsMenuEntryTable);
    }
    if ((value == 0) && ((value2 & 2) != 0)) {
      g_JoystickControlsMenuCursor =
           SelectNextEnabledMenuItem(g_JoystickControlsMenuCursor,&g_JoystickControlsMenuEntryTable)
      ;
    }
    if ((value == 0) && ((value2 & 0x20) != 0)) {
      g_JoystickControlsMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_JoystickControlsMenuState = 0x57;
    }
    if (flagByte) {
      value3 = PollJoystickButtonEdgeFlags(g_SelectedJoystickIndex);
      value4 = value3 & 0xfffffff;
      if (value4 == 0) {
        menuIndex = 0;
      }
      else {
        for (menuIndex = 0; ((value3 & 1) == 0 && (menuIndex < 0x1c)); menuIndex = menuIndex + 1) {
          value4 = (int)value4 >> 1;
          value3 = value4;
        }
        menuIndex = menuIndex + 1;
      }
    }
    menuIndex3 = g_SelectedJoystickIndex;
    menuIndex2 = g_SelectedJoystickIndex;
    switch((&g_JoystickControlsMenu_Global_00516654)[g_JoystickControlsMenuCursor * 4]) {
    case 0x2d:
      if ((value == 0) && ((value2 & 0x1c) != 0)) {
        g_SelectedJoystickIndex = -1;
        menuIndex3 = menuIndex3 + 1;
        if (0xf < menuIndex3) {
          menuIndex3 = 0;
        }
        do {
          menuIndex2 = menuIndex3;
          if ((&g_JoystickButtonCountByIndex)[menuIndex3] != '\0') break;
          menuIndex3 = menuIndex3 + 1;
          menuIndex2 = g_SelectedJoystickIndex;
        } while (menuIndex3 < 0x10);
      }
      break;
    case 0x2e:
      if ((value == 0) && ((value2 & 0x1c) != 0)) {
        g_JoystickBindingColumnIndex = (uint)(g_JoystickBindingColumnIndex == 0);
      }
      break;
    case 0x2f:
      if ((menuIndex != 0) ||
         (((value == 0 && ((value2 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        AssignUniqueJoystickBinding
                  (&g_CfgJoystickBindingAction0,menuIndex,g_JoystickBindingColumnIndex);
        menuIndex2 = g_SelectedJoystickIndex;
      }
      break;
    case 0x30:
      if ((menuIndex != 0) ||
         (((value == 0 && ((value2 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        AssignUniqueJoystickBinding
                  (&g_CfgJoystickBindingAction1,menuIndex,g_JoystickBindingColumnIndex);
        menuIndex2 = g_SelectedJoystickIndex;
      }
      break;
    case 0x31:
      if ((menuIndex != 0) ||
         (((value == 0 && ((value2 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        AssignUniqueJoystickBinding
                  (&g_CfgJoystickBindingAction2,menuIndex,g_JoystickBindingColumnIndex);
        menuIndex2 = g_SelectedJoystickIndex;
      }
      break;
    case 0x32:
      if ((menuIndex != 0) ||
         (((value == 0 && ((value2 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        AssignUniqueJoystickBinding
                  (&g_CfgJoystickBindingAction3,menuIndex,g_JoystickBindingColumnIndex);
        menuIndex2 = g_SelectedJoystickIndex;
      }
      break;
    case 0x33:
      if ((menuIndex != 0) ||
         (((value == 0 && ((value2 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        AssignUniqueJoystickBinding
                  (&g_CfgJoystickBindingAction4,menuIndex,g_JoystickBindingColumnIndex);
        menuIndex2 = g_SelectedJoystickIndex;
      }
      break;
    case 0x34:
      if ((menuIndex != 0) ||
         (((value == 0 && ((value2 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        AssignUniqueJoystickBinding
                  (&g_CfgJoystickBindingAction5,menuIndex,g_JoystickBindingColumnIndex);
        menuIndex2 = g_SelectedJoystickIndex;
      }
      break;
    case 0x35:
      if ((menuIndex != 0) ||
         (((value == 0 && ((value2 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        AssignUniqueJoystickBinding
                  (&g_CfgJoystickBindingAction6,menuIndex,g_JoystickBindingColumnIndex);
        menuIndex2 = g_SelectedJoystickIndex;
      }
      break;
    case 0x36:
      if ((menuIndex != 0) ||
         (((value == 0 && ((value2 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        AssignUniqueJoystickBinding
                  (&g_CfgJoystickBindingAction7,menuIndex,g_JoystickBindingColumnIndex);
        menuIndex2 = g_SelectedJoystickIndex;
      }
      break;
    case 0x37:
      if ((menuIndex != 0) ||
         (((value == 0 && ((value2 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        AssignUniqueJoystickBinding
                  (&g_CfgJoystickBindingAction8,menuIndex,g_JoystickBindingColumnIndex);
        menuIndex2 = g_SelectedJoystickIndex;
      }
      break;
    case 0x57:
      if ((value == 0) && ((value2 & 0x10) != 0)) {
        g_JoystickControlsMenuState = 0x57;
      }
    }
  }
  else if (g_JoystickControlsMenuState == 0x57) {
    g_JoystickControlsMenuState = 0;
  }
  g_SelectedJoystickIndex = menuIndex2;
  if (g_JoystickControlsMenuEntryTable != (undefined *)0x0) {
    dataCursor2 = &g_JoystickControlsMenuEntryTable;
    do {
      switch(*(undefined2 *)(dataCursor2 + 1)) {
      case 0x2d:
        if (g_SelectedJoystickIndex == -1) {
          LoadSFX(&DAT_00723d38,&DAT_00516d88);
          dataCursor3 = &DAT_00723d38;
        }
        else {
          LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_SelectedJoystickIndex + 1);
          dataCursor3 = &DAT_00723d38;
        }
        goto LAB_0049fcfa;
      case 0x2e:
        LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_JoystickBindingColumnIndex + 1);
        SetOptionsMenuEntryValueText(dataCursor2,&DAT_00723d38);
        goto switchD_0049fa81_default;
      case 0x2f:
        LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_CfgJoystickBindingAction0);
        if ((g_CfgJoystickBindingAction0 != 0) &&
           (dataCursor3 = &DAT_00723d38, g_SelectedJoystickIndex != -1)) goto LAB_0049fcfa;
        goto LAB_0049fcf4;
      case 0x30:
        LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_CfgJoystickBindingAction1);
        menuIndex = g_CfgJoystickBindingAction1;
        break;
      case 0x31:
        LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_CfgJoystickBindingAction2);
        menuIndex = g_CfgJoystickBindingAction2;
        break;
      case 0x32:
        LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_CfgJoystickBindingAction3);
        menuIndex = g_CfgJoystickBindingAction3;
        break;
      case 0x33:
        LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_CfgJoystickBindingAction4);
        menuIndex = g_CfgJoystickBindingAction4;
        break;
      case 0x34:
        LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_CfgJoystickBindingAction5);
        menuIndex = g_CfgJoystickBindingAction5;
        break;
      case 0x35:
        LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_CfgJoystickBindingAction6);
        menuIndex = g_CfgJoystickBindingAction6;
        break;
      case 0x36:
        LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_CfgJoystickBindingAction7);
        menuIndex = g_CfgJoystickBindingAction7;
        break;
      case 0x37:
        LoadSFX(&DAT_00723d38,&PTR_DAT_005175ac,g_CfgJoystickBindingAction8);
        menuIndex = g_CfgJoystickBindingAction8;
        break;
      default:
        goto switchD_0049fa81_default;
      }
      if ((menuIndex == 0) || (dataCursor3 = &DAT_00723d38, g_SelectedJoystickIndex == -1)) {
LAB_0049fcf4:
        dataCursor3 = &DAT_00516d88;
      }
LAB_0049fcfa:
      SetOptionsMenuEntryValueText(dataCursor2,dataCursor3);
switchD_0049fa81_default:
      dataCursor = dataCursor2 + 2;
      dataCursor2 = dataCursor2 + 2;
    } while (*dataCursor != (undefined *)0x0);
  }
  DrawOptionsMenu(&g_JoystickControlsMenuEntryTable,g_JoystickControlsMenuCursor);
  return g_JoystickControlsMenuState != 0;
}

