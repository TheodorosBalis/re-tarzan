// Address: 0x004A9190

void UpdateAudioInGameOrOptions(void)

{
  if (g_IsDSoundInitialized != 0) {
    if (g_DSound3DListener != (int *)0x0) {
      (**(code **)(*g_DSound3DListener + 0x44))(g_DSound3DListener);
    }
    UpdateAudioLinePerSecond();
    FUN_004a8af0();
    return;
  }
  return;
}


