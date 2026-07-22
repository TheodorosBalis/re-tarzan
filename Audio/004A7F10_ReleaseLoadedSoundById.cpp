#include "tarzan_ghidra_types.hpp"

// Address: 0x004A7F10
// Label: ReleaseLoadedSoundById
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void ReleaseLoadedSoundById(ushort soundId)

{
  byte flagByte;
  int *intCursor;
  int value;
  int value2;
  int value3;
  int *intCursor2;
  
  if (soundId < 2000) {
    value = (int)(short)soundId;
    value2 = value * 0x2c;
    if ((&g_LoadedSoundBufferTable)[value * 0xb] != 0) {
      if (g_ActiveSoundBufferReleaseCursor == 0) {
        flagByte = (&g_LoadedSoundFlags)[value2];
        if ((flagByte & 4) != 0) {
          return;
        }
        value3 = 0;
        intCursor2 = &g_LoadedSoundBufferTable + value * 0xb;
        do {
          if (((*intCursor2 != 0) && ((&g_LoadedSoundVariantBusyFlags)[value3 + value2] != '\0')) &&
             ((flagByte & 1) == 0)) {
            (&g_LoadedSoundFlags)[value2] = flagByte | 2;
            return;
          }
          value3 = value3 + 1;
          intCursor2 = intCursor2 + 1;
        } while (value3 < 4);
      }
      if (*(int *)(&g_LoadedSoundRefCountTable + value2) != 0) {
        g_SoundMixBufferByteSize =
             g_SoundMixBufferByteSize - *(int *)(&g_LoadedSoundRefCountTable + value2);
        g_SoundMixBufferWriteCursor = g_SoundMixBufferWriteCursor + -1;
        g_SoundSystemInitialized = g_SoundSystemInitialized + 1;
      }
      intCursor2 = (int *)(&g_LastReleasedSoundId + value2);
      value2 = 4;
      do {
        intCursor = (int *)*intCursor2;
        if (intCursor != (int *)0x0) {
          (**(code **)(*intCursor + 0x48))(intCursor);
        }
        intCursor = (int *)intCursor2[4];
        if (intCursor != (int *)0x0) {
          (**(code **)(*intCursor + 8))(intCursor);
        }
        intCursor = (int *)*intCursor2;
        if (intCursor != (int *)0x0) {
          (**(code **)(*intCursor + 8))(intCursor);
        }
        intCursor2 = intCursor2 + -1;
        value2 = value2 + -1;
      } while (value2 != 0);
      intCursor2 = &g_LoadedSoundBufferTable + value * 0xb;
      for (value2 = 0xb; value2 != 0; value2 = value2 + -1) {
        *intCursor2 = 0;
        intCursor2 = intCursor2 + 1;
      }
    }
  }
  return;
}

