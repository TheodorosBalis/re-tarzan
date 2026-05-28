
void CEntities__UpdateBonusHealthPickup(int param_1)

{
  int iVar1;
  char cVar2;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    *(ushort *)(iVar1 + 0xa2) = *(short *)(iVar1 + 0xa2) + 0x38U & 0xfff;
    cVar2 = CEntities__IsPlayerWithinPickupTriggerBounds
                      (iVar1,g_PlayerPickupTriggerRadius,(int)*(short *)(g_PlayerSceneEntry + 0x142)
                       ,0);
    if ((cVar2 != '\0') && (cVar2 = CEntities__CanStartPickupCollection(param_1), cVar2 != '\0')) {
      g_PlayerMaxHealth = g_PlayerMaxHealth + 0x20;
      PlayAudioById(0xbd,0,0);
      if (0x180 < g_PlayerMaxHealth) {
        g_PlayerMaxHealth = 0x180;
      }
      CEntities__SpawnRuntimeEntryByTypeAtPosition
                (*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x18),
                 *(undefined4 *)(iVar1 + 0x1c),0x14,0x11);
      CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
      return;
    }
  }
  cVar2 = CEntities__UpdateBouncingPickupMotionAndLifetime(param_1);
  if ((cVar2 != '\0') ||
     (cVar2 = IsRuntimeEntryOutsideOuterActivationBounds(param_1), cVar2 != '\0')) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

