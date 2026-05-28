
void CEntities__UnlinkRuntimeEntryFromProcessingList(int param_1)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0x24) != (int *)0x0) {
    if (*(int *)(param_1 + 0x1c) == 0) {
      iVar1 = *(int *)(param_1 + 0x20);
      **(int **)(param_1 + 0x24) = iVar1;
      if (iVar1 != 0) {
        *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1c) = 0;
      }
    }
    else {
      *(undefined4 *)(*(int *)(param_1 + 0x1c) + 0x20) = *(undefined4 *)(param_1 + 0x20);
      if (*(int *)(param_1 + 0x20) != 0) {
        *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x1c) = *(undefined4 *)(param_1 + 0x1c);
        *(undefined4 *)(param_1 + 0x1c) = 0;
        *(undefined4 *)(param_1 + 0x20) = 0;
        *(undefined4 *)(param_1 + 0x24) = 0;
        return;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  return;
}

