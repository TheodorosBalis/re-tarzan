// Address: 0x004A0C00

bool ExitGameConfirmationMenu(void)

{
  uint uVar1;
  uint uVar2;
  
  if ((DAT_00724170 & 1) == 0) {
    DAT_00724170 = DAT_00724170 | 1;
    g_ExitGameConfirmationMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&PTR_s_EXIT_GAME_NOW__00516310);
  }
  if (g_ExitGameConfirmationMenuState == 0) {
    g_ExitGameConfirmationMenuState = 2;
    g_ExitGameConfirmationMenuCursor =
         SelectPreviousEnabledMenuItem(0,&PTR_s_EXIT_GAME_NOW__00516310);
  }
  else if (g_ExitGameConfirmationMenuState == 2) {
    uVar1 = GetUserInputInMenuAndProcessSound(1);
    uVar2 = uVar1 & 0x8000;
    if ((uVar2 == 0) && ((uVar1 & 1) != 0)) {
      g_ExitGameConfirmationMenuCursor =
           SelectPreviousEnabledMenuItem
                     (g_ExitGameConfirmationMenuCursor,&PTR_s_EXIT_GAME_NOW__00516310);
    }
    if ((uVar2 == 0) && ((uVar1 & 2) != 0)) {
      g_ExitGameConfirmationMenuCursor =
           SelectNextEnabledMenuItem
                     (g_ExitGameConfirmationMenuCursor,&PTR_s_EXIT_GAME_NOW__00516310);
    }
    if ((uVar2 == 0) && ((uVar1 & 0x20) != 0)) {
      g_ExitGameConfirmationMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_ExitGameConfirmationMenuState = 0x57;
    }
    if (*(short *)(&DAT_00516314 + g_ExitGameConfirmationMenuCursor * 8) == 4) {
      if ((uVar2 == 0) && ((uVar1 & 0x10) != 0)) {
        ExitIfFailed2();
        g_ExitGameConfirmationMenuState = 0x57;
      }
    }
    else if (((*(short *)(&DAT_00516314 + g_ExitGameConfirmationMenuCursor * 8) == 5) &&
             (uVar2 == 0)) && ((uVar1 & 0x10) != 0)) {
      g_ExitGameConfirmationMenuState = 0x57;
    }
  }
  else if (g_ExitGameConfirmationMenuState == 0x57) {
    g_ExitGameConfirmationMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_EXIT_GAME_NOW__00516310,g_ExitGameConfirmationMenuCursor);
  return g_ExitGameConfirmationMenuState != 0;
}


