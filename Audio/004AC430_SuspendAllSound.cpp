#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC430
// Label: SuspendAllSound
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SuspendAllSound(void)

{
  StopAllSoundChannels();
  InitAudioLine();
  ResetBackgroundMusicPlaybackState();
  return;
}

