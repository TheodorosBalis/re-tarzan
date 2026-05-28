
undefined4 CEntities__CheckPlayerDamageContact(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar1 = param_1;
  uVar2 = *(int *)(g_PlayerSceneEntryData + 8) - *(int *)(param_1 + 0x14);
  uVar4 = (int)uVar2 >> 0x1f;
  if ((((((int)((uVar2 ^ uVar4) - uVar4) < 0x1001) &&
        (uVar2 = *(int *)(g_PlayerSceneEntryData + 0xc) - *(int *)(param_1 + 0x18),
        uVar4 = (int)uVar2 >> 0x1f, (int)((uVar2 ^ uVar4) - uVar4) < 0x1001)) &&
       (uVar2 = *(int *)(g_PlayerSceneEntryData + 0x10) - *(int *)(param_1 + 0x1c),
       uVar4 = (int)uVar2 >> 0x1f, (int)((uVar2 ^ uVar4) - uVar4) < 0x1001)) &&
      ((*(int *)(param_1 + 0x60) == 0 || ((g_PlayerCollisionContactFlags & 0x200000) == 0)))) &&
     ((g_PlayerSpecialAttachmentEntry != 0 &&
      ((iVar3 = GetSceneEntryAttachmentList(param_1,&param_1), iVar3 != 0 && (iVar5 = 0, 0 < iVar3))
      )))) {
    do {
      if (((*(uint *)(param_1 + 0xc) & 0x600) != 0) &&
         ((*(uint *)(param_1 + 0xc) & 0xc0000000) == 0)) {
        g_PlayerDamageContactPushDistance =
             CEntities__ComputePlayerAttachmentPenetrationDepth
                       (g_PlayerSceneEntry,g_PlayerSpecialAttachmentEntry,iVar1,param_1);
        if (g_PlayerDamageContactPushDistance != 0) {
          return 1;
        }
        g_PlayerDamageContactPushDistance = 0;
      }
      param_1 = param_1 + 0x10;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  return 0;
}

