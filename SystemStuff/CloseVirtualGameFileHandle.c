// Address: 0x0049A660

undefined4 CloseVirtualGameFileHandle(uint param_1)

{
  undefined4 uVar1;
  
  if (g_IsTarzanFsdArchiveActive == 0) {
    uVar1 = FileLoadedEpilogueWithCS(param_1);
    return uVar1;
  }
  if (0x800 < param_1) {
    return 0;
  }
  *(undefined4 *)(&g_TarzanFsdHandleSeekOffsets + param_1 * 4) = 0xffffffff;
  return 0;
}


