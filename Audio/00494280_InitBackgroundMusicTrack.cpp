#include "tarzan_ghidra_types.hpp"

// Address: 0x00494280
// Label: InitBackgroundMusicTrack
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitBackgroundMusicTrack(int trackId)

{
  int value;
  
  if ((trackId == g_CurrentBackgroundMusicTrack) && (value = IsBackgroundMusicPlaying(), value != 0)
     ) {
    return;
  }
  ResetBackgroundMusicPlaybackState();
  if (((0 < trackId) && (value = LoadECMFilesAndInit(), value != 0)) &&
     (g_CurrentBackgroundMusicTrackLengthSeconds = GetBackgroundMusicTrackLengthSeconds(trackId),
     g_CurrentBackgroundMusicTrackLengthSeconds != 0)) {
    PlayBackgroundMusicTrackFromSecond(trackId,0);
  }
  return;
}

