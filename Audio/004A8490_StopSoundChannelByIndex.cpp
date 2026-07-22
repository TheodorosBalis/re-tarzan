#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8490
// Label: StopSoundChannelByIndex
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void StopSoundChannelByIndex(ushort channelIndex2,byte soundId)

{
  short channelIndex3;
  int *slotCursor;
  int channelIndex;
  int *slotCursor2;
  
  if (channelIndex2 < 2000) {
    channelIndex = 0;
    slotCursor2 = &g_LoadedSoundBufferTable + (short)channelIndex2 * 0xb;
    do {
      slotCursor = (int *)*slotCursor2;
      if (slotCursor != (int *)0x0) {
        (**(code **)(*slotCursor + 0x48))(slotCursor);
      }
      slotCursor = (int *)*slotCursor2;
      if (slotCursor != (int *)0x0) {
        (**(code **)(*slotCursor + 0x34))(slotCursor,0);
      }
      (&g_LoadedSoundVariantBusyFlags)[(short)channelIndex2 * 0x2c + channelIndex] = 0;
      channelIndex = channelIndex + 1;
      slotCursor2 = slotCursor2 + 1;
    } while (channelIndex < 4);
  }
  else if (soundId < 0x10) {
    channelIndex = (int)(char)soundId;
    if ((&g_ActiveSoundChannelMap)[channelIndex * 2] != -1) {
      slotCursor2 = (int *)(&g_LoadedSoundBufferTable)
                      [(short)(&g_ActiveSoundChannelMap)[channelIndex * 2] * 0xb +
                       (int)(short)(&g_ActiveSoundChannelVariantIndex)[channelIndex * 2]];
      if (slotCursor2 != (int *)0x0) {
        (**(code **)(*slotCursor2 + 0x48))(slotCursor2);
      }
      slotCursor2 = (int *)(&g_LoadedSoundBufferTable)
                      [(short)(&g_ActiveSoundChannelMap)[channelIndex * 2] * 0xb +
                       (int)(short)(&g_ActiveSoundChannelVariantIndex)[channelIndex * 2]];
      if (slotCursor2 != (int *)0x0) {
        (**(code **)(*slotCursor2 + 0x34))(slotCursor2,0);
      }
      channelIndex3 = (&g_ActiveSoundChannelMap)[channelIndex * 2];
      (&g_ActiveSoundChannelMap)[channelIndex * 2] = 0xffff;
      (&g_LoadedSoundVariantBusyFlags)
      [channelIndex3 * 0x2c + (int)(short)(&g_ActiveSoundChannelVariantIndex)[channelIndex * 2]] = 0;
      return;
    }
  }
  return;
}

