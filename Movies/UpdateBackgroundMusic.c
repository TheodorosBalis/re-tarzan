// Address: 0x004940E0

void UpdateBackgroundMusic(void)

{
  DWORD DVar1;
  
  if ((DAT_0053a310 != 0) && (DAT_0053a30c == 0)) {
    DVar1 = timeGetTime();
    if ((uint)(DAT_0053a314 * 1000) <= DVar1 - DAT_0053a300) {
      DAT_0053a304 = 0;
      InitAudioForECMFile(DAT_0053a310);
    }
  }
  return;
}


