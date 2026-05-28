
void CEntities__LinkRuntimeEntryIntoProcessingList(int *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 0) {
    *(int *)(param_2 + 0x20) = iVar1;
    *(int *)(iVar1 + 0x1c) = param_2;
  }
  *param_1 = param_2;
  *(int **)(param_2 + 0x24) = param_1;
  return;
}

