
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities__UpdateTARZANLetterPickup(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 == 0) {
LAB_0044afa2:
    cVar2 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
    if (cVar2 != '\0') {
      CEntities__ReleaseRuntimeEntryToFreeList(param_1);
    }
    return;
  }
  *(ushort *)(iVar1 + 0xa2) = *(short *)(iVar1 + 0xa2) + 0x38U & 0xfff;
  cVar2 = CEntities__IsPlayerWithinPickupTriggerBounds
                    (iVar1,g_PlayerPickupTriggerRadius,(int)*(short *)(g_PlayerSceneEntry + 0x142),0
                    );
  if ((cVar2 == '\0') || (cVar2 = CEntities__CanStartPickupCollection(param_1), cVar2 == '\0'))
  goto LAB_0044afa2;
  PlayAudioById(0xb6,0,(undefined4 *)(iVar1 + 0x14));
  switch(_g_PlayerHeroMode) {
  case 1:
  case 7:
    uVar3 = 0x5d;
    break;
  case 2:
  case 9:
    uVar3 = 0x1e;
    break;
  default:
    goto switchD_0044af35_caseD_3;
  case 4:
  case 5:
    uVar3 = 0x22e;
    break;
  case 6:
    uVar3 = 0x4c1;
  }
  PlayAudioById(uVar3,0,0);
switchD_0044af35_caseD_3:
  g_CollectedTARZANLetterMask6 = g_CollectedTARZANLetterMask6 | *(byte *)(param_1 + 0x4c);
  g_HudCollectedTARZANslotSlideTicks = 0x5a;
  CEntities__SpawnRuntimeEntryByTypeAtPosition
            (*(undefined4 *)(iVar1 + 0x14),*(undefined4 *)(iVar1 + 0x18),
             *(undefined4 *)(iVar1 + 0x1c),0x14,0x11);
  CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
  return;
}

