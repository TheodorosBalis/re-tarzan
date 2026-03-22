/* Address: 0x004944F0 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 InitCdPlayerAndEMCFiles(undefined4 param_1)

{
  HWND hWnd;
  
  _DAT_0053a318 = param_1;
  DAT_0053a304 = 0;
  DAT_0053a308 = 0;
  DAT_0053a30c = 0;
  DAT_0053a300 = 0;
  DAT_0053a314 = 0;
  DAT_0053a2fc = 0;
  DAT_0053a310 = 0;
  DAT_0053a2f8 = 0;
  hWnd = FindWindowA(s_SJE_CdPlayerClass_005156ec,(LPCSTR)0x0);
  if (hWnd != (HWND)0x0) {
    SendMessageTimeoutA(hWnd,0x10,0,0,2,500,(PDWORD_PTR)0x0);
  }
  DAT_0053a31c = 1;
  LoadECMFilesAndInit();
  return 1;
}

