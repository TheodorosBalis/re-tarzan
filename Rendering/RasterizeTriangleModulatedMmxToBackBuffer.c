// Address: 0x004A3E10

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeTriangleModulatedMmxToBackBuffer(void)

{
  float *pfVar1;
  ushort uVar2;
  bool bVar3;
  int iVar4;
  unkuint10 Var5;
  unkuint10 Var6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  ushort *puVar13;
  float10 in_ST0;
  float10 fVar14;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 extraout_ST0_02;
  float10 extraout_ST0_03;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  float10 extraout_ST1_02;
  short sVar15;
  short sVar16;
  float10 in_ST2;
  short sVar17;
  short sVar18;
  short sVar19;
  ulonglong uVar20;
  
  DAT_009cf140 = (DAT_009cf124 & 0xf) * 0x20000 + g_GraphicsPageBufferBase;
  DAT_009ceec4 = g_BackBufferStridePixels * DAT_009cef60 + g_BackBufferPixelsPtr;
  DAT_009cef68 = DAT_009cef28;
  DAT_009cefc8 = 0;
  DAT_009cef5c = 0;
  if (DAT_009cef60 < DAT_009ceff8) {
    do {
      iVar11 = DAT_009ced80;
      iVar12 = DAT_009cef28;
      if (DAT_009cef5c <= DAT_009cef60) {
        fVar14 = (float10)(DAT_009cef60 + 1);
        iVar8 = DAT_009cef28;
        do {
          iVar12 = iVar8 + -1;
          if (iVar12 < 0) {
            iVar12 = 2;
          }
          if ((float)(&DAT_009cefb4)[iVar12] - (float)(&DAT_009cefb4)[iVar8] != _DAT_004ba2b4) {
            in_ST0 = fVar14;
            iVar7 = ConvertFpuTopToInt64();
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef84 + iVar12 * 4) -
                          (float10)*(float *)(&DAT_009cef84 + iVar8 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            iVar11 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef94 + iVar12 * 4) -
                          (float10)*(float *)(&DAT_009cef94 + iVar8 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            iVar4 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef70 + iVar12 * 4) -
                          (float10)*(float *)(&DAT_009cef70 + iVar8 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            iVar10 = DAT_009cf110;
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef4c + iVar12 * 4) -
                          (float10)*(float *)(&DAT_009cef4c + iVar8 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            DAT_009ced94 = iVar7 - (iVar7 >> 0x1f);
            DAT_009ced8c = iVar11 - (iVar11 >> 0x1f);
            DAT_009ced90 = iVar4 - (iVar4 >> 0x1f);
            DAT_009ced88 = iVar10 - (iVar10 >> 0x1f);
            DAT_009ced84 = DAT_009cf110 - ((int)DAT_009cf110 >> 0x1f);
            _DAT_009cf110 =
                 (double)(((float10)*(float *)(&DAT_009cef30 + iVar12 * 4) -
                          (float10)*(float *)(&DAT_009cef30 + iVar8 * 4)) * extraout_ST0 +
                         (float10)_DAT_004ba2a8);
            iVar11 = DAT_009cf110 - ((int)DAT_009cf110 >> 0x1f);
            DAT_009ced80 = iVar11;
          }
          DAT_009cef48 = ConvertFpuTopToInt64();
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef84 + iVar8 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef40 = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef94 + iVar8 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef44 = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef70 + iVar8 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef2c = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef4c + iVar8 * 4) + (float)_DAT_004ba2a8);
          DAT_009cef24 = DAT_009cf110;
          _DAT_009cf110 = (double)(*(float *)(&DAT_009cef30 + iVar8 * 4) + (float)_DAT_004ba2a8);
          uVar9 = DAT_009cf110;
          DAT_009cef20 = DAT_009cf110;
          _DAT_009cedb0 = (float)(extraout_ST0_00 - (float10)(float)(&DAT_009cefb4)[iVar8]);
          if (extraout_ST0_00 - (float10)(float)(&DAT_009cefb4)[iVar8] != (float10)_DAT_004ba26c) {
            if (_DAT_004ba26c < _DAT_009cedb0) {
              _DAT_009cedb0 = _DAT_009cedb0 - _DAT_004ba26c;
            }
            in_ST0 = extraout_ST1;
            iVar8 = ConvertFpuTopToInt64();
            DAT_009cef48 = DAT_009cef48 + iVar8;
            _DAT_009cf110 = (double)((float)DAT_009ced8c * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef40 = DAT_009cef40 + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced90 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef44 = DAT_009cef44 + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced88 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef2c = DAT_009cef2c + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced84 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef24 = DAT_009cef24 + DAT_009cf110;
            _DAT_009cf110 = (double)((float)DAT_009ced80 * _DAT_009cedb0 + (float)_DAT_004ba2a8);
            DAT_009cef20 = uVar9 + DAT_009cf110;
          }
          in_ST2 = in_ST0;
          DAT_009cef5c = ConvertFpuTopToInt64();
          iVar8 = iVar12;
          in_ST0 = extraout_ST1_00;
          fVar14 = extraout_ST0_01;
        } while (DAT_009cef5c <= DAT_009cef60);
      }
      DAT_009cef28 = iVar12;
      if (DAT_009cefc8 <= DAT_009cef60) {
        fVar14 = (float10)(DAT_009cef60 + 1);
        do {
          iVar12 = DAT_009cef68 + 1;
          if (2 < iVar12) {
            iVar12 = 0;
          }
          pfVar1 = (float *)(&DAT_009cefb4 + DAT_009cef68);
          if ((float)(&DAT_009cefb4)[iVar12] - (float)(&DAT_009cefb4)[DAT_009cef68] != _DAT_004ba2b4
             ) {
            in_ST0 = fVar14;
            DAT_009ced9c = ConvertFpuTopToInt64();
          }
          DAT_009cefc4 = ConvertFpuTopToInt64();
          _DAT_009cedb0 = (float)(extraout_ST0_02 - (float10)*pfVar1);
          if (extraout_ST0_02 - (float10)*pfVar1 != (float10)_DAT_004ba26c) {
            if (_DAT_004ba26c < _DAT_009cedb0) {
              _DAT_009cedb0 = _DAT_009cedb0 - _DAT_004ba26c;
            }
            in_ST0 = extraout_ST1_01;
            iVar8 = ConvertFpuTopToInt64();
            DAT_009cefc4 = DAT_009cefc4 + iVar8;
          }
          in_ST2 = in_ST0;
          DAT_009cef68 = iVar12;
          DAT_009cefc8 = ConvertFpuTopToInt64();
          in_ST0 = extraout_ST1_02;
          fVar14 = extraout_ST0_03;
        } while (DAT_009cefc8 <= DAT_009cef60);
      }
      DAT_009cef64 = DAT_009cef5c;
      if (DAT_009cefc8 <= DAT_009cef5c) {
        DAT_009cef64 = DAT_009cefc8;
      }
      DAT_009ceec8 = DAT_009cef64 - DAT_009cef60;
      DAT_009cef60 = DAT_009cef64;
      iVar12 = DAT_009cedb4;
      iVar8 = DAT_009cedb8;
      iVar4 = DAT_009cf140;
      if (DAT_009ceff8 < DAT_009cef64) {
        DAT_009ceec8 = DAT_009ceec8 + (DAT_009ceff8 - DAT_009cef64);
      }
      for (; DAT_009cedb4 = iVar12, DAT_009cedb8 = iVar8, DAT_009cf140 = iVar4, 0 < DAT_009ceec8;
          DAT_009ceec8 = DAT_009ceec8 + -1) {
        _DAT_009cef6c = DAT_009cef48 >> 0x10;
        DAT_009cef64 = (DAT_009cefc4 >> 0x10) - _DAT_009cef6c;
        if (0 < DAT_009cef64) {
          DAT_009ceec0 = DAT_009ceec4 + _DAT_009cef6c * 2;
          in_ST0 = (float10)CONCAT28((short)((unkuint10)in_ST0 >> 0x40),
                                     CONCAT44(DAT_009cef44,DAT_009cef40));
          in_ST2 = (float10)CONCAT28((short)((unkuint10)in_ST2 >> 0x40),
                                     CONCAT26((short)((ulonglong)DAT_00517610 >> 0x30),
                                              CONCAT24((short)(((ulonglong)(DAT_009cef2c & 0xffe000)
                                                               << 0x13) >> 0x20) +
                                                       (short)((ulonglong)DAT_00517610 >> 0x20),
                                                       CONCAT22((short)(((DAT_009cef24 & 0xffe000)
                                                                        << 3) >> 0x10) +
                                                                (short)((ulonglong)DAT_00517610 >>
                                                                       0x10),
                                                                (short)((DAT_009cef20 & 0xffe000) >>
                                                                       0xd) + (short)DAT_00517610)))
                                    );
          sVar17 = (short)((DAT_009ceda0 & 0x1fffe000) >> 0xd);
          sVar18 = (short)(((DAT_009ceda4 & 0x1fffe000) << 3) >> 0x10);
          sVar19 = (short)(((ulonglong)(DAT_009cedac & 0x1fffe000) << 0x13) >> 0x20);
          sVar17 = sVar17 - (sVar17 >> 0xf);
          sVar18 = sVar18 - (sVar18 >> 0xf);
          sVar19 = sVar19 - (sVar19 >> 0xf);
          puVar13 = (ushort *)(DAT_009ceec0 + -2);
          iVar10 = DAT_009cef64;
          if (DAT_005175f0 == 0) {
            do {
              Var6 = (unkuint10)in_ST0 >> 0x10;
              Var5 = (unkuint10)in_ST0 >> 0x30;
              in_ST0 = (float10)CONCAT28((short)((unkuint10)in_ST0 >> 0x40),
                                         CONCAT44((int)((unkuint10)in_ST0 >> 0x20) + iVar8,
                                                  SUB104(in_ST0,0) + iVar12));
              uVar2 = *(ushort *)(iVar4 + (uint)CONCAT11((char)Var5,(char)Var6) * 2);
              uVar9 = (uint)uVar2;
              puVar13 = puVar13 + 1;
              sVar15 = (short)((unkuint10)in_ST2 >> 0x10);
              sVar16 = (short)((unkuint10)in_ST2 >> 0x20);
              if (uVar2 != 0) {
                uVar20 = ((ulonglong)uVar9 | (ulonglong)uVar9 << 0xb | (ulonglong)uVar9 << 0x16) &
                         _DAT_00517600;
                uVar20 = CONCAT24((short)(uVar20 >> 0x20) * sVar16,
                                  CONCAT22((short)(uVar20 >> 0x10) * sVar15,
                                           (short)uVar20 * SUB102(in_ST2,0))) & _DAT_00517608;
                *puVar13 = (ushort)(uVar20 >> 0xb) | (ushort)(uVar20 >> 0x16) |
                           (ushort)(uVar20 >> 0x21);
              }
              in_ST2 = (float10)CONCAT28((short)((unkuint10)in_ST2 >> 0x40),
                                         CONCAT26((short)((unkuint10)in_ST2 >> 0x30),
                                                  CONCAT24(sVar16 + sVar19,
                                                           CONCAT22(sVar15 + sVar18,
                                                                    SUB102(in_ST2,0) + sVar17))));
              iVar7 = iVar10 + -1;
              bVar3 = 0 < iVar10;
              iVar10 = iVar7;
              iVar11 = DAT_009ced80;
            } while (iVar7 != 0 && bVar3);
          }
          else {
            do {
              Var6 = (unkuint10)in_ST0 >> 0x10;
              Var5 = (unkuint10)in_ST0 >> 0x30;
              in_ST0 = (float10)CONCAT28((short)((unkuint10)in_ST0 >> 0x40),
                                         CONCAT44((int)((unkuint10)in_ST0 >> 0x20) + iVar8,
                                                  SUB104(in_ST0,0) + iVar12));
              uVar2 = *(ushort *)(iVar4 + (uint)CONCAT11((char)Var5,(char)Var6) * 2);
              uVar9 = (uint)uVar2;
              puVar13 = puVar13 + 1;
              sVar15 = (short)((unkuint10)in_ST2 >> 0x10);
              sVar16 = (short)((unkuint10)in_ST2 >> 0x20);
              if (uVar2 != 0) {
                uVar20 = ((ulonglong)uVar9 | (ulonglong)uVar9 << 10 | (ulonglong)uVar9 << 0x15) &
                         _DAT_00517600;
                uVar20 = CONCAT24((short)(uVar20 >> 0x20) * sVar16,
                                  CONCAT22((short)(uVar20 >> 0x10) * sVar15,
                                           (short)uVar20 * SUB102(in_ST2,0))) & _DAT_00517608;
                *puVar13 = (ushort)(uVar20 >> 0xb) | (ushort)(uVar20 >> 0x15) |
                           (ushort)(uVar20 >> 0x20);
              }
              in_ST2 = (float10)CONCAT28((short)((unkuint10)in_ST2 >> 0x40),
                                         CONCAT26((short)((unkuint10)in_ST2 >> 0x30),
                                                  CONCAT24(sVar16 + sVar19,
                                                           CONCAT22(sVar15 + sVar18,
                                                                    SUB102(in_ST2,0) + sVar17))));
              iVar7 = iVar10 + -1;
              bVar3 = 0 < iVar10;
              iVar10 = iVar7;
              iVar11 = DAT_009ced80;
            } while (iVar7 != 0 && bVar3);
          }
        }
        DAT_009ceec4 = DAT_009ceec4 + g_BackBufferStridePixels;
        DAT_009cef48 = DAT_009cef48 + DAT_009ced94;
        DAT_009cefc4 = DAT_009cefc4 + DAT_009ced9c;
        DAT_009cef40 = DAT_009cef40 + DAT_009ced8c;
        DAT_009cef44 = DAT_009cef44 + DAT_009ced90;
        DAT_009cef2c = DAT_009cef2c + DAT_009ced88;
        DAT_009cef24 = DAT_009cef24 + DAT_009ced84;
        DAT_009cef20 = DAT_009cef20 + iVar11;
        iVar12 = DAT_009cedb4;
        iVar8 = DAT_009cedb8;
        iVar4 = DAT_009cf140;
      }
    } while (DAT_009cef60 < DAT_009ceff8);
  }
  return;
}


