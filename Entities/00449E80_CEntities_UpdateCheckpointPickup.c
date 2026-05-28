
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities__UpdateCheckpointPickup(int param_1)

{
  int iVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  short sVar5;
  undefined4 uVar6;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if ((iVar1 != 0) && (iVar4 = FindRuntimeEntityAttachmentByFlags(param_1,0x80000058), iVar4 != 0))
  {
    switch(*(undefined2 *)(param_1 + 0x48)) {
    case 2:
    case 9:
      *(short *)(iVar4 + 0xc) = *(short *)(iVar4 + 0xc) + -1;
      if (*(short *)(iVar4 + 0xc) < 0) {
        *(short *)(iVar4 + 0xe) = *(short *)(iVar4 + 0xe) + 1;
        if ((&g_CheckpointPickupActivationFrameSequence)[*(short *)(iVar4 + 0xe)] == 0) {
          *(undefined2 *)(iVar4 + 0xc) = 0;
          *(undefined2 *)(iVar4 + 0xe) = 0;
          *(undefined2 *)(iVar1 + 0xc) = g_CheckpointPickupActivationFrameSequence;
        }
        else {
          *(undefined2 *)(iVar1 + 0xc) =
               (&g_CheckpointPickupActivationFrameSequence)[*(short *)(iVar4 + 0xe)];
          *(undefined2 *)(iVar4 + 0xc) = 0;
        }
      }
      if (g_CurrentCheckpointId == *(int *)(param_1 + 0x4c)) {
        sVar5 = *(short *)(iVar4 + 0x16) + 0x44;
        *(short *)(iVar4 + 0x16) = sVar5;
        *(int *)(iVar1 + 0x40) =
             -0xc0 - (((int)(short)(&g_SinCosTable12Bit)[(int)sVar5 - 0x400U & 0xfff] << 6) >> 0xc);
        *(ushort *)(iVar1 + 0xa2) = sVar5 >> 1 & 0xfff;
        *(short *)(iVar1 + 0xa0) =
             (short)(((int)(short)(&g_SinCosTable12Bit)[(ushort)(sVar5 >> 1) - 0x400 & 0xfff] +
                     (int)(short)(&g_SinCosTable12Bit)[(int)sVar5 & 0xfff]) * 0x1c7 >> 0xd);
      }
      else {
        *(undefined2 *)(param_1 + 0x48) = 3;
        sVar5 = RandomModulo(0x10);
        *(short *)(iVar4 + 0xc) = sVar5 + 0x20;
        *(undefined2 *)(iVar4 + 0xe) = 0xffff;
        sVar5 = RandomModulo(0x14);
        *(short *)(iVar4 + 0x10) = sVar5 + 1;
        *(undefined2 *)(iVar1 + 0xa0) = 0;
      }
      break;
    case 3:
      *(undefined4 *)(iVar1 + 0x40) = 0xffffff80;
      *(ushort *)(iVar1 + 0xa2) = (*(ushort *)(iVar1 + 0x132) ^ 0x800) - 0x555;
    case 1:
      *(undefined2 *)(iVar1 + 0xc) = 0x1c;
      *(short *)(iVar4 + 0x10) = *(short *)(iVar4 + 0x10) + -1;
      sVar5 = *(short *)(iVar4 + 0x14);
      if (*(short *)(iVar4 + 0x10) < 0) {
        sVar3 = RandomModulo(0x60);
        *(short *)(iVar4 + 0xc) = sVar3 + 0x20;
        *(ushort *)(iVar4 + 0xe) = ~*(ushort *)(iVar4 + 0xe);
        sVar3 = RandomModulo(0x1e);
        *(short *)(iVar4 + 0x10) = sVar3 + 1;
      }
      if (*(short *)(iVar4 + 0xe) == 0) {
        sVar5 = sVar5 - *(short *)(iVar4 + 0xc);
        if (sVar5 < 0x60) {
          sVar5 = 0x60;
        }
      }
      else {
        sVar5 = sVar5 + *(short *)(iVar4 + 0xc);
        if (0x3ff < sVar5) {
          sVar5 = 0x3ff;
        }
      }
      *(short *)(iVar4 + 0x14) = sVar5;
      *(undefined2 *)(iVar1 + 0xa0) = 0;
      *(short *)(iVar1 + 0xa4) = sVar5;
      *(short *)(iVar1 + 0x84) = sVar5 * -2;
      *(undefined2 *)(iVar1 + 0x7a) = 1;
      cVar2 = CEntities__IsPlayerWithinPickupTriggerBounds
                        (iVar1,0x120,0,(int)*(short *)(iVar4 + 0x12));
      if ((cVar2 != '\0') && (cVar2 = CEntities__CanStartPickupCollection(param_1), cVar2 != '\0'))
      {
        switch(_g_PlayerHeroMode) {
        default:
          uVar6 = 0x5e;
          break;
        case 2:
        case 9:
          uVar6 = 0x1f;
          break;
        case 6:
          uVar6 = 0x4c2;
        }
        PlayAudioById(uVar6,0,0);
        *(undefined2 *)(param_1 + 0x48) = 2;
        *(undefined2 *)(iVar4 + 0xc) = 0;
        *(undefined2 *)(iVar4 + 0xe) = 0;
        *(undefined2 *)(iVar1 + 0xc) = g_CheckpointPickupActivationFrameSequence;
        *(undefined2 *)(iVar1 + 0xa4) = 0;
        *(undefined2 *)(iVar1 + 0x84) = 0;
        *(undefined2 *)(iVar1 + 0x7a) = 0;
        g_CurrentCheckpointId = *(int *)(param_1 + 0x4c);
      }
    }
  }
  cVar2 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar2 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

