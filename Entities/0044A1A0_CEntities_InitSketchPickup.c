
void CEntities__InitSketchPickup(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = g_WorldSceneEntryArrayBase;
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    *(byte *)(iVar1 + 0xf) = *(byte *)(iVar1 + 0xf) | 0x10;
    *(int *)(iVar1 + 0x10) = iVar2 + 0x3a8;
    CEntities__SetSceneEntryScriptAttachment(param_1,&g_SketchPickupScriptAttachmentDesc);
    MoveSceneEntryWithCollision(0,0,iVar1);
    if (*(int *)(param_1 + 0x34) != 0) {
      iVar2 = *(int *)(*(int *)(param_1 + 0x34) + 0x10);
      *(int *)(param_1 + 0x4c) = *(int *)(iVar2 + 4) + -1;
      *(undefined4 *)(iVar1 + 0x6c) = *(undefined4 *)(iVar2 + 8);
      iVar2 = *(int *)(iVar2 + 0x10);
      if (iVar2 != 0) {
        *(undefined4 *)(iVar1 + 0xb4) = 1;
        uVar3 = (uint)*(ushort *)(&g_CollectibleInitialVariantFrameTable + iVar2 * 2);
        *(uint *)(iVar1 + 0xb0) = uVar3;
        *(uint *)(iVar1 + 0xac) = uVar3;
        *(uint *)(iVar1 + 0xa8) = uVar3;
      }
    }
  }
  if ((*(byte *)(param_1 + 0x44) & 1) != 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

