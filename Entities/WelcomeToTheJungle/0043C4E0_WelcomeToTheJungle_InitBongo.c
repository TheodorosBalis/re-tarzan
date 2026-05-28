
void WelcomeToTheJungle__InitBongo(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x38);
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x1000;
  if (iVar1 != 0) {
    iVar2 = g_WorldSceneEntryArrayBase + 0x548;
    *(undefined2 *)(iVar1 + 0xa6) = 1;
    *(int *)(iVar1 + 0x10) = iVar2;
    *(undefined2 *)(iVar1 + 0x140) = 0;
    CEntities__AcquireSceneEntryResourceSet(iVar1);
    CEntities__SetSceneEntryScriptAttachment(param_1,&g_BongoScriptAttachmentDesc);
    *(undefined2 *)(param_1 + 0x4a) = 0;
    *(undefined2 *)(param_1 + 0x48) = 0;
  }
  CEntities__LinkRuntimeEntryIntoProcessingList(&g_ActiveRuntimeEntryListHead,param_1);
  return;
}

