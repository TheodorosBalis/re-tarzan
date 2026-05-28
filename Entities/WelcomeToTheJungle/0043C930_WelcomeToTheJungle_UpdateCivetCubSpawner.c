
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void WelcomeToTheJungle__UpdateCivetCubSpawner(int param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if ((_g_PlayerHeroMode == 2) && ((g_PlayerActionState == 0x28 || (g_PlayerActionState == 0x25))))
  {
    CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
    return;
  }
  iVar4 = *(int *)(param_1 + 0x38);
  if ((iVar4 != 0) &&
     (iVar3 = *(int *)(param_1 + 0x4c) + -1, *(int *)(param_1 + 0x4c) = iVar3, iVar3 < 0)) {
    iVar3 = CEntities__SpawnRuntimeEntryByTypeAtPosition
                      (*(undefined4 *)(iVar4 + 0x14),*(undefined4 *)(iVar4 + 0x18),
                       *(undefined4 *)(iVar4 + 0x1c),0x47,0x11);
    if (iVar3 != 0) {
      iVar1 = *(int *)(iVar3 + 0x38);
      *(byte *)(iVar3 + 0x4b) = *(byte *)(iVar3 + 0x4b) | 2;
      if (iVar1 == 0) {
        CEntities__ReleaseRuntimeEntryToFreeList(iVar3);
      }
      else {
        *(undefined4 *)(iVar1 + 0x108) = 1;
        *(undefined4 *)(iVar1 + 0x10c) = *(undefined4 *)(iVar4 + 0x10c);
        *(undefined4 *)(iVar1 + 0x110) = *(undefined4 *)(iVar4 + 0x110);
        *(undefined4 *)(iVar1 + 0x10c) = *(undefined4 *)(iVar4 + 0x10c);
        if ((*(int *)(param_1 + 0x34) != 0) &&
           ((*(byte *)(*(int *)(*(int *)(param_1 + 0x34) + 0x10) + 2) & 0x20) != 0)) {
          *(undefined4 *)(iVar1 + 0x10c) = 0x10;
        }
        UpdateRuntimeEntitySceneEntryTransformFromPlacement(iVar1);
        CEntities__RefreshAnimalFacingAndCollisionAfterTurn(iVar3,iVar1);
      }
    }
    iVar4 = RandomModulo(*(int *)(param_1 + 0x50) - *(int *)(param_1 + 0x4c));
    *(uint *)(param_1 + 0x4c) = iVar4 + (uint)*(ushort *)(param_1 + 0x4a);
  }
  cVar2 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar2 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

