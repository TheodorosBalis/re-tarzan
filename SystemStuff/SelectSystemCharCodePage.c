/* Address: 0x004B775C */

int SelectSystemCharCodePage(int param_1)

{
  int iVar1;
  bool bVar2;
  
  if (param_1 == -2) {
    DAT_00c46e50 = 1;
                    /* WARNING: Could not recover jumptable at 0x004b7776. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetOEMCP();
    return iVar1;
  }
  if (param_1 == -3) {
    DAT_00c46e50 = 1;
                    /* WARNING: Could not recover jumptable at 0x004b778b. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = GetACP();
    return iVar1;
  }
  bVar2 = param_1 == -4;
  if (bVar2) {
    param_1 = DAT_00c46e98;
  }
  DAT_00c46e50 = (uint)bVar2;
  return param_1;
}

