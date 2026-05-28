
int CEntities__GetSceneEntryVerticalCollisionDelta(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x58);
  if ((((*(int *)(param_1 + 0x108) == 1) && (*(int *)(param_1 + 0x114) != 0)) &&
      ((*(uint *)(*(int *)(param_1 + 0x114) + 0x14) & 0x800) != 0)) && (iVar1 < 1)) {
    *(uint *)(param_1 + 0x13c) = *(uint *)(param_1 + 0x13c) | 4;
    iVar1 = 0x3ffffffe;
  }
  return iVar1;
}

