
void CEntities__UpdateThrowableFromNPC(int param_1)

{
  char cVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  short *psVar11;
  ushort *puVar12;
  char *pcVar13;
  int iStack_14;
  short *psStack_c;
  
  iVar7 = *(int *)(param_1 + 0x38);
  if ((iVar7 != 0) && (iVar3 = FindRuntimeEntityAttachmentByFlags(param_1,0x10000000), iVar3 != 0))
  {
    piVar9 = (int *)(iVar7 + 0x14);
    *piVar9 = *(int *)(iVar7 + 0x14) - *(int *)(iVar3 + 0xc);
    *(int *)(iVar7 + 0x18) = *(int *)(iVar7 + 0x18) - *(int *)(iVar3 + 0x10);
    *(int *)(iVar7 + 0x1c) = *(int *)(iVar7 + 0x1c) - *(int *)(iVar3 + 0x14);
    cVar1 = *(char *)(iVar3 + 0x20);
    if (cVar1 == '\0') {
      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) - *(int *)(iVar3 + 0x1c);
      *(short *)(iVar7 + 0xa4) = *(short *)(iVar7 + 0xa4) + 0x100;
      cVar1 = CEntities__CheckPlayerDamageContact(iVar7);
      *(short *)(iVar3 + 0x18) = *(short *)(iVar3 + 0x18) + -1;
      uVar5 = *(int *)(iVar7 + 0x18) - *(int *)(iVar7 + 0x4c);
      uVar6 = (int)uVar5 >> 0x1f;
      if (0x1000 < (int)((uVar5 ^ uVar6) - uVar6)) {
        *(undefined2 *)(iVar3 + 0x18) = 0;
      }
      if ((*(short *)(iVar3 + 0x18) == 0) || (cVar1 != '\0')) {
        *(undefined2 *)(iVar7 + 0xa6) = 3;
        *(ushort *)(iVar7 + 0xe) = *(ushort *)(iVar7 + 0xe) & 0x6fff | 0x1000;
        *(int *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) >> 1;
        *(undefined1 *)(iVar3 + 0x20) = 1;
        *(int *)(iVar3 + 0xc) = *(int *)(iVar3 + 0xc) >> 1;
        *(int *)(iVar3 + 0x10) = -*(int *)(iVar3 + 0x10) >> 2;
        iVar8 = FUN_004403c0(param_1,1,8);
        if (iVar8 != 0) {
          psStack_c = (short *)(iVar3 + 0x8c);
          iVar10 = 0;
          puVar12 = (ushort *)(iVar8 + 0x12);
          do {
            *puVar12 = *puVar12 & 0x6fff | 0x1000;
            *(undefined1 *)(iVar10 + 0x84 + iVar3) = 0;
            sVar2 = RandomModulo(4);
            *psStack_c = sVar2 + 1;
            puVar12[-1] = 0x2011;
            psStack_c = psStack_c + 1;
            iVar10 = iVar10 + 1;
            *(int *)(puVar12 + 1) = g_WorldSceneEntryArrayBase + 0x3a8;
            puVar12 = puVar12 + 0x14;
          } while (iVar10 < 8);
        }
        CEntities__SpawnRuntimeEntryByTypeAtPosition
                  (*piVar9,*(undefined4 *)(iVar7 + 0x18),*(undefined4 *)(iVar7 + 0x1c),0x13,0x11);
        PlayAudioById(0xb7,0,piVar9);
        if ((cVar1 != '\0') && (g_PlayerBlockDamageGuardActive == 0)) {
          QueuePlayerDamageEvent(param_1,0x2005);
        }
      }
    }
    else if (cVar1 == '\x01') {
      pcVar13 = (char *)(iVar3 + 0x84);
      psVar11 = (short *)(iVar3 + 0x8c);
      iStack_14 = 0;
      piVar4 = (int *)(*(int *)(*(int *)(param_1 + 0x38) + 0x38) + 0x1c);
      piVar9 = (int *)(iVar3 + 0x28);
      do {
        sVar2 = *psVar11;
        *psVar11 = sVar2 + -1;
        cVar1 = *pcVar13;
        if (cVar1 == '\0') {
          if ((short)(sVar2 + -1) == 0) {
            *pcVar13 = '\x01';
            sVar2 = RandomModulo(0x14);
            *psVar11 = sVar2 + 0x14;
            uVar5 = RandomModulo(0x1000);
            uVar6 = RandomModulo(0x400);
            iVar7 = RandomModulo(10);
            iVar8 = RandomModulo(0x10);
            piVar9[-1] = (int)(short)(&g_SinCosTable12Bit)[uVar5 - 0x400 & 0xfff] * (iVar7 + 0x18)
                         >> 0xc;
            piVar9[1] = (int)(short)(&g_SinCosTable12Bit)[uVar5 & 0xfff] * (iVar7 + 0x18) >> 0xc;
            *piVar9 = -((int)(short)(&g_SinCosTable12Bit)[uVar6 & 0xfff] * (iVar8 + 0x20)) >> 0xc;
            *(byte *)((int)piVar4 + -9) = *(byte *)((int)piVar4 + -9) | 0x80;
          }
        }
        else if (cVar1 == '\x01') {
          piVar4[-1] = piVar4[-1] + piVar9[-1];
          *piVar4 = *piVar4 + *piVar9;
          piVar4[1] = piVar4[1] + piVar9[1];
          *piVar9 = *piVar9 + *(int *)(iVar3 + 0x1c);
          if (*psVar11 == 0) {
            *pcVar13 = '\x02';
            *(ushort *)((int)piVar4 + -10) = *(ushort *)((int)piVar4 + -10) & 0x7fff;
          }
        }
        else if (cVar1 == '\x02') {
          iStack_14 = iStack_14 + 1;
        }
        psVar11 = psVar11 + 1;
        pcVar13 = pcVar13 + 1;
        piVar9 = piVar9 + 3;
        piVar4 = piVar4 + 10;
      } while ((int)(pcVar13 + (-0x84 - iVar3)) < 8);
      if (iStack_14 == 8) {
        CEntities__ReleaseRuntimeEntryToFreeList(param_1);
      }
    }
    else if (cVar1 == '\x02') {
      *(int *)(iVar3 + 0x10) = *(int *)(iVar3 + 0x10) - *(int *)(iVar3 + 0x1c);
      *(short *)(iVar7 + 0xa4) = *(short *)(iVar7 + 0xa4) + 0x100;
      *(short *)(iVar3 + 0x18) = *(short *)(iVar3 + 0x18) + -1;
      if (*(short *)(iVar3 + 0x18) == 0) {
        CEntities__ReleaseRuntimeEntryToFreeList(param_1);
      }
    }
  }
  cVar1 = IsRuntimeEntryOutsideOuterActivationBounds(param_1);
  if (cVar1 != '\0') {
    CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  }
  return;
}

