// 0x004acb80

void UpdateSceneEntryAnimations(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = *(int **)(param_1 + 0xc);
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    if (iVar2 != 0) {
      iVar3 = 0;
      iVar4 = (int)piVar1 + iVar2 + 4;
      if (0 < *(int *)((int)piVar1 + iVar2)) {
        do {
          UpdateSceneEntryFramePointerAnimation(iVar4,param_1);
          iVar4 = iVar4 + 0x14;
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)((int)piVar1 + iVar2));
      }
    }
    iVar2 = piVar1[1];
    if (iVar2 != 0) {
      iVar3 = 0;
      iVar4 = (int)piVar1 + iVar2 + 8;
      if (0 < *(int *)((int)piVar1 + iVar2 + 4)) {
        do {
          UpdateSceneEntryFrameIndexAnimation(iVar4,param_1);
          iVar4 = iVar4 + 0x10;
          iVar3 = iVar3 + 1;
        } while (iVar3 < *(int *)((int)piVar1 + iVar2 + 4));
      }
    }
  }
  return;
}