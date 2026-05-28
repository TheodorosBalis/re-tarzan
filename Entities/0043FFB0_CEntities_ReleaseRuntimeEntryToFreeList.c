
undefined4 CEntities__ReleaseRuntimeEntryToFreeList(byte *param_1)

{
  ushort *puVar1;
  int iVar2;
  
  if ((*param_1 & 1) != 0) {
    if ((*(int *)(param_1 + 0x34) != 0) &&
       ((*(byte *)(*(int *)(param_1 + 0x34) + 0x1a) & 0x10) != 0)) {
      return 0;
    }
    param_1[0x43] = param_1[0x43] | 0x80;
    if ((param_1[0x28] & 4) != 0) {
      (**(code **)(param_1 + 0x2c))(param_1);
    }
    if (g_PlayerHeldThrowableRuntimeEntry == param_1) {
      g_PlayerHeldThrowableRuntimeEntry = (byte *)0x0;
    }
    if (g_PendingPlayerDamageSourceRuntimeEntry == param_1) {
      g_PendingPlayerDamageSourceRuntimeEntry = (byte *)0x0;
    }
    if (*(int *)(param_1 + 0x34) != 0) {
      puVar1 = (ushort *)(*(int *)(param_1 + 0x34) + 0x1a);
      *puVar1 = *puVar1 & 0xfffe;
    }
    for (iVar2 = *(int *)(param_1 + 0x38); iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x34)) {
      if (*(int *)(iVar2 + 0x60) != 0) {
        *(undefined4 *)(*(int *)(iVar2 + 0x60) + 0x60) = 0;
      }
      *(undefined4 *)(iVar2 + 0x60) = 0;
      if ((*(int *)(iVar2 + 100) != 0) || (*(int *)(iVar2 + 0x68) != 0)) {
        CEntities__ReleaseSceneEntryResourceSet(iVar2);
      }
      CEntities__ReleaseSceneEntryAttachedSound(iVar2);
    }
    CEntities__ReleaseRuntimeEntryAttachments(param_1);
    CEntities__UnlinkRuntimeEntryFromSpawnChain(param_1);
    CEntities__UnlinkRuntimeEntryFromProcessingList(param_1);
    if (*(int *)(param_1 + 0xc) != 0) {
      *(undefined4 *)(*(int *)(param_1 + 0xc) + 0x10) = *(undefined4 *)(param_1 + 0x10);
      if (*(int *)(param_1 + 0x10) == 0) {
        g_ActiveRuntimeEntryListTail = *(undefined4 *)(param_1 + 0xc);
      }
      else {
        *(undefined4 *)(*(int *)(param_1 + 0x10) + 0xc) = *(undefined4 *)(param_1 + 0xc);
      }
    }
    param_1[0] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    param_1[3] = 0;
    if (g_FreeRuntimeEntryListHead != (byte *)0x0) {
      *(byte **)(g_FreeRuntimeEntryListHead + 0xc) = param_1;
      *(byte **)(param_1 + 0x10) = g_FreeRuntimeEntryListHead;
      g_FreeRuntimeEntryListHead = param_1;
      param_1[0xc] = 0;
      param_1[0xd] = 0;
      param_1[0xe] = 0;
      param_1[0xf] = 0;
      return 1;
    }
    g_FreeRuntimeEntryListHead = param_1;
    param_1[0x10] = 0;
    param_1[0x11] = 0;
    param_1[0x12] = 0;
    param_1[0x13] = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
  }
  return 1;
}

