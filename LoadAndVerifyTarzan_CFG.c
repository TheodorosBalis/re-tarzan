/* Address: 0x00494A40 */

void LoadAndVerifyTarzan_CFG(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = GetFileNameFirst();
  if ((iVar1 != 0) && (iVar1 = FetchAndGetHwdForGameFile(iVar1,&DAT_005156bc), iVar1 != 0)) {
    iVar2 = LoadGameFileInBuffer(&tarzanCFGbuffer,0xbc,1,iVar1);
    if (iVar2 != 1) {
      FileLoadedEpilogueWithCS(iVar1);
      FUN_00494ad0();
      DAT_0053a7f0 = 1;
      return;
    }
    FileLoadedEpilogueWithCS(iVar1);
    DecodeCfgBuffer();
    iVar1 = CalcCfgChecksum();
    if (tarzanCFGbuffer == iVar1) {
      DAT_0053a7f0 = 1;
      return;
    }
    if (tarzanCFGbuffer == -1) {
      DAT_0053a7f0 = 1;
      return;
    }
  }
  FUN_00494ad0();
  DAT_0053a7f0 = 1;
  return;
}

