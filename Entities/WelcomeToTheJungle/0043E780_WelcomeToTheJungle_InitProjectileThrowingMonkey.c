
void WelcomeToTheJungle__InitProjectileThrowingMonkey(int param_1)

{
  int iVar1;
  int iVar2;
  
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x1004;
  if ((*(byte *)(param_1 + 0x43) & 0x80) == 0) {
    LoadEncodedResourceId(0x1015);
    iVar1 = *(int *)(param_1 + 0x38);
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x10) = g_WorldSceneEntryArrayBase + 0x9c0;
      *(undefined2 *)(iVar1 + 0xa6) = 1;
      *(undefined2 *)(iVar1 + 0x140) = 0x100;
      CEntities__SetSceneEntryScriptAttachment(param_1,&g_MonkeyScriptAttachmentDesc);
      *(undefined2 *)(param_1 + 0x48) = 0;
      *(undefined2 *)(param_1 + 0x4a) = 0;
    }
    iVar2 = *(int *)(param_1 + 0x34);
    if (iVar2 != 0) {
      *(undefined2 *)(param_1 + 0x3e) = *(undefined2 *)(*(int *)(iVar2 + 0x10) + 4);
      *(undefined2 *)(param_1 + 0x4a) = *(undefined2 *)(*(int *)(iVar2 + 0x10) + 8);
      if (*(int *)(iVar2 + 0x10) != 0) {
        CEntities__ApplyAnimalRenderVariant
                  (param_1,iVar1,*(undefined4 *)(*(int *)(iVar2 + 0x10) + 0x10));
      }
    }
    if (*(short *)(param_1 + 0x3e) == 0) {
      *(undefined2 *)(param_1 + 0x3e) = 0x200;
    }
    if (*(short *)(param_1 + 0x4a) == 0) {
      *(undefined2 *)(param_1 + 0x4a) = 0x32;
    }
    CEntities__LinkRuntimeEntryIntoProcessingList(&DAT_00531e54,param_1);
  }
  else {
    iVar1 = CEntities__CountRuntimeEntriesOfTypeInList(DAT_00531e54,*(undefined2 *)(param_1 + 0x46))
    ;
    iVar2 = CEntities__CountRuntimeEntriesOfTypeInList(g_ActiveRuntimeEntryListHead,0x36);
    if (iVar1 + iVar2 < 2) {
      UnloadEncodedResourceId(0x1015);
      return;
    }
  }
  return;
}

