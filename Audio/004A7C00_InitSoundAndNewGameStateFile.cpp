#include "tarzan_ghidra_types.hpp"

// Address: 0x004A7C00
// Label: InitSoundAndNewGameStateFile
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Type propagation algorithm not settling */

void InitSoundAndNewGameStateFile(uint soundId)

{
  int *intCursor;
  undefined4 *stateFlags;
  int *intCursor3;
  ushort stateFlags2;
  ushort stateFlags3;
  undefined4 stateFlags4;
  int value2;
  int value3;
  int value4;
  int value;
  int *intCursor2;
  bool flagByte;
  int localState14;
  uint localState13;
  int localState12;
  undefined2 localState11;
  undefined2 localState10;
  int localState9;
  int localState8;
  ushort localState7;
  ushort localState15;
  undefined2 localState6;
  int localState5 [4];
  undefined4 localState4;
  undefined2 *localState3;
  int localState2;
  undefined1 localState [256];
  
  value4 = 0;
  localState14 = 0;
  localState13 = 0;
  if (g_IsDSoundInitialized != 0) {
    if ((ushort)soundId < 2000) {
      value3 = (int)(short)(ushort)soundId;
      value = value3 * 0x2c;
      if (((&g_LoadedSoundFlags)[value] & 2) != 0) {
        (&g_LoadedSoundFlags)[value] = (&g_LoadedSoundFlags)[value] & 0xfd;
        return;
      }
      intCursor = &g_LoadedSoundBufferTable + value3 * 0xb;
      if ((&g_LoadedSoundBufferTable)[value3 * 0xb] == 0) {
        intCursor2 = intCursor;
        for (value2 = 0xb; value2 != 0; value2 = value2 + -1) {
          *intCursor2 = 0;
          intCursor2 = intCursor2 + 1;
        }
        if (100 < g_SoundSystemInitialized) {
          g_SoundSystemInitialized = 0;
        }
        LoadSFX(localState,s_t__win_sound_sfx_pc__04d_esf_0051761c,soundId & 0xffff);
        stateFlags4 = OpenAudioEsfStream(localState,&localState2,&localState12,localState5);
        *(undefined4 *)(&g_LoadedSoundRefCountTable + value) = stateFlags4;
        *(undefined2 *)(&g_LoadedSoundNextVariantIndex + value) = 0;
        localState11 = 1;
        localState10 = 1;
        (&g_LoadedSoundFlags)[value] =
             (localState5[0] != 0 ^ (&g_LoadedSoundFlags)[value] & 0xf9) & 1 ^
             (&g_LoadedSoundFlags)[value] & 0xf9;
        localState9 = (-(uint)(localState12 != 0x2b11) & 0x2b11) + 0x2b11;
        localState5[3] = *(int *)(&g_LoadedSoundRefCountTable + value);
        localState6 = 0;
        stateFlags2 = (-(ushort)(localState2 != 8) & 8) + 8;
        stateFlags3 = stateFlags2 >> 3;
        _local_124 = CONCAT22(stateFlags2,stateFlags3);
        localState8 = (uint)stateFlags3 * localState9;
        localState3 = &localState11;
        localState5[1] = 0x14;
        localState5[2] = 0x92;
        localState4 = 0;
        if (g_DirectSound != (int *)0x0) {
          (**(code **)(*g_DirectSound + 0xc))(g_DirectSound,localState5 + 1,intCursor,0);
        }
        intCursor2 = (int *)*intCursor;
        if (intCursor2 != (int *)0x0) {
          g_SoundMixBufferByteSize =
               g_SoundMixBufferByteSize + *(int *)(&g_LoadedSoundRefCountTable + value);
          g_SoundMixBufferWriteCursor = g_SoundMixBufferWriteCursor + 1;
          (**(code **)(*intCursor2 + 0x2c))
                    (intCursor2,0,*(int *)(&g_LoadedSoundRefCountTable + value),&localState14,&localState13,
                     0,0,0);
          if ((localState14 != 0) && (*(uint *)(&g_LoadedSoundRefCountTable + value) <= localState13)) {
            LoadUnknownFileOnNewGameState(localState14);
          }
          intCursor2 = (int *)*intCursor;
          if (intCursor2 != (int *)0x0) {
            (**(code **)(*intCursor2 + 0x4c))(intCursor2,localState14,localState13,0,0);
          }
          do {
            intCursor2 = g_DirectSound;
            if (value4 != 0) {
              intCursor3 = &g_LoadedSoundBufferTable + value3 * 0xb + value4;
              flagByte = g_DirectSound != (int *)0x0;
              *intCursor3 = 0;
              if (flagByte) {
                (**(code **)(*intCursor2 + 0x14))(intCursor2,*intCursor,intCursor3);
              }
              if (*intCursor3 == 0) {
                ReleaseLoadedSoundById(soundId);
                break;
              }
            }
            value = value3 * 0xb + value4;
            intCursor2 = (int *)(&g_ActiveSoundChannelTable + value * 4);
            *intCursor2 = 0;
            stateFlags = (undefined4 *)(&g_LoadedSoundBufferTable)[value];
            if (stateFlags != (undefined4 *)0x0) {
              (**(code **)*stateFlags)(stateFlags,&DAT_004ba3e0,intCursor2);
            }
            intCursor3 = (int *)(&g_LoadedSoundBufferTable)[value];
            if (intCursor3 != (int *)0x0) {
              (**(code **)(*intCursor3 + 0x34))(intCursor3,0);
            }
            intCursor3 = (int *)(&g_LoadedSoundBufferTable)[value];
            if (intCursor3 != (int *)0x0) {
              (**(code **)(*intCursor3 + 0x3c))(intCursor3,0);
            }
            intCursor3 = (int *)*intCursor2;
            if (intCursor3 != (int *)0x0) {
              (**(code **)(*intCursor3 + 0x4c))(intCursor3,0,0,0,0);
            }
            intCursor2 = (int *)*intCursor2;
            if (intCursor2 != (int *)0x0) {
              (**(code **)(*intCursor2 + 0x50))(intCursor2,0,0,0,0);
            }
            value4 = value4 + 1;
            if (3 < value4) {
              CloseAudioEsfStream();
              return;
            }
          } while( true );
        }
        CloseAudioEsfStream();
      }
    }
  }
  return;
}

