// Address: 0x004A8580

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 InitDSound(undefined4 param_1)

{
  undefined2 uVar1;
  undefined2 *puVar2;
  undefined2 uStack_68;
  undefined2 uStack_66;
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined2 uStack_5c;
  undefined2 uStack_5a;
  undefined2 uStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  if (g_IsDSoundInitialized != 0) {
    return 1;
  }
  SetupAudioBuffers();
  DAT_009e4a40 = param_1;
  puVar2 = &g_DSoundVolumeCurve;
  do {
    uVar1 = ConvertFpuTopToInt64();
    *puVar2 = uVar1;
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0x9cf219);
  g_DSoundVolumeCurve = 0xd8f0;
  DAT_009cf218 = 0;
  DAT_009e4a24 = LoadLibraryA(s_dsound_dll_00517650);
  if (((DAT_009e4a24 != (HMODULE)0x0) &&
      (_DAT_009e4a20 = GetProcAddress(DAT_009e4a24,s_DirectSoundCreate_0051763c),
      _DAT_009e4a20 != (FARPROC)0x0)) &&
     ((*_DAT_009e4a20)(0,&g_DirectSound,0), g_DirectSound != (int *)0x0)) {
    (**(code **)(*g_DirectSound + 0x18))(g_DirectSound,DAT_009e4a40,3);
    uStack_54 = 0x14;
    uStack_50 = 0x91;
    uStack_4c = 0;
    uStack_48 = 0;
    uStack_44 = 0;
    if (g_DirectSound != (int *)0x0) {
      (**(code **)(*g_DirectSound + 0xc))(g_DirectSound,&uStack_54,&g_PrimarySoundBuffer,0);
    }
    if (g_PrimarySoundBuffer != (int *)0x0) {
      uStack_58 = 0;
      uStack_68 = 1;
      uStack_66 = 2;
      uStack_64 = 0x5622;
      uStack_5a = 0x10;
      uStack_5c = 4;
      uStack_60 = 0x15888;
      (**(code **)(*g_PrimarySoundBuffer + 0x38))(g_PrimarySoundBuffer,&uStack_68);
      if (g_PrimarySoundBuffer != (int *)0x0) {
        (**(code **)*g_PrimarySoundBuffer)(g_PrimarySoundBuffer,&DAT_004ba3d0,&g_DSound3DListener);
      }
      uStack_48 = 0x40;
      uStack_44 = 0;
      uStack_40 = 0;
      uStack_3c = 0;
      uStack_38 = 0;
      uStack_34 = 0;
      uStack_30 = 0;
      uStack_2c = 0;
      uStack_28 = 0;
      uStack_24 = 0x3f800000;
      uStack_20 = 0;
      uStack_1c = 0x3f800000;
      uStack_18 = 0;
      uStack_14 = 0x3f800000;
      uStack_10 = 0x3f800000;
      uStack_c = 0x3f800000;
      if (g_DSound3DListener != (int *)0x0) {
        (**(code **)(*g_DSound3DListener + 0x28))(g_DSound3DListener,&uStack_48,0);
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


