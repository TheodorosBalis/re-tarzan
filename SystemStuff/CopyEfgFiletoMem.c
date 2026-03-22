/* Address: 0x00498860 */

void CopyEfgFiletoMem(int param_1,int param_2)

{
  int iVar1;
  
  if (((DAT_00719db8 != 0) && (-1 < param_1)) && (param_1 < DAT_00719e08)) {
    iVar1 = (param_2 - (&DAT_00719dc8)[param_1]) + 0x20000;
    FUN_0049a7a0(DAT_00719db8,(&DAT_00719e0c)[param_1],0);
    LoadAndCopyEfgToBuffer(iVar1,(&DAT_00719dc8)[param_1],1,DAT_00719db8);
    FillunknownEfgBuffer(param_2,iVar1);
  }
  return;
}

