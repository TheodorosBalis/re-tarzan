// Address: 0x004397F0

undefined2 * ResizeModelHeapBlock(int param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  
  uVar1 = (param_2 >> 2) - 6;
  iVar2 = param_1 + *(int *)(param_1 + -0x10) * 4;
  puVar3 = (undefined2 *)(param_1 + uVar1 * 4);
  iVar4 = *(int *)(param_1 + -0xc);
  *(undefined4 *)(puVar3 + 2) = *(undefined4 *)(param_1 + -0x14);
  *puVar3 = *(undefined2 *)(param_1 + -0x18);
  puVar3[1] = *(undefined2 *)(param_1 + -0x16);
  if (*(int **)(puVar3 + 2) != (int *)0xffffffff) {
    **(int **)(puVar3 + 2) = (int)(puVar3 + 0xc);
  }
  *(uint *)(puVar3 + 4) = (*(int *)(param_1 + -0x10) - uVar1) + -6;
  if (uVar1 < 0x40) {
    if (*(int *)(iVar4 + 4) == 0) {
      *(undefined2 **)(iVar2 + 0xc) = puVar3;
      UnlinkModelHeapFreeBlock(iVar4,param_3);
      *(undefined4 *)(iVar4 + 4) = 0xffffffff;
      *(uint *)(iVar4 + 8) = *(int *)(iVar4 + 8) + (param_2 >> 2);
      *(int *)(puVar3 + 6) = iVar4;
      FreeModelHeapBlock(iVar4 + 0x18,param_3);
      return puVar3 + 0xc;
    }
    *(int *)(puVar3 + 6) = iVar4;
    *(uint *)(iVar4 + 8) = *(int *)(iVar4 + 8) + param_2;
    return puVar3 + 0xc;
  }
  *(undefined4 *)(param_1 + -0x14) = 0xffffffff;
  *(uint *)(param_1 + -0x10) = uVar1;
  *(undefined2 **)(iVar2 + 0xc) = puVar3;
  *(undefined2 **)(puVar3 + 6) = (undefined2 *)(param_1 + -0x18);
  FreeModelHeapBlock(param_1,param_3);
  return puVar3 + 0xc;
}


