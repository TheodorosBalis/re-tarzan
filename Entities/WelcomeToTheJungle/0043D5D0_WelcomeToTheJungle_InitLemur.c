
void WelcomeToTheJungle__InitLemur(int param_1)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 0x38);
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) | 0x1000;
  if (iVar1 != 0) {
    iVar3 = g_WorldSceneEntryArrayBase + 0x478;
    *(undefined2 *)(iVar1 + 0xa6) = 1;
    *(int *)(iVar1 + 0x10) = iVar3;
    *(undefined2 *)(iVar1 + 0x140) = 0;
    CEntities__AcquireSceneEntryResourceSet(iVar1);
    CEntities__SetSceneEntryScriptAttachment(param_1,&g_LemurScriptAttachmentDesc);
    iVar3 = *(int *)(param_1 + 0x34);
    *(undefined2 *)(param_1 + 0x48) = 0;
    *(undefined2 *)(param_1 + 0x4a) = 0;
    if (iVar3 != 0) {
      if ((*(byte *)(*(int *)(iVar3 + 0x10) + 3) & 1) != 0) {
        *(undefined2 *)(param_1 + 0x4a) = 0x80;
      }
      bVar2 = *(byte *)(*(int *)(iVar3 + 0x10) + 4);
      if (*(int *)(*(int *)(iVar3 + 0x10) + 4) == 99) {
        bVar2 = RandomModulo(8);
      }
      if ((bVar2 & 1) != 0) {
        *(byte *)(iVar1 + 0xf) = *(byte *)(iVar1 + 0xf) | 2;
        *(undefined4 *)(iVar1 + 0x70) = 1;
      }
    }
  }
  CEntities__LinkRuntimeEntryIntoProcessingList(&g_ActiveRuntimeEntryListHead,param_1);
  return;
}

