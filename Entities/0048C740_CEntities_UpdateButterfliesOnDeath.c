
void CEntities__UpdateButterfliesOnDeath(int param_1)

{
  int iVar1;
  bool bVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  ushort *puVar8;
  ushort *puVar9;
  
  bVar2 = false;
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 != 0) {
    *(short *)(iVar1 + 0xa2) = *(short *)(iVar1 + 0xa2) + 0x9f;
    if (*(int *)(iVar1 + 0x38) != 0) {
      puVar9 = (ushort *)(*(int *)(iVar1 + 0x38) + 0x10);
      iVar5 = FindRuntimeEntityAttachmentByFlags(param_1,0x10000021);
      if (iVar5 != 0) {
        puVar8 = (ushort *)(iVar5 + 0xc);
        for (uVar7 = (uint)**(ushort **)(iVar5 + 0xb4); uVar7 != 0; uVar7 = uVar7 - 1) {
          if (puVar8[6] == 0) {
            puVar8[3] = puVar8[3] - 1;
            if ((short)puVar8[3] < 0) {
              sVar3 = RandomModulo(0x30);
              uVar4 = sVar3 + 0x40;
              puVar8[2] = uVar4;
              uVar6 = *(ushort *)(iVar1 + 0xa2) - 0x400 & 0xfff;
              *puVar8 = (ushort)uVar6;
              *(int *)(puVar9 + 4) =
                   (int)(short)(&g_SinCosTable12Bit)[uVar6 - 0x400 & 0xfff] * (int)(short)uVar4 >>
                   0xc;
              *(int *)(puVar9 + 8) =
                   (int)(short)(&g_SinCosTable12Bit)[uVar6] * (int)(short)uVar4 >> 0xc;
              iVar5 = RandomModulo(0x80);
              *(byte *)((int)puVar9 + 3) = *(byte *)((int)puVar9 + 3) | 0x80;
              *(int *)(puVar9 + 6) = -0x80 - iVar5;
              puVar8[6] = 1;
              puVar8[3] = 0x3c;
              puVar8[5] = 0x1000;
            }
LAB_0048c93b:
            bVar2 = true;
          }
          else if (puVar8[6] == 1) {
            puVar8[3] = puVar8[3] - 1;
            if ((short)puVar8[3] < 0) {
              puVar8[6] = 2;
              puVar9[1] = puVar9[1] & 0x7fff;
              goto LAB_0048c93b;
            }
            *puVar9 = *puVar9 + 1;
            if (0x2020 < *puVar9) {
              *puVar9 = 0x2019;
            }
            uVar4 = *puVar8;
            iVar5 = (short)puVar8[2] + 5;
            *(int *)(puVar9 + 4) =
                 (short)(&g_SinCosTable12Bit)[uVar4 - 0x400 & 0xfff] * iVar5 >> 0xc;
            *(int *)(puVar9 + 8) = (short)(&g_SinCosTable12Bit)[uVar4 & 0xfff] * iVar5 >> 0xc;
            *(int *)(puVar9 + 6) = *(int *)(puVar9 + 6) + -0xf;
            puVar8[2] = (ushort)iVar5;
            iVar5 = puVar8[5] - 0x44;
            if (iVar5 < 0) {
              iVar5 = 1;
LAB_0048c846:
              uVar6 = (uint)puVar8[4];
              *(int *)(puVar9 + 10) =
                   (int)(*(short *)(&DAT_00511860 + uVar6 * 8) * iVar5 +
                        (*(short *)(&DAT_00511860 + uVar6 * 8) * iVar5 >> 0x1f & 0xfffU)) >> 0xc;
              *(int *)(puVar9 + 0xc) =
                   (int)(*(short *)(&DAT_00511862 + uVar6 * 8) * iVar5 +
                        (*(short *)(&DAT_00511862 + uVar6 * 8) * iVar5 >> 0x1f & 0xfffU)) >> 0xc;
              *(int *)(puVar9 + 0xe) =
                   (int)(*(short *)(&DAT_00511864 + uVar6 * 8) * iVar5 +
                        (*(short *)(&DAT_00511864 + uVar6 * 8) * iVar5 >> 0x1f & 0xfffU)) >> 0xc;
            }
            else if (iVar5 != 0) goto LAB_0048c846;
            puVar8[5] = (ushort)iVar5;
            goto LAB_0048c93b;
          }
          puVar9 = puVar9 + 0x14;
          puVar8 = puVar8 + 7;
        }
        for (iVar1 = *(int *)(iVar1 + 0x34); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x34)) {
          if (*(char *)(iVar1 + 0x74) == '\0') {
            if ((*(byte *)(iVar1 + 0xf) & 0x80) != 0) {
              *(short *)(iVar1 + 0xc) = *(short *)(iVar1 + 0xc) + 1;
              if (0x205b < *(ushort *)(iVar1 + 0xc)) {
                *(undefined2 *)(iVar1 + 0xe) = 0;
              }
              goto LAB_0048c97f;
            }
          }
          else {
            *(char *)(iVar1 + 0x74) = *(char *)(iVar1 + 0x74) + -1;
LAB_0048c97f:
            bVar2 = true;
          }
        }
        if (bVar2) {
          return;
        }
      }
    }
  }
  CEntities__ReleaseRuntimeEntryToFreeList(param_1);
  return;
}

