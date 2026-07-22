#include "tarzan_ghidra_types.hpp"

// Address: 0x00494570
// Label: StopMciCdAudioAndResetPlayback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StopMciCdAudioAndResetPlayback(void)

{
  ResetBackgroundMusicPlaybackState();
  if (g_BackgroundMusicMciDeviceOpen != 0) {
    mciSendCommandA(g_BackgroundMusicMciDeviceId,0x804,0,0);
  }
  g_BackgroundMusicMciDeviceOpen = 0;
  g_BackgroundMusicInitialized = 0;
  return;
}

