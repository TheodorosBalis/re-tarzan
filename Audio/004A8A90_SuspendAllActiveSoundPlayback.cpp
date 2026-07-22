#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8A90
// Label: SuspendAllActiveSoundPlayback
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void SuspendAllActiveSoundPlayback(void)

{
  int *intCursor;
  short *value;
  
  if (g_AllSoundPlaybackSuspended == 0) {
    g_AllSoundPlaybackSuspended = 1;
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

