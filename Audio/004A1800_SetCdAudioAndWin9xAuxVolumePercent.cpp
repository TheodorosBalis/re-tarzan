#include "tarzan_ghidra_types.hpp"

// Address: 0x004A1800
// Label: SetCdAudioAndWin9xAuxVolumePercent
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetCdAudioAndWin9xAuxVolumePercent(int volumePercent)

{
  UINT *value2;
  int value;
  
  if (volumePercent < 0) {
    volumePercent = 0;
  }
  else if (100 < volumePercent) {
    volumePercent = 100;
  }
  if (g_CdAudioMixerVolumeState_Field0004 != 0) {
    _g_CdAudioMixerVolumeState_Field0028 = volumePercent * 0x28f;
    _g_CdAudioAuxVolumePercent = volumePercent;
    _g_CdAudioMixerVolumeState_Field002C = _g_CdAudioMixerVolumeState_Field0028;
    mixerSetControlDetails((HMIXEROBJ)0x0,(LPMIXERCONTROLDETAILS)&DAT_007246b0,0);
  }
  value = 0;
  if (0 < g_Win9xAuxVolumeDeviceCount) {
    value2 = &g_Win9xAuxVolumeDeviceTable;
    do {
      auxSetVolume(*value2,volumePercent * 0x28f028f);
      value = value + 1;
      value2 = value2 + 2;
    } while (value < g_Win9xAuxVolumeDeviceCount);
  }
  return;
}

