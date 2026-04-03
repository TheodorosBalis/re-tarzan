// Address: 0x00494180

void ResumeBackgroundMusicIfSuspended(void)

{
  DWORD DVar1;
  int iVar2;
  
  if (DAT_0053a30c != 0) {
    DVar1 = timeGetTime();
    iVar2 = DVar1 - DAT_0053a30c;
    DAT_0053a30c = 0;
    DAT_0053a300 = DAT_0053a300 + iVar2;
    HandleDeviceArrivalForECM();
    return;
  }
  return;
}


