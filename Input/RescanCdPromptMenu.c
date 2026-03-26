// Address: 0x004A11F0

bool RescanCdPromptMenu(void)

{
  short sVar1;
  uint uVar2;
  uint uVar3;
  
  if ((DAT_00723d30 & 1) == 0) {
    DAT_00723d30 = DAT_00723d30 | 1;
    g_RescanCdPromptMenuCursor =
         SelectNextEnabledMenuItem(0xffffffff,&PTR_s_TO_PLAY_TARZAN_00516428);
  }
  if (g_RescanCdPromptMenuState == 0) {
    g_RescanCdPromptMenuState = 2;
  }
  else if (g_RescanCdPromptMenuState == 2) {
    uVar2 = GetUserInputInMenuAndProcessSound(1);
    uVar3 = uVar2 & 0x8000;
    if ((uVar3 == 0) && ((uVar2 & 1) != 0)) {
      g_RescanCdPromptMenuCursor =
           SelectPreviousEnabledMenuItem(g_RescanCdPromptMenuCursor,&PTR_s_TO_PLAY_TARZAN_00516428);
    }
    if ((uVar3 == 0) && ((uVar2 & 2) != 0)) {
      g_RescanCdPromptMenuCursor =
           SelectNextEnabledMenuItem(g_RescanCdPromptMenuCursor,&PTR_s_TO_PLAY_TARZAN_00516428);
    }
    sVar1 = *(short *)(&DAT_0051642c + g_RescanCdPromptMenuCursor * 8);
    if (sVar1 == 0x13) {
      if ((uVar3 != 0) || ((uVar2 & 0x10) == 0)) goto LAB_004a12f9;
      IsGameRunningOnCD();
      uVar2 = bGameInitSuccess;
    }
    else {
      if (sVar1 != 0x14) {
        if (((sVar1 == 0x15) && (uVar3 == 0)) && ((uVar2 & 0x10) != 0)) {
          ExitIfFailed2();
        }
        goto LAB_004a12f9;
      }
      if (uVar3 != 0) goto LAB_004a12f9;
      uVar2 = uVar2 & 0x10;
    }
    if (uVar2 != 0) {
      g_RescanCdPromptMenuState = 0x57;
    }
  }
  else if (g_RescanCdPromptMenuState == 0x57) {
    g_RescanCdPromptMenuState = 0;
  }
LAB_004a12f9:
  DrawOptionsMenu(&PTR_s_TO_PLAY_TARZAN_00516428,g_RescanCdPromptMenuCursor);
  return g_RescanCdPromptMenuState != 0;
}


