#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8580
// Label: InitDSound
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 InitDSound(undefined4 soundId)

{
  undefined2 soundMask;
  undefined2 *dataCursor;
  undefined2 localState25;
  undefined2 localState24;
  undefined4 localState23;
  undefined4 localState22;
  undefined2 localState21;
  undefined2 localState20;
  undefined2 localState19;
  undefined4 localState18;
  undefined4 localState17;
  undefined4 localState16;
  undefined4 localState15;
  undefined4 localState14;
  undefined4 localState13;
  undefined4 localState12;
  undefined4 localState11;
  undefined4 localState10;
  undefined4 localState9;
  undefined4 localState8;
  undefined4 localState7;
  undefined4 localState6;
  undefined4 localState5;
  undefined4 localState4;
  undefined4 localState3;
  undefined4 localState2;
  undefined4 localState;
  undefined4 localState26;
  
  if (g_IsDSoundInitialized != 0) {
    return 1;
  }
  SetupAudioBuffers();
  g_DSoundListenerCaps = soundId;
  dataCursor = &g_DSoundVolumeCurve;
  do {
    soundMask = ConvertFpuTopToInt64();
    *dataCursor = soundMask;
    dataCursor = dataCursor + 1;
  } while ((int)dataCursor < 0x9cf219);
  g_DSoundVolumeCurve = 0xd8f0;
  g_DSoundCoCreateInstanceResult = 0;
  g_DSoundCoInitializeResult = LoadLibraryA(s_dsound_dll_00517650);
  if (((g_DSoundCoInitializeResult != (HMODULE)0x0) &&
      (_g_DSoundCreateResult =
            GetProcAddress(g_DSoundCoInitializeResult,s_DirectSoundCreate_0051763c),
      _g_DSoundCreateResult != (FARPROC)0x0)) &&
     ((*_g_DSoundCreateResult)(0,&g_DirectSound,0), g_DirectSound != (int *)0x0)) {
    (**(code **)(*g_DirectSound + 0x18))(g_DirectSound,g_DSoundListenerCaps,3);
    localState18 = 0x14;
    localState17 = 0x91;
    localState16 = 0;
    localState15 = 0;
    localState14 = 0;
    if (g_DirectSound != (int *)0x0) {
      (**(code **)(*g_DirectSound + 0xc))(g_DirectSound,&localState18,&g_PrimarySoundBuffer,0);
    }
    if (g_PrimarySoundBuffer != (int *)0x0) {
      localState19 = 0;
      localState25 = 1;
      localState24 = 2;
      localState23 = 0x5622;
      localState20 = 0x10;
      localState21 = 4;
      localState22 = 0x15888;
      (**(code **)(*g_PrimarySoundBuffer + 0x38))(g_PrimarySoundBuffer,&localState25);
      if (g_PrimarySoundBuffer != (int *)0x0) {
        (**(code **)*g_PrimarySoundBuffer)(g_PrimarySoundBuffer,&DAT_004ba3d0,&g_DSound3DListener);
      }
      localState15 = 0x40;
      localState14 = 0;
      localState13 = 0;
      localState12 = 0;
      localState11 = 0;
      localState10 = 0;
      localState9 = 0;
      localState8 = 0;
      localState7 = 0;
      localState6 = 0x3f800000;
      localState5 = 0;
      localState4 = 0x3f800000;
      localState3 = 0;
      localState2 = 0x3f800000;
      localState = 0x3f800000;
      localState26 = 0x3f800000;
      if (g_DSound3DListener != (int *)0x0) {
        (**(code **)(*g_DSound3DListener + 0x28))(g_DSound3DListener,&localState15,0);
      }
      if (g_PrimarySoundBuffer != (int *)0x0) {
        (**(code **)(*g_PrimarySoundBuffer + 0x30))(g_PrimarySoundBuffer,0,0,1);
      }
      DoDsoundSetupStuff();
      LegacyAudioCheck_DoNothing(0);
      if (((g_DirectSound != (int *)0x0) && (g_PrimarySoundBuffer != (int *)0x0)) &&
         (g_DSound3DListener != (int *)0x0)) {
        g_IsDSoundInitialized = 1;
        return 1;
      }
      g_IsDSoundInitialized = 0;
      return 0;
    }
  }
  FreeDSound();
  g_IsDSoundInitialized = 0;
  return 0;
}

