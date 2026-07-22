#include "tarzan_ghidra_types.hpp"

// Address: 0x004AE160
// Label: UpdateMainWindowActiveState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateMainWindowActiveState(void)

{
  int value;
  int value2;
  char *lpString;
  
  if (mainWindowHandle == (HWND)0x0) {
    return;
  }
  if ((((g_LastMainWindowActivationState == g_MainWindowActivationState) &&
       (g_LastMainWindowMinimized == g_IsMainWindowMinimized)) &&
      (g_LastMainWindowMessagePulseCount == g_MainWindowMessagePulseCount)) &&
     (value = IsGamePaused(), g_LastGamePausedState == value)) {
    return;
  }
  if (((g_MainWindowActivationState < 2) || (g_IsMainWindowMinimized != 0)) ||
     (g_MainWindowMessagePulseCount != 0)) {
    value = 0;
  }
  else {
    value = 1;
  }
  if (((value == g_IsMainWindowActive) ||
      (SetTarzanPagePermissions(), value == g_IsMainWindowActive)) ||
     (CaptureKInputsInBuffer(), value == g_IsMainWindowActive)) {
LAB_004ae211:
    if ((value != 0) &&
       ((value2 = IsGamePaused(), value2 == 0 || (value2 = IsMenuModeActive(), value2 != 0)))) {
      ResumeAudioLinePlayback();
      goto LAB_004ae233;
    }
  }
  else if (value != 0) {
    SetCdAudioAndWin9xAuxVolumePercent(g_MasterVolumePercent);
    SetWaveOutMixerVolumePercent(g_AuxVolumePercent);
    goto LAB_004ae211;
  }
  PauseAudioLinePlayback();
LAB_004ae233:
  if (value == 0) {
    StopActiveStreamedWork();
  }
  if (value != g_IsMainWindowActive) {
    lpString = s_Tarzan_Action_Game_00518e10;
    if (value == 0) {
      lpString = s_Tarzan_Action_Game___Waiting_00518df0;
    }
    SetWindowTextA(mainWindowHandle,lpString);
  }
  if (value == 0) {
    if ((g_MainWindowActivationState < 2) || (g_IsMainWindowMinimized != 0)) {
      PauseBackgroundMusicForInactiveWindow();
    }
    SuspendAllActiveSoundPlayback();
  }
  else {
    ResumeBackgroundMusicIfSuspended();
    ResumeAllSoundPlaybackIfSuspended();
  }
  g_LastMainWindowActivationState = g_MainWindowActivationState;
  g_LastMainWindowMinimized = g_IsMainWindowMinimized;
  g_LastMainWindowMessagePulseCount = g_MainWindowMessagePulseCount;
  g_LastGamePausedState = IsGamePaused();
  g_IsMainWindowActive = value;
  return;
}

