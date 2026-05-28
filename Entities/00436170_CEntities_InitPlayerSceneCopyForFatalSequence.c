
void CEntities__InitPlayerSceneCopyForFatalSequence(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    iVar2 = g_WorldSceneEntryArrayBase + 0x3a8;
    *(ushort *)(iVar1 + 0xe) = *(ushort *)(iVar1 + 0xe) & 0x7fff;
    *(int *)(iVar1 + 0x10) = iVar2;
  }
  if (*(short *)(param_1 + 0x44) != 0) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

