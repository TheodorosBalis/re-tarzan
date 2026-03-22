/* Address: 0x00494230 */

void LoadAndInitializeIntroCinematic(void)

{
  int iVar1;
  
  if (DAT_0053a304 != 0) {
    iVar1 = LoadECMFilesAndInit();
    if (iVar1 != 0) {
      mciSendCommandA(DAT_0053a2f8,0x808,2,0);
    }
  }
  DAT_0053a304 = 0;
  DAT_0053a30c = 0;
  DAT_0053a300 = 0;
  DAT_0053a310 = 0;
  DAT_0053a314 = 0;
  return;
}

