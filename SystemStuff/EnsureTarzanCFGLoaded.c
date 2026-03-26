// Address: 0x004949C0

undefined4 EnsureTarzanCFGLoaded(void)

{
  if (DAT_0053a7ec == 0) {
    DAT_0053a7f0 = 0;
    DAT_0053a7f4 = 0;
    SetCurrentDirectoryToExePath();
    LoadAndVerifyTarzan_CFG();
    DAT_0053a334 = DAT_0053a334 + 1;
    if (DAT_0053a338 != 0) {
      bLastTimeCrashed = 1;
      DAT_0053a7ec = 1;
      return 1;
    }
    DAT_0053a338 = 1;
    FUN_00494810();
    DAT_0053a7ec = 1;
  }
  return 1;
}


