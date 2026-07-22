#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8AF0
// Label: ManageActiveSoundSlots
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void __fastcall ManageActiveSoundSlots(uint soundId)

{
  short shortValue;
  int *slotCursor;
  int slotIndex;
  short *value;
  int slotIndex2;
  uint localState;
  
  value = &g_ActiveSoundChannelVariantIndex;
  localState = soundId;
  do {
    shortValue = value[-1];
    if (shortValue != -1) {
      slotIndex = (int)shortValue;
      slotIndex2 = slotIndex * 0x2c;
      if ((&g_LoadedSoundBufferTable)[slotIndex * 0xb] == 0) {
        value[-1] = -1;
      }
      else {
        slotCursor = (int *)(&g_LoadedSoundBufferTable)[slotIndex * 0xb + (int)*value];
        if (slotCursor != (int *)0x0) {
          (**(code **)(*slotCursor + 0x24))(slotCursor,&localState);
        }
        if (((&g_LoadedSoundFlags)[slotIndex2] & 2) == 0) {
LAB_004a8b6e:
          if (g_SoundEffectsPlaybackMuted != 0) goto LAB_004a8bbf;
        }
        else if (((localState & 1) == 0) || (g_SoundEffectsPlaybackMuted != 0)) {
          ReleaseLoadedSoundById(shortValue);
          goto LAB_004a8b6e;
        }
        if ((g_AllSoundPlaybackSuspended == 0) &&
           ((((byte)localState & 1) == 0 || (((byte)localState & 2) != 0)))) {
          (&g_LoadedSoundVariantBusyFlags)[slotIndex2 + *value] = 0;
          value[-1] = -1;
          if (((byte)localState & 2) != 0) {
            ReleaseLoadedSoundById(shortValue);
            if (((&g_LoadedSoundFlags)[slotIndex2] & 2) == 0) {
              InitSoundAndNewGameStateFile(shortValue);
            }
          }
        }
      }
    }
LAB_004a8bbf:
    value = value + 2;
    if (0x9e4a21 < (int)value) {
      return;
    }
  } while( true );
}

