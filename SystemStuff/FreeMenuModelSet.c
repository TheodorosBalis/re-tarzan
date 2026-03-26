// Address: 0x0041C6C0

void FreeMenuModelSet(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar2 = 0;
    piVar1 = (int *)(param_1 + 0x2c);
    do {
      if ((piVar1[1] != 0) || (*piVar1 != -1)) {
        FUN_0041c8b0(param_1,iVar2);
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 2;
    } while (iVar2 < 7);
    FUN_0041c6b0(*(undefined4 *)(param_1 + 0xc));
    FreeModelHeapBlock(*(undefined4 *)(param_1 + 0xc),&g_ModelLoadHeapState);
    FUN_004adc60(param_1 + 0x10);
    *(undefined4 *)(param_1 + 8) = 0xffffffff;
    return;
  }
  if (*(int *)(param_1 + 8) != -1) {
    if (*(int *)(param_1 + 0x14) != 0) {
      FUN_004adc60(param_1 + 0x10);
    }
    FUN_00429950(*(undefined4 *)(param_1 + 8));
    *(undefined4 *)(param_1 + 8) = 0xffffffff;
  }
  return;
}


