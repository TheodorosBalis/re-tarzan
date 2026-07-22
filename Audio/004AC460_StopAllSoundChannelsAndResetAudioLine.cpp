#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC460
// Label: StopAllSoundChannelsAndResetAudioLine
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StopAllSoundChannelsAndResetAudioLine(void)

{
  StopAllSoundChannels();
  InitAudioLine();
  return;
}

