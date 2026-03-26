// Address: 0x004A0EB0

bool RecoveryModeMenu(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  if ((DAT_00724144 & 1) == 0) {
    DAT_00724144 = DAT_00724144 | 1;
    g_RecoveryModeMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_RECOVERY_MODE_00516338);
  }
  if (g_RecoveryModeMenuState == 0) {
    g_RecoveryModeMenuState = 2;
  }
  else if (g_RecoveryModeMenuState == 2) {
    uVar2 = GetUserInputInMenuAndProcessSound(1);
    uVar3 = uVar2 & 0x8000;
    if ((uVar3 == 0) && ((uVar2 & 1) != 0)) {
      g_RecoveryModeMenuCursor =
           SelectPreviousEnabledMenuItem(g_RecoveryModeMenuCursor,&PTR_s_RECOVERY_MODE_00516338);
    }
    if ((uVar3 == 0) && ((uVar2 & 2) != 0)) {
      g_RecoveryModeMenuCursor =
           SelectNextEnabledMenuItem(g_RecoveryModeMenuCursor,&PTR_s_RECOVERY_MODE_00516338);
    }
    sVar1 = *(short *)(&DAT_0051633c + g_RecoveryModeMenuCursor * 8);
    if (sVar1 == 0x54) {
      if ((uVar3 == 0) && ((uVar2 & 0x10) != 0)) {
        bLastTimeCrashed = 0;
        SetActiveBitmapSlot(7);
        g_RecoveryModeMenuState = 0x57;
      }
    }
    else if (sVar1 == 0x55) {
      if ((uVar3 == 0) && ((uVar2 & 0x10) != 0)) {
        bLastTimeCrashed = 0;
        g_CurrentDisplayModeIndex = 5;
        SetCurrentBitMapSlot(5);
        SetActiveBitmapSlot(g_CurrentDisplayModeIndex);
        g_RecoveryModeMenuState = 0x57;
      }
    }
    else if (((sVar1 == 0x56) && (uVar3 == 0)) && ((uVar2 & 0x10) != 0)) {
      bLastTimeCrashed = 0;
      SetActiveBitmapSlot(5);
      SetOptionsMenu(5);
      g_RecoveryModeMenuState = 0x57;
    }
  }
  else if (g_RecoveryModeMenuState == 0x57) {
    g_RecoveryModeMenuState = 0;
  }
  DrawOptionsMenu(&PTR_s_RECOVERY_MODE_00516338,g_RecoveryModeMenuCursor);
  return g_RecoveryModeMenuState != 0;
}


