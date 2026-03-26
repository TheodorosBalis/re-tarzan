// Address: 0x004A76F0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

ushort ClipTrianglePacketToScreenXBounds(void)

{
  char cVar1;
  bool bVar2;
  float fVar3;
  float fVar4;
  ushort uVar5;
  ushort uVar6;
  int iVar7;
  ushort uVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  ushort uVar12;
  uint uVar13;
  float *pfVar14;
  float *pfVar15;
  ushort uVar16;
  float *pfVar17;
  char *local_1c;
  int local_10;
  int local_c;
  char local_8 [8];
  
  uVar16 = 3;
  DAT_009cefe4 = (float *)&DAT_0079e7c0;
  local_c = 2;
  uVar6 = 3;
  fVar3 = 2.8026e-45;
  DAT_009cedbc = (float *)&DAT_0079e7c0;
  DAT_009ceff0 = (float *)&DAT_0079e8a0;
  local_10 = 2;
  pfVar14 = (float *)&DAT_0079e8a0;
  do {
    pfVar15 = pfVar14;
    if (local_10 == 2) {
      if (DAT_009cefec != 0) {
        pcVar9 = local_8;
        _DAT_009ceff4 = DAT_009cefe4;
        fVar3 = _g_RenderWindowWidthF;
        if (uVar16 != 0) {
          uVar13 = (uint)uVar16;
          do {
            *pcVar9 = _g_RenderWindowWidthF < *DAT_009cefe4;
            pcVar9 = pcVar9 + 1;
            DAT_009cefe4 = DAT_009cefe4 + 8;
            uVar13 = uVar13 - 1;
            _DAT_009ceff4 = DAT_009cefe4;
            fVar3 = _g_RenderWindowWidthF;
          } while (uVar13 != 0);
        }
        goto LAB_004a77e9;
      }
    }
    else {
      if (local_10 == 4) {
        if (DAT_0079e7b0 == 0) goto LAB_004a7986;
        pcVar9 = local_8;
        _DAT_009ceff4 = DAT_009cefe4;
        fVar3 = _DAT_004ba2b4;
        if (uVar16 != 0) {
          uVar13 = (uint)uVar16;
          do {
            *pcVar9 = *DAT_009cefe4 < _DAT_004ba2b4;
            pcVar9 = pcVar9 + 1;
            DAT_009cefe4 = DAT_009cefe4 + 8;
            uVar13 = uVar13 - 1;
            _DAT_009ceff4 = DAT_009cefe4;
          } while (uVar13 != 0);
        }
      }
LAB_004a77e9:
      iVar7 = 0;
      uVar12 = uVar16 - 1;
      bVar2 = uVar16 != 0;
      uVar16 = 0;
      if (bVar2) {
        local_1c = local_8;
        uVar8 = 0;
        do {
          uVar5 = uVar8;
          uVar13 = (uint)uVar12;
          cVar1 = *local_1c;
          if (local_8[uVar13] != cVar1) {
            uVar10 = (uint)uVar16;
            pfVar14[uVar10 * 8] = fVar3;
            uVar16 = uVar16 + 1;
            pfVar14 = (float *)(iVar7 + 4 + (int)DAT_009cedbc);
            fVar4 = (fVar3 - *(float *)(iVar7 + (int)DAT_009cedbc)) /
                    (DAT_009cedbc[uVar13 * 8] - *(float *)(iVar7 + (int)DAT_009cedbc));
            DAT_009ceff0[uVar10 * 8 + 1] =
                 (DAT_009cedbc[uVar13 * 8 + 1] - *pfVar14) * fVar4 + *pfVar14;
            DAT_009ceff0[uVar10 * 8 + 2] =
                 (DAT_009cedbc[uVar13 * 8 + 2] - *(float *)(iVar7 + 8 + (int)DAT_009cedbc)) * fVar4
                 + *(float *)(iVar7 + 8 + (int)DAT_009cedbc);
            DAT_009ceff0[uVar10 * 8 + 3] =
                 (DAT_009cedbc[uVar13 * 8 + 3] - *(float *)(iVar7 + 0xc + (int)DAT_009cedbc)) *
                 fVar4 + *(float *)(iVar7 + 0xc + (int)DAT_009cedbc);
            DAT_009ceff0[uVar10 * 8 + 4] =
                 (DAT_009cedbc[uVar13 * 8 + 4] - *(float *)(iVar7 + 0x10 + (int)DAT_009cedbc)) *
                 fVar4 + *(float *)(iVar7 + 0x10 + (int)DAT_009cedbc);
            DAT_009ceff0[uVar10 * 8 + 5] =
                 (DAT_009cedbc[uVar13 * 8 + 5] - *(float *)(iVar7 + 0x14 + (int)DAT_009cedbc)) *
                 fVar4 + *(float *)(iVar7 + 0x14 + (int)DAT_009cedbc);
            DAT_009ceff0[uVar10 * 8 + 6] =
                 (DAT_009cedbc[uVar13 * 8 + 6] - *(float *)(iVar7 + 0x18 + (int)DAT_009cedbc)) *
                 fVar4 + *(float *)(iVar7 + 0x18 + (int)DAT_009cedbc);
            DAT_009ceff0[uVar10 * 8 + 7] =
                 (DAT_009cedbc[uVar13 * 8 + 7] - *(float *)(iVar7 + 0x1c + (int)DAT_009cedbc)) *
                 fVar4 + *(float *)(iVar7 + 0x1c + (int)DAT_009cedbc);
            pfVar14 = DAT_009ceff0;
          }
          if (cVar1 == '\0') {
            uVar13 = (uint)uVar16;
            uVar16 = uVar16 + 1;
            pfVar15 = (float *)(iVar7 + (int)DAT_009cedbc);
            pfVar17 = pfVar14 + uVar13 * 8;
            for (iVar11 = 8; pfVar14 = DAT_009ceff0, iVar11 != 0; iVar11 = iVar11 + -1) {
              *pfVar17 = *pfVar15;
              pfVar15 = pfVar15 + 1;
              pfVar17 = pfVar17 + 1;
            }
          }
          uVar8 = uVar5 + 1;
          local_1c = local_1c + 1;
          iVar7 = iVar7 + 0x20;
          uVar12 = uVar5;
        } while (uVar8 < uVar6);
      }
      DAT_009ceff0 = DAT_009cedbc;
      pfVar15 = DAT_009cedbc;
      DAT_009cefe4 = pfVar14;
      DAT_009cedbc = pfVar14;
      _DAT_009cf10c = pfVar14;
      uVar6 = uVar16;
    }
LAB_004a7986:
    local_10 = local_10 + 2;
    local_c = local_c + -1;
    pfVar14 = pfVar15;
    if (local_c == 0) {
      return uVar16;
    }
  } while( true );
}


