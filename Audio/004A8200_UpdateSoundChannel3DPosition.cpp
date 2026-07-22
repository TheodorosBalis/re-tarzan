#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8200
// Label: UpdateSoundChannel3DPosition
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateSoundChannel3DPosition
               (ushort channelIndex,byte soundId,undefined4 position,undefined4 flags,undefined4 arg5
               )

{
  short channelIndex2;
  int *slotCursor;
  int *slotCursor2;
  
  if (channelIndex < 2000) {
    _param_2 = 4;
    slotCursor2 = (int *)(&g_ActiveSoundChannelTable + (short)channelIndex * 0x2c);
    do {
      slotCursor = (int *)*slotCursor2;
      if (slotCursor != (int *)0x0) {
        (**(code **)(*slotCursor + 0x4c))(slotCursor,position,flags,arg5,1);
      }
      slotCursor2 = slotCursor2 + 1;
      _param_2 = _param_2 + -1;
    } while (_param_2 != 0);
  }
  else if (soundId < 0x10) {
    channelIndex2 = (&g_ActiveSoundChannelMap)[(char)soundId * 2];
    if (((channelIndex2 != -1) && ((&g_LoadedSoundBufferTable)[channelIndex2 * 0xb] != 0)) &&
       (slotCursor2 = *(int **)(&g_ActiveSoundChannelTable +
                          ((int)(short)(&g_ActiveSoundChannelVariantIndex)[(char)soundId * 2] +
                          channelIndex2 * 0xb) * 4), slotCursor2 != (int *)0x0)) {
      (**(code **)(*slotCursor2 + 0x4c))(slotCursor2,position,flags,arg5,1);
      return;
    }
  }
  return;
}

