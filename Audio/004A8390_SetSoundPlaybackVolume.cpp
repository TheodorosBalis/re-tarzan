#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8390
// Label: SetSoundPlaybackVolume
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SetSoundPlaybackVolume(ushort volumePercent,byte soundId,undefined4 channelIndex)

{
  undefined4 *dataCursor;
  int value;
  
  if (volumePercent < 2000) {
    value = 4;
    dataCursor = (undefined4 *)(&g_ActiveSoundChannelTable + (short)volumePercent * 0x2c);
    do {
      SetDirectSoundBufferVolumePercent(*dataCursor,channelIndex);
      dataCursor = dataCursor + 1;
      value = value + -1;
    } while (value != 0);
  }
  else if (soundId < 0x10) {
    if ((&g_ActiveSoundChannelMap)[(char)soundId * 2] != -1) {
      SetDirectSoundBufferVolumePercent
                (*(undefined4 *)
                  (&g_ActiveSoundChannelTable +
                  ((int)(short)(&g_ActiveSoundChannelVariantIndex)[(char)soundId * 2] +
                  (short)(&g_ActiveSoundChannelMap)[(char)soundId * 2] * 0xb) * 4),channelIndex);
      return;
    }
  }
  return;
}

