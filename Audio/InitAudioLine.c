// Address: 0x004A9140

void InitAudioLine(void)

{
  if (g_AudioLineSoundBuffer != (int *)0x0) {
    (**(code **)(*g_AudioLineSoundBuffer + 0x3c))(g_AudioLineSoundBuffer,(int)g_DSoundVolumeCurve);
    if (g_AudioLineSoundBuffer != (int *)0x0) {
      (**(code **)(*g_AudioLineSoundBuffer + 0x48))(g_AudioLineSoundBuffer);
      if (g_AudioLineSoundBuffer != (int *)0x0) {
        (**(code **)(*g_AudioLineSoundBuffer + 8))(g_AudioLineSoundBuffer);
      }
    }
  }
  g_AudioLineSoundBuffer = (int *)0x0;
  CloseAudioEsfStream();
  g_AudioLinePauseStartTick = 0;
  return;
}


