// Address: 0x004A8A20

void FreeDSound(void)

{
  DAT_009e4a60 = 1;
  FUN_004a8e40();
  FUN_004a89f0();
  DAT_009e4a60 = 0;
  FUN_004a8930();
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
  if (DAT_009e4a24 != (HMODULE)0x0) {
    FreeLibrary(DAT_009e4a24);
  }
  SetupAudioBuffers();
  return;
}


