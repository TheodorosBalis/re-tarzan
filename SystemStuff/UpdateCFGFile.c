// Address: 0x004947D0

void UpdateCFGFile(byte param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  
  if (-1 < param_2) {
    iVar2 = param_2 + 1;
    puVar1 = (uint *)(&DAT_0053a3bc + param_2 * 4);
    do {
      iVar2 = iVar2 + -1;
      *puVar1 = *puVar1 | 1 << (param_1 & 0x1f);
      puVar1 = puVar1 + -1;
    } while (iVar2 != 0);
  }
  FUN_00494810();
  return;
}


