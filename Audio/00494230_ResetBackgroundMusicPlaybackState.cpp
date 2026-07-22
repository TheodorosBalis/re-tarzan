#include "tarzan_ghidra_types.hpp"

// Address: 0x00494230
// Label: ResetBackgroundMusicPlaybackState
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResetBackgroundMusicPlaybackState(void)

{
  int value;
  
  if (g_BackgroundMusicMciIsPlaying != 0) {
    value = LoadECMFilesAndInit();
    if (value != 0) {
      mciSendCommandA(g_BackgroundMusicMciDeviceId,0x808,2,0);
    }
  }
  g_BackgroundMusicMciIsPlaying = 0;
  g_BackgroundMusicInactiveWindowPauseTickMs = 0;
  g_BackgroundMusicTrackStartTickMs = 0;
  g_CurrentBackgroundMusicTrack = 0;
  g_CurrentBackgroundMusicTrackLengthSeconds = 0;
  return;
}

