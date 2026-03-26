// Address: 0x004A1040

bool UnsupportedDisplaySettingsMenu(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((DAT_00724160 & 1) == 0) {
    DAT_00724160 = DAT_00724160 | 1;
    g_UnsupportedDisplaySettingsMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&PTR_s_THE_GAME_CANNOT_RUN_IN_THIS_005163b8);
  }
  if (g_UnsupportedDisplaySettingsMenuState == 0) {
    g_UnsupportedDisplaySettingsMenuState = 2;
  }
  else if (g_UnsupportedDisplaySettingsMenuState == 2) {
    uVar1 = GetUserInputInMenuAndProcessSound(1);
    uVar3 = uVar1 & 0x8000;
    if ((uVar3 == 0) && ((uVar1 & 1) != 0)) {
      g_UnsupportedDisplaySettingsMenuCursor =
           SelectPreviousEnabledMenuItem
                     (g_UnsupportedDisplaySettingsMenuCursor,
                      &PTR_s_THE_GAME_CANNOT_RUN_IN_THIS_005163b8);
    }
    if ((uVar3 == 0) && ((uVar1 & 2) != 0)) {
      g_UnsupportedDisplaySettingsMenuCursor =
           SelectNextEnabledMenuItem
                     (g_UnsupportedDisplaySettingsMenuCursor,
                      &PTR_s_THE_GAME_CANNOT_RUN_IN_THIS_005163b8);
    }
    if ((uVar3 == 0) && ((uVar1 & 0x20) != 0)) {
      g_UnsupportedDisplaySettingsMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_UnsupportedDisplaySettingsMenuState = 0x57;
    }
    iVar2 = VerifyGraphicsMode();
    if ((iVar2 != 0) || (IsDisplayOptionSupported != 0)) {
      g_UnsupportedDisplaySettingsMenuState = 0x57;
    }
    switch(*(undefined2 *)(&DAT_005163bc + g_UnsupportedDisplaySettingsMenuCursor * 8)) {
    case 0xf:
      if ((uVar3 == 0) && ((uVar1 & 0x10) != 0)) {
        SetActiveBitmapSlot(1);
        g_UnsupportedDisplaySettingsMenuState = 0x57;
      }
      break;
    case 0x10:
      if ((uVar3 == 0) && ((uVar1 & 0x10) != 0)) {
        SetActiveBitmapSlot(2);
        g_UnsupportedDisplaySettingsMenuState = 0x57;
      }
      break;
    case 0x11:
      if ((uVar3 == 0) && ((uVar1 & 0x10) != 0)) {
        SetActiveBitmapSlot(3);
        g_UnsupportedDisplaySettingsMenuState = 0x57;
      }
      break;
    case 0x12:
      if ((uVar3 == 0) && ((uVar1 & 0x10) != 0)) {
        SetActiveBitmapSlot(4);
        g_UnsupportedDisplaySettingsMenuState = 0x57;
      }
    }
  }
  else if (g_UnsupportedDisplaySettingsMenuState == 0x57) {
    g_UnsupportedDisplaySettingsMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_THE_GAME_CANNOT_RUN_IN_THIS_005163b8,g_UnsupportedDisplaySettingsMenuCursor
                 );
  return g_UnsupportedDisplaySettingsMenuState != 0;
}


