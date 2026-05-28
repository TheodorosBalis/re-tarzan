
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void CEntities__ProcessEntityDeath(int param_1,int param_2)

{
  undefined **ppuVar1;
  ushort uVar2;
  int iVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined4 *puVar10;
  short *psVar11;
  undefined4 *puVar12;
  undefined2 *puVar13;
  bool bVar14;
  
  bVar14 = _g_PlayerHeroMode == 2;
  uVar5 = (uint)*(ushort *)(&DAT_00511940 + param_2 * 8);
  uVar2 = *(ushort *)(&DAT_00511942 + param_2 * 8);
  iVar6 = CEntities__SpawnRuntimeEntryByTypeAtPosition
                    (*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18),
                     *(undefined4 *)(param_1 + 0x1c),0x15,0x11);
  if (iVar6 != 0) {
    iVar3 = *(int *)(iVar6 + 0x38);
    if (iVar3 != 0) {
      *(int *)(iVar3 + 0x10) = g_WorldSceneEntryArrayBase + 0x3a8;
      *(undefined2 *)(iVar3 + 0xa6) = 0;
      *(undefined2 *)(iVar3 + 0xe) = 0x421;
      puVar10 = (undefined4 *)(param_1 + 0x108);
      puVar12 = (undefined4 *)(iVar3 + 0x108);
      for (iVar9 = 0xf; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar12 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar12 = puVar12 + 1;
      }
      sVar4 = *(short *)(param_1 + 0xa2);
      if (bVar14) {
        *(undefined4 *)(iVar3 + 0xb4) = 1;
        *(undefined4 *)(iVar3 + 0xa8) = 0xa00;
        *(undefined4 *)(iVar3 + 0xac) = 0xa00;
        *(undefined4 *)(iVar3 + 0xb0) = 0xa00;
      }
      iVar9 = 0;
      if (uVar2 != 0) {
        do {
          iVar7 = CreateRuntimeEntitySceneEntry(iVar6,iVar9 + 10);
          if (iVar7 != 0) {
            ppuVar1 = &PTR_DAT_00511944 + param_2 * 2;
            *(int *)(iVar7 + 0x18) =
                 (int)*(short *)((&PTR_DAT_00511944)[param_2 * 2] + iVar9 * 8 + 4) +
                 *(int *)(iVar3 + 0x18);
            *(int *)(iVar7 + 0x14) =
                 *(int *)(iVar3 + 0x14) -
                 ((int)(short)(&g_SinCosTable12Bit)[(int)sVar4 - 0x400U & 0xfff] *
                  (int)*(short *)(*ppuVar1 + iVar9 * 8 + 2) >> 0xc);
            *(int *)(iVar7 + 0x1c) =
                 *(int *)(iVar3 + 0x1c) -
                 ((int)(short)(&g_SinCosTable12Bit)[(int)sVar4 & 0xfff] *
                  (int)*(short *)(*ppuVar1 + iVar9 * 8 + 2) >> 0xc);
            *(undefined *)(iVar7 + 0x74) = (*ppuVar1)[iVar9 * 8];
            iVar8 = g_WorldSceneEntryArrayBase;
            *(ushort *)(iVar7 + 0xe) = *(ushort *)(iVar7 + 0xe) | 0x1421;
            *(int *)(iVar7 + 0x10) = iVar8 + 0x3a8;
            *(undefined2 *)(iVar7 + 0xc) = 0x204c;
            iVar8 = RandomModulo(0x800);
            *(int *)(iVar7 + 0x20) = iVar8 + 0x600;
            iVar8 = RandomModulo(0x800);
            *(int *)(iVar7 + 0x24) = iVar8 + 0x600;
            iVar8 = RandomModulo(0x800);
            *(int *)(iVar7 + 0x28) = iVar8 + 0x600;
            *(undefined4 *)(iVar7 + 0x30) = 0;
          }
          iVar9 = iVar9 + 1;
        } while (iVar9 < (int)(uint)uVar2);
      }
      iVar9 = FUN_004403c0(iVar6,1,uVar5);
      if (iVar9 != 0) {
        psVar11 = (short *)(iVar9 + 0x10);
        iVar9 = CEntities__CreateRuntimeEntryAttachment(iVar6,0xb8,0x10000021);
        if ((iVar9 != 0) && (iVar7 = 0, uVar5 != 0)) {
          puVar13 = (undefined2 *)(iVar9 + 0xc);
          do {
            *(int *)(psVar11 + 2) = g_WorldSceneEntryArrayBase + 0x3a8;
            sVar4 = RandomModulo(8);
            *psVar11 = sVar4 + 0x2019;
            psVar11[4] = 0;
            psVar11[5] = 0;
            psVar11[6] = 0;
            psVar11[7] = 0;
            psVar11[8] = 0;
            psVar11[9] = 0;
            iVar8 = RandomModulo(0x10);
            puVar13[4] = (short)iVar8;
            *(int *)(psVar11 + 10) = (int)*(short *)(&DAT_00511860 + iVar8 * 8);
            *(int *)(psVar11 + 0xc) = (int)*(short *)(&DAT_00511862 + iVar8 * 8);
            *(int *)(psVar11 + 0xe) = (int)*(short *)(&DAT_00511864 + iVar8 * 8);
            psVar11[1] = 0x421;
            psVar11[0x12] = 0;
            psVar11[0x13] = 0;
            *(undefined **)(iVar9 + 0xb4) = &DAT_00511940 + param_2 * 8;
            *puVar13 = 0;
            puVar13[1] = 0xff80;
            puVar13[2] = 0x20;
            puVar13[3] = (short)iVar7 * 4 + -1;
            psVar11 = psVar11 + 0x14;
            puVar13[6] = 0;
            iVar7 = iVar7 + 1;
            puVar13 = puVar13 + 7;
          } while (iVar7 < (int)uVar5);
        }
      }
      PlayAudioById(0xad,0,iVar3 + 0x14);
    }
    if (*(short *)(iVar6 + 0x44) != 0) {
      CEntities__ReleaseRuntimeEntryToFreeList(iVar6);
    }
  }
  return;
}

