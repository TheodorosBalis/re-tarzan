// Address: 0x0049E800

int SelectPreviousEnabledMenuItem(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  param_1 = param_1 + -1;
  if (-1 < param_1) {
    piVar3 = param_2 + param_1 * 2;
    do {
      if (*piVar3 == 0) break;
      if ((short)piVar3[1] != 1) {
        return param_1;
      }
      param_1 = param_1 + -1;
      piVar3 = piVar3 + -2;
    } while (-1 < param_1);
  }
  iVar4 = 0;
  iVar2 = 0;
  iVar1 = *param_2;
  while (iVar1 != 0) {
    if ((short)param_2[1] != 1) {
      iVar2 = iVar4;
    }
    piVar3 = param_2 + 2;
    param_2 = param_2 + 2;
    iVar4 = iVar4 + 1;
    iVar1 = *piVar3;
  }
  return iVar2;
}


