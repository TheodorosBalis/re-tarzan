// Address: 0x00439520

void InsertModelHeapFreeBlockSorted(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 4) == 0) {
    *(int *)(param_2 + 4) = param_1;
    *(undefined4 *)(param_1 + 0x14) = 0;
    *(undefined4 *)(param_1 + 0x10) = 0;
    return;
  }
  iVar2 = *(int *)(param_2 + 4);
  while( true ) {
    if (*(uint *)(param_1 + 8) <= *(uint *)(iVar2 + 8)) {
      iVar1 = *(int *)(iVar2 + 0x10);
      if (iVar1 != 0) {
        *(int *)(iVar1 + 0x14) = param_1;
        *(int *)(param_1 + 0x10) = iVar1;
        *(int *)(param_1 + 0x14) = iVar2;
        *(int *)(iVar2 + 0x10) = param_1;
        return;
      }
      *(int *)(param_2 + 4) = param_1;
      *(undefined4 *)(param_1 + 0x10) = 0;
      *(int *)(param_1 + 0x14) = iVar2;
      *(int *)(iVar2 + 0x10) = param_1;
      return;
    }
    iVar1 = *(int *)(iVar2 + 0x14);
    if (iVar1 == 0) break;
    iVar2 = iVar1;
    if (iVar1 == 0) {
      return;
    }
  }
  *(int *)(iVar2 + 0x14) = param_1;
  *(int *)(param_1 + 0x10) = iVar2;
  *(undefined4 *)(param_1 + 0x14) = 0;
  return;
}


