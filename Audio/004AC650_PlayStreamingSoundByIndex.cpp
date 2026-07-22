#include "tarzan_ghidra_types.hpp"

// Address: 0x004AC650
// Label: PlayStreamingSoundByIndex
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void PlayStreamingSoundByIndex(int soundId)

{
  InitAudioLine();
  LoadAndPlayAudioLineById(soundId + -0x8000,(g_AuxVolumePercent * 0x3c) / 100);
  return;
}

