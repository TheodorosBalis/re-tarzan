/* Address: 0x004AE160 */

void SetIsWindowActive(void)

{
  int iVar1;
  int iVar2;
  char *lpString;
  
  if (mainWindowHandle == (HWND)0x0) {
    return;
  }
  if ((((DAT_00518ddc == WindowHandlerValue1) && (DAT_00518de0 == WindowInactive)) &&
      (DAT_00518de4 == WindowHandlerValue3)) && (iVar1 = IsGamePaused(), DAT_00518de8 == iVar1)) {
    return;
  }
  if (((WindowHandlerValue1 < 2) || (WindowInactive != 0)) || (WindowHandlerValue3 != 0)) {
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
  }
  if (((iVar1 == bIsWindowActive) || (SetTarzanPagePermissions(), iVar1 == bIsWindowActive)) ||
     (CaptureKInputsInBuffer(), iVar1 == bIsWindowActive)) {
LAB_004ae211:
    if ((iVar1 != 0) &&
       ((iVar2 = IsGamePaused(), iVar2 == 0 || (iVar2 = FUN_004abd40(), iVar2 != 0)))) {
      PlayAudioLine2();
      goto LAB_004ae233;
    }
  }
  else if (iVar1 != 0) {
    SetVolumeForAllDevices(DAT_0053a340);
    SetAuxVolumePercent(DAT_0053a348);
    goto LAB_004ae211;
  }
  PlayAudioLine();
LAB_004ae233:
  if (iVar1 == 0) {
    FUN_004a1a10();
  }
  if (iVar1 != bIsWindowActive) {
    lpString = s_Tarzan_Action_Game_00518e10;
    if (iVar1 == 0) {
      lpString = s_Tarzan_Action_Game_::Waiting_00518df0;
    }
    SetWindowTextA(mainWindowHandle,lpString);
  }
  if (iVar1 == 0) {
    if ((WindowHandlerValue1 < 2) || (WindowInactive != 0)) {
      FUN_00494130();
    }
    FUN_004a8a90();
  }
  else {
    CheckIfECMfilesLoaded();
    CheckIfSoundIsAvailableAndRunOrSomething();
  }
  DAT_00518ddc = WindowHandlerValue1;
  DAT_00518de0 = WindowInactive;
  DAT_00518de4 = WindowHandlerValue3;
  DAT_00518de8 = IsGamePaused();
  bIsWindowActive = iVar1;
  return;
}

