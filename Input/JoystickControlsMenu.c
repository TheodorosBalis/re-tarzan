// Address: 0x0049F650

/* WARNING: Type propagation algorithm not settling */

bool JoystickControlsMenu(void)

{
  undefined **ppuVar1;
  short sVar2;
  bool bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined *puVar9;
  int iVar10;
  undefined **ppuVar11;
  uint uVar12;
  
  if ((DAT_00724179 & 1) == 0) {
    DAT_00724179 = DAT_00724179 | 1;
    g_JoystickControlsMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_JOYSTICK_00516650);
  }
  iVar10 = 0;
  iVar4 = g_SelectedJoystickIndex;
  if (g_JoystickControlsMenuState == 0) {
    g_JoystickControlsMenuState = 2;
  }
  else if (g_JoystickControlsMenuState == 2) {
    sVar2 = (&DAT_00516654)[g_JoystickControlsMenuCursor * 4];
    if ((((((sVar2 == 0x2f) || (sVar2 == 0x30)) || (sVar2 == 0x31)) ||
         ((sVar2 == 0x32 || (sVar2 == 0x33)))) || (sVar2 == 0x34)) ||
       (((sVar2 == 0x35 || (sVar2 == 0x36)) || (sVar2 == 0x37)))) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    uVar5 = GetUserInputInMenuAndProcessSound(!bVar3);
    uVar12 = uVar5 & 0x8000;
    if ((uVar12 == 0) && ((uVar5 & 1) != 0)) {
      g_JoystickControlsMenuCursor =
           SelectPreviousEnabledMenuItem(g_JoystickControlsMenuCursor,&PTR_s_JOYSTICK_00516650);
    }
    if ((uVar12 == 0) && ((uVar5 & 2) != 0)) {
      g_JoystickControlsMenuCursor =
           SelectNextEnabledMenuItem(g_JoystickControlsMenuCursor,&PTR_s_JOYSTICK_00516650);
    }
    if ((uVar12 == 0) && ((uVar5 & 0x20) != 0)) {
      g_JoystickControlsMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_JoystickControlsMenuState = 0x57;
    }
    if (bVar3) {
      uVar6 = PollJoystickButtonEdgeFlags(g_SelectedJoystickIndex);
      uVar7 = uVar6 & 0xfffffff;
      if (uVar7 == 0) {
        iVar10 = 0;
      }
      else {
        for (iVar10 = 0; ((uVar6 & 1) == 0 && (iVar10 < 0x1c)); iVar10 = iVar10 + 1) {
          uVar7 = (int)uVar7 >> 1;
          uVar6 = uVar7;
        }
        iVar10 = iVar10 + 1;
      }
    }
    iVar8 = g_SelectedJoystickIndex;
    iVar4 = g_SelectedJoystickIndex;
    switch((&DAT_00516654)[g_JoystickControlsMenuCursor * 4]) {
    case 0x2d:
      if ((uVar12 == 0) && ((uVar5 & 0x1c) != 0)) {
        g_SelectedJoystickIndex = -1;
        iVar8 = iVar8 + 1;
        if (0xf < iVar8) {
          iVar8 = 0;
        }
        do {
          iVar4 = iVar8;
          if ((&DAT_00723cd8)[iVar8] != '\0') break;
          iVar8 = iVar8 + 1;
          iVar4 = g_SelectedJoystickIndex;
        } while (iVar8 < 0x10);
      }
      break;
    case 0x2e:
      if ((uVar12 == 0) && ((uVar5 & 0x1c) != 0)) {
        g_JoystickBindingColumnIndex = (uint)(g_JoystickBindingColumnIndex == 0);
      }
      break;
    case 0x2f:
      if ((iVar10 != 0) ||
         (((uVar12 == 0 && ((uVar5 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        FUN_0049fdd0(&DAT_0053a394,iVar10,g_JoystickBindingColumnIndex);
        iVar4 = g_SelectedJoystickIndex;
      }
      break;
    case 0x30:
      if ((iVar10 != 0) ||
         (((uVar12 == 0 && ((uVar5 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        FUN_0049fdd0(&DAT_0053a398,iVar10,g_JoystickBindingColumnIndex);
        iVar4 = g_SelectedJoystickIndex;
      }
      break;
    case 0x31:
      if ((iVar10 != 0) ||
         (((uVar12 == 0 && ((uVar5 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        FUN_0049fdd0(&DAT_0053a39c,iVar10,g_JoystickBindingColumnIndex);
        iVar4 = g_SelectedJoystickIndex;
      }
      break;
    case 0x32:
      if ((iVar10 != 0) ||
         (((uVar12 == 0 && ((uVar5 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        FUN_0049fdd0(&DAT_0053a3a0,iVar10,g_JoystickBindingColumnIndex);
        iVar4 = g_SelectedJoystickIndex;
      }
      break;
    case 0x33:
      if ((iVar10 != 0) ||
         (((uVar12 == 0 && ((uVar5 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        FUN_0049fdd0(&DAT_0053a3a4,iVar10,g_JoystickBindingColumnIndex);
        iVar4 = g_SelectedJoystickIndex;
      }
      break;
    case 0x34:
      if ((iVar10 != 0) ||
         (((uVar12 == 0 && ((uVar5 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        FUN_0049fdd0(&DAT_0053a3a8,iVar10,g_JoystickBindingColumnIndex);
        iVar4 = g_SelectedJoystickIndex;
      }
      break;
    case 0x35:
      if ((iVar10 != 0) ||
         (((uVar12 == 0 && ((uVar5 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        FUN_0049fdd0(&DAT_0053a3ac,iVar10,g_JoystickBindingColumnIndex);
        iVar4 = g_SelectedJoystickIndex;
      }
      break;
    case 0x36:
      if ((iVar10 != 0) ||
         (((uVar12 == 0 && ((uVar5 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        FUN_0049fdd0(&DAT_0053a3b0,iVar10,g_JoystickBindingColumnIndex);
        iVar4 = g_SelectedJoystickIndex;
      }
      break;
    case 0x37:
      if ((iVar10 != 0) ||
         (((uVar12 == 0 && ((uVar5 & 0x1c) != 0)) && (g_SelectedJoystickIndex != -1)))) {
        FUN_0049fdd0(&DAT_0053a3b4,iVar10,g_JoystickBindingColumnIndex);
        iVar4 = g_SelectedJoystickIndex;
      }
      break;
    case 0x57:
      if ((uVar12 == 0) && ((uVar5 & 0x10) != 0)) {
        g_JoystickControlsMenuState = 0x57;
      }
    }
  }
  else if (g_JoystickControlsMenuState == 0x57) {
    g_JoystickControlsMenuState = 0;
  }
  g_SelectedJoystickIndex = iVar4;
  if (PTR_s_JOYSTICK_00516650 != (undefined *)0x0) {
    ppuVar11 = &PTR_s_JOYSTICK_00516650;
    do {
      switch(*(undefined2 *)(ppuVar11 + 1)) {
      case 0x2d:
        if (g_SelectedJoystickIndex == -1) {
          DrawGraphicsTextinMem_2(&DAT_00723d38,&DAT_00516d88);
          puVar9 = &DAT_00723d38;
        }
        else {
          DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,g_SelectedJoystickIndex + 1);
          puVar9 = &DAT_00723d38;
        }
        goto LAB_0049fcfa;
      case 0x2e:
        DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,g_JoystickBindingColumnIndex + 1);
        SetOptionsMenuEntryValueText(ppuVar11,&DAT_00723d38);
        goto switchD_0049fa81_default;
      case 0x2f:
        DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,DAT_0053a394);
        if ((DAT_0053a394 != 0) && (puVar9 = &DAT_00723d38, g_SelectedJoystickIndex != -1))
        goto LAB_0049fcfa;
        goto LAB_0049fcf4;
      case 0x30:
        DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,DAT_0053a398);
        iVar10 = DAT_0053a398;
        break;
      case 0x31:
        DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,DAT_0053a39c);
        iVar10 = DAT_0053a39c;
        break;
      case 0x32:
        DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,DAT_0053a3a0);
        iVar10 = DAT_0053a3a0;
        break;
      case 0x33:
        DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,DAT_0053a3a4);
        iVar10 = DAT_0053a3a4;
        break;
      case 0x34:
        DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,DAT_0053a3a8);
        iVar10 = DAT_0053a3a8;
        break;
      case 0x35:
        DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,DAT_0053a3ac);
        iVar10 = DAT_0053a3ac;
        break;
      case 0x36:
        DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,DAT_0053a3b0);
        iVar10 = DAT_0053a3b0;
        break;
      case 0x37:
        DrawGraphicsTextinMem_2(&DAT_00723d38,&PTR_DAT_005175ac,DAT_0053a3b4);
        iVar10 = DAT_0053a3b4;
        break;
      default:
        goto switchD_0049fa81_default;
      }
      if ((iVar10 == 0) || (puVar9 = &DAT_00723d38, g_SelectedJoystickIndex == -1)) {
LAB_0049fcf4:
        puVar9 = &DAT_00516d88;
      }
LAB_0049fcfa:
      SetOptionsMenuEntryValueText(ppuVar11,puVar9);
switchD_0049fa81_default:
      ppuVar1 = ppuVar11 + 2;
      ppuVar11 = ppuVar11 + 2;
    } while (*ppuVar1 != (undefined *)0x0);
  }
  DrawOptionsMenu(&PTR_s_JOYSTICK_00516650,g_JoystickControlsMenuCursor);
  return g_JoystickControlsMenuState != 0;
}


