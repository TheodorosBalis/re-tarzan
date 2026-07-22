#include "tarzan_ghidra_types.hpp"

// Address: 0x00494130
// Label: PauseBackgroundMusicForInactiveWindow
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void PauseBackgroundMusicForInactiveWindow(void)

{
  int value;
  
  if ((g_BackgroundMusicMciIsPlaying != 0) && (g_BackgroundMusicInactiveWindowPauseTickMs == 0)) {
    value = LoadECMFilesAndInit();
    if (value != 0) {
      mciSendCommandA(g_BackgroundMusicMciDeviceId,0x808,2,0);
    }
    g_BackgroundMusicInactiveWindowPauseTickMs = timeGetTime();
    g_BackgroundMusicMciIsPlaying = 0;
  }
  return;
}

