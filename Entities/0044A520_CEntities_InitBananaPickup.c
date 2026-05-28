
void CEntities__InitBananaPickup(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    iVar2 = g_WorldSceneEntryArrayBase + 0x3a8;
    *(undefined2 *)(iVar1 + 0xa6) = 1;
    *(int *)(iVar1 + 0x10) = iVar2;
    if (*(int *)(param_1 + 0x34) != 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x34) + 0x10);
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) - *(int *)(iVar2 + 4);
      *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(iVar2 + 8);
      *(undefined2 *)(param_1 + 0x4a) = *(undefined2 *)(iVar2 + 0xc);
      uVar3 = *(uint *)(iVar2 + 0x10);
      if (uVar3 != 0) {
        *(uint *)(param_1 + 0x50) = uVar3;
        *(undefined4 *)(iVar1 + 0xb4) = 1;
        uVar3 = (uint)*(ushort *)(&g_CollectibleInitialVariantFrameTable + (uVar3 & 0xf) * 2);
        *(uint *)(iVar1 + 0xb0) = uVar3;
        *(uint *)(iVar1 + 0xac) = uVar3;
        *(uint *)(iVar1 + 0xa8) = uVar3;
      }
    }
    if (*(short *)(param_1 + 0x4a) == 0) {
      *(undefined2 *)(iVar1 + 0xc) = 0x2021;
    }
    else {
      *(undefined2 *)(iVar1 + 0xc) = 0x2022;
    }
  }
  if (*(short *)(param_1 + 0x44) != 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

