// Address: 0x00439480

void InitModelLoadHeap(undefined4 *param_1,undefined2 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = (param_3 + 3U >> 2) - 0xc;
  *(int *)(param_2 + 4) = iVar1;
  *(undefined4 *)(param_2 + 2) = 0;
  *param_2 = 0;
  *(undefined4 *)(param_2 + 6) = 0;
  *(undefined4 *)(param_2 + 10) = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  *(undefined4 *)(param_2 + iVar1 * 2 + 0x10) = 0;
  *(undefined4 *)(param_2 + iVar1 * 2 + 0xe) = 0xffffffff;
  param_2[iVar1 * 2 + 0xc] = 0;
  *(undefined2 **)(param_2 + iVar1 * 2 + 0x12) = param_2;
  *param_1 = param_2;
  param_1[1] = param_2;
  param_1[2] = param_2;
  param_1[3] = 0;
  return;
}


