// Address: 0x004395A0

void SplitModelHeapFreeBlockForAlloc(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  UnlinkModelHeapFreeBlock(param_1,param_3);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + (-6 - param_2);
  InsertModelHeapFreeBlockSorted(param_1,param_3);
  iVar1 = *(int *)(param_1 + 8);
  *(int *)(param_1 + 0x20 + iVar1 * 4) = param_2;
  *(int *)(param_1 + 0x24 + iVar1 * 4) = param_1;
  iVar1 = param_1 + 0x18 + iVar1 * 4;
  *(int *)(iVar1 + 0x24 + param_2 * 4) = iVar1;
  return;
}


