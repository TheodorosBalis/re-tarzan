// Address: 0x004A1480

void ProcessPauseOrOptionsMenus(void)

{
  int iVar1;
  code *pcVar2;
  
  if (g_OptionsMenuStatus == 0) {
    g_ActiveOptionsMenuHandler = (code *)0x0;
    pcVar2 = (code *)ResolveOptionsMenuHandlerById(g_PendingOptionsMenuId);
    if (pcVar2 != (code *)0xffffffff) {
      g_ActiveOptionsMenuHandler = pcVar2;
    }
    g_ActiveOptionsMenuId = g_PendingOptionsMenuId;
    g_PendingOptionsMenuId = 0;
    if (g_ActiveOptionsMenuHandler != (code *)0x0) {
      g_OptionsMenuStatus = 2;
      InitSoundAndNewGameStateFile(0xac);
      PlaySoundID(0xac,100,0,0,0x3fb33333);
      iVar1 = g_BrightnessPercent;
      if (0x19 < g_BrightnessPercent) {
        iVar1 = 0x19;
      }
      FillArrayOfNumbers255(iVar1);
    }
  }
  else if (g_OptionsMenuStatus == 2) {
    if ((g_ActiveOptionsMenuHandler == (code *)0x0) ||
       (iVar1 = (*g_ActiveOptionsMenuHandler)(), iVar1 == 0)) {
      bIsPaused = 1;
      g_OptionsMenuStatus = 3;
      return;
    }
  }
  else if ((g_OptionsMenuStatus == 3) && (iVar1 = DrawOptionsMenu(0,0xffffffff), iVar1 == 0)) {
    if (g_ReturnOptionsMenuId != 0) {
      SetOptionsMenu(g_ReturnOptionsMenuId);
    }
    g_OptionsMenuStatus = 0;
    if (g_PendingOptionsMenuId == 0) {
      FillArrayOfNumbers255(g_BrightnessPercent);
    }
    CaptureKInputsInBuffer();
  }
  if ((g_OptionsMenuStatus == 0) && (g_PendingOptionsMenuId == 0)) {
    bIsPaused = 0;
    return;
  }
  bIsPaused = 1;
  return;
}


