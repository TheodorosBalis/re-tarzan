/* Address: 0x004ABE80 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void scan_input(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = IsGamePaused();
  if (iVar1 == 0) {
    uVar2 = thunk_FUN_0049e130(0);
    if (DAT_00a43a20 != 0) {
      if (uVar2 != 0) {
        DAT_00533ff8._0_1_ = (byte)DAT_00533ff8 | 0x10;
      }
      uVar2 = FUN_004abf10(DAT_00a43a20);
    }
    if ((uVar2 & 0x80000000) != 0) {
      FUN_004abd50();
    }
    uVar2 = uVar2 & 0x7fffffff;
  }
  MenuKeyPressed = uVar2;
  MenuKeyJustReleased = DAT_0051cf4c ^ uVar2;
  DAT_0051cf4c = uVar2;
  DAT_0051cf5c = 0;
  DAT_0051cf54 = 0;
  _DAT_0051cf58 = 0;
  return;
}

