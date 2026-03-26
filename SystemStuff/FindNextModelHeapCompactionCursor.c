// Address: 0x004394D0

int FindNextModelHeapCompactionCursor(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    param_1 = param_1 + 0x18 + iVar1 * 4;
    if (*(int *)(param_1 + 4) == 0) break;
    iVar1 = *(int *)(param_1 + 8);
  }
  return param_1;
}


