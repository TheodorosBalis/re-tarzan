// Address: 0x004A3360

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeTriangleModulatedToBackBuffer(void)

{
  float *pfVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  
  DAT_009cf140 = (DAT_009cf124 & 0xf) * 0x20000 + g_GraphicsPageBufferBase;
  DAT_009ceec4 = g_BackBufferStridePixels * DAT_009cef60 + g_BackBufferPixelsPtr;
  DAT_009cef68 = DAT_009cef28;
  DAT_009cefc8 = 0;
  DAT_009cef5c = 0;
  iVar9 = DAT_009cef28;
  if (DAT_009cef60 < DAT_009ceff8) {
    do {
      iVar11 = iVar9;
      iVar10 = DAT_009cef28;
      if (DAT_009cef5c <= DAT_009cef60) {
        do {
          iVar11 = iVar9 + -1;
          if (iVar11 < 0) {
            iVar11 = 2;
          }
          if ((float)(&DAT_009cefb4)[iVar11] - (float)(&DAT_009cefb4)[iVar9] != _DAT_004ba2b4) {
            iVar8 = ConvertFpuTopToInt64();
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef84 + iVar11 * 4) -
                          (float10)*(float *)(&DAT_009cef84 + iVar9 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            iVar10 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef94 + iVar11 * 4) -
                          (float10)*(float *)(&DAT_009cef94 + iVar9 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            iVar3 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef70 + iVar11 * 4) -
                          (float10)*(float *)(&DAT_009cef70 + iVar9 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            iVar5 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef4c + iVar11 * 4) -
                          (float10)*(float *)(&DAT_009cef4c + iVar9 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            DAT_009ced94 = iVar8 - (iVar8 >> 0x1f);
            DAT_009ced8c = iVar10 - (iVar10 >> 0x1f);
            DAT_009ced90 = iVar3 - (iVar3 >> 0x1f);
            DAT_009ced88 = iVar5 - (iVar5 >> 0x1f);
            DAT_009ced84 = DAT_009cf110 - ((int)DAT_009cf110 >> 0x1f);
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef30 + iVar11 * 4) -
                          (float10)*(float *)(&DAT_009cef30 + iVar9 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            DAT_009ced80 = DAT_009cf110 - ((int)DAT_009cf110 >> 0x1f);
          }
          DAT_009cef48 = ConvertFpuTopToInt64();
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef84 + iVar9 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef40 = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef94 + iVar9 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef44 = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef70 + iVar9 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef2c = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef4c + iVar9 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef24 = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef30 + iVar9 * 4) + (float)_DAT_004ba2a8);
          iVar10 = DAT_009cf110;
          DAT_009cef20 = DAT_009cf110;
          _DAT_009cedb0 = (float)(extraout_ST0_00 - (float10)(float)(&DAT_009cefb4)[iVar9]);
          if (extraout_ST0_00 - (float10)(float)(&DAT_009cefb4)[iVar9] != (float10)_DAT_004ba26c) {
            if (_DAT_004ba26c < _DAT_009cedb0) {
              _DAT_009cedb0 = _DAT_009cedb0 - _DAT_004ba26c;
            }
            iVar9 = ConvertFpuTopToInt64();
            DAT_009cef48 = DAT_009cef48 + iVar9;
            _DAT_009cf110 = (double)((float)DAT_009ced8c * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef40 = DAT_009cef40 + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced90 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef44 = DAT_009cef44 + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced88 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef2c = DAT_009cef2c + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced84 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef24 = DAT_009cef24 + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced80 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef20 = iVar10 + DAT_009cf110;
          }
          DAT_009cef5c = ConvertFpuTopToInt64();
          iVar9 = iVar11;
          iVar10 = iVar11;
        } while (DAT_009cef5c <= DAT_009cef60);
      }
      DAT_009cef28 = iVar10;
      if (DAT_009cefc8 <= DAT_009cef60) {
        do {
          iVar9 = DAT_009cef68 + 1;
          if (2 < iVar9) {
            iVar9 = 0;
          }
          pfVar1 = (float *)(&DAT_009cefb4 + DAT_009cef68);
          if ((float)(&DAT_009cefb4)[iVar9] - (float)(&DAT_009cefb4)[DAT_009cef68] != _DAT_004ba2b4)
          {
            DAT_009ced9c = ConvertFpuTopToInt64();
          }
          DAT_009cefc4 = ConvertFpuTopToInt64();
          _DAT_009cedb0 = (float)(extraout_ST0_01 - (float10)*pfVar1);
          if (extraout_ST0_01 - (float10)*pfVar1 != (float10)_DAT_004ba26c) {
            if (_DAT_004ba26c < _DAT_009cedb0) {
              _DAT_009cedb0 = _DAT_009cedb0 - _DAT_004ba26c;
            }
            iVar10 = ConvertFpuTopToInt64();
            DAT_009cefc4 = DAT_009cefc4 + iVar10;
          }
          DAT_009cef68 = iVar9;
          DAT_009cefc8 = ConvertFpuTopToInt64();
        } while (DAT_009cefc8 <= DAT_009cef60);
      }
      DAT_009cef64 = DAT_009cefc8;
      if (DAT_009cef5c < DAT_009cefc8) {
        DAT_009cef64 = DAT_009cef5c;
      }
      DAT_009ceec8 = DAT_009cef64 - DAT_009cef60;
      DAT_009cef60 = DAT_009cef64;
      iVar9 = iVar11;
      iVar5 = DAT_009cef20;
      iVar8 = DAT_009cef24;
      iVar6 = DAT_009cef2c;
      uVar7 = DAT_009cef44;
      iVar11 = DAT_009cefcc;
      iVar10 = DAT_009cefd0;
      iVar3 = DAT_009cefd4;
      uVar4 = DAT_009cefdc;
      if (DAT_009ceff8 < DAT_009cef64) {
        DAT_009ceec8 = DAT_009ceec8 + (DAT_009ceff8 - DAT_009cef64);
        iVar5 = DAT_009cef20;
        iVar8 = DAT_009cef24;
        iVar6 = DAT_009cef2c;
        uVar7 = DAT_009cef44;
      }
      for (; DAT_009cefdc = uVar7, DAT_009cefd4 = iVar6, DAT_009cefd0 = iVar8, DAT_009cefcc = iVar5,
          DAT_009cef20 = DAT_009cefcc, DAT_009cef24 = DAT_009cefd0, DAT_009cef2c = DAT_009cefd4,
          DAT_009cef44 = DAT_009cefdc, 0 < DAT_009ceec8; DAT_009ceec8 = DAT_009ceec8 + -1) {
        _DAT_009cef6c = DAT_009cef48 >> 0x10;
        DAT_009cef64 = (DAT_009cefc4 >> 0x10) - _DAT_009cef6c;
        if (0 < DAT_009cef64) {
          DAT_009ceec0 = (ushort *)(DAT_009ceec4 + _DAT_009cef6c * 2);
          DAT_009cefd8 = DAT_009cef40;
          if (DAT_005175f0 == 0) {
            do {
              uVar2 = *(ushort *)
                       (DAT_009cf140 +
                       ((int)((DAT_009cefd8 >> 0x10 & 0xff) << 8 | DAT_009cefdc & 0xff0000) >> 8) *
                       2);
              if (uVar2 != 0) {
                *DAT_009ceec0 =
                     ((ushort)*(byte *)((uVar2 >> 5 & 0x3e0 | DAT_009cefd4 >> 0x13) + DAT_0079e7b4)
                      << 5 | (ushort)*(byte *)((uVar2 & 0x3e0 | DAT_009cefd0 >> 0x13) + DAT_0079e7b4
                                              )) << 5 |
                     (ushort)*(byte *)(((uVar2 & 0x1f) << 5 | DAT_009cefcc >> 0x13) + DAT_0079e7b4);
                iVar9 = DAT_009cef28;
              }
              DAT_009cefd8 = DAT_009cefd8 + DAT_009cedb4;
              DAT_009cefd4 = DAT_009cefd4 + DAT_009cedac;
              DAT_009cefdc = DAT_009cefdc + DAT_009cedb8;
              DAT_009cefd0 = DAT_009cefd0 + DAT_009ceda4;
              DAT_009cef64 = DAT_009cef64 + -1;
              DAT_009cefcc = DAT_009cefcc + DAT_009ceda0;
              DAT_009ceec0 = DAT_009ceec0 + 1;
              iVar11 = DAT_009cefcc;
              iVar10 = DAT_009cefd0;
              iVar3 = DAT_009cefd4;
              uVar4 = DAT_009cefdc;
            } while (0 < DAT_009cef64);
          }
          else {
            do {
              uVar2 = *(ushort *)
                       (DAT_009cf140 +
                       ((int)((DAT_009cefd8 >> 0x10 & 0xff) << 8 | DAT_009cefdc & 0xff0000) >> 8) *
                       2);
              if (uVar2 != 0) {
                *DAT_009ceec0 =
                     ((ushort)*(byte *)((uVar2 >> 6 & 0x3e0 | DAT_009cefd4 >> 0x13) + DAT_0079e7b4)
                      << 5 | (ushort)*(byte *)((uVar2 >> 1 & 0x3e0 | DAT_009cefd0 >> 0x13) +
                                              DAT_0079e7b4)) << 6 |
                     (ushort)*(byte *)(((uVar2 & 0x1f) << 5 | DAT_009cefcc >> 0x13) + DAT_0079e7b4);
                iVar9 = DAT_009cef28;
              }
              DAT_009cefd8 = DAT_009cefd8 + DAT_009cedb4;
              DAT_009cefd4 = DAT_009cefd4 + DAT_009cedac;
              DAT_009cefdc = DAT_009cefdc + DAT_009cedb8;
              DAT_009cefd0 = DAT_009cefd0 + DAT_009ceda4;
              DAT_009cef64 = DAT_009cef64 + -1;
              DAT_009cefcc = DAT_009cefcc + DAT_009ceda0;
              DAT_009ceec0 = DAT_009ceec0 + 1;
              iVar11 = DAT_009cefcc;
              iVar10 = DAT_009cefd0;
              iVar3 = DAT_009cefd4;
              uVar4 = DAT_009cefdc;
            } while (0 < DAT_009cef64);
          }
        }
        DAT_009cefdc = uVar4;
        DAT_009cefd4 = iVar3;
        DAT_009cefd0 = iVar10;
        DAT_009cefcc = iVar11;
        DAT_009ceec4 = DAT_009ceec4 + g_BackBufferStridePixels;
        DAT_009cefc4 = DAT_009cefc4 + DAT_009ced9c;
        DAT_009cef48 = DAT_009cef48 + DAT_009ced94;
        DAT_009cef40 = DAT_009cef40 + DAT_009ced8c;
        iVar5 = DAT_009cef20 + DAT_009ced80;
        iVar8 = DAT_009cef24 + DAT_009ced84;
        iVar6 = DAT_009cef2c + DAT_009ced88;
        uVar7 = DAT_009cef44 + DAT_009ced90;
        iVar11 = DAT_009cefcc;
        iVar10 = DAT_009cefd0;
        iVar3 = DAT_009cefd4;
        uVar4 = DAT_009cefdc;
      }
      DAT_009cefcc = iVar11;
      DAT_009cefd0 = iVar10;
      DAT_009cefd4 = iVar3;
      DAT_009cefdc = uVar4;
    } while (DAT_009cef60 < DAT_009ceff8);
  }
  return;
}


