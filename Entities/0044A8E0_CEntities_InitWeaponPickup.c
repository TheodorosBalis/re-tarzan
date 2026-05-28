
void CEntities__InitWeaponPickup(int param_1)

{
  int iVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    iVar3 = g_WorldSceneEntryArrayBase + 0x3a8;
    *(undefined2 *)(iVar1 + 0xa6) = 1;
    *(int *)(iVar1 + 0x10) = iVar3;
    if (*(int *)(param_1 + 0x34) == 0) {
      uVar5 = 0;
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0x34) + 0x10);
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) - *(int *)(iVar3 + 4);
      *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(iVar3 + 8);
      uVar5 = *(undefined4 *)(iVar3 + 0xc);
      uVar4 = *(uint *)(iVar3 + 0x10);
      if (uVar4 != 0) {
        *(uint *)(param_1 + 0x50) = uVar4;
        *(undefined4 *)(iVar1 + 0xb4) = 1;
        uVar4 = (uint)*(ushort *)(&g_CollectibleInitialVariantFrameTable + (uVar4 & 0xf) * 2);
        *(uint *)(iVar1 + 0xb0) = uVar4;
        *(uint *)(iVar1 + 0xac) = uVar4;
        *(uint *)(iVar1 + 0xa8) = uVar4;
      }
    }
    *(undefined4 *)(param_1 + 0x4c) = uVar5;
    switch(uVar5) {
    case 1:
      *(undefined2 *)(iVar1 + 0xc) = 0x2024;
      break;
    case 2:
      *(undefined2 *)(iVar1 + 0xc) = 0x2025;
      break;
    default:
      *(undefined2 *)(iVar1 + 0xc) = 0x2023;
      break;
    case 10:
      if ((g_PlayerPowerFruitInventoryFlags & 0x10) != 0) {
        if (g_HudTokenCounterScene != 0) {
          *(undefined2 *)(param_1 + 0x46) = 4;
          pcVar2 = *(code **)(g_RuntimeEntityTypeCallbackTable + 0x20);
          *(code **)(param_1 + 0x2c) = pcVar2;
          *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(g_RuntimeEntityTypeCallbackTable + 0x24)
          ;
          (*pcVar2)(param_1);
          return;
        }
        CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
        return;
      }
      *(undefined2 *)(iVar1 + 0xc) = 0x2028;
      break;
    case 0x14:
      *(undefined2 *)(iVar1 + 0xc) = 0x2029;
    }
  }
  if (*(short *)(param_1 + 0x44) != 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

