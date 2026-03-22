/* Address: 0x004ABC70 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 IsOnMainMenu(void)

{
  int iVar1;
  
  iVar1 = ShouldBeInMainMenu();
  if (iVar1 != 0) {
    FUN_00494970();
  }
  if (DAT_00a43a10 != 0) {
    if (DAT_00a43a10 == 1) {
      _DAT_00a43a14 = 1;
    }
    else if (DAT_00a43a10 == 2) {
      _DAT_00a43a14 = 3;
      DAT_00a43a10 = 0;
      return 0;
    }
    DAT_00a43a10 = 0;
  }
  return 0;
}

