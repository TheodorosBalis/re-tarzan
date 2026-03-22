/* Address: 0x00453E00 */

void CIntro::Process(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  FUN_004abdd0();
  FUN_00453f70();
  FUN_00439480(&DAT_0051d280,&DAT_00a43a24,0x200000);
  FUN_00429970();
  LoadFonts(&PTR_DAT_00502d48,&DAT_00c46020);
  GetUserInputsAndZeroGlobals();
  FUN_00453da0();
  puVar2 = &DAT_00534030;
  for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  ProcessMovieClipOrLogo(0x8000,0x3c,0,0xffff);
  ProcessMovieClipOrLogo(0x8001,0x3c,0,0xffff);
  ProcessMovieClipOrLogo(0x8010,0x3c,0,0xffff);
  FUN_004a9ef0(&DAT_00517728);
  ProcessLevelLogo(&DAT_004e57c8);
  TransitionToWorldOrMenu(0);
  return;
}

