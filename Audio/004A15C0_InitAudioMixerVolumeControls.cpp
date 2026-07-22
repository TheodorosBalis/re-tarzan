#include "tarzan_ghidra_types.hpp"

// Address: 0x004A15C0
// Label: InitAudioMixerVolumeControls
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void InitAudioMixerVolumeControls(void)

{
  InitWin9xAuxVolumeFallbackDevices();
  QueryMixerSourceVolumeControl(&g_CdAudioMixerVolumeControl,0x1005);
  QueryMixerSourceVolumeControl(&g_WaveOutMixerVolumeControl,0x1008);
  return;
}

