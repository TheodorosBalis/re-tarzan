// Address: 0x004A0D50

bool PauseMenu(void)

{
  uint uVar1;
  uint uVar2;
  
  if ((DAT_00724162 & 1) == 0) {
    DAT_00724162 = DAT_00724162 | 1;
    g_PauseMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_PAUSED_00516390);
  }
  if (g_PauseMenuState == 0) {
    g_PauseMenuState = 2;
    g_PauseMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_PAUSED_00516390);
  }
  else if (g_PauseMenuState == 2) {
    uVar1 = GetUserInputInMenuAndProcessSound(1);
    uVar2 = uVar1 & 0x8000;
    if ((uVar2 == 0) && ((uVar1 & 1) != 0)) {
      g_PauseMenuCursor = SelectPreviousEnabledMenuItem(g_PauseMenuCursor,&PTR_s_PAUSED_00516390);
    }
    if ((uVar2 == 0) && ((uVar1 & 2) != 0)) {
      g_PauseMenuCursor = SelectNextEnabledMenuItem(g_PauseMenuCursor,&PTR_s_PAUSED_00516390);
    }
    if ((uVar2 == 0) && ((uVar1 & 0x20) != 0)) {
      g_PauseMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_PauseMenuState = 0x57;
    }
    if (*(short *)(&DAT_00516394 + g_PauseMenuCursor * 8) == 0x16) {
      if ((uVar2 == 0) && ((uVar1 & 0x10) != 0)) {
        g_PauseMenuState = 0x57;
      }
    }
    else if (((*(short *)(&DAT_00516394 + g_PauseMenuCursor * 8) == 0x17) && (uVar2 == 0)) &&
            ((uVar1 & 0x10) != 0)) {
      FUN_00454000();
      g_PauseMenuState = 0x57;
    }
  }
  else if (g_PauseMenuState == 0x57) {
    FUN_004abd50();
    g_PauseMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_PAUSED_00516390,g_PauseMenuCursor);
  return g_PauseMenuState != 0;
}


