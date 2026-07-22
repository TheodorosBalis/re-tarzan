#include "tarzan_ghidra_types.hpp"

// Address: 0x004944F0
// Label: InitCdPlayerAndEMCFiles
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 InitCdPlayerAndEMCFiles(undefined4 arg1)

{
  HWND hWnd;
  
  _g_CdPlayerEmcInitState_Field0018 = arg1;
  g_BackgroundMusicMciIsPlaying = 0;
  g_BackgroundMusicMusicDisabledPauseTickMs = 0;
  g_BackgroundMusicInactiveWindowPauseTickMs = 0;
  g_BackgroundMusicTrackStartTickMs = 0;
  g_CurrentBackgroundMusicTrackLengthSeconds = 0;
  g_BackgroundMusicMciDeviceOpen = 0;
  g_CurrentBackgroundMusicTrack = 0;
  g_BackgroundMusicMciDeviceId = 0;
  hWnd = FindWindowA(s_SJE_CdPlayerClass_005156ec,(LPCSTR)0x0);
  if (hWnd != (HWND)0x0) {
    SendMessageTimeoutA(hWnd,0x10,0,0,2,500,(PDWORD_PTR)0x0);
  }
  g_BackgroundMusicInitialized = 1;
  LoadECMFilesAndInit();
  return 1;
}

