/* Address: 0x004391F0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CMenu::LoadGame_BeginExitTransition(void)

{
  int iVar1;
  
  LoadSoundFileAndInitAudio(0xaa,0,0);
  _g_LoadGameExitPending = 1;
  _g_LoadGameTimer = 0x5a;
  _g_LoadGameState = 0;
  iVar1 = RandomModulo(4,0,0);
  LoadSoundFileAndInitAudio(*(undefined4 *)(&g_LoadGameExitSfxTable + iVar1 * 4));
  return;
}

