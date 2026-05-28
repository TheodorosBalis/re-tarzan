
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities__InitTutorialPickup(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  if ('\x01' < g_LevelTransitionContext._1_1_) {
    CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
    return;
  }
  _g_TutorialPickupInitResetFlag = 0;
  if (*(int *)(param_1 + 0x34) != 0) {
    uVar3 = (uint)*(ushort *)(*(int *)(param_1 + 0x34) + 0x14);
  }
  *(uint *)(param_1 + 0x4c) = uVar3;
  iVar1 = *(int *)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined2 *)(param_1 + 0x48) = 1;
  iVar2 = g_WorldSceneEntryArrayBase;
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0xa6) = 1;
    *(undefined4 *)(iVar1 + 0x40) = 0xc0;
    *(int *)(iVar1 + 0x10) = iVar2 + 0x340;
    *(undefined2 *)(iVar1 + 0xc) = 0x2011;
    *(undefined4 *)(iVar1 + 0xb4) = 1;
    *(undefined4 *)(iVar1 + 0xa8) = 0xc00;
    *(undefined4 *)(iVar1 + 0xac) = 0xc00;
    *(undefined4 *)(iVar1 + 0xb0) = 0xc00;
  }
  if (*(short *)(param_1 + 0x44) != 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

