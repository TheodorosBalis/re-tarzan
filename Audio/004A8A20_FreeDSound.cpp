#include "tarzan_ghidra_types.hpp"

// Address: 0x004A8A20
// Label: FreeDSound
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

void FreeDSound(void)

{
  g_ActiveSoundBufferReleaseCursor = 1;
  ClearAllLoadedSoundPersistentFlags();
  ReleaseNonPersistentLoadedSounds();
  g_ActiveSoundBufferReleaseCursor = 0;
  ReleaseDirectSoundInterfaces();
  InitAudioLine();
  if (g_DSound3DListener != (int *)0x0) {
    (**(code **)(*g_DSound3DListener + 8))(g_DSound3DListener);
  }
  if (g_PrimarySoundBuffer != (int *)0x0) {
    (**(code **)(*g_PrimarySoundBuffer + 8))(g_PrimarySoundBuffer);
  }
  if (g_DirectSound != (int *)0x0) {
    (**(code **)(*g_DirectSound + 8))(g_DirectSound);
  }
  if (g_DSoundCoInitializeResult != (HMODULE)0x0) {
    FreeLibrary(g_DSoundCoInitializeResult);
  }
  SetupAudioBuffers();
  return;
}

