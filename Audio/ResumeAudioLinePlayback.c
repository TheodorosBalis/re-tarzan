// Address: 0x004A8EA0

void ResumeAudioLinePlayback(void)

{
  DWORD DVar1;
  int iVar2;
  
  if ((g_AudioLineSoundBuffer != (int *)0x0) && (g_AudioLinePauseStartTick != 0)) {
    (**(code **)(*g_AudioLineSoundBuffer + 0x30))(g_AudioLineSoundBuffer,0,0,1);
    DVar1 = timeGetTime();
    iVar2 = DVar1 - g_AudioLinePauseStartTick;
    g_AudioLinePauseStartTick = 0;
    g_AudioLineNextRefillTick = g_AudioLineNextRefillTick + iVar2;
  }
  return;
}


