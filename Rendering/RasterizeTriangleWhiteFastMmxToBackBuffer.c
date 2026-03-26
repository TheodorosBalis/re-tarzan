// Address: 0x004A4620

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeTriangleWhiteFastMmxToBackBuffer(void)

{
  float *pfVar1;
  short sVar2;
  bool bVar3;
  unkuint10 Var4;
  unkuint10 Var5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  short *psVar11;
  unkbyte10 in_ST0;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  unkbyte10 extraout_ST1;
  unkbyte10 extraout_ST1_00;
  
  DAT_009cf140 = (DAT_009cf124 & 0xf) * 0x20000 + g_GraphicsPageBufferBase;
  DAT_009ceec4 = g_BackBufferStridePixels * DAT_009cef60 + g_BackBufferPixelsPtr;
  DAT_009cef68 = DAT_009cef28;
  DAT_009cefc8 = 0;
  DAT_009cef5c = 0;
  if (DAT_009cef60 < DAT_009ceff8) {
    do {
      iVar7 = DAT_009cef28;
      iVar10 = DAT_009cef28;
      if (DAT_009cef5c <= DAT_009cef60) {
        do {
          iVar10 = iVar7 + -1;
          if (iVar10 < 0) {
            iVar10 = 2;
          }
          if ((float)(&DAT_009cefb4)[iVar10] - (float)(&DAT_009cefb4)[iVar7] != _DAT_004ba2b4) {
            iVar6 = ConvertFpuTopToInt64();
            DAT_009ced94 = iVar6 - (iVar6 >> 0x1f);
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef84 + iVar10 * 4) -
                          (float10)*(float *)(&DAT_009cef84 + iVar7 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            DAT_009ced8c = DAT_009cf110 - (DAT_009cf110 >> 0x1f);
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef94 + iVar10 * 4) -
                          (float10)*(float *)(&DAT_009cef94 + iVar7 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            DAT_009ced90 = DAT_009cf110 - (DAT_009cf110 >> 0x1f);
          }
          DAT_009cef48 = ConvertFpuTopToInt64();
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef84 + iVar7 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef40 = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef94 + iVar7 * 4) + (float)_DAT_004ba2a8);
          iVar6 = DAT_009cf110;
          DAT_009cef44 = DAT_009cf110;
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
            DAT_009cef44 = iVar6 + DAT_009cf110;
          }
          DAT_009cef5c = ConvertFpuTopToInt64();
          iVar7 = iVar10;
          in_ST0 = extraout_ST1;
        } while (DAT_009cef5c <= DAT_009cef60);
      }
      DAT_009cef28 = iVar10;
      if (DAT_009cefc8 <= DAT_009cef60) {
        do {
          iVar10 = DAT_009cef68 + 1;
          if (2 < iVar10) {
            iVar10 = 0;
          }
          pfVar1 = (float *)(&DAT_009cefb4 + DAT_009cef68);
          if ((float)(&DAT_009cefb4)[iVar10] - (float)(&DAT_009cefb4)[DAT_009cef68] != _DAT_004ba2b4
             ) {
            DAT_009ced9c = ConvertFpuTopToInt64();
          }
          DAT_009cefc4 = ConvertFpuTopToInt64();
          _DAT_009cedb0 = (float)(extraout_ST0_01 - (float10)*pfVar1);
          if (extraout_ST0_01 - (float10)*pfVar1 != (float10)_DAT_004ba26c) {
            if (_DAT_004ba26c < _DAT_009cedb0) {
              _DAT_009cedb0 = _DAT_009cedb0 - _DAT_004ba26c;
            }
            iVar7 = ConvertFpuTopToInt64();
            DAT_009cefc4 = DAT_009cefc4 + iVar7;
          }
          DAT_009cef68 = iVar10;
          DAT_009cefc8 = ConvertFpuTopToInt64();
          in_ST0 = extraout_ST1_00;
        } while (DAT_009cefc8 <= DAT_009cef60);
      }
      DAT_009cef64 = DAT_009cefc8;
      if (DAT_009cef5c < DAT_009cefc8) {
        DAT_009cef64 = DAT_009cef5c;
      }
      DAT_009ceec8 = DAT_009cef64 - DAT_009cef60;
      DAT_009cef60 = DAT_009cef64;
      iVar10 = DAT_009cedb4;
      iVar7 = DAT_009cedb8;
      iVar6 = DAT_009cf140;
      if (DAT_009ceff8 < DAT_009cef64) {
        DAT_009ceec8 = DAT_009ceec8 + (DAT_009ceff8 - DAT_009cef64);
      }
      for (; DAT_009cedb4 = iVar10, DAT_009cedb8 = iVar7, DAT_009cf140 = iVar6, 0 < DAT_009ceec8;
          DAT_009ceec8 = DAT_009ceec8 + -1) {
        _DAT_009cef6c = DAT_009cef48 >> 0x10;
        DAT_009cef64 = (DAT_009cefc4 >> 0x10) - _DAT_009cef6c;
        if (0 < DAT_009cef64) {
          DAT_009ceec0 = DAT_009ceec4 + _DAT_009cef6c * 2;
          in_ST0 = CONCAT28((short)((unkuint10)in_ST0 >> 0x40),CONCAT44(DAT_009cef44,DAT_009cef40));
          psVar11 = (short *)(DAT_009ceec0 + -2);
          iVar8 = DAT_009cef64;
          do {
            Var5 = (unkuint10)in_ST0 >> 0x10;
            Var4 = (unkuint10)in_ST0 >> 0x30;
            in_ST0 = CONCAT28((short)((unkuint10)in_ST0 >> 0x40),
                              CONCAT44((int)((unkuint10)in_ST0 >> 0x20) + iVar7,(int)in_ST0 + iVar10
                                      ));
            sVar2 = *(short *)(iVar6 + (uint)CONCAT11((char)Var4,(char)Var5) * 2);
            psVar11 = psVar11 + 1;
            if (sVar2 != 0) {
              *psVar11 = sVar2;
            }
            iVar9 = iVar8 + -1;
            bVar3 = 0 < iVar8;
            iVar8 = iVar9;
          } while (iVar9 != 0 && bVar3);
        }
        DAT_009ceec4 = DAT_009ceec4 + g_BackBufferStridePixels;
        DAT_009cefc4 = DAT_009cefc4 + DAT_009ced9c;
        DAT_009cef48 = DAT_009cef48 + DAT_009ced94;
        DAT_009cef40 = DAT_009cef40 + DAT_009ced8c;
        DAT_009cef44 = DAT_009cef44 + DAT_009ced90;
        iVar10 = DAT_009cedb4;
        iVar7 = DAT_009cedb8;
        iVar6 = DAT_009cf140;
      }
    } while (DAT_009cef60 < DAT_009ceff8);
  }
  return;
}


