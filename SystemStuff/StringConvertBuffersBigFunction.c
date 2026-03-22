/* Address: 0x004B75AF */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 StringConvertBuffersBigFunction(undefined4 param_1)

{
  BYTE *pBVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  UINT CodePage;
  UINT *pUVar5;
  BOOL BVar6;
  uint uVar7;
  uint uVar8;
  BYTE *pBVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  undefined4 uVar14;
  undefined4 *puVar15;
  _cpinfo local_1c;
  uint local_8;
  
  MemAllocOrEnterCS(0x19);
  CodePage = SelectSystemCharCodePage(param_1);
  if (CodePage != DAT_00c46ff0) {
    if (CodePage != 0) {
      iVar12 = 0;
      pUVar5 = &DAT_0051baa8;
LAB_004b75ec:
      if (*pUVar5 != CodePage) goto code_r0x004b75f0;
      local_8 = 0;
      puVar15 = &DAT_00c47120;
      for (iVar10 = 0x40; iVar10 != 0; iVar10 = iVar10 + -1) {
        *puVar15 = 0;
        puVar15 = puVar15 + 1;
      }
      iVar12 = iVar12 * 0x30;
      *(undefined1 *)puVar15 = 0;
      pbVar13 = (byte *)(iVar12 + 0x51bab8);
      do {
        bVar3 = *pbVar13;
        pbVar11 = pbVar13;
        while ((bVar3 != 0 && (bVar3 = pbVar11[1], bVar3 != 0))) {
          uVar8 = (uint)*pbVar11;
          if (uVar8 <= bVar3) {
            bVar4 = (&DAT_0051baa0)[local_8];
            do {
              pbVar2 = (byte *)((int)&DAT_00c47120 + uVar8 + 1);
              *pbVar2 = *pbVar2 | bVar4;
              uVar8 = uVar8 + 1;
            } while (uVar8 <= bVar3);
          }
          pbVar11 = pbVar11 + 2;
          bVar3 = *pbVar11;
        }
        local_8 = local_8 + 1;
        pbVar13 = pbVar13 + 8;
      } while (local_8 < 4);
      _DAT_00c4700c = 1;
      DAT_00c46ff0 = CodePage;
      DAT_00c47224 = ReturnBasedOnArgSize(CodePage);
      DAT_00c47000 = *(undefined4 *)(iVar12 + 0x51baac);
      DAT_00c47004 = *(undefined4 *)(iVar12 + 0x51bab0);
      DAT_00c47008 = *(undefined4 *)(iVar12 + 0x51bab4);
      goto LAB_004b7740;
    }
    goto LAB_004b773b;
  }
  goto LAB_004b75d6;
code_r0x004b75f0:
  pUVar5 = pUVar5 + 0xc;
  iVar12 = iVar12 + 1;
  if (0x51bb97 < (int)pUVar5) goto code_r0x004b75fb;
  goto LAB_004b75ec;
code_r0x004b75fb:
  BVar6 = GetCPInfo(CodePage,&local_1c);
  uVar8 = 1;
  if (BVar6 == 1) {
    DAT_00c47224 = 0;
    puVar15 = &DAT_00c47120;
    for (iVar12 = 0x40; iVar12 != 0; iVar12 = iVar12 + -1) {
      *puVar15 = 0;
      puVar15 = puVar15 + 1;
    }
    *(undefined1 *)puVar15 = 0;
    if (local_1c.MaxCharSize < 2) {
      _DAT_00c4700c = 0;
      DAT_00c46ff0 = CodePage;
    }
    else {
      DAT_00c46ff0 = CodePage;
      if (local_1c.LeadByte[0] != '\0') {
        pBVar9 = local_1c.LeadByte + 1;
        do {
          bVar3 = *pBVar9;
          if (bVar3 == 0) break;
          for (uVar7 = (uint)pBVar9[-1]; uVar7 <= bVar3; uVar7 = uVar7 + 1) {
            pbVar13 = (byte *)((int)&DAT_00c47120 + uVar7 + 1);
            *pbVar13 = *pbVar13 | 4;
          }
          pBVar1 = pBVar9 + 1;
          pBVar9 = pBVar9 + 2;
        } while (*pBVar1 != 0);
      }
      do {
        pbVar13 = (byte *)((int)&DAT_00c47120 + uVar8 + 1);
        *pbVar13 = *pbVar13 | 8;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 0xff);
      DAT_00c47224 = ReturnBasedOnArgSize(CodePage);
      _DAT_00c4700c = 1;
    }
    DAT_00c47000 = 0;
    DAT_00c47004 = 0;
    DAT_00c47008 = 0;
  }
  else {
    if (DAT_00c46e50 == 0) {
      uVar14 = 0xffffffff;
      goto LAB_004b774d;
    }
LAB_004b773b:
    ZeroBufferC47000();
  }
LAB_004b7740:
  ConvertAndUpdateStringBuffers();
LAB_004b75d6:
  uVar14 = 0;
LAB_004b774d:
  LeaveCSforObjectInTable(0x19);
  return uVar14;
}

