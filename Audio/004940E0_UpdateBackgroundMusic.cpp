#include "tarzan_ghidra_types.hpp"

// Address: 0x004940E0
// Label: UpdateBackgroundMusic
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateBackgroundMusic(void)

{
  DWORD mciResult;
  
  if ((g_CurrentBackgroundMusicTrack != 0) && (g_BackgroundMusicInactiveWindowPauseTickMs == 0)) {
    mciResult = timeGetTime();
    if ((uint)(g_CurrentBackgroundMusicTrackLengthSeconds * 1000) <=
        mciResult - g_BackgroundMusicTrackStartTickMs) {
      g_BackgroundMusicMciIsPlaying = 0;
      InitBackgroundMusicTrack(g_CurrentBackgroundMusicTrack);
    }
  }
  return;
}

