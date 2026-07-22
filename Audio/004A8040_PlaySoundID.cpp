#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8040
// Label: PlaySoundID
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

char PlaySoundID(ushort soundId,byte position,undefined4 outParams,undefined4 flags,
                undefined4 arg5)

{
  short shortValue;
  int *intCursor;
  char resultFlag;
  uint soundMask;
  int value;
  int value2;
  int value3;
  
  if (((g_IsDSoundInitialized != 0) && (g_AllSoundPlaybackSuspended == 0)) && (soundId < 2000)) {
    value3 = (int)(short)soundId;
    value2 = value3 * 0x2c;
    if ((((&g_LoadedSoundBufferTable)[value3 * 0xb] != 0) &&
        ((g_SoundEffectsPlaybackMuted == 0 || (((&g_LoadedSoundFlags)[value2] & 1) != 0)))) &&
       ((&g_LoadedSoundVariantBusyFlags)[value2 + *(short *)(&g_LoadedSoundNextVariantIndex + value2)]
        == '\0')) {
      resultFlag = FindNextFreeSoundChannel();
      if (resultFlag != -1) {
        value = (int)resultFlag;
        shortValue = *(short *)(&g_LoadedSoundNextVariantIndex + value2);
        (&g_ActiveSoundChannelMap)[value * 2] = soundId;
        (&g_ActiveSoundChannelVariantIndex)[value * 2] = shortValue;
        if ((position < 0x65) &&
           (intCursor = (int *)(&g_LoadedSoundBufferTable)[value3 * 0xb + (int)shortValue],
           intCursor != (int *)0x0)) {
          (**(code **)(*intCursor + 0x3c))(intCursor,(int)(short)(&g_DSoundVolumeCurve)[(char)position]);
        }
        intCursor = *(int **)(&g_ActiveSoundChannelTable +
                          ((int)(short)(&g_ActiveSoundChannelVariantIndex)[value * 2] + value3 * 0xb)
                          * 4);
        if (intCursor != (int *)0x0) {
          (**(code **)(*intCursor + 0x4c))(intCursor,outParams,flags,arg5,0);
        }
        if ((g_SoundEffectsPlaybackMuted == 0) &&
           (intCursor = (int *)(&g_LoadedSoundBufferTable)
                            [(int)*(short *)(&g_LoadedSoundNextVariantIndex + value2) + value3 * 0xb],
           intCursor != (int *)0x0)) {
          (**(code **)(*intCursor + 0x30))(intCursor,0,0,(&g_LoadedSoundFlags)[value2] & 1);
        }
        (&g_LoadedSoundVariantBusyFlags)[value2 + *(short *)(&g_LoadedSoundNextVariantIndex + value2)]
             = 1;
        soundMask = (int)*(short *)(&g_LoadedSoundNextVariantIndex + value2) + 1U & 0x80000003;
        if ((int)soundMask < 0) {
          soundMask = (soundMask - 1 | 0xfffffffc) + 1;
        }
        *(short *)(&g_LoadedSoundNextVariantIndex + value2) = (short)soundMask;
        return resultFlag;
      }
    }
  }
  return -1;
}

