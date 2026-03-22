/* Address: 0x00445EF0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::SelectMovie_UpdateIdleBehavior(void)

{
  int iVar1;
  
  DAT_0051c4dc = 0x280;
  iVar1 = RandomModulo(0x78);
  if (iVar1 == 0x3c) {
    _g_SelectMovieIdleEventCounter = 7;
  }
  AdvanceMenuIdleScriptCursor(&g_SelectMovieIdleScriptCursor,&g_SelectMovieMenuScene);
  if ((300 < TimeIDLEinMenu) && (g_SelectMovieIdleScriptPending == 0)) {
    iVar1 = RandomModulo(0xdc);
    if (iVar1 == 100) {
      iVar1 = RandomModulo(5);
      SetMenuIdleScriptOverride
                (&g_SelectMovieIdleScriptCursor,(&g_SelectMovieIdleVoiceTable)[iVar1]);
    }
  }
  if (TimeIDLEinMenu < 0x50) {
    g_SelectMovieIdleToggle = 0;
    return;
  }
  iVar1 = RandomModulo((-(g_SelectMovieIdleToggle != 0) & 100U) + 0x14);
  if (iVar1 == 5) {
    g_SelectMovieIdleToggle = (uint)(g_SelectMovieIdleToggle == 0);
  }
  return;
}

