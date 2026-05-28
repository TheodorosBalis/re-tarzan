
void CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(int param_1)

{
  byte *pbVar1;
  
  if (*(int *)(param_1 + 0x34) != 0) {
    pbVar1 = (byte *)(*(int *)(param_1 + 0x34) + 0x1b);
    *pbVar1 = *pbVar1 | 0x80;
  }
  CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  return;
}

