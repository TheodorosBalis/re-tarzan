
int CEntities__GetSceneEntryCurrentLocalBounds(int param_1)

{
  short *psVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(*(int *)(param_1 + 0x10) + 0xc);
  psVar1 = (short *)(*(int *)(iVar3 + 8) + 8 + iVar3);
  uVar2 = *(ushort *)(param_1 + 0xc) & 0xfff;
  if ((int)*psVar1 <= (int)uVar2) {
    uVar2 = 0;
  }
  iVar3 = ResolveModelDataIndexedRelativePointer(*(int *)(param_1 + 0x10),psVar1,uVar2);
  if (iVar3 != 0) {
    return iVar3 + 8;
  }
  return 0;
}

