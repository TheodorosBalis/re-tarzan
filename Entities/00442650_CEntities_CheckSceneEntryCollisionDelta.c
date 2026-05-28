
undefined4 CEntities__CheckSceneEntryCollisionDelta(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x48);
  uVar2 = (int)uVar1 >> 0x1f;
  iVar3 = (uVar1 ^ uVar2) - uVar2;
  if (iVar3 < 0x10) {
    iVar3 = iVar3 + 0x10;
  }
  else {
    iVar3 = iVar3 + 8;
  }
  uVar1 = *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x50);
  uVar2 = (int)uVar1 >> 0x1f;
  uVar1 = iVar3 + ((uVar1 ^ uVar2) - uVar2);
  iVar3 = CEntities__GetSceneEntryVerticalCollisionDelta(param_1);
  if (iVar3 == 0x7fffffff) {
    *(undefined4 *)(param_1 + 0x14) = *(undefined4 *)(param_1 + 0x48);
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x4c);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(param_1 + 0x50);
    return 1;
  }
  if (iVar3 < 0) {
    if ((int)(~uVar1 + 1) <= iVar3) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar3;
      return 1;
    }
  }
  else if (iVar3 <= (int)uVar1) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar3;
    return 1;
  }
  return 0;
}

