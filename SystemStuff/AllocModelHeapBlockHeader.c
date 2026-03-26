// Address: 0x004395F0

int AllocModelHeapBlockHeader(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 3U >> 2;
  iVar1 = FindModelHeapFreeBlockAtLeastWords(uVar3,*(undefined4 *)(param_2 + 4));
  if (iVar1 == 0) {
    return 0;
  }
  if (uVar3 + 0x58 < *(uint *)(iVar1 + 8)) {
    iVar1 = SplitModelHeapFreeBlockForAlloc(iVar1,uVar3,param_2);
  }
  else {
    UnlinkModelHeapFreeBlock(iVar1);
  }
  if (iVar1 == *(int *)(param_2 + 8)) {
    uVar2 = FindNextModelHeapCompactionCursor(iVar1);
    *(undefined4 *)(param_2 + 8) = uVar2;
  }
  return iVar1;
}


