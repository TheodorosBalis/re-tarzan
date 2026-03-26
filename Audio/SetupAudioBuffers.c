// Address: 0x004A8980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void SetupAudioBuffers(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_009cf220;
  for (iVar1 = 22000; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)&DAT_009e49e0;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0xffffffff;
    puVar2 = puVar2 + 1;
  }
  DAT_009e4a24 = 0;
  _DAT_009e4a20 = 0;
  DAT_009e4a40 = 0;
  DAT_009e4a50 = 0;
  DAT_009e4a4c = 0;
  DAT_009e4a58 = 0;
  DAT_009e4a54 = 0;
  DAT_009e4a48 = 0;
  g_PrimarySoundBuffer = 0;
  g_DSound3DListener = 0;
  g_IsDSoundInitialized = 0;
  return;
}


