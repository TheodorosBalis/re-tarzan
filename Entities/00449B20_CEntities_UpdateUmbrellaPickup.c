
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities_UpdateUmbrellaPickup(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar4 = *(int *)(param_1 + 0x38);
  if ((iVar4 == 0) || (iVar3 = FindRuntimeEntityAttachmentByFlags(param_1,0x80000058), iVar3 == 0))
  goto LAB_00449cd0;
  sVar2 = *(short *)(param_1 + 0x48);
  if (sVar2 != 1) {
    if (sVar2 == 2) {
      *(short *)(iVar3 + 0xc) = *(short *)(iVar3 + 0xc) + -1;
      if (*(short *)(iVar3 + 0xc) < 0) {
        *(short *)(iVar3 + 0xe) = *(short *)(iVar3 + 0xe) + 1;
        if (*(short *)(&g_UmbrellaPickupOpenFrameSequence + *(short *)(iVar3 + 0xe) * 2) == 0) {
          *(undefined2 *)(param_1 + 0x48) = 9;
        }
        else {
          *(short *)(iVar4 + 0xc) =
               *(short *)(&g_UmbrellaPickupOpenFrameSequence + *(short *)(iVar3 + 0xe) * 2);
          *(undefined2 *)(iVar3 + 0xc) = 0;
        }
      }
    }
    else if (sVar2 != 9) goto LAB_00449cd0;
    sVar2 = *(short *)(iVar3 + 0x14) + 0x44;
    *(short *)(iVar3 + 0x14) = sVar2;
    *(int *)(iVar4 + 0x40) =
         -0x80 - (((int)(short)(&g_SinCosTable12Bit)[(int)sVar2 - 0x400U & 0xfff] << 6) >> 0xc);
    *(ushort *)(iVar4 + 0xa2) = sVar2 >> 1 & 0xfff;
    *(short *)(iVar4 + 0xa0) =
         (short)(((int)(short)(&g_SinCosTable12Bit)[(ushort)(sVar2 >> 1) - 0x400 & 0xfff] +
                 (int)(short)(&g_SinCosTable12Bit)[(int)sVar2 & 0xfff]) * 0xe3 >> 0xd);
    iVar4 = *(int *)(param_1 + 0x4c) + -1;
    *(int *)(param_1 + 0x4c) = iVar4;
    if (iVar4 < 0) {
      g_LevelTransitionRequestFlags._0_2_ = 0x8001;
    }
    goto LAB_00449cd0;
  }
  *(undefined2 *)(iVar4 + 0xa2) = 0;
  *(undefined2 *)(iVar4 + 0xa0) = 0;
  if (*(int *)(iVar4 + 0x40) != 0) {
    *(int *)(iVar4 + 0x40) = *(int *)(iVar4 + 0x40) + 1 >> 1;
  }
  cVar1 = CEntities_IsPlayerWithinPickupTriggerBounds
                    (iVar4,0x100,0x280,(int)*(short *)(iVar3 + 0x10));
  if (cVar1 == '\0') goto LAB_00449cd0;
  PlayAudioById(0xb9,0,0);
  if (_g_PlayerHeroMode == 2) {
LAB_00449cae:
    uVar5 = 0x1f;
  }
  else if (_g_PlayerHeroMode == 6) {
    uVar5 = 0x4c1;
  }
  else {
    if (_g_PlayerHeroMode == 9) goto LAB_00449cae;
    uVar5 = 0x5e;
  }
  PlayAudioById(uVar5,0,0);
  *(undefined2 *)(param_1 + 0x48) = 2;
  _g_PlayerSequenceFlags = _g_PlayerSequenceFlags | 0x4000;
  *(undefined2 *)(iVar3 + 0xc) = 0xffff;
  *(undefined2 *)(iVar3 + 0xe) = 0xffff;
LAB_00449cd0:
  if (((_g_PlayerSequenceFlags & 0x4000) == 0) &&
     (cVar1 = IsRuntimeEntryOutsideOuterActivationBounds(param_1), cVar1 != '\0')) {
    CEntities_ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

