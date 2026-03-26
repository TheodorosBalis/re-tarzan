// Address: 0x004A8E70

void PauseAudioLinePlayback(void)

{
  DWORD DVar1;
  
  if ((g_AudioLineSoundBuffer != (int *)0x0) && (g_AudioLinePauseStartTick == 0)) {
    DVar1 = timeGetTime();
    g_AudioLinePauseStartTick = DVar1 | 1;
    if (g_AudioLineSoundBuffer != (int *)0x0) {
      (**(code **)(*g_AudioLineSoundBuffer + 0x48))(g_AudioLineSoundBuffer);
    }
  }
  return;
}


