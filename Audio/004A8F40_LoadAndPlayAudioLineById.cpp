#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8F40
// Label: LoadAndPlayAudioLineById
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Type propagation algorithm not settling */

void LoadAndPlayAudioLineById(undefined2 soundId,int position)

{
  int value;
  DWORD mciResult;
  undefined4 scratchBuffer12;
  undefined4 scratchBuffer13;
  int scratchBuffer11 [5];
  undefined2 *scratchBuffer10;
  int scratchBuffer9;
  undefined2 scratchBuffer8;
  undefined2 scratchBuffer7;
  undefined4 scratchBuffer6;
  undefined4 scratchBuffer5;
  undefined2 scratchBuffer4;
  undefined2 scratchBuffer3;
  undefined2 scratchBuffer2;
  undefined1 scratchBuffer [256];
  
  scratchBuffer12 = 0;
  if ((g_IsDSoundInitialized != 0) && (g_SoundEffectsPlaybackMuted == 0)) {
    InitAudioLine();
    LoadSFX(scratchBuffer,s_t__win_sound_xa_xa_03d_esf_0051765c,soundId);
    value = OpenAudioEsfStream(scratchBuffer,scratchBuffer11,&scratchBuffer9,0);
    g_AudioLineLengthSeconds = value / 0xac44;
    if ((scratchBuffer11[0] == 0x10) && (scratchBuffer9 == 0x5622)) {
      scratchBuffer6 = 0x5622;
      scratchBuffer3 = 0x10;
      scratchBuffer10 = &scratchBuffer8;
      scratchBuffer11[4] = 0;
      scratchBuffer2 = 0;
      scratchBuffer8 = 1;
      scratchBuffer7 = 1;
      scratchBuffer4 = 2;
      scratchBuffer5 = 0xac44;
      scratchBuffer11[1] = 0x14;
      scratchBuffer11[2] = 0x10090;
      scratchBuffer11[3] = 0x2b110;
      if (g_DirectSound != (int *)0x0) {
        (**(code **)(*g_DirectSound + 0xc))(g_DirectSound,scratchBuffer11 + 1,&g_AudioLineSoundBuffer,0);
      }
      if (g_AudioLineSoundBuffer != (int *)0x0) {
        SetAudioLineVolumePercent(g_AudioLineSoundBuffer,0);
        if (g_AudioLineSoundBuffer != (int *)0x0) {
          (**(code **)(*g_AudioLineSoundBuffer + 0x2c))
                    (g_AudioLineSoundBuffer,0,0x2b110,&scratchBuffer12,&scratchBuffer13,0,0,0);
        }
        ReadAudioEsfStreamBytes(scratchBuffer12,0x2b110);
        if (g_AudioLineSoundBuffer != (int *)0x0) {
          (**(code **)(*g_AudioLineSoundBuffer + 0x4c))
                    (g_AudioLineSoundBuffer,scratchBuffer12,scratchBuffer13,0,0);
        }
        AudioLineSecondsQueued = 4;
        if (g_AudioLineSoundBuffer != (int *)0x0) {
          (**(code **)(*g_AudioLineSoundBuffer + 0x34))(g_AudioLineSoundBuffer,0);
          if (g_AudioLineSoundBuffer != (int *)0x0) {
            (**(code **)(*g_AudioLineSoundBuffer + 0x3c))
                      (g_AudioLineSoundBuffer,(int)(short)(&g_DSoundVolumeCurve)[position]);
            if (g_AudioLineSoundBuffer != (int *)0x0) {
              (**(code **)(*g_AudioLineSoundBuffer + 0x30))(g_AudioLineSoundBuffer,0,0,1);
            }
          }
        }
        mciResult = timeGetTime();
        g_AudioLineNextRefillTick = mciResult + 1000;
        return;
      }
    }
    InitAudioLine();
  }
  return;
}

