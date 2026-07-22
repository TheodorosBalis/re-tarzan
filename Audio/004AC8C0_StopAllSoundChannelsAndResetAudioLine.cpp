#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC8C0
// Label: StopAllSoundChannelsAndResetAudioLine
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StopAllSoundChannelsAndResetAudioLine_004AC8C0(void)

{
  StopAllSoundChannels();
  InitAudioLine();
  return;
}

