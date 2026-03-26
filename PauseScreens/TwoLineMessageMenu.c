// Address: 0x004A1320

bool TwoLineMessageMenu(void)

{
  uint uVar1;
  uint uVar2;
  
  if ((DAT_00723d31 & 1) == 0) {
    DAT_00723d31 = DAT_00723d31 | 1;
    g_TwoLineMessageMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&PTR_s_a23456789_123456789_123456789_12_00516470);
  }
  if (g_TwoLineMessageMenuState == 0) {
    g_TwoLineMessageMenuState = 2;
  }
  else if (g_TwoLineMessageMenuState == 2) {
    uVar1 = GetUserInputInMenuAndProcessSound(1);
    uVar2 = uVar1 & 0x8000;
    if ((uVar2 == 0) && ((uVar1 & 1) != 0)) {
      g_TwoLineMessageMenuCursor =
           SelectPreviousEnabledMenuItem
                     (g_TwoLineMessageMenuCursor,&PTR_s_a23456789_123456789_123456789_12_00516470);
    }
    if (uVar2 == 0) {
      if ((uVar1 & 2) != 0) {
        g_TwoLineMessageMenuCursor =
             SelectNextEnabledMenuItem
                       (g_TwoLineMessageMenuCursor,&PTR_s_a23456789_123456789_123456789_12_00516470)
        ;
      }
      if ((uVar1 & 0x10) != 0) {
        g_TwoLineMessageMenuState = (int)*(short *)(&DAT_00516474 + g_TwoLineMessageMenuCursor * 8);
      }
    }
    if ((uVar2 == 0) && ((uVar1 & 0x20) != 0)) {
      g_TwoLineMessageMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_TwoLineMessageMenuState = 0x57;
    }
  }
  else if (g_TwoLineMessageMenuState == 0x57) {
    g_TwoLineMessageMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_a23456789_123456789_123456789_12_00516470,g_TwoLineMessageMenuCursor);
  return g_TwoLineMessageMenuState != 0;
}


