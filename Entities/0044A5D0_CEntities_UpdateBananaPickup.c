
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities__UpdateBananaPickup(int param_1)

{
  short sVar1;
  int iVar2;
  char cVar3;
  undefined4 uVar4;
  
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 != 0) {
    *(ushort *)(iVar2 + 0xa2) = *(short *)(iVar2 + 0xa2) + 0x38U & 0xfff;
    cVar3 = CEntities__IsPlayerWithinPickupTriggerBounds
                      (iVar2,g_PlayerPickupTriggerRadius,(int)*(short *)(g_PlayerSceneEntry + 0x142)
                       ,0);
    if ((cVar3 != '\0') && (cVar3 = CEntities__CanStartPickupCollection(param_1), cVar3 != '\0')) {
      switch(_g_PlayerHeroMode) {
      default:
        uVar4 = 0x5c;
        break;
      case 2:
      case 9:
        uVar4 = 0x1d;
        break;
      case 4:
      case 5:
        uVar4 = 0x22d;
        break;
      case 6:
        uVar4 = 0x4c0;
      }
      PlayAudioById(uVar4,0,0);
      if (*(short *)(param_1 + 0x4a) == 0) {
        sVar1 = *(short *)(&g_SingleBananaHealthGainByDifficulty +
                          g_LevelTransitionContext._1_1_ * 2);
      }
      else {
        sVar1 = *(short *)((int)&g_BananaBunchHealthGainByDifficulty +
                          g_LevelTransitionContext._1_1_ * 2);
      }
      g_PlayerHealth = g_PlayerHealth + sVar1;
      if ((int)(uint)g_PlayerMaxHealth < (int)(short)g_PlayerHealth) {
        g_PlayerHealth = g_PlayerMaxHealth;
      }
      CEntities__SpawnRuntimeEntryByTypeAtPosition
                (*(undefined4 *)(iVar2 + 0x14),*(int *)(iVar2 + 0x18) + -0xb4,
                 *(undefined4 *)(iVar2 + 0x1c),0x14,0x11);
      CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
      return;
    }
  }
  cVar3 = CEntities__UpdateBouncingPickupMotionAndLifetime(param_1);
  if ((cVar3 != '\0') ||
     (cVar3 = IsRuntimeEntryOutsideOuterActivationBounds(param_1), cVar3 != '\0')) {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

