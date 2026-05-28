
void WelcomeToTheJungle__InitMonkey(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x1004;
  if ((*(byte *)(param_1 + 0x43) & 0x80) == 0) {
    LoadEncodedResourceId(0x1015);
    iVar1 = *(int *)(param_1 + 0x38);
    if (iVar1 != 0) {
      *(int *)(iVar1 + 0x10) = g_WorldSceneEntryArrayBase + 0x9c0;
      *(undefined2 *)(iVar1 + 0xa6) = 1;
      *(undefined2 *)(iVar1 + 0x140) = 0x100;
      CEntities__SetSceneEntryScriptAttachment(param_1,&g_MonkeyScriptAttachmentDesc);
      iVar2 = *(int *)(param_1 + 0x34);
      *(undefined2 *)(param_1 + 0x48) = 0;
      *(undefined2 *)(param_1 + 0x4a) = 0;
      if (iVar2 != 0) {
        if ((*(ushort *)(*(int *)(iVar2 + 0x10) + 2) & 0x100) != 0) {
          *(undefined2 *)(param_1 + 0x4a) = 0x80;
        }
        if ((*(ushort *)(*(int *)(iVar2 + 0x10) + 2) & 0x200) != 0) {
          *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) | 0x100;
        }
        if ((*(ushort *)(*(int *)(iVar2 + 0x10) + 2) & 0x400) != 0) {
          *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) | 0x200;
        }
        if ((*(byte *)(*(int *)(iVar2 + 0x10) + 3) & 8) != 0) {
          *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) | 0x400;
        }
        if (*(int *)(iVar2 + 0x10) != 0) {
          CEntities__ApplyAnimalRenderVariant
                    (param_1,iVar1,*(undefined4 *)(*(int *)(iVar2 + 0x10) + 0x10));
        }
      }
    }
    CEntities__LinkRuntimeEntryIntoProcessingList(&g_ActiveRuntimeEntryListHead,param_1);
  }
  else {
    iVar1 = CEntities__CountRuntimeEntriesOfTypeInList
                      (g_ActiveRuntimeEntryListHead,*(undefined2 *)(param_1 + 0x46));
    iVar2 = CEntities__CountRuntimeEntriesOfTypeInList(DAT_00531e54,0x3a);
    iVar3 = CEntities__CountRuntimeEntriesOfTypeInList(DAT_00531e54,0x39);
    if (iVar1 + iVar2 + iVar3 < 2) {
      UnloadEncodedResourceId(0x1015);
      return;
    }
  }
  return;
}

