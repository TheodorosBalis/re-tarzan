// Address: 0x004A0720

bool OptionsCategoryMenu(void)

{
  uint uVar1;
  uint uVar2;
  
  if ((DAT_00724139 & 1) == 0) {
    DAT_00724139 = DAT_00724139 | 1;
    g_OptionsCategoryMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_OPTIONS_MENU_00516530)
    ;
  }
  switch(g_OptionsCategoryMenuState) {
  case 0:
    g_OptionsCategoryMenuState = 2;
    break;
  case 2:
    uVar1 = GetUserInputInMenuAndProcessSound(1);
    uVar2 = uVar1 & 0x8000;
    if ((uVar2 == 0) && ((uVar1 & 1) != 0)) {
      g_OptionsCategoryMenuCursor =
           SelectPreviousEnabledMenuItem(g_OptionsCategoryMenuCursor,&PTR_s_OPTIONS_MENU_00516530);
    }
    if (uVar2 == 0) {
      if ((uVar1 & 2) != 0) {
        g_OptionsCategoryMenuCursor =
             SelectNextEnabledMenuItem(g_OptionsCategoryMenuCursor,&PTR_s_OPTIONS_MENU_00516530);
      }
      if ((uVar1 & 0x10) != 0) {
        g_OptionsCategoryMenuState =
             (int)*(short *)(&DAT_00516534 + g_OptionsCategoryMenuCursor * 8);
      }
    }
    if ((uVar2 == 0) && ((uVar1 & 0x20) != 0)) {
      g_OptionsCategoryMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_OptionsCategoryMenuState = 0x57;
    }
    break;
  case 0x18:
    SetOptionsMenuAndReturnHere(3);
    g_OptionsCategoryMenuState = 0x57;
    break;
  case 0x19:
    SetOptionsMenuAndReturnHere(4);
    g_OptionsCategoryMenuState = 0x57;
    break;
  case 0x1a:
    SetOptionsMenuAndReturnHere(7);
    g_OptionsCategoryMenuState = 0x57;
    break;
  case 0x1b:
    SetOptionsMenuAndReturnHere(6);
    g_OptionsCategoryMenuState = 0x57;
    break;
  case 0x1c:
    SetOptionsMenuAndReturnHere(5);
    g_OptionsCategoryMenuState = 0x57;
    break;
  case 0x57:
    g_OptionsCategoryMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_OPTIONS_MENU_00516530,g_OptionsCategoryMenuCursor);
  return g_OptionsCategoryMenuState != 0;
}


