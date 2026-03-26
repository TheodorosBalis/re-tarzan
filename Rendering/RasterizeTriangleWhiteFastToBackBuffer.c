// Address: 0x004A2E50

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeTriangleWhiteFastToBackBuffer(void)

{
  float *pfVar1;
  int iVar2;
  char cVar6;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  char cVar9;
  short sVar11;
  uint uVar13;
  int iVar14;
  short *psVar15;
  bool bVar16;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  uint uVar10;
  short sVar12;
  
  DAT_009ceec4 = g_BackBufferStridePixels * DAT_009cef60 + g_BackBufferPixelsPtr;
  DAT_009cf140 = (DAT_009cf124 & 0xf) * 0x20000 + g_GraphicsPageBufferBase;
  DAT_009cef68 = DAT_009cef28;
  DAT_009cefc8 = 0;
  DAT_009cef5c = 0;
  if (DAT_009cef60 < DAT_009ceff8) {
    do {
      iVar4 = DAT_009cef28;
      iVar14 = DAT_009cef28;
      if (DAT_009cef5c <= DAT_009cef60) {
        do {
          iVar14 = iVar4 + -1;
          if (iVar14 < 0) {
            iVar14 = 2;
          }
          if ((float)(&DAT_009cefb4)[iVar14] - (float)(&DAT_009cefb4)[iVar4] != _DAT_004ba2b4) {
            iVar3 = ConvertFpuTopToInt64();
            DAT_009ced94 = iVar3 - (iVar3 >> 0x1f);
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef84 + iVar14 * 4) -
                          (float10)*(float *)(&DAT_009cef84 + iVar4 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            DAT_009ced8c = DAT_009cf110 - (DAT_009cf110 >> 0x1f);
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef94 + iVar14 * 4) -
                          (float10)*(float *)(&DAT_009cef94 + iVar4 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            DAT_009ced90 = DAT_009cf110 - (DAT_009cf110 >> 0x1f);
          }
          DAT_009cef48 = ConvertFpuTopToInt64();
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef84 + iVar4 * 4) + (float)_DAT_004ba2a8);
          iVar3 = DAT_009cf110;
          DAT_009cef40 = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef94 + iVar4 * 4) + (float)_DAT_004ba2a8);
          iVar2 = DAT_009cf110;
          DAT_009cef44 = DAT_009cf110;
          _DAT_009cedb0 = (float)(extraout_ST0_00 - (float10)(float)(&DAT_009cefb4)[iVar4]);
          if (extraout_ST0_00 - (float10)(float)(&DAT_009cefb4)[iVar4] != (float10)_DAT_004ba26c) {
            if (_DAT_004ba26c < _DAT_009cedb0) {
              _DAT_009cedb0 = _DAT_009cedb0 - _DAT_004ba26c;
            }
            iVar4 = ConvertFpuTopToInt64();
            DAT_009cef48 = DAT_009cef48 + iVar4;
            _DAT_009cf110 = (double)((float)DAT_009ced8c * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef40 = iVar3 + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced90 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef44 = iVar2 + DAT_009cf110;
          }
          DAT_009cef5c = ConvertFpuTopToInt64();
          iVar4 = iVar14;
        } while (DAT_009cef5c <= DAT_009cef60);
      }
      DAT_009cef28 = iVar14;
      if (DAT_009cefc8 <= DAT_009cef60) {
        do {
          iVar14 = DAT_009cef68 + 1;
          if (2 < iVar14) {
            iVar14 = 0;
          }
          pfVar1 = (float *)(&DAT_009cefb4 + DAT_009cef68);
          if ((float)(&DAT_009cefb4)[iVar14] - (float)(&DAT_009cefb4)[DAT_009cef68] != _DAT_004ba2b4
             ) {
            DAT_009ced9c = ConvertFpuTopToInt64();
          }
          DAT_009cefc4 = ConvertFpuTopToInt64();
          _DAT_009cedb0 = (float)(extraout_ST0_01 - (float10)*pfVar1);
          if (extraout_ST0_01 - (float10)*pfVar1 != (float10)_DAT_004ba26c) {
            if (_DAT_004ba26c < _DAT_009cedb0) {
              _DAT_009cedb0 = _DAT_009cedb0 - _DAT_004ba26c;
            }
            iVar4 = ConvertFpuTopToInt64();
            DAT_009cefc4 = DAT_009cefc4 + iVar4;
          }
          DAT_009cef68 = iVar14;
          DAT_009cefc8 = ConvertFpuTopToInt64();
        } while (DAT_009cefc8 <= DAT_009cef60);
      }
      DAT_009cef64 = DAT_009cefc8;
      if (DAT_009cef5c < DAT_009cefc8) {
        DAT_009cef64 = DAT_009cef5c;
      }
      DAT_009ceec8 = DAT_009cef64 - DAT_009cef60;
      DAT_009cef60 = DAT_009cef64;
      iVar14 = DAT_009cf140;
      if (DAT_009ceff8 < DAT_009cef64) {
        DAT_009ceec8 = DAT_009ceec8 + (DAT_009ceff8 - DAT_009cef64);
      }
      for (; DAT_009cf140 = iVar14, 0 < DAT_009ceec8; DAT_009ceec8 = DAT_009ceec8 + -1) {
        _DAT_009cef6c = DAT_009cef48 >> 0x10;
        DAT_009cef64 = (DAT_009cefc4 >> 0x10) - _DAT_009cef6c;
        if (0 < DAT_009cef64) {
          psVar15 = (short *)(DAT_009ceec4 + _DAT_009cef6c * 2);
          cVar6 = (char)((uint)DAT_009cedb8 >> 0x10);
          cVar9 = (char)((uint)DAT_009cedb4 >> 0x10);
          uVar10 = CONCAT22((short)DAT_009cedb4,CONCAT11(cVar6,cVar9));
          uVar7 = DAT_009cef44 << 0x10;
          uVar8 = CONCAT21((short)((uint)DAT_009cef44 >> 0x10),(char)((uint)DAT_009cef40 >> 0x10)) &
                  0xffff;
          uVar13 = CONCAT22((short)DAT_009cedb8,(short)DAT_009cef64);
          iVar4 = DAT_009cef40 << 0x10;
          DAT_009ceec0 = psVar15;
          do {
            sVar11 = *(short *)(iVar14 + uVar8 * 2);
            uVar5 = CONCAT22((short)((uint)iVar4 >> 0x10),sVar11);
            if (sVar11 != 0) {
              *psVar15 = sVar11;
            }
            bVar16 = CARRY4(uVar7,uVar13);
            uVar7 = uVar7 + uVar13;
            iVar4 = uVar5 + uVar10;
            uVar8 = (uint)CONCAT11((char)(uVar8 >> 8) + cVar6 + bVar16,
                                   (char)uVar8 + cVar9 + CARRY4(uVar5,uVar10));
            psVar15 = psVar15 + 1;
            sVar12 = (short)uVar13;
            sVar11 = sVar12 + -1;
            uVar13 = CONCAT22((short)(uVar13 >> 0x10),sVar11);
          } while (sVar11 != 0 && 0 < sVar12);
        }
        DAT_009ceec4 = DAT_009ceec4 + g_BackBufferStridePixels;
        DAT_009cef48 = DAT_009cef48 + DAT_009ced94;
        DAT_009cefc4 = DAT_009cefc4 + DAT_009ced9c;
        DAT_009cef40 = DAT_009cef40 + DAT_009ced8c;
        DAT_009cef44 = DAT_009cef44 + DAT_009ced90;
        iVar14 = DAT_009cf140;
      }
    } while (DAT_009cef60 < DAT_009ceff8);
  }
  return;
}


