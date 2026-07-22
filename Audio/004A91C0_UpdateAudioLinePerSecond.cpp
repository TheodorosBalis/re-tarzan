#include "tarzan_ghidra_types.hpp"

// Address: 0x004A91C0
// Label: UpdateAudioLinePerSecond
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void UpdateAudioLinePerSecond(void)

{
  DWORD mciResult;
  uint soundMask;
  uint soundMask2;
  uint localState;
  undefined4 localState4;
  undefined4 localState3;
  undefined1 localState2 [4];
  
  localState4 = 0;
  localState3 = 0;
  localState = 0;
  if ((g_AudioLineSoundBuffer != (int *)0x0) && (g_AudioLinePauseStartTick == 0)) {
    mciResult = timeGetTime();
    if (g_AudioLineNextRefillTick < mciResult) {
      if (g_AudioLineSoundBuffer != (int *)0x0) {
        (**(code **)(*g_AudioLineSoundBuffer + 0x10))(g_AudioLineSoundBuffer,&localState,localState2);
      }
      localState = localState / 0xac44;
      if (localState == (AudioLineSecondsQueued + 1 & 3)) {
        if (g_AudioLineSoundBuffer != (int *)0x0) {
          (**(code **)(*g_AudioLineSoundBuffer + 0x2c))
                    (g_AudioLineSoundBuffer,(AudioLineSecondsQueued & 3) * 0xac44,0xac44,&localState4,
                     &localState3,0,0,0);
        }
        ReadAudioEsfStreamBytes(localState4,0xac44);
        if (g_AudioLineSoundBuffer != (int *)0x0) {
          (**(code **)(*g_AudioLineSoundBuffer + 0x4c))(g_AudioLineSoundBuffer,localState4,localState3,0,0);
        }
        soundMask = AudioLineSecondsQueued + 1;
        soundMask2 = AudioLineSecondsQueued - 3;
        g_AudioLineNextRefillTick = g_AudioLineNextRefillTick + 1000;
        AudioLineSecondsQueued = soundMask;
        if (g_AudioLineLengthSeconds < soundMask2) {
          InitAudioLine();
        }
      }
    }
  }
  return;
}

