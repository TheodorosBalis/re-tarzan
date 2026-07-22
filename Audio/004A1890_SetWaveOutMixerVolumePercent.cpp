#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1890
// Label: SetWaveOutMixerVolumePercent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetWaveOutMixerVolumePercent(int volumePercent)

{
  if (volumePercent < 0) {
    volumePercent = 0;
  }
  else if (100 < volumePercent) {
    volumePercent = 100;
  }
  if (g_WaveOutMixerVolumeState_Field000C != 0) {
    _g_WaveOutMixerVolumeState_Field0030 = volumePercent * 0x28f;
    _g_WaveOutMixerVolumePercent = volumePercent;
    _g_WaveOutMixerVolumeState_Field0034 = _g_WaveOutMixerVolumeState_Field0030;
    mixerSetControlDetails((HMIXEROBJ)0x0,(LPMIXERCONTROLDETAILS)&DAT_00724288,0);
  }
  return;
}

