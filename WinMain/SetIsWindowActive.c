// Address: 0x004AE160

void SetIsWindowActive(void)

{
  int iVar1;
  int iVar2;
  char *lpString;
  
  if (mainWindowHandle == (HWND)0x0) {
    return;
  }
  if ((((DAT_00518ddc == g_MainWindowActivationState) && (DAT_00518de0 == g_IsMainWindowMinimized))
      && (DAT_00518de4 == g_MainWindowMessagePulseCount)) &&
     (iVar1 = IsGamePaused(), DAT_00518de8 == iVar1)) {
    return;
  }
  if (((g_MainWindowActivationState < 2) || (g_IsMainWindowMinimized != 0)) ||
     (g_MainWindowMessagePulseCount != 0)) {
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
      ResumeAudioLinePlayback();
      goto LAB_004ae233;
    }
  }
  else if (iVar1 != 0) {
    SetVolumeForAllDevices(g_MasterVolumePercent);
    SetAuxVolumePercent(g_AuxVolumePercent);
    goto LAB_004ae211;
  }
  PauseAudioLinePlayback();
LAB_004ae233:
  if (iVar1 == 0) {
    StopActiveStreamedWork();
  }
  if (iVar1 != bIsWindowActive) {
    lpString = s_Tarzan_Action_Game_00518e10;
    if (iVar1 == 0) {
      lpString = s_Tarzan_Action_Game___Waiting_00518df0;
    }
    SetWindowTextA(mainWindowHandle,lpString);
  }
  if (iVar1 == 0) {
    if ((g_MainWindowActivationState < 2) || (g_IsMainWindowMinimized != 0)) {
      FUN_00494130();
    }
    FUN_004a8a90();
  }
  else {
    ResumeBackgroundMusicIfSuspended();
    CheckIfSoundIsAvailableAndRunOrSomething();
  }
  DAT_00518ddc = g_MainWindowActivationState;
  DAT_00518de0 = g_IsMainWindowMinimized;
  DAT_00518de4 = g_MainWindowMessagePulseCount;
  DAT_00518de8 = IsGamePaused();
  bIsWindowActive = iVar1;
  return;
}


