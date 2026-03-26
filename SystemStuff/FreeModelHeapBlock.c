// Address: 0x004396E0

void FreeModelHeapBlock(int param_1,int param_2)

{
  undefined2 *puVar1;
  int iVar2;
  undefined2 *puVar3;
  
  puVar3 = (undefined2 *)(param_1 + -0x18);
  if (*(undefined4 **)(param_1 + -0x14) != (undefined4 *)0xffffffff) {
    **(undefined4 **)(param_1 + -0x14) = 0;
  }
  puVar1 = *(undefined2 **)(param_1 + -0xc);
  iVar2 = param_1 + *(int *)(param_1 + -0x10) * 4;
  if ((puVar3 < *(undefined2 **)(param_2 + 8)) ||
     (*(undefined2 **)(param_2 + 8) == (undefined2 *)0x0)) {
    *(undefined2 **)(param_2 + 8) = puVar3;
  }
  if (*(int *)(iVar2 + 4) == 0) {
    UnlinkModelHeapFreeBlock(iVar2,param_2);
    iVar2 = *(int *)(param_1 + -0x10) + *(int *)(iVar2 + 8) + 6;
    *puVar3 = 0;
    *(int *)(param_1 + -0x10) = iVar2;
    *(undefined2 **)(param_1 + 0xc + iVar2 * 4) = puVar3;
  }
  if ((puVar1 == (undefined2 *)0x0) || (*(int *)(puVar1 + 2) != 0)) {
    *(undefined4 *)(param_1 + -0x14) = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + -0x10);
    *puVar1 = 0;
    *(int *)(puVar1 + 4) = *(int *)(puVar1 + 4) + iVar2 + 6;
    *(undefined2 **)(param_1 + 0xc + *(int *)(param_1 + -0x10) * 4) = puVar1;
    UnlinkModelHeapFreeBlock(puVar1,param_2);
    if ((puVar1 < *(undefined2 **)(param_2 + 8)) ||
       (puVar3 = puVar1, *(undefined2 **)(param_2 + 8) == (undefined2 *)0x0)) {
      *(undefined2 **)(param_2 + 8) = puVar1;
      InsertModelHeapFreeBlockSorted(puVar1,param_2);
      return;
    }
  }
  InsertModelHeapFreeBlockSorted(puVar3,param_2);
  return;
}


