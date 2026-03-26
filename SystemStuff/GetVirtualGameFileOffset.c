// Address: 0x0049A850

undefined4 GetVirtualGameFileOffset(uint param_1)

{
  undefined4 uVar1;
  
  if (g_IsTarzanFsdArchiveActive == 0) {
    uVar1 = FUN_004af63a(param_1);
    return uVar1;
  }
  if (0x800 < param_1) {
    return 0xffffffff;
  }
  return *(undefined4 *)(&g_TarzanFsdHandleSeekOffsets + param_1 * 4);
}


