#include "tarzan_ghidra_types.hpp"

// Address: 0x004944A0
// Label: ResumeBackgroundMusicAfterDeviceArrival
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ResumeBackgroundMusicAfterDeviceArrival(void)

{
  int value;
  DWORD mciResult;
  
  if ((g_CurrentBackgroundMusicTrack != 0) && (g_BackgroundMusicInactiveWindowPauseTickMs == 0)) {
    value = LoadECMFilesAndInit();
    if (value != 0) {
      value = IsBackgroundMusicPlaying();
      if (value == 0) {
        mciResult = timeGetTime();
        PlayBackgroundMusicTrackFromSecond
                  (g_CurrentBackgroundMusicTrack,(mciResult - g_BackgroundMusicTrackStartTickMs) / 1000)
        ;
      }
    }
  }
  return;
}

