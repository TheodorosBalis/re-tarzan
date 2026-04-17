// Address: 0x004A03D0

bool GraphicsOptionsMenu(void)

{
  undefined **ppuVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined **ppuVar6;
  
  if ((DAT_0072413a & 1) == 0) {
    DAT_0072413a = DAT_0072413a | 1;
    g_GraphicsOptionsMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_GRAPHICS_00516580);
  }
  if (g_GraphicsOptionsMenuState == 0) {
    g_PendingGraphicsModeSelection = CurrentGraphicsMode();
    g_GraphicsOptionsMenuState = 2;
  }
  else if (g_GraphicsOptionsMenuState == 2) {
    uVar3 = GetUserInputInMenuAndProcessSound(1);
    uVar5 = uVar3 & 0x8000;
    if ((uVar5 == 0) && ((uVar3 & 1) != 0)) {
      g_GraphicsOptionsMenuCursor =
           SelectPreviousEnabledMenuItem(g_GraphicsOptionsMenuCursor,&PTR_s_GRAPHICS_00516580);
    }
    if (uVar5 == 0) {
      if ((uVar3 & 2) != 0) {
        g_GraphicsOptionsMenuCursor =
             SelectNextEnabledMenuItem(g_GraphicsOptionsMenuCursor,&PTR_s_GRAPHICS_00516580);
      }
      if ((uVar3 & 0x20) != 0) {
        g_GraphicsOptionsMenuState = 0x57;
      }
    }
    if (g_PendingOptionsMenuId != 0) {
      g_GraphicsOptionsMenuState = 0x57;
    }
    iVar4 = GetGraphicsModeRevision();
    if (DAT_00516b78 != iVar4) {
      DAT_00516b78 = ReadFromGlobal722994();
      g_PendingGraphicsModeSelection = CurrentGraphicsMode();
    }
    switch((&DAT_00516584)[g_GraphicsOptionsMenuCursor * 4]) {
    case 0x3e:
      if (uVar5 == 0) {
        if ((uVar3 & 4) != 0) {
          g_PendingGraphicsModeSelection = g_PendingGraphicsModeSelection + -1;
        }
        if ((uVar3 & 8) != 0) {
          g_PendingGraphicsModeSelection = g_PendingGraphicsModeSelection + 1;
        }
        if ((uVar3 & 0x10) != 0) {
          SetActiveBitmapSlot(g_PendingGraphicsModeSelection);
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
      if ((uVar3 & 4) != 0) {
        g_BrightnessPercent = g_BrightnessPercent + -2;
      }
      if ((uVar3 & 8) != 0) {
        g_BrightnessPercent = g_BrightnessPercent + 2;
      }
      if (g_BrightnessPercent < 10) {
        g_BrightnessPercent = 10;
        FillArrayOfNumbers255(10);
      }
      else {
        if (100 < g_BrightnessPercent) {
          g_BrightnessPercent = 100;
        }
        FillArrayOfNumbers255(g_BrightnessPercent);
      }
      break;
    case 0x40:
      if ((uVar5 == 0) && ((uVar3 & 4) != 0)) {
        g_CurrentDisplayModeIndex = g_CurrentDisplayModeIndex + -1;
      }
      if ((uVar5 == 0) && ((uVar3 & 8) != 0)) {
        g_CurrentDisplayModeIndex = g_CurrentDisplayModeIndex + 1;
      }
      if (g_CurrentDisplayModeIndex < 1) {
        g_CurrentDisplayModeIndex = 1;
        SetCurrentBitMapSlot(1);
      }
      else {
        if (5 < g_CurrentDisplayModeIndex) {
          g_CurrentDisplayModeIndex = 5;
        }
        SetCurrentBitMapSlot(g_CurrentDisplayModeIndex);
      }
      break;
    case 0x57:
      if ((uVar5 == 0) && ((uVar3 & 0x10) != 0)) {
        g_GraphicsOptionsMenuState = 0x57;
      }
    }
  }
  else if (g_GraphicsOptionsMenuState == 0x57) {
    g_GraphicsOptionsMenuState = 0;
  }
  if (PTR_s_GRAPHICS_00516580 != (undefined *)0x0) {
    ppuVar6 = &PTR_s_GRAPHICS_00516580;
    do {
      sVar2 = *(short *)(ppuVar6 + 1);
      iVar4 = g_PendingGraphicsModeSelection;
      if (sVar2 == 0x3e) {
LAB_004a06a3:
        SetOptionsMenuEntryValueText(ppuVar6,*(undefined4 *)(&stack0xffffffe0 + iVar4 * 4));
      }
      else if (sVar2 == 0x3f) {
        DrawGraphicsTextinMem_2(&DAT_00723d38,s__ld___005175c8,g_BrightnessPercent);
        SetOptionsMenuEntryValueText(ppuVar6,&DAT_00723d38);
      }
      else {
        iVar4 = g_CurrentDisplayModeIndex;
        if (sVar2 == 0x40) goto LAB_004a06a3;
      }
      ppuVar1 = ppuVar6 + 2;
      ppuVar6 = ppuVar6 + 2;
    } while (*ppuVar1 != (undefined *)0x0);
  }
  DrawOptionsMenu(&PTR_s_GRAPHICS_00516580,g_GraphicsOptionsMenuCursor);
  return g_GraphicsOptionsMenuState != 0;
}


