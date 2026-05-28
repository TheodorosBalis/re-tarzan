
int CEntities__CountRuntimeEntriesOfTypeInList(int param_1,short param_2)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x20)) {
    if (*(short *)(param_1 + 0x46) == param_2) {
      iVar1 = iVar1 + 1;
    }
  }
  return iVar1;
}

