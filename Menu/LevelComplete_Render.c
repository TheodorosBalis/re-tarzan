/* Address: 0x0045EA00 */

void CMenu::LevelComplete_Render(void)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  DAT_0051c4dc = 900;
  ClearFontInMenus(0x4ed35c,0xffffffff);
  ClearFontInMenus(0x4ed37c,0xffffffff);
  puVar1 = &g_LevelCompleteScoreSceneEntries;
  iVar2 = 0x14;
  do {
    FUN_00445290(puVar1);
    puVar1 = puVar1 + 0x144;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  CMenu::LevelComplete_UpdateRewardBurstSystem(&g_LevelCompleteRewardBurstSystem);
  uStack_8 = 0;
  uStack_4 = 0xfffffff8;
  if (g_LevelCompleteInputMode == 0) {
    uVar3 = 1;
  }
  else {
    uVar3 = 2;
  }
  FUN_004adde0(&g_LevelCompleteTextAnchor,&uStack_8,uVar3,*(int *)(DAT_00a439d4 + 0x1c) + 0x40,0);
  FUN_004adde0(&g_LevelCompleteTextAnchor,&uStack_8,0,*(int *)(DAT_00a439d4 + 0x1c) + 0x40,0);
  ClearFontInMenus(&g_LevelCompleteTextAnchor,2);
  ClearFontInMenus(0x4ed37c,2);
  return;
}

