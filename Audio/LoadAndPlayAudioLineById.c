// Address: 0x004A8F40

/* WARNING: Type propagation algorithm not settling */

void LoadAndPlayAudioLineById(undefined2 param_1,int param_2)

{
  int iVar1;
  DWORD DVar2;
  undefined4 local_138;
  undefined4 uStack_134;
  int local_130 [5];
  undefined2 *local_11c;
  int local_118;
  undefined2 local_114;
  undefined2 local_112;
  undefined4 local_110;
  undefined4 local_10c;
  undefined2 local_108;
  undefined2 local_106;
  undefined2 local_104;
  undefined1 local_100 [256];
  
  local_138 = 0;
  if ((g_IsDSoundInitialized != 0) && (DAT_009e4a50 == 0)) {
    InitAudioLine();
    DrawGraphicsTextinMem_2(local_100,s_t__win_sound_xa_xa_03d_esf_0051765c,param_1);
    iVar1 = OpenAudioEsfStream(local_100,local_130,&local_118,0);
    g_AudioLineLengthSeconds = iVar1 / 0xac44;
    if ((local_130[0] == 0x10) && (local_118 == 0x5622)) {
      local_110 = 0x5622;
      local_106 = 0x10;
      local_11c = &local_114;
      local_130[4] = 0;
      local_104 = 0;
      local_114 = 1;
      local_112 = 1;
      local_108 = 2;
      local_10c = 0xac44;
      local_130[1] = 0x14;
      local_130[2] = 0x10090;
      local_130[3] = 0x2b110;
      if (g_DirectSound != (int *)0x0) {
        (**(code **)(*g_DirectSound + 0xc))(g_DirectSound,local_130 + 1,&g_AudioLineSoundBuffer,0);
      }
      if (g_AudioLineSoundBuffer != (int *)0x0) {
        FUN_004a8ef0(g_AudioLineSoundBuffer,0);
        if (g_AudioLineSoundBuffer != (int *)0x0) {
          (**(code **)(*g_AudioLineSoundBuffer + 0x2c))
                    (g_AudioLineSoundBuffer,0,0x2b110,&local_138,&uStack_134,0,0,0);
        }
        ReadAudioEsfStreamBytes(local_138,0x2b110);
        if (g_AudioLineSoundBuffer != (int *)0x0) {
          (**(code **)(*g_AudioLineSoundBuffer + 0x4c))
                    (g_AudioLineSoundBuffer,local_138,uStack_134,0,0);
        }
        AudioLineSecondsQueued = 4;
        if (g_AudioLineSoundBuffer != (int *)0x0) {
          (**(code **)(*g_AudioLineSoundBuffer + 0x34))(g_AudioLineSoundBuffer,0);
          if (g_AudioLineSoundBuffer != (int *)0x0) {
            (**(code **)(*g_AudioLineSoundBuffer + 0x3c))
                      (g_AudioLineSoundBuffer,(int)(short)(&g_DSoundVolumeCurve)[param_2]);
            if (g_AudioLineSoundBuffer != (int *)0x0) {
              (**(code **)(*g_AudioLineSoundBuffer + 0x30))(g_AudioLineSoundBuffer,0,0,1);
            }
          }
        }
        DVar2 = timeGetTime();
        g_AudioLineNextRefillTick = DVar2 + 1000;
        return;
      }
    }
    InitAudioLine();
  }
  return;
}


