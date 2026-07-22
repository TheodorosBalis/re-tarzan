#include "tarzan_ghidra_types.hpp"

// Address: 0x00494210
// Label: ResumeBackgroundMusicIfSoundOptionsChanged
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResumeBackgroundMusicIfSoundOptionsChanged(void)

{
  if (g_BackgroundMusicMusicDisabledPauseTickMs != 0) {
    g_BackgroundMusicMusicDisabledPauseTickMs = 0;
    ResumeBackgroundMusicAfterDeviceArrival();
    return;
  }
  return;
}

