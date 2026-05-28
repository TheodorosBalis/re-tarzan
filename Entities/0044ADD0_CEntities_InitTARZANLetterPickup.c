
void CEntities__InitTARZANLetterPickup(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined2 *)(param_1 + 0x48) = 1;
  iVar2 = g_WorldSceneEntryArrayBase;
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0xa6) = 1;
    *(undefined4 *)(iVar1 + 0x40) = 0xffffff80;
    *(int *)(iVar1 + 0x10) = iVar2 + 0x3a8;
    if (*(int *)(param_1 + 0x34) != 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x34) + 0x10);
      uVar3 = *(undefined4 *)(iVar2 + 4);
      *(int *)(param_1 + 0x4c) = 1 << ((byte)uVar3 & 0x1f);
      *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(iVar2 + 8);
      iVar2 = *(int *)(iVar2 + 0x10);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar1 + 0xb4) = 1;
        uVar4 = (uint)*(ushort *)(&g_CollectibleInitialVariantFrameTable + iVar2 * 2);
        *(uint *)(iVar1 + 0xb0) = uVar4;
        *(uint *)(iVar1 + 0xac) = uVar4;
        *(uint *)(iVar1 + 0xa8) = uVar4;
      }
      switch(uVar3) {
      case 0:
        *(undefined2 *)(iVar1 + 0xc) = 0x2012;
        break;
      case 1:
      case 4:
        *(undefined2 *)(iVar1 + 0xc) = 0x2013;
        break;
      case 2:
        *(undefined2 *)(iVar1 + 0xc) = 0x2014;
        break;
      case 3:
        *(undefined2 *)(iVar1 + 0xc) = 0x2015;
        break;
      case 5:
        *(undefined2 *)(iVar1 + 0xc) = 0x2016;
      }
    }
  }
  if (*(short *)(param_1 + 0x44) != 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

