
void CEntities__AcquireSceneEntryResourceSet(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    if ((*(int *)(iVar1 + 0xc) == 0) && (*(int *)(iVar1 + 8) == -1)) {
      RequestResourceSetLoad(iVar1);
      *(int *)(iVar1 + 100) = param_1;
      *(int *)(param_1 + 100) = iVar1;
      return;
    }
    iVar2 = *(int *)(iVar1 + 100);
    if (iVar2 != 0) {
      *(int *)(param_1 + 0x68) = iVar2;
      *(int *)(iVar2 + 100) = param_1;
    }
    *(int *)(param_1 + 100) = iVar1;
    *(int *)(iVar1 + 100) = param_1;
  }
  return;
}

