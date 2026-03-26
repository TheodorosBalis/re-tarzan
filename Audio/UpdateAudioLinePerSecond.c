// Address: 0x004A91C0

void UpdateAudioLinePerSecond(void)

{
  DWORD DVar1;
  uint uVar2;
  uint uVar3;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined1 local_4 [4];
  
  local_c = 0;
  local_8 = 0;
  local_10 = 0;
  if ((g_AudioLineSoundBuffer != (int *)0x0) && (g_AudioLinePauseStartTick == 0)) {
    DVar1 = timeGetTime();
    if (g_AudioLineNextRefillTick < DVar1) {
      if (g_AudioLineSoundBuffer != (int *)0x0) {
        (**(code **)(*g_AudioLineSoundBuffer + 0x10))(g_AudioLineSoundBuffer,&local_10,local_4);
      }
      local_10 = local_10 / 0xac44;
      if (local_10 == (AudioLineSecondsQueued + 1 & 3)) {
        if (g_AudioLineSoundBuffer != (int *)0x0) {
          (**(code **)(*g_AudioLineSoundBuffer + 0x2c))
                    (g_AudioLineSoundBuffer,(AudioLineSecondsQueued & 3) * 0xac44,0xac44,&local_c,
                     &local_8,0,0,0);
        }
        ReadAudioEsfStreamBytes(local_c,0xac44);
        if (g_AudioLineSoundBuffer != (int *)0x0) {
          (**(code **)(*g_AudioLineSoundBuffer + 0x4c))(g_AudioLineSoundBuffer,local_c,local_8,0,0);
        }
        uVar2 = AudioLineSecondsQueued + 1;
        uVar3 = AudioLineSecondsQueued - 3;
        g_AudioLineNextRefillTick = g_AudioLineNextRefillTick + 1000;
        AudioLineSecondsQueued = uVar2;
        if (g_AudioLineLengthSeconds < uVar3) {
          InitAudioLine();
        }
      }
    }
  }
  return;
}


