
void CEntities__UpdateTokenPickup(int param_1)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if ((iVar1 != 0) &&
     (CEntities__UpdateScriptedSceneEntryAttachment(param_1), *(short *)(param_1 + 0x48) != 0)) {
    cVar2 = CEntities__IsPlayerWithinPickupTriggerBounds
                      (iVar1,g_PlayerPickupTriggerRadius,(int)*(short *)(g_PlayerSceneEntry + 0x142)
                       ,0);
    if ((cVar2 != '\0') && (cVar2 = CEntities__CanStartPickupCollection(param_1), cVar2 != '\0')) {
      gCurrentTokensCollected = gCurrentTokensCollected + 1;
      if (g_HudTokenCounterSlideTicks < 0x50) {
        g_HudTokenCounterSlideTicks = 0x50;
      }
      PlayAudioById(0xb5,0,iVar1 + 0x14);
      CEntities__SetSceneEntryScriptAttachment(param_1,&g_CollectibleCollectedScriptAttachmentDesc);
      uVar3 = *(uint *)(param_1 + 0x50) & 0xf0;
      if (uVar3 != 0) {
        *(undefined4 *)(iVar1 + 0xb4) = 1;
        uVar3 = (uint)*(ushort *)(&g_CollectibleCollectedVariantFrameTable + ((int)uVar3 >> 4) * 2);
        *(uint *)(iVar1 + 0xb0) = uVar3;
        *(uint *)(iVar1 + 0xac) = uVar3;
        *(uint *)(iVar1 + 0xa8) = uVar3;
      }
      *(byte *)(iVar1 + 0xe) = *(byte *)(iVar1 + 0xe) | 0x21;
      *(undefined2 *)(param_1 + 0x48) = 0;
      return;
    }
    cVar2 = CEntities__UpdateBouncingPickupMotionAndLifetime(param_1);
    if ((cVar2 != '\0') ||
       (cVar2 = IsRuntimeEntryOutsideOuterActivationBounds(param_1), cVar2 != '\0')) {
      CEntities__ReleaseRuntimeEntryToFreeList(param_1);
    }
  }
  return;
}

