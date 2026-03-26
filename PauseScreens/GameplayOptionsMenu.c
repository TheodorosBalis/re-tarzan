// Address: 0x004A0210

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool GameplayOptionsMenu(void)

{
  undefined **ppuVar1;
  uint uVar2;
  uint uVar3;
  undefined **ppuVar4;
  char *local_10 [3];
  
  if ((DAT_00724161 & 1) == 0) {
    DAT_00724161 = DAT_00724161 | 1;
    g_GameplayOptionsMenuCursor = SelectNextEnabledMenuItem(0xffffffff,&PTR_s_GAME_PLAY_00516728);
  }
  if (g_GameplayOptionsMenuState == 0) {
    g_GameplayOptionsMenuState = 2;
  }
  else if (g_GameplayOptionsMenuState == 2) {
    uVar2 = GetUserInputInMenuAndProcessSound(1);
    uVar3 = uVar2 & 0x8000;
    if ((uVar3 == 0) && ((uVar2 & 1) != 0)) {
      g_GameplayOptionsMenuCursor =
           SelectPreviousEnabledMenuItem(g_GameplayOptionsMenuCursor,&PTR_s_GAME_PLAY_00516728);
    }
    if ((uVar3 == 0) && ((uVar2 & 2) != 0)) {
      g_GameplayOptionsMenuCursor =
           SelectNextEnabledMenuItem(g_GameplayOptionsMenuCursor,&PTR_s_GAME_PLAY_00516728);
    }
    if ((uVar3 == 0) && ((uVar2 & 0x20) != 0)) {
      g_GameplayOptionsMenuState = 0x57;
    }
    if (g_PendingOptionsMenuId != 0) {
      g_GameplayOptionsMenuState = 0x57;
    }
    if ((&DAT_0051672c)[g_GameplayOptionsMenuCursor * 4] == 0x3d) {
      if (uVar3 == 0) {
        if ((uVar2 & 4) != 0) {
          _g_GameDifficulty = _g_GameDifficulty + -1;
        }
        if ((uVar2 & 8) != 0) {
          _g_GameDifficulty = _g_GameDifficulty + 1;
        }
      }
      if (_g_GameDifficulty < 0) {
        _g_GameDifficulty = 0;
      }
      else if (2 < _g_GameDifficulty) {
        _g_GameDifficulty = 2;
      }
    }
    else if ((((&DAT_0051672c)[g_GameplayOptionsMenuCursor * 4] == 0x57) && (uVar3 == 0)) &&
            ((uVar2 & 0x10) != 0)) {
      g_GameplayOptionsMenuState = 0x57;
    }
  }
  else if (g_GameplayOptionsMenuState == 0x57) {
    g_GameplayOptionsMenuState = 0;
  }
  local_10[0] = &DAT_005175e0;
  local_10[1] = s_MEDIUM_005175d8;
  local_10[2] = &DAT_005175d0;
  if (PTR_s_GAME_PLAY_00516728 != (undefined *)0x0) {
    ppuVar4 = &PTR_s_GAME_PLAY_00516728;
    do {
      if (*(short *)(ppuVar4 + 1) == 0x3d) {
        SetOptionsMenuEntryValueText(ppuVar4,local_10[_g_GameDifficulty]);
      }
      ppuVar1 = ppuVar4 + 2;
      ppuVar4 = ppuVar4 + 2;
    } while (*ppuVar1 != (undefined *)0x0);
  }
  DrawOptionsMenu(&PTR_s_GAME_PLAY_00516728,g_GameplayOptionsMenuCursor);
  return g_GameplayOptionsMenuState != 0;
}


