// Address: 0x004944A0

void ResumeBackgroundMusicAfterDeviceArrival(void)

{
  int iVar1;
  DWORD DVar2;
  
  if ((DAT_0053a310 != 0) && (DAT_0053a30c == 0)) {
    iVar1 = LoadECMFilesAndInit();
    if (iVar1 != 0) {
      iVar1 = IsBackgroundMusicPlaying();
      if (iVar1 == 0) {
        DVar2 = timeGetTime();
        PlayBackgroundMusicTrackFromSecond(DAT_0053a310,(DVar2 - DAT_0053a300) / 1000);
      }
    }
  }
  return;
}


