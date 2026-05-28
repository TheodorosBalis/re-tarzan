
void WelcomeToTheJungle__InitBaboon(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x1004;
  if ((*(byte *)(param_1 + 0x43) & 0x80) == 0) {
    LoadEncodedResourceId(0x1013);
    iVar1 = *(int *)(param_1 + 0x38);
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x10) = g_WorldSceneEntryArrayBase + 0x8f0;
      *(undefined2 *)(iVar1 + 0xa6) = 1;
      CEntities__SetSceneEntryScriptAttachment(param_1,&g_BaboonScriptAttachmentDesc);
      *(undefined2 *)(param_1 + 0x48) = 0;
      *(undefined2 *)(param_1 + 0x4a) = 0;
      *(undefined4 *)(param_1 + 0x4c) = 0;
      *(undefined4 *)(param_1 + 0x50) = 0;
      if (((*(int *)(param_1 + 0x34) != 0) &&
          (iVar2 = *(int *)(*(int *)(param_1 + 0x34) + 0x10), iVar2 != 0)) &&
         (*(int *)(iVar2 + 0x10) != 0)) {
        *(undefined4 *)(iVar1 + 0xb4) = 1;
        iVar2 = *(int *)(iVar2 + 0x10) << 4;
        *(int *)(iVar1 + 0xb0) = iVar2;
        *(int *)(iVar1 + 0xac) = iVar2;
        *(int *)(iVar1 + 0xa8) = iVar2;
      }
      *(undefined2 *)(param_1 + 0x3e) = 0x200;
    }
    CEntities__LinkRuntimeEntryIntoProcessingList(&g_ActiveRuntimeEntryListHead,param_1);
  }
  else {
    iVar1 = CEntities__CountRuntimeEntriesOfTypeInList
                      (g_ActiveRuntimeEntryListHead,*(undefined2 *)(param_1 + 0x46));
    if (iVar1 < 2) {
      UnloadEncodedResourceId(0x1013);
      return;
    }
  }
  return;
}

