
void CEntities__ReleaseSceneEntryResourceSet(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x10);
  if (iVar1 != 0) {
    iVar2 = *(int *)(param_1 + 100);
    if (iVar2 == 0) {
      *(undefined4 *)(iVar1 + 100) = *(undefined4 *)(param_1 + 0x68);
    }
    else if (iVar2 == iVar1) {
      *(undefined4 *)(iVar1 + 100) = *(undefined4 *)(param_1 + 0x68);
      if (*(int *)(param_1 + 0x68) != 0) {
        *(int *)(*(int *)(param_1 + 0x68) + 100) = iVar1;
      }
    }
    else {
      *(undefined4 *)(iVar2 + 0x68) = *(undefined4 *)(param_1 + 0x68);
      if (*(int *)(param_1 + 0x68) != 0) {
        *(undefined4 *)(*(int *)(param_1 + 0x68) + 100) = *(undefined4 *)(param_1 + 100);
      }
    }
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 100) = 0;
  }
  if (*(int *)(iVar1 + 100) == 0) {
    ReleaseResourceSet(*(undefined4 *)(param_1 + 0x10));
    *(undefined4 *)(param_1 + 0x10) = 0;
  }
  return;
}

