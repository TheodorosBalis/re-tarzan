// Address: 0x0049E860

int SelectNextEnabledMenuItem(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 < -1) {
    param_1 = -1;
  }
  iVar4 = 1;
  do {
    param_1 = param_1 + 1;
    iVar3 = param_2 + param_1 * 8;
    iVar2 = *(int *)(param_2 + param_1 * 8);
    while (iVar2 != 0) {
      if (*(short *)(iVar3 + 4) != 1) {
        return param_1;
      }
      piVar1 = (int *)(iVar3 + 8);
      iVar3 = iVar3 + 8;
      param_1 = param_1 + 1;
      iVar2 = *piVar1;
    }
    param_1 = -1;
    iVar4 = iVar4 + -1;
  } while (-1 < iVar4);
  return -1;
}


