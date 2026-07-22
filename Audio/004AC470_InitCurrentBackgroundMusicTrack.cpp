#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC470
// Label: InitCurrentBackgroundMusicTrack
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitCurrentBackgroundMusicTrack(void)

{
  InitBackgroundMusicTrack(g_CurrentBackgroundMusicTrackId);
  return;
}

