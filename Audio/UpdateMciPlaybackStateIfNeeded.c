// Address: 0x004941C0

void UpdateMciPlaybackStateIfNeeded(void)

{
  int iVar1;
  
  if (DAT_0053a308 == 0) {
    if (DAT_0053a304 != 0) {
      iVar1 = LoadECMFilesAndInit();
      if (iVar1 != 0) {
        mciSendCommandA(DAT_0053a2f8,0x808,2,0);
      }
    }
    DAT_0053a308 = timeGetTime();
    DAT_0053a304 = 0;
  }
  return;
}


