/* Address: 0x0047ECE0 */

void LoadGameLevel(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)0x0;
  if (-1 < DAT_00533fe4) {
    iVar1 = (int)DAT_00533fe4;
    DAT_00533fe0._2_1_ = *(undefined1 *)(&DAT_004f2668 + iVar1 * 0xf);
    puVar2 = &DAT_004f2668 + iVar1 * 0xf;
    DAT_0053402c = -(uint)((&DAT_004f266c)[iVar1 * 0xf] != 0xffffffff) &
                   (&DAT_004f266c)[iVar1 * 0xf];
  }
  DAT_00533ff4._0_2_ = 0;
  LoadFonts(&PTR_DAT_0050df58,&DAT_00c46024);
  GetUserInputsAndZeroGlobals();
  FUN_004a9ef0(&DAT_00517728);
  if (puVar2 != (undefined4 *)0x0) {
    if (DAT_00533fe8 == 0) {
      ProcessMovieClipOrLogo(puVar2[3],10000,0,0x1000);
    }
    if (puVar2[2] != -1) {
      FUN_004a9ef0(&DAT_00517728);
      ProcessLevelLogo((&PTR_DAT_004f2c80)[puVar2[2] & 0xffff3fff]);
    }
  }
  TransitionToWorldOrMenu(1);
  return;
}

