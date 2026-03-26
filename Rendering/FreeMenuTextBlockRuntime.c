// Address: 0x004ADCB0

void FreeMenuTextBlockRuntime(int *param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_4;
  
  if (param_1 != (int *)0x0) {
    if ((param_1[1] != 0) && (iVar2 = 0, 0 < *param_1)) {
      iVar4 = param_1[1] + 0x10;
      do {
        FUN_004adff0(iVar4);
        iVar2 = iVar2 + 1;
        iVar4 = iVar4 + 0x26;
      } while (iVar2 < *param_1);
    }
    piVar1 = (int *)param_1[3];
    if ((piVar1 != (int *)0x0) && (*piVar1 != 0)) {
      local_4 = 0;
      piVar1 = (int *)(*piVar1 + (int)piVar1);
      piVar3 = piVar1 + 1;
      if (0 < *piVar1) {
        do {
          iVar2 = *piVar3 + (int)piVar3;
          iVar4 = 0;
          if (0 < piVar3[2]) {
            do {
              FUN_004adff0(iVar2);
              iVar4 = iVar4 + 1;
              iVar2 = iVar2 + 4;
            } while (iVar4 < piVar3[2]);
          }
          local_4 = local_4 + 1;
          piVar3 = piVar3 + 5;
        } while (local_4 < *piVar1);
      }
    }
    if (param_1[4] != 0) {
      piVar1 = (int *)param_1[5];
      iVar2 = 0;
      if (0 < param_1[4]) {
        do {
          if (*piVar1 != 0) {
            FreeModelHeapBlock(*piVar1,&g_ModelLoadHeapState);
          }
          *piVar1 = 0;
          piVar1 = (int *)((int)piVar1 + 0x72);
          iVar2 = iVar2 + 1;
        } while (iVar2 < param_1[4]);
      }
    }
  }
  return;
}


