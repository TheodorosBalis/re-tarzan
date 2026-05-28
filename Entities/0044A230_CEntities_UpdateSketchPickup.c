
void CEntities__UpdateSketchPickup(int param_1)

{
  int iVar1;
  char cVar2;
  short sVar3;
  undefined2 extraout_var;
  byte bVar4;
  undefined4 uVar5;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    CEntities__UpdateScriptedSceneEntryAttachment(param_1);
    sVar3 = *(short *)(param_1 + 0x50) + 0x44;
    *(int *)(param_1 + 0x50) = (int)sVar3;
    *(int *)(iVar1 + 0x40) =
         -0x80 - (((int)(short)(&g_SinCosTable12Bit)
                               [(CONCAT22(extraout_var,sVar3) >> 1) - 0x400U & 0xfff] +
                  (int)(short)(&g_SinCosTable12Bit)[(int)sVar3 & 0xfff]) * 0x40 >> 0xc);
    cVar2 = CEntities__IsPlayerWithinPickupTriggerBounds
                      (iVar1,g_PlayerPickupTriggerRadius,(int)*(short *)(g_PlayerSceneEntry + 0x142)
                       ,0);
    if (cVar2 != '\0') {
      cVar2 = CEntities__CanStartPickupCollection(param_1);
      if (cVar2 != '\0') {
        bVar4 = g_CollectedSketchPieceMask4 |
                '\x01' << ((byte)*(undefined4 *)(param_1 + 0x4c) & 0x1f);
        g_CollectedSketchPieceMask4 = bVar4;
        (&DAT_00532842)[*(int *)(param_1 + 0x4c) * 0x14] =
             (&DAT_00532842)[*(int *)(param_1 + 0x4c) * 0x14] & 0xfbde;
        if (bVar4 == 0xf) {
          uVar5 = 0xbf;
        }
        else {
          uVar5 = 0xb4;
        }
        PlayAudioById(uVar5,0,0);
        CEntities__SpawnRuntimeEntryByTypeAtPosition
                  (*(undefined4 *)(iVar1 + 0x14),*(int *)(iVar1 + 0x18) + *(int *)(iVar1 + 0x40) * 2
                   ,*(undefined4 *)(iVar1 + 0x1c),0x14,0x11);
        g_HudCollectedSketchSlideTicks = 0xb4;
        CEntities__ReleaseRuntimeEntryAndMarkDescriptorConsumed(param_1);
        return;
      }
    }
    cVar2 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
    if (cVar2 != '\0') {
      CEntities__ReleaseRuntimeEntryToFreeList(param_1);
    }
  }
  return;
}

