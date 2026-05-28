
undefined4 CEntities__CheckSceneEntryVerticalImpact(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = *(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x4c);
  uVar5 = (int)uVar1 >> 0x1f;
  uVar2 = *(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x48);
  uVar6 = (int)uVar2 >> 0x1f;
  uVar3 = *(int *)(param_1 + 0x1c) - *(int *)(param_1 + 0x50);
  uVar7 = (int)uVar3 >> 0x1f;
  iVar4 = CEntities__GetSceneEntryVerticalCollisionDelta(param_1);
  if (iVar4 != 0x7fffffff) {
    if (iVar4 == 0) {
      return 1;
    }
    if ((iVar4 < 0) &&
       ((int)(~(((uVar1 ^ uVar5) - uVar5) + 0x4000 +
               ((uVar3 ^ uVar7) - uVar7) + ((uVar2 ^ uVar6) - uVar6)) + 1) <= iVar4)) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar4;
      return 1;
    }
  }
  return 0;
}

