#include "tarzan_ghidra_types.hpp"

// Address: 0x004A17E0
// Label: RestoreStartupMixerVolumeLevels
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void RestoreStartupMixerVolumeLevels(void)

{
  SetCdAudioAndWin9xAuxVolumePercent(g_CdAudioMixerVolumeState_Field0008);
  SetWaveOutMixerVolumePercent(g_WaveOutMixerVolumeState_Field0010);
  return;
}

