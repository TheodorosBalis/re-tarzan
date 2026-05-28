
void CEntities__ProcessRuntimeEntryDeathAndRelease(int param_1)

{
  if (*(int *)(param_1 + 0x38) != 0) {
    CEntities__ProcessEntityDeath(*(int *)(param_1 + 0x38),2);
    CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
  }
  return;
}

