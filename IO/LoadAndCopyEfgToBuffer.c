/* Address: 0x0049A690 */

int LoadAndCopyEfgToBuffer(undefined4 param_1,uint param_2,uint param_3,uint param_4)

{
  int iVar1;
  
  if (DAT_007222d4 == 0) {
    iVar1 = LoadGameFileInBuffer(param_1,param_2,param_3,param_4);
    if ((iVar1 < (int)param_3) && ((*(byte *)(param_4 + 0xc) & 0x20) != 0)) {
      InternalError(s_FSYS_fread_1__00515c30);
    }
    return iVar1;
  }
  if (0x800 < param_4) {
    return 0;
  }
  if ((DAT_00515ad0 != param_4) || (*(int *)(&DAT_0071feac + param_4 * 4) == 0)) {
    DAT_00515ad0 = param_4;
    SetFilePTRofEfGFilewithCS
              (DAT_007222cc,
               *(int *)(&DAT_00719ea8 + param_4 * 0xc) + *(int *)(&DAT_0071feac + param_4 * 4),0);
  }
  if (*(uint *)(&DAT_00719eac + param_4 * 0xc) <=
      param_2 * param_3 + *(int *)(&DAT_0071feac + param_4 * 4)) {
    param_3 = param_2;
    if (param_2 == 0) {
      param_3 = 1;
    }
    param_3 = (*(uint *)(&DAT_00719eac + param_4 * 0xc) - *(int *)(&DAT_0071feac + param_4 * 4)) /
              param_3;
  }
  iVar1 = LoadGameFileInBuffer(param_1,param_2,param_3,DAT_007222cc);
  *(uint *)(&DAT_0071feac + param_4 * 4) = *(int *)(&DAT_0071feac + param_4 * 4) + iVar1 * param_2;
  return iVar1;
}

