// Address: 0x0049A7A0

undefined4 SeekVirtualGameFileHandle(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (g_IsTarzanFsdArchiveActive == 0) {
    uVar1 = SetFilePTRofEfGFilewithCS(param_1,param_2,param_3);
    return uVar1;
  }
  if (0x800 < param_1) {
    return 0xffffffff;
  }
  if (param_3 == 1) {
    iVar2 = *(int *)(&g_TarzanFsdHandleSeekOffsets + param_1 * 4);
  }
  else {
    if (param_3 != 2) goto LAB_0049a7e9;
    iVar2 = *(int *)(&g_TarzanFsdEntrySizes + param_1 * 0xc);
  }
  param_2 = iVar2 + param_2;
LAB_0049a7e9:
  *(int *)(&g_TarzanFsdHandleSeekOffsets + param_1 * 4) = param_2;
  if (*(uint *)(&g_TarzanFsdEntrySizes + param_1 * 0xc) <
      *(uint *)(&g_TarzanFsdHandleSeekOffsets + param_1 * 4)) {
    *(uint *)(&g_TarzanFsdHandleSeekOffsets + param_1 * 4) =
         *(uint *)(&g_TarzanFsdEntrySizes + param_1 * 0xc);
  }
  uVar1 = SetFilePTRofEfGFilewithCS
                    (g_TarzanFsdArchiveHandle,
                     *(int *)(&g_TarzanFsdEntryOffsets + param_1 * 0xc) +
                     *(int *)(&g_TarzanFsdHandleSeekOffsets + param_1 * 4),0);
  return uVar1;
}


