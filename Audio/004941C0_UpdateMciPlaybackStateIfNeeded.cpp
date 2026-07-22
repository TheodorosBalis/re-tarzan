#include "tarzan_ghidra_types.hpp"

// Address: 0x004941C0
// Label: UpdateMciPlaybackStateIfNeeded
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateMciPlaybackStateIfNeeded(void)

{
  int value;
  
  if (g_BackgroundMusicMusicDisabledPauseTickMs == 0) {
    if (g_BackgroundMusicMciIsPlaying != 0) {
      value = LoadECMFilesAndInit();
      if (value != 0) {
        mciSendCommandA(g_BackgroundMusicMciDeviceId,0x808,2,0);
      }
    }
    g_BackgroundMusicMusicDisabledPauseTickMs = timeGetTime();
    g_BackgroundMusicMciIsPlaying = 0;
  }
  return;
}

