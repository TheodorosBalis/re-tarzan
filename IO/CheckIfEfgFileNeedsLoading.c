/* Address: 0x0049AA80 */

void CheckIfEfgFileNeedsLoading(void)

{
  int iVar1;
  
  iVar1 = ReadFromGlobal7222E0();
  if (iVar1 != 0) {
    if ((((DAT_007222e8 != 0) && (DAT_007222e0 != 0)) && (DAT_007222e4 != 0)) && (DAT_007222ec != 0)
       ) {
      iVar1 = DAT_007222e4;
      if (DAT_007222e0 < DAT_007222e4) {
        iVar1 = DAT_007222e0;
      }
      iVar1 = LoadAndCopyEfgToBuffer(DAT_007222e8,1,iVar1,DAT_007222ec);
      DAT_007222e8 = DAT_007222e8 + iVar1;
      DAT_007222e0 = DAT_007222e0 - iVar1;
      if (((0 < iVar1) && (DAT_007222e4 <= iVar1)) && (0 < DAT_007222e0)) {
        return;
      }
    }
    FUN_0049a930();
  }
  return;
}

