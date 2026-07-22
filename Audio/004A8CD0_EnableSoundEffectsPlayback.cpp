#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8CD0
// Label: EnableSoundEffectsPlayback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void EnableSoundEffectsPlayback(void)

{
  short shortValue;
  int *intCursor;
  short *value;
  
  if (g_SoundEffectsPlaybackMuted != 0) {
    g_SoundEffectsPlaybackMuted = 0;
    if (g_AllSoundPlaybackSuspended == 0) {
      value = &g_ActiveSoundChannelMap;
      do {
        shortValue = *value;
        if (shortValue != -1) {
          intCursor = (int *)(&g_LoadedSoundBufferTable)[(int)value[1] + shortValue * 0xb];
          if (intCursor != (int *)0x0) {
            (**(code **)(*intCursor + 0x30))(intCursor,0,0,(&g_LoadedSoundFlags)[shortValue * 0x2c] & 1);
          }
        }
        value = value + 2;
      } while ((int)value < 0x9e4a20);
    }
    return;
  }
  return;
}

