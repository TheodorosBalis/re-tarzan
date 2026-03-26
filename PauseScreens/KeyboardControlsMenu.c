// Address: 0x0049EA50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool KeyboardControlsMenu(void)

{
  undefined **ppuVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined **ppuVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  if ((DAT_00724138 & 1) == 0) {
    DAT_00724138 = DAT_00724138 | 1;
    g_KeyboardControlsMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_KEYBOARD_005165b8);
  }
  switch(g_KeyboardControlsMenuState) {
  case 0:
    g_KeyboardControlsMenuState = 2;
    break;
  case 2:
    uVar2 = GetUserInputInMenuAndProcessSound(1);
    uVar3 = uVar2 & 0x8000;
    if ((uVar3 == 0) && ((uVar2 & 1) != 0)) {
      g_KeyboardControlsMenuCursor =
           SelectPreviousEnabledMenuItem(g_KeyboardControlsMenuCursor,&PTR_s_KEYBOARD_005165b8);
    }
    if (uVar3 == 0) {
      if ((uVar2 & 2) != 0) {
        g_KeyboardControlsMenuCursor =
             SelectNextEnabledMenuItem(g_KeyboardControlsMenuCursor,&PTR_s_KEYBOARD_005165b8);
      }
      if ((uVar2 & 0x20) != 0) {
        g_KeyboardControlsMenuState = 0x57;
      }
    }
    if (g_PendingOptionsMenuId != 0) {
      g_KeyboardControlsMenuState = 0x57;
    }
    switch((int)(short)(&DAT_005165bc)[g_KeyboardControlsMenuCursor * 4]) {
    case 0x1e:
      if ((uVar3 == 0) && ((uVar2 & 0x1c) != 0)) {
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
      if ((uVar3 == 0) && ((uVar2 & 0x1c) != 0)) {
        g_KeyboardControlsMenuState = 0x1d;
        _g_PendingKeyboardBindingActionId =
             (int)(short)(&DAT_005165bc)[g_KeyboardControlsMenuCursor * 4];
      }
      break;
    case 0x2c:
      if ((uVar3 == 0) && ((uVar2 & 0x10) != 0)) {
        if (PTR_s_KEYBOARD_005165b8 == (undefined *)0x0) goto LAB_0049ef20;
        ppuVar6 = &PTR_s_KEYBOARD_005165b8;
        do {
          switch(*(undefined2 *)(ppuVar6 + 1)) {
          case 0x1f:
            puVar7 = &DAT_0053a360;
            uVar8 = DAT_00515710;
            break;
          case 0x20:
            puVar7 = &DAT_0053a364;
            uVar8 = DAT_00515714;
            break;
          case 0x21:
            puVar7 = &DAT_0053a368;
            uVar8 = DAT_00515718;
            break;
          case 0x22:
            puVar7 = &DAT_0053a36c;
            uVar8 = DAT_0051571c;
            break;
          case 0x23:
            puVar7 = &DAT_0053a370;
            uVar8 = DAT_00515720;
            break;
          case 0x24:
            puVar7 = &DAT_0053a374;
            uVar8 = DAT_00515724;
            break;
          case 0x25:
            puVar7 = &DAT_0053a378;
            uVar8 = DAT_00515728;
            break;
          case 0x26:
            puVar7 = &DAT_0053a37c;
            uVar8 = DAT_0051572c;
            break;
          case 0x27:
            puVar7 = &DAT_0053a380;
            uVar8 = DAT_00515730;
            break;
          case 0x28:
            puVar7 = &DAT_0053a384;
            uVar8 = DAT_00515734;
            break;
          case 0x29:
            puVar7 = &DAT_0053a388;
            uVar8 = DAT_00515738;
            break;
          case 0x2a:
            puVar7 = &DAT_0053a38c;
            uVar8 = DAT_0051573c;
            break;
          case 0x2b:
            puVar7 = &DAT_0053a390;
            uVar8 = DAT_00515740;
            break;
          default:
            goto switchD_0049eba2_default;
          }
          AssignUniqueKeyBinding(puVar7,uVar8);
switchD_0049eba2_default:
          ppuVar1 = ppuVar6 + 2;
          ppuVar6 = ppuVar6 + 2;
        } while (*ppuVar1 != (undefined *)0x0);
      }
      break;
    case 0x57:
      if (uVar3 == 0) {
        uVar2 = uVar2 & 0x10;
        goto LAB_0049ed9b;
      }
    }
    break;
  case 0x1d:
    uVar3 = GetUserInputInMenuAndProcessSound(1);
    uVar2 = g_PendingOptionsMenuId;
    if ((uVar3 & 0x8000) == 0) {
      iVar5 = 0;
      if ((uVar3 & 0x40) == 0) {
        ppuVar6 = &PTR_DAT_00516770;
        do {
          if ((*ppuVar6 != (undefined *)0x0) && (iVar4 = IsControlBindingPressed(iVar5), iVar4 != 0)
             ) {
            uVar2 = g_PendingOptionsMenuId;
            if (iVar5 < 0x100) goto LAB_0049ecff;
            break;
          }
          ppuVar6 = ppuVar6 + 1;
          iVar5 = iVar5 + 1;
          uVar2 = g_PendingOptionsMenuId;
        } while ((int)ppuVar6 < 0x516b70);
        goto LAB_0049ed9b;
      }
LAB_0049ecff:
      switch((&DAT_005165bc)[g_KeyboardControlsMenuCursor * 4]) {
      case 0x1f:
        puVar7 = &DAT_0053a360;
        break;
      case 0x20:
        puVar7 = &DAT_0053a364;
        break;
      case 0x21:
        puVar7 = &DAT_0053a368;
        break;
      case 0x22:
        puVar7 = &DAT_0053a36c;
        break;
      case 0x23:
        puVar7 = &DAT_0053a370;
        break;
      case 0x24:
        puVar7 = &DAT_0053a374;
        break;
      case 0x25:
        puVar7 = &DAT_0053a378;
        break;
      case 0x26:
        puVar7 = &DAT_0053a37c;
        break;
      case 0x27:
        puVar7 = &DAT_0053a380;
        break;
      case 0x28:
        puVar7 = &DAT_0053a384;
        break;
      case 0x29:
        puVar7 = &DAT_0053a388;
        break;
      case 0x2a:
        puVar7 = &DAT_0053a38c;
        break;
      case 0x2b:
        puVar7 = &DAT_0053a390;
        break;
      default:
        goto switchD_0049ed15_default;
      }
      AssignUniqueKeyBinding(puVar7,iVar5);
switchD_0049ed15_default:
      g_KeyboardControlsMenuState = 2;
      uVar2 = g_PendingOptionsMenuId;
    }
LAB_0049ed9b:
    if (uVar2 != 0) {
      g_KeyboardControlsMenuState = 0x57;
    }
    break;
  case 0x57:
    g_KeyboardControlsMenuState = 0;
  }
  if (PTR_s_KEYBOARD_005165b8 != (undefined *)0x0) {
    ppuVar6 = &PTR_s_KEYBOARD_005165b8;
    do {
      switch(*(undefined2 *)(ppuVar6 + 1)) {
      case 0x1e:
        DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,g_KeyboardBindingSetIndex + 1);
        SetOptionsMenuEntryValueText(ppuVar6,&DAT_00723d38);
        break;
      case 0x1f:
        iVar5 = DAT_0053a360;
        goto LAB_0049eeda;
      case 0x20:
        SetOptionsMenuEntryValueText(ppuVar6,(&PTR_DAT_00516770)[DAT_0053a364]);
        break;
      case 0x21:
        SetOptionsMenuEntryValueText(ppuVar6,(&PTR_DAT_00516770)[DAT_0053a368]);
        break;
      case 0x22:
        iVar5 = DAT_0053a36c;
        goto LAB_0049eeda;
      case 0x23:
        SetOptionsMenuEntryValueText(ppuVar6,(&PTR_DAT_00516770)[DAT_0053a370]);
        break;
      case 0x24:
        SetOptionsMenuEntryValueText(ppuVar6,(&PTR_DAT_00516770)[DAT_0053a374]);
        break;
      case 0x25:
        iVar5 = DAT_0053a378;
        goto LAB_0049eeda;
      case 0x26:
        SetOptionsMenuEntryValueText(ppuVar6,(&PTR_DAT_00516770)[DAT_0053a37c]);
        break;
      case 0x27:
        SetOptionsMenuEntryValueText(ppuVar6,(&PTR_DAT_00516770)[DAT_0053a380]);
        break;
      case 0x28:
        iVar5 = DAT_0053a384;
        goto LAB_0049eeda;
      case 0x29:
        SetOptionsMenuEntryValueText(ppuVar6,(&PTR_DAT_00516770)[DAT_0053a388]);
        break;
      case 0x2a:
        SetOptionsMenuEntryValueText(ppuVar6,(&PTR_DAT_00516770)[DAT_0053a38c]);
        break;
      case 0x2b:
        iVar5 = DAT_0053a390;
LAB_0049eeda:
        SetOptionsMenuEntryValueText(ppuVar6,(&PTR_DAT_00516770)[iVar5]);
      }
      ppuVar1 = ppuVar6 + 2;
      ppuVar6 = ppuVar6 + 2;
    } while (*ppuVar1 != (undefined *)0x0);
  }
LAB_0049ef20:
  if (g_KeyboardControlsMenuState == 0x1d) {
    SetOptionsMenuEntryValueText
              (&PTR_s_KEYBOARD_005165b8 + g_KeyboardControlsMenuCursor * 2,s_PRESS_KEY__005175a0);
  }
  DrawOptionsMenu(&PTR_s_KEYBOARD_005165b8,g_KeyboardControlsMenuCursor);
  return g_KeyboardControlsMenuState != 0;
}


