
void CEntities__InitBonusHealthPickup(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = g_WorldSceneEntryArrayBase;
  if (0x17f < g_PlayerMaxHealth) {
    *(undefined2 *)(param_1 + 0x46) = 6;
    *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(g_RuntimeEntityTypeCallbackTable + 0x30);
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(g_RuntimeEntityTypeCallbackTable + 0x34);
    (**(code **)(param_1 + 0x2c))(param_1);
    return;
  }
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0xc) = 0x2018;
    *(undefined2 *)(iVar1 + 0xa6) = 1;
    *(int *)(iVar1 + 0x10) = iVar2 + 0x3a8;
    if (*(int *)(param_1 + 0x34) != 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x34) + 0x10);
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) - *(int *)(iVar2 + 4);
      *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(iVar2 + 8);
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
  }
  if (*(short *)(param_1 + 0x44) != 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

