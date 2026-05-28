
void WelcomeToTheJungle__InitChameleon(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    iVar2 = g_WorldSceneEntryArrayBase + 0xa28;
    *(undefined2 *)(iVar1 + 0xa6) = 2;
    *(int *)(iVar1 + 0x10) = iVar2;
    *(undefined2 *)(iVar1 + 0x140) = 0;
    CEntities__AcquireSceneEntryResourceSet(iVar1);
    CEntities__SetSceneEntryScriptAttachment(param_1,&g_ChameleonScriptAttachmentDesc);
    *(byte *)(param_1 + 0x4a) = *(byte *)(param_1 + 0x4a) | 1;
  }
  CEntities__LinkRuntimeEntryIntoProcessingList(&DAT_00531e54,param_1);
  return;
}

