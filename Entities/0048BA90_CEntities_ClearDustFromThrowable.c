
void CEntities__ClearDustFromThrowable(int param_1)

{
  short sVar1;
  
  if (*(int *)(param_1 + 0x38) != 0) {
    sVar1 = CEntities__UpdateScriptedSceneEntryAttachment(param_1);
    if (sVar1 != 0) {
      CEntities__ReleaseRuntimeEntryToFreeList(param_1);
    }
  }
  return;
}

