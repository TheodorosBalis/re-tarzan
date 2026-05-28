
void CEntities__InitTokenPickup(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 != 0) {
    *(undefined ***)(iVar2 + 0x10) = &g_LanguageFontAssetSet;
    *(undefined2 *)(iVar2 + 0xa6) = 3;
    pbVar1 = (byte *)(*(int *)(param_1 + 0x38) + 0xf);
    *pbVar1 = *pbVar1 | 0x10;
    *(undefined2 *)(param_1 + 0x48) = 1;
    *(undefined2 *)(param_1 + 0x4a) = 0;
    iVar3 = CEntities__SetSceneEntryScriptAttachment(param_1,&g_CollectibleIdleScriptAttachmentDesc)
    ;
    if (iVar3 != 0) {
      uVar4 = (int)*(uint *)(iVar2 + 0x14) >> 0x1f;
      *(short *)(iVar3 + 0x16) = (short)((int)((*(uint *)(iVar2 + 0x14) ^ uVar4) - uVar4) % 0x18);
      CEntities__UpdateScriptedSceneEntryAttachment(param_1);
    }
    if (*(int *)(param_1 + 0x34) != 0) {
      iVar3 = *(int *)(*(int *)(param_1 + 0x34) + 0x10);
      if (*(int *)(iVar3 + 4) != 0) {
        *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) - *(int *)(iVar3 + 4);
      }
      *(undefined4 *)(iVar2 + 0x6c) = *(undefined4 *)(iVar3 + 8);
      uVar4 = *(uint *)(iVar3 + 0x10);
      if (uVar4 != 0) {
        *(uint *)(param_1 + 0x50) = uVar4;
        *(undefined4 *)(iVar2 + 0xb4) = 1;
        uVar4 = (uint)*(ushort *)(&g_CollectibleInitialVariantFrameTable + (uVar4 & 0xf) * 2);
        *(uint *)(iVar2 + 0xb0) = uVar4;
        *(uint *)(iVar2 + 0xac) = uVar4;
        *(uint *)(iVar2 + 0xa8) = uVar4;
      }
    }
  }
  if ((*(byte *)(param_1 + 0x44) & 1) != 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

