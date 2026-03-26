// Address: 0x00453F00

undefined4
ProcessMovieClipOrLogo(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_1 != 0xffffffff) {
    if ((param_1 & 0xc000) == 0x4000) {
      SetActiveMenuContext(&g_MenuSceneContext);
      ProcessLevelLogo((&PTR_DAT_004f2c80)[param_1 & 0xffff3fff]);
      FUN_00453eb0(param_2,param_3,param_4);
    }
    else if ((param_1 & 0xc000) == 0x8000) {
      LoadAndHandleECM(param_1 & 0xffff3fff,0);
      return 0;
    }
  }
  return 0;
}


