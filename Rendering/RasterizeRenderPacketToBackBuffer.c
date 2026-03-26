// Address: 0x004A5160

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeRenderPacketToBackBuffer(code *param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  byte bVar8;
  byte bVar9;
  byte bVar10;
  float fVar11;
  float fVar12;
  int iVar13;
  float fVar14;
  ushort uVar15;
  ushort uVar16;
  int iVar17;
  int iVar18;
  int iVar19;
  int iVar20;
  float *pfVar21;
  short sVar22;
  uint uVar23;
  int iVar24;
  short sVar25;
  int local_8;
  
  DAT_009cf124 = *(byte *)((int)param_1 + 0x38) & 0x1f;
  fVar14 = *(float *)((int)param_1 + 0x38);
  if (((uint)fVar14 & 0x600) != 0x200) {
    if ((((uint)fVar14 & 0x20) == 0) && (g_RenderWindowWidth < 0x141)) {
      *(float *)param_1 = *(float *)param_1 * _DAT_004ba2e8;
      *(float *)((int)param_1 + 0xc) = *(float *)((int)param_1 + 0xc) * _DAT_004ba260;
      *(float *)((int)param_1 + 4) = *(float *)((int)param_1 + 4) * _DAT_004ba2e8;
      *(float *)((int)param_1 + 0x10) = *(float *)((int)param_1 + 0x10) * _DAT_004ba260;
      *(float *)((int)param_1 + 8) = *(float *)((int)param_1 + 8) * _DAT_004ba2e8;
      *(float *)((int)param_1 + 0x14) = *(float *)((int)param_1 + 0x14) * _DAT_004ba260;
    }
    else {
      *(float *)param_1 = *(float *)param_1 * _DAT_004ba2e4;
      *(float *)((int)param_1 + 4) = *(float *)((int)param_1 + 4) * _DAT_004ba2e4;
      *(float *)((int)param_1 + 8) = *(float *)((int)param_1 + 8) * _DAT_004ba2e4;
    }
    uVar16 = DAT_009cefec_2;
    uVar15 = DAT_0079e7b0_2;
    DAT_009cefe4 = &DAT_0079e7c0;
    _DAT_009ceda8 =
         (*(float *)((int)param_1 + 4) - *(float *)param_1) *
         (*(float *)((int)param_1 + 0x14) - *(float *)((int)param_1 + 0xc)) -
         (*(float *)((int)param_1 + 8) - *(float *)param_1) *
         (*(float *)((int)param_1 + 0x10) - *(float *)((int)param_1 + 0xc));
    if (_DAT_004ba2b4 <= _DAT_009ceda8) {
      DAT_0079e7e4 = *(float *)((int)param_1 + 0x10);
      bVar6 = *(byte *)((int)param_1 + 0x33);
      bVar7 = *(byte *)((int)param_1 + 0x32);
      bVar8 = *(byte *)((int)param_1 + 0x2a);
      bVar9 = *(byte *)((int)param_1 + 0x29);
      bVar10 = *(byte *)((int)param_1 + 0x28);
      DAT_0079e800 = *(float *)((int)param_1 + 8);
      DAT_0079e804 = *(float *)((int)param_1 + 0x14);
      bVar1 = *(byte *)((int)param_1 + 0x35);
      bVar2 = *(byte *)((int)param_1 + 0x34);
      bVar3 = *(byte *)((int)param_1 + 0x2e);
      bVar4 = *(byte *)((int)param_1 + 0x2d);
      bVar5 = *(byte *)((int)param_1 + 0x2c);
      DAT_0079e7e0 = *(float *)((int)param_1 + 4);
    }
    else {
      DAT_0079e804 = *(float *)((int)param_1 + 0x10);
      bVar1 = *(byte *)((int)param_1 + 0x33);
      bVar2 = *(byte *)((int)param_1 + 0x32);
      bVar3 = *(byte *)((int)param_1 + 0x2a);
      bVar4 = *(byte *)((int)param_1 + 0x29);
      bVar5 = *(byte *)((int)param_1 + 0x28);
      DAT_0079e7e4 = *(float *)((int)param_1 + 0x14);
      bVar6 = *(byte *)((int)param_1 + 0x35);
      bVar7 = *(byte *)((int)param_1 + 0x34);
      bVar8 = *(byte *)((int)param_1 + 0x2e);
      bVar9 = *(byte *)((int)param_1 + 0x2d);
      bVar10 = *(byte *)((int)param_1 + 0x2c);
      DAT_0079e7e0 = *(float *)((int)param_1 + 8);
      DAT_0079e800 = *(float *)((int)param_1 + 4);
    }
    DAT_0079e81c = (float)((ulonglong)bVar5 << 0x10);
    DAT_0079e818 = (float)((ulonglong)bVar4 << 0x10);
    DAT_0079e814 = (float)((ulonglong)bVar3 << 0x10);
    DAT_0079e80c = (float)((ulonglong)bVar2 << 0x10);
    DAT_0079e808 = (float)((ulonglong)bVar1 << 0x10);
    DAT_0079e7fc = (float)((ulonglong)bVar10 << 0x10);
    DAT_0079e7f8 = (float)((ulonglong)bVar9 << 0x10);
    DAT_0079e7f4 = (float)((ulonglong)bVar8 << 0x10);
    DAT_0079e7ec = (float)((ulonglong)bVar7 << 0x10);
    DAT_0079e7e8 = (float)((ulonglong)bVar6 << 0x10);
    DAT_0079e7c0 = *(float *)param_1;
    DAT_0079e7c4 = *(float *)((int)param_1 + 0xc);
    DAT_0079e7c8 = (float)((ulonglong)*(byte *)((int)param_1 + 0x31) << 0x10);
    sVar25 = 0;
    DAT_0079e7cc = (float)((ulonglong)*(byte *)((int)param_1 + 0x30) << 0x10);
    DAT_0079e7d4 = (float)((ulonglong)*(byte *)((int)param_1 + 0x26) << 0x10);
    DAT_0079e7d8 = (float)((ulonglong)*(byte *)((int)param_1 + 0x25) << 0x10);
    _DAT_009cefec = (uint)DAT_009cefec_2 << 0x10;
    sVar22 = 0;
    DAT_0079e7dc = (float)((ulonglong)*(byte *)((int)param_1 + 0x24) << 0x10);
    _DAT_0079e7b0 = (uint)DAT_0079e7b0_2 << 0x10;
    if (_DAT_004ba2b4 <= DAT_0079e7c0) {
      if (_g_RenderWindowWidthF < DAT_0079e7c0) {
        sVar25 = 1;
        _DAT_009cefec = CONCAT22(uVar16,1);
      }
    }
    else {
      sVar22 = 1;
      _DAT_0079e7b0 = CONCAT22(uVar15,1);
    }
    if (_DAT_004ba2b4 <= DAT_0079e7e0) {
      if (_g_RenderWindowWidthF < DAT_0079e7e0) {
        sVar25 = sVar25 + 1;
        _DAT_009cefec = CONCAT22(DAT_009cefec_2,sVar25);
      }
    }
    else {
      sVar22 = sVar22 + 1;
      _DAT_0079e7b0 = CONCAT22(DAT_0079e7b0_2,sVar22);
    }
    if (_DAT_004ba2b4 <= DAT_0079e800) {
      if (_g_RenderWindowWidthF < DAT_0079e800) {
        sVar25 = sVar25 + 1;
        _DAT_009cefec = CONCAT22(DAT_009cefec_2,sVar25);
      }
    }
    else {
      sVar22 = sVar22 + 1;
      _DAT_0079e7b0 = CONCAT22(DAT_0079e7b0_2,sVar22);
    }
    if ((sVar22 != 3) && (sVar25 != 3)) {
      fVar14 = *(float *)((int)param_1 + 0x24);
      fVar11 = *(float *)((int)param_1 + 0x28);
      fVar12 = *(float *)((int)param_1 + 0x2c);
      local_8 = 3;
      if ((_DAT_009cefec & 0xffff) + (_DAT_0079e7b0 & 0xffff) != 0) {
        local_8 = ClipTrianglePacketToScreenXBounds();
      }
      uVar23 = (*(ushort *)((int)param_1 + 0x38) & 0x1800) >> 0xb;
      param_1 = (code *)PTR_RasterizeTriangleModulatedToBackBuffer_005175f4;
      if (uVar23 == 0) {
        if (((uint)fVar14 & (uint)fVar11 & (uint)fVar12 & 0xffffff) == 0xffffff) {
          param_1 = (code *)PTR_RasterizeTriangleWhiteFastToBackBuffer_005175f8;
        }
      }
      else if (uVar23 == 1) {
        param_1 = RasterizeTriangleAdditiveBlendToBackBuffer;
      }
      else if (uVar23 == 2) {
        param_1 = RasterizeTriangleSubtractiveBlendToBackBuffer;
      }
      DAT_009cefa4 = *DAT_009cefe4;
      DAT_009cefb4 = DAT_009cefe4[1];
      _DAT_009cef84 = DAT_009cefe4[2];
      _DAT_009cef94 = DAT_009cefe4[3];
      _DAT_009cef70 = DAT_009cefe4[5];
      _DAT_009cef4c = DAT_009cefe4[6];
      _DAT_009cef30 = DAT_009cefe4[7];
      if (1 < local_8 + -1) {
        local_8 = local_8 + -2;
        pfVar21 = DAT_009cefe4;
        iVar24 = 0x20;
        do {
          DAT_009cefa8 = *(float *)(iVar24 + (int)pfVar21);
          DAT_009cefb8 = *(float *)(iVar24 + 4 + (int)pfVar21);
          _DAT_009cef88 = *(float *)(iVar24 + 8 + (int)pfVar21);
          _DAT_009cef98 = *(float *)(iVar24 + 0xc + (int)pfVar21);
          _DAT_009cef74 = *(float *)(iVar24 + 0x14 + (int)pfVar21);
          _DAT_009cef50 = *(float *)(iVar24 + 0x18 + (int)pfVar21);
          _DAT_009cef34 = *(float *)(iVar24 + 0x1c + (int)pfVar21);
          DAT_009cefac = *(float *)(iVar24 + 0x20 + (int)pfVar21);
          DAT_009cefbc = *(float *)(iVar24 + 0x24 + (int)pfVar21);
          DAT_009cef8c = *(float *)(iVar24 + 0x28 + (int)pfVar21);
          DAT_009cef9c = *(float *)(iVar24 + 0x2c + (int)pfVar21);
          DAT_009cef78 = *(float *)(iVar24 + 0x34 + (int)pfVar21);
          DAT_009cef54 = *(float *)(iVar24 + 0x38 + (int)pfVar21);
          DAT_009cef38 = *(float *)(iVar24 + 0x3c + (int)pfVar21);
          fVar11 = DAT_009cefbc - DAT_009cefb4;
          fVar14 = DAT_009cefb8 - DAT_009cefb4;
          _DAT_009ceda8 =
               (DAT_009cefa8 - DAT_009cefa4) * fVar11 - (DAT_009cefac - DAT_009cefa4) * fVar14;
          if (_DAT_009ceda8 != _DAT_004ba2b4) {
            _DAT_009ceda8 = _DAT_004ba2e4 / _DAT_009ceda8;
            _DAT_009cf110 =
                 (double)(((_DAT_009cef88 - _DAT_009cef84) * fVar11 -
                          (DAT_009cef8c - _DAT_009cef84) * fVar14) * _DAT_009ceda8 +
                         (float)_DAT_004ba2a8);
            iVar17 = DAT_009cf110;
            iVar13 = DAT_009cf110 >> 0x1f;
            _DAT_009cf110 =
                 (double)(((_DAT_009cef98 - _DAT_009cef94) * fVar11 -
                          (DAT_009cef9c - _DAT_009cef94) * fVar14) * _DAT_009ceda8 +
                         (float)_DAT_004ba2a8);
            iVar18 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((_DAT_009cef74 - _DAT_009cef70) * fVar11 -
                          (DAT_009cef78 - _DAT_009cef70) * fVar14) * _DAT_009ceda8 +
                         (float)_DAT_004ba2a8);
            iVar19 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((_DAT_009cef50 - _DAT_009cef4c) * fVar11 -
                          (DAT_009cef54 - _DAT_009cef4c) * fVar14) * _DAT_009ceda8 +
                         (float)_DAT_004ba2a8);
            iVar20 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((_DAT_009cef34 - _DAT_009cef30) * fVar11 -
                          (DAT_009cef38 - _DAT_009cef30) * fVar14) * _DAT_009ceda8 +
                         (float)_DAT_004ba2a8);
            DAT_009cedb4 = iVar17 - iVar13;
            DAT_009cedb8 = iVar18 - (iVar18 >> 0x1f);
            DAT_009cedac = iVar19 - (iVar19 >> 0x1f);
            DAT_009ceda4 = iVar20 - (iVar20 >> 0x1f);
            DAT_009ceda0 = DAT_009cf110 - (DAT_009cf110 >> 0x1f);
            _DAT_009cf000 = DAT_009cefb4;
            _DAT_009cefe8 = DAT_009cefb4;
            fVar14 = DAT_009cefb8;
            if (DAT_009cefb8 < DAT_009cefb4) {
              _DAT_009cefe8 = DAT_009cefb8;
              fVar14 = _DAT_009cf000;
            }
            _DAT_009cf000 = fVar14;
            DAT_009cef28 = (uint)(DAT_009cefb8 < DAT_009cefb4);
            if (DAT_009cefbc < _DAT_009cefe8) {
              DAT_009cef28 = 2;
              _DAT_009cefe8 = DAT_009cefbc;
            }
            if (_DAT_009cf000 < DAT_009cefbc) {
              _DAT_009cf000 = DAT_009cefbc;
            }
            DAT_009cef60 = ConvertFpuTopToInt64();
            if (DAT_009cef60 < 0) {
              DAT_009cef60 = 0;
            }
            DAT_009ceff8 = ConvertFpuTopToInt64();
            if (g_RenderWindowHeight < DAT_009ceff8) {
              DAT_009ceff8 = g_RenderWindowHeight;
            }
            (*param_1)();
            pfVar21 = DAT_009cefe4;
          }
          local_8 = local_8 + -1;
          iVar24 = iVar24 + 0x20;
        } while (local_8 != 0);
      }
    }
    return;
  }
  if ((((uint)fVar14 & 0x20) == 0) && (g_RenderWindowWidth < 0x141)) {
    *(float *)param_1 = *(float *)param_1 * _DAT_004ba260;
    *(float *)((int)param_1 + 0xc) = *(float *)((int)param_1 + 0xc) * _DAT_004ba260;
    *(float *)((int)param_1 + 4) = *(float *)((int)param_1 + 4) * _DAT_004ba260;
    *(float *)((int)param_1 + 0x10) = *(float *)((int)param_1 + 0x10) * _DAT_004ba260;
    *(float *)((int)param_1 + 8) = *(float *)((int)param_1 + 8) * _DAT_004ba260;
    *(float *)((int)param_1 + 0x14) = *(float *)((int)param_1 + 0x14) * _DAT_004ba260;
  }
  DAT_009ceeec = ConvertFpuTopToInt64();
  DAT_009ceefc = ConvertFpuTopToInt64();
  DAT_009ceef0 = ConvertFpuTopToInt64();
  DAT_009cef00 = ConvertFpuTopToInt64();
  DAT_009ceef4 = ConvertFpuTopToInt64();
  DAT_009cef04 = ConvertFpuTopToInt64();
  DAT_009ceecc = (uint)*(byte *)((int)param_1 + 0x31) << 0x10;
  DAT_009ceedc = (uint)*(byte *)((int)param_1 + 0x30) << 0x10;
  DAT_009ceed4 = (uint)*(ushort *)((int)param_1 + 0x32) << 0x10;
  DAT_009ceee4 = (uint)*(ushort *)((int)param_1 + 0x34) << 0x10;
  DAT_009ceffc = (uint)*(float *)((int)param_1 + 0x24) & 0xffffff;
  DAT_009cefe0 = (*(ushort *)((int)param_1 + 0x38) & 0x1800) >> 0xb;
  RasterizeRectPacketToBackBuffer();
  return;
}


