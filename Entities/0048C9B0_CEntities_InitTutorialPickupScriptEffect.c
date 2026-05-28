
void CEntities__InitTutorialPickupScriptEffect(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    *(int *)(iVar1 + 0x10) = g_WorldSceneEntryArrayBase + 0x3a8;
    CEntities__SetSceneEntryScriptAttachment(param_1,&g_TutorialPickupScriptEffectAttachmentDesc);
    CEntities__UpdateScriptedSceneEntryAttachment(param_1);
    *(ushort *)(iVar1 + 0xe) = *(ushort *)(iVar1 + 0xe) | 0x1421;
  }
  if (*(short *)(param_1 + 0x44) != 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

