
void WelcomeToTheJungle__BirdProjectileDropCallback(int param_1,int param_2)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  
  iVar8 = FindRuntimeEntityAttachmentByFlags(param_1,0x10000000);
  if (iVar8 != 0) {
    iVar14 = 0;
    uVar12 = 0;
    iVar9 = *(int *)(param_2 + 0x14) - *(int *)(g_PlayerSceneEntryData + 8);
    iVar11 = *(int *)(param_2 + 0x1c) - *(int *)(g_PlayerSceneEntryData + 0x10);
    iVar9 = SqrtToInt(iVar11 * iVar11 + iVar9 * iVar9);
    uVar13 = iVar9 >> 6;
    if (((int)uVar13 < 0x200) && ((*(byte *)(param_1 + 0x4b) & 1) != 0)) {
      uVar12 = uVar13 * 2;
      iVar14 = (int)(short)(&g_SinCosTable12Bit)[(uVar13 & 0x7ff) * 2] >> 4;
      if (0 < *(int *)(param_1 + 0x50)) {
        uVar12 = ~uVar12 & 0xfff;
      }
    }
    *(short *)(param_2 + 0xa0) =
         (short)((int)((uVar12 - (int)*(short *)(param_2 + 0xa0)) * 0x100000) >> 0x17) +
         *(short *)(param_2 + 0xa0);
    *(int *)(param_2 + 0x40) = (iVar14 - *(int *)(param_2 + 0x40) >> 3) + *(int *)(param_2 + 0x40);
    uVar2 = *(ushort *)(param_1 + 0x4a);
    if ((uVar2 & 0x100) == 0) {
      if ((uVar2 & 0x80) != 0) {
        *(ushort *)(param_1 + 0x4a) = uVar2 & 0xff7f;
        iVar9 = CEntities__SpawnRuntimeEntryByTypeAtPosition
                          (*(undefined4 *)(param_2 + 0x14),*(undefined4 *)(param_2 + 0x18),
                           *(undefined4 *)(param_2 + 0x1c),0x1a,0x11);
        *(int *)(iVar8 + 0x28) = iVar9;
        if (iVar9 != 0) {
          *(byte *)(param_1 + 0x4b) = *(byte *)(param_1 + 0x4b) | 1;
        }
      }
    }
    else {
      iVar9 = *(int *)(*(int *)(iVar8 + 0x28) + 0x38);
      *(undefined4 *)(iVar9 + 0x14) = *(undefined4 *)(param_2 + 0x14);
      *(undefined4 *)(iVar9 + 0x18) = *(undefined4 *)(param_2 + 0x18);
      *(undefined4 *)(iVar9 + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
      piVar1 = (int *)(*(int *)(*(int *)(iVar8 + 0x28) + 0x38) + 0x18);
      *piVar1 = *piVar1 + *(int *)(param_2 + 0x40) + 0x28;
    }
    if ((((int)uVar13 < 100) && (*(int *)(param_1 + 0x50) < 1)) &&
       ((*(byte *)(param_1 + 0x4b) & 1) != 0)) {
      if (*(short *)(iVar8 + 0x20) == 0x10) {
        PlayAudioById(0x14d,param_2 + 0x104,param_2 + 0x14);
      }
      iVar9 = RandomModulo(0x1e);
      *(int *)(param_1 + 0x50) = iVar9 + 0x32;
      iVar9 = *(int *)(param_2 + 0x3c);
      iVar11 = *(int *)(param_2 + 0x14);
      iVar14 = *(int *)(param_2 + 0x1c);
      iVar3 = *(int *)(param_2 + 0x44);
      iVar4 = *(int *)(g_PlayerSceneEntryData + 8);
      iVar5 = *(int *)(g_PlayerSceneEntry + 0x54);
      iVar6 = *(int *)(g_PlayerSceneEntry + 0x5c);
      iVar7 = *(int *)(g_PlayerSceneEntryData + 0x10);
      iVar10 = SqrtToInt((((*(int *)(g_PlayerSceneEntry + 0x58) +
                           *(int *)(g_PlayerSceneEntryData + 0xc)) -
                          (*(int *)(param_2 + 0x18) + *(int *)(param_2 + 0x40))) * 2) / 6);
      uVar12 = (iVar10 >> 6) + 1;
      if (5 < (int)uVar12) {
        iVar10 = CEntities__CreateRuntimeEntryAttachment
                           (*(undefined4 *)(iVar8 + 0x28),0x9c,0x10000000);
        if (iVar10 == 0) {
          CEntities__ReleaseRuntimeEntryToFreeList(*(undefined4 *)(iVar8 + 0x28));
          *(undefined4 *)(iVar8 + 0x28) = 0;
          *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfe7f;
          return;
        }
        *(short *)(iVar10 + 0x18) = (short)uVar12;
        *(undefined4 *)(iVar10 + 0x1c) = 6;
        *(undefined1 *)(iVar10 + 0x20) = 0;
        *(undefined4 *)(iVar10 + 0x10) = 0;
        *(int *)(iVar10 + 0xc) = ((iVar9 + iVar11) - (iVar5 + iVar4)) / (int)(uVar12 & 0xffff);
        *(int *)(iVar10 + 0x14) = ((iVar3 + iVar14) - (iVar6 + iVar7)) / (int)(uVar12 & 0xffff);
        *(ushort *)(param_1 + 0x4a) = *(ushort *)(param_1 + 0x4a) & 0xfe7f;
        return;
      }
    }
    else {
      *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + -1;
    }
  }
  return;
}

