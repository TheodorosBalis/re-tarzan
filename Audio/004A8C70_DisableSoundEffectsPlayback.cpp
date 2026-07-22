#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8C70
// Label: DisableSoundEffectsPlayback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void DisableSoundEffectsPlayback(void)

{
  int *intCursor;
  short *value;
  
  if (g_SoundEffectsPlaybackMuted == 0) {
    g_SoundEffectsPlaybackMuted = 1;
    StopSoundChannelsMutedBySoundEffectsSetting();
    ManageActiveSoundSlots();
    value = &g_ActiveSoundChannelMap;
    do {
      if ((*value != -1) &&
         (intCursor = (int *)(&g_LoadedSoundBufferTable)[*value * 0xb + (int)value[1]],
         intCursor != (int *)0x0)) {
        (**(code **)(*intCursor + 0x48))(intCursor);
      }
      value = value + 2;
    } while ((int)value < 0x9e4a20);
  }
  return;
}

