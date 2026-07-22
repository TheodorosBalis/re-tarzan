#include "tarzan_ghidra_types.hpp"

// Address: 0x00494180
// Label: ResumeBackgroundMusicIfSuspended
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResumeBackgroundMusicIfSuspended(void)

{
  DWORD mciResult;
  int value;
  
  if (g_BackgroundMusicInactiveWindowPauseTickMs != 0) {
    mciResult = timeGetTime();
    value = mciResult - g_BackgroundMusicInactiveWindowPauseTickMs;
    g_BackgroundMusicInactiveWindowPauseTickMs = 0;
    g_BackgroundMusicTrackStartTickMs = g_BackgroundMusicTrackStartTickMs + value;
    ResumeBackgroundMusicAfterDeviceArrival();
    return;
  }
  return;
}

