/* Address: 0x004A1480 */

void ProcessPauseOrOptionsMenus(void)

{
  int iVar1;
  code *pcVar2;
  
  if (MenuSelectedID == 0) {
    DAT_007241e0 = (code *)0x0;
    pcVar2 = (code *)GetRightFunctionFromJMPtable(DAT_007241d4);
    if (pcVar2 != (code *)0xffffffff) {
      DAT_007241e0 = pcVar2;
    }
    DAT_007241d8 = DAT_007241d4;
    DAT_007241d4 = 0;
    if (DAT_007241e0 != (code *)0x0) {
      MenuSelectedID = 2;
      InitSoundAndNewGameStateFile(0xac);
      PlaySoundID(0xac,100,0,0,0x3fb33333);
      iVar1 = DAT_0053a354;
      if (0x19 < DAT_0053a354) {
        iVar1 = 0x19;
      }
      FillArrayOfNumbers255(iVar1);
    }
  }
  else if (MenuSelectedID == 2) {
    if ((DAT_007241e0 == (code *)0x0) || (iVar1 = (*DAT_007241e0)(), iVar1 == 0)) {
      bIsPaused = 1;
      MenuSelectedID = 3;
      return;
    }
  }
  else if ((MenuSelectedID == 3) && (iVar1 = DrawOptionsMenu(0,0xffffffff), iVar1 == 0)) {
    if (DAT_007241dc != 0) {
      SetOptionsMenu(DAT_007241dc);
    }
    MenuSelectedID = 0;
    if (DAT_007241d4 == 0) {
      FillArrayOfNumbers255(DAT_0053a354);
    }
    CaptureKInputsInBuffer();
  }
  if ((MenuSelectedID == 0) && (DAT_007241d4 == 0)) {
    bIsPaused = 0;
    return;
  }
  bIsPaused = 1;
  return;
}

