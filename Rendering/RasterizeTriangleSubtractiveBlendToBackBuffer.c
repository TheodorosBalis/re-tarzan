// Address: 0x004A6410

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeTriangleSubtractiveBlendToBackBuffer(void)

{
  float *pfVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  
  DAT_009cf140 = (DAT_009cf124 & 0xf) * 0x20000 + g_GraphicsPageBufferBase;
  DAT_009ceec4 = g_BackBufferStridePixels * DAT_009cef60 + g_BackBufferPixelsPtr;
  DAT_009cef68 = DAT_009cef28;
  DAT_009cefc8 = 0;
  DAT_009cef5c = 0;
  iVar7 = DAT_009cef28;
  if (DAT_009cef60 < DAT_009ceff8) {
    do {
      iVar10 = iVar7;
      iVar8 = DAT_009cef28;
      if (DAT_009cef5c <= DAT_009cef60) {
        do {
          iVar10 = iVar7 + -1;
          if (iVar10 < 0) {
            iVar10 = 2;
          }
          if ((float)(&DAT_009cefb4)[iVar10] - (float)(&DAT_009cefb4)[iVar7] != _DAT_004ba2b4) {
            iVar6 = ConvertFpuTopToInt64();
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef84 + iVar10 * 4) -
                          (float10)*(float *)(&DAT_009cef84 + iVar7 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            iVar8 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef94 + iVar10 * 4) -
                          (float10)*(float *)(&DAT_009cef94 + iVar7 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            iVar3 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef70 + iVar10 * 4) -
                          (float10)*(float *)(&DAT_009cef70 + iVar7 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            iVar4 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef4c + iVar10 * 4) -
                          (float10)*(float *)(&DAT_009cef4c + iVar7 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            DAT_009ced94 = iVar6 - (iVar6 >> 0x1f);
            DAT_009ced8c = iVar8 - (iVar8 >> 0x1f);
            DAT_009ced90 = iVar3 - (iVar3 >> 0x1f);
            DAT_009ced88 = iVar4 - (iVar4 >> 0x1f);
            DAT_009ced84 = DAT_009cf110 - ((int)DAT_009cf110 >> 0x1f);
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef30 + iVar10 * 4) -
                          (float10)*(float *)(&DAT_009cef30 + iVar7 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            DAT_009ced80 = DAT_009cf110 - ((int)DAT_009cf110 >> 0x1f);
          }
          DAT_009cef48 = ConvertFpuTopToInt64();
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef84 + iVar7 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef40 = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef94 + iVar7 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef44 = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef70 + iVar7 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef2c = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef4c + iVar7 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef24 = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef30 + iVar7 * 4) + (float)_DAT_004ba2a8);
          iVar8 = DAT_009cf110;
          DAT_009cef20 = DAT_009cf110;
          _DAT_009cedb0 = (float)(extraout_ST0_00 - (float10)(float)(&DAT_009cefb4)[iVar7]);
          if (extraout_ST0_00 - (float10)(float)(&DAT_009cefb4)[iVar7] != (float10)_DAT_004ba26c) {
            if (_DAT_004ba26c < _DAT_009cedb0) {
              _DAT_009cedb0 = _DAT_009cedb0 - _DAT_004ba26c;
            }
            iVar7 = ConvertFpuTopToInt64();
            DAT_009cef48 = DAT_009cef48 + iVar7;
            _DAT_009cf110 = (double)((float)DAT_009ced8c * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef40 = DAT_009cef40 + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced90 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef44 = DAT_009cef44 + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced88 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef2c = DAT_009cef2c + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced84 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef24 = DAT_009cef24 + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced80 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef20 = iVar8 + DAT_009cf110;
          }
          DAT_009cef5c = ConvertFpuTopToInt64();
          iVar7 = iVar10;
          iVar8 = iVar10;
        } while (DAT_009cef5c <= DAT_009cef60);
      }
      DAT_009cef28 = iVar8;
      if (DAT_009cefc8 <= DAT_009cef60) {
        do {
          iVar7 = DAT_009cef68 + 1;
          if (2 < iVar7) {
            iVar7 = 0;
          }
          pfVar1 = (float *)(&DAT_009cefb4 + DAT_009cef68);
          if ((float)(&DAT_009cefb4)[iVar7] - (float)(&DAT_009cefb4)[DAT_009cef68] != _DAT_004ba2b4)
          {
            DAT_009ced9c = ConvertFpuTopToInt64();
          }
          DAT_009cefc4 = ConvertFpuTopToInt64();
          _DAT_009cedb0 = (float)(extraout_ST0_01 - (float10)*pfVar1);
          if (extraout_ST0_01 - (float10)*pfVar1 != (float10)_DAT_004ba26c) {
            if (_DAT_004ba26c < _DAT_009cedb0) {
              _DAT_009cedb0 = _DAT_009cedb0 - _DAT_004ba26c;
            }
            iVar8 = ConvertFpuTopToInt64();
            DAT_009cefc4 = DAT_009cefc4 + iVar8;
          }
          DAT_009cef68 = iVar7;
          DAT_009cefc8 = ConvertFpuTopToInt64();
        } while (DAT_009cefc8 <= DAT_009cef60);
      }
      DAT_009cef64 = DAT_009cefc8;
      if (DAT_009cef5c < DAT_009cefc8) {
        DAT_009cef64 = DAT_009cef5c;
      }
      DAT_009ceec8 = DAT_009cef64 - DAT_009cef60;
      DAT_009cef60 = DAT_009cef64;
      iVar7 = iVar10;
      iVar8 = DAT_009cef2c;
      uVar5 = DAT_009cef44;
      iVar10 = DAT_009cefd4;
      uVar9 = DAT_009cefdc;
      if (DAT_009ceff8 < DAT_009cef64) {
        DAT_009ceec8 = DAT_009ceec8 + (DAT_009ceff8 - DAT_009cef64);
        iVar8 = DAT_009cef2c;
        uVar5 = DAT_009cef44;
      }
      for (; DAT_009cefdc = uVar5, DAT_009cefd4 = iVar8, DAT_009cef2c = DAT_009cefd4,
          DAT_009cef44 = DAT_009cefdc, 0 < DAT_009ceec8; DAT_009ceec8 = DAT_009ceec8 + -1) {
        _DAT_009cef6c = DAT_009cef48 >> 0x10;
        DAT_009cef64 = (DAT_009cefc4 >> 0x10) - _DAT_009cef6c;
        if (0 < DAT_009cef64) {
          DAT_009ceec0 = (ushort *)(DAT_009ceec4 + _DAT_009cef6c * 2);
          DAT_009cefcc = DAT_009cef20;
          DAT_009cefd0 = DAT_009cef24;
          DAT_009cefd8 = DAT_009cef40;
          if (DAT_005175f0 == 0) {
            do {
              uVar2 = *(ushort *)
                       (DAT_009cf140 +
                       ((int)((DAT_009cefd8 >> 0x10 & 0xff) << 8 | DAT_009cefdc & 0xff0000) >> 8) *
                       2);
              if (uVar2 != 0) {
                uVar9 = (uint)(short)*DAT_009ceec0;
                *DAT_009ceec0 =
                     ((ushort)*(byte *)(DAT_009ced98 +
                                       (DAT_009cefd4 >> 0x13 | uVar2 >> 5 & 0x3e0 | uVar9 & 0x7c00))
                      << 5 | (ushort)*(byte *)(((uVar9 & 0x3e0) << 5 | DAT_009cefd0 >> 0x13 |
                                               uVar2 & 0x3e0) + DAT_009ced98)) << 5 |
                     (ushort)*(byte *)((((uVar9 & 0x1f) << 5 | uVar2 & 0x1f) << 5 |
                                       DAT_009cefcc >> 0x13) + DAT_009ced98);
                iVar7 = DAT_009cef28;
              }
              DAT_009cefd8 = DAT_009cefd8 + DAT_009cedb4;
              DAT_009cefdc = DAT_009cefdc + DAT_009cedb8;
              DAT_009cefd4 = DAT_009cefd4 + DAT_009cedac;
              DAT_009cefd0 = DAT_009cefd0 + DAT_009ceda4;
              DAT_009cef64 = DAT_009cef64 + -1;
              DAT_009cefcc = DAT_009cefcc + DAT_009ceda0;
              DAT_009ceec0 = DAT_009ceec0 + 1;
              iVar10 = DAT_009cefd4;
              uVar9 = DAT_009cefdc;
            } while (0 < DAT_009cef64);
          }
          else {
            do {
              uVar2 = *(ushort *)
                       (DAT_009cf140 +
                       ((int)((DAT_009cefd8 >> 0x10 & 0xff) << 8 | DAT_009cefdc & 0xff0000) >> 8) *
                       2);
              if (uVar2 != 0) {
                uVar9 = (uint)(short)*DAT_009ceec0;
                *DAT_009ceec0 =
                     ((ushort)*(byte *)(((uVar2 >> 5 & 0x7c0 | uVar9 & 0xf800) >> 1 |
                                        DAT_009cefd4 >> 0x13) + DAT_009ced98) << 5 |
                     (ushort)*(byte *)((DAT_009cefd0 >> 0x13 | (uVar2 & 0x7c0) >> 1 |
                                       (uVar9 & 0x7c0) << 4) + DAT_009ced98)) << 6 |
                     (ushort)*(byte *)((((uVar9 & 0x1f) << 5 | uVar2 & 0x1f) << 5 |
                                       DAT_009cefcc >> 0x13) + DAT_009ced98);
                iVar7 = DAT_009cef28;
              }
              DAT_009cefd8 = DAT_009cefd8 + DAT_009cedb4;
              DAT_009cefdc = DAT_009cefdc + DAT_009cedb8;
              DAT_009cefd4 = DAT_009cefd4 + DAT_009cedac;
              DAT_009cefd0 = DAT_009cefd0 + DAT_009ceda4;
              DAT_009cef64 = DAT_009cef64 + -1;
              DAT_009cefcc = DAT_009cefcc + DAT_009ceda0;
              DAT_009ceec0 = DAT_009ceec0 + 1;
              iVar10 = DAT_009cefd4;
              uVar9 = DAT_009cefdc;
            } while (0 < DAT_009cef64);
          }
        }
        DAT_009cefdc = uVar9;
        DAT_009cefd4 = iVar10;
        DAT_009ceec4 = DAT_009ceec4 + g_BackBufferStridePixels;
        DAT_009cefc4 = DAT_009cefc4 + DAT_009ced9c;
        DAT_009cef48 = DAT_009cef48 + DAT_009ced94;
        DAT_009cef40 = DAT_009cef40 + DAT_009ced8c;
        DAT_009cef24 = DAT_009cef24 + DAT_009ced84;
        DAT_009cef20 = DAT_009cef20 + DAT_009ced80;
        iVar8 = DAT_009cef2c + DAT_009ced88;
        uVar5 = DAT_009cef44 + DAT_009ced90;
        iVar10 = DAT_009cefd4;
        uVar9 = DAT_009cefdc;
      }
      DAT_009cefd4 = iVar10;
      DAT_009cefdc = uVar9;
    } while (DAT_009cef60 < DAT_009ceff8);
  }
  return;
}


