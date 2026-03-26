// Address: 0x004A6CE0

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void RasterizeRectPacketToBackBuffer(void)

{
  int iVar1;
  short sVar2;
  ushort uVar3;
  bool bVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  uint uVar11;
  ushort *puVar12;
  
  if (((((0 < DAT_009ceef4) && (0 < DAT_009cef04)) && (-1 < DAT_009ceef0)) &&
      ((-1 < DAT_009cef00 && (DAT_009ceeec < g_RenderWindowWidth)))) &&
     (DAT_009ceefc < g_RenderWindowHeight)) {
    DAT_009ced90 = DAT_009ceee4 / DAT_009cef04;
    DAT_009cedb4 = DAT_009ceed4 / DAT_009ceef4;
    if (DAT_009ceeec < 0) {
      DAT_009ceef4 = DAT_009ceef4 + DAT_009ceeec;
      DAT_009ceecc = DAT_009ceecc - DAT_009cedb4 * DAT_009ceeec;
      DAT_009ceeec = 0;
    }
    if (DAT_009ceefc < 0) {
      DAT_009cef04 = DAT_009cef04 + DAT_009ceefc;
      DAT_009ceedc = DAT_009ceedc - DAT_009ced90 * DAT_009ceefc;
      DAT_009ceefc = 0;
    }
    if (g_RenderWindowWidth <= DAT_009ceef0) {
      DAT_009ceef4 = DAT_009ceef4 + (g_RenderWindowWidth - DAT_009ceef0);
    }
    if (g_RenderWindowHeight <= DAT_009cef00) {
      DAT_009cef04 = DAT_009cef04 + (g_RenderWindowHeight - DAT_009cef00);
    }
    if ((0 < DAT_009ceef4) && (0 < DAT_009cef04)) {
      DAT_009cf140 = (DAT_009cf124 & 0xf) * 0x20000 + g_GraphicsPageBufferBase;
      DAT_009ceec4 = (ushort *)
                     (g_BackBufferPixelsPtr + g_BackBufferStridePixels * DAT_009ceefc +
                     DAT_009ceeec * 2);
      uVar10 = DAT_009ceffc >> 0xb & 0x1f;
      uVar6 = DAT_009ceffc >> 0x13 & 0x1f;
      uVar11 = DAT_009ceffc >> 3 & 0x1f;
      DAT_009cefcc = uVar11;
      DAT_009cefd0 = uVar10;
      DAT_009cefd4 = uVar6;
      if (DAT_009cefe0 == 0) {
        if (DAT_009ceffc == 0xffffff) {
          if (0 < DAT_009cef04) {
            DAT_009cefd0 = 0x1f;
            DAT_009cefd4 = 0x1f;
            DAT_009cefcc = 0x1f;
            do {
              iVar1 = DAT_009cedb4;
              iVar7 = DAT_009cf140 + (DAT_009ceedc >> 0x10 & 0xff) * 0x200;
              DAT_009cefd8 = DAT_009ceecc;
              puVar12 = DAT_009ceec4 + -1;
              uVar6 = DAT_009ceecc;
              iVar8 = DAT_009ceef4;
              DAT_009cef64 = DAT_009ceef4;
              do {
                puVar12 = puVar12 + 1;
                uVar3 = *(ushort *)(iVar7 + (uVar6 >> 0x10) * 2);
                uVar6 = uVar6 + iVar1;
                if (uVar3 != 0) {
                  *puVar12 = uVar3;
                }
                iVar9 = iVar8 + -1;
                bVar4 = 0 < iVar8;
                iVar8 = iVar9;
              } while (iVar9 != 0 && bVar4);
              DAT_009cef04 = DAT_009cef04 + -1;
              DAT_009ceec4 = (ushort *)((int)DAT_009ceec4 + g_BackBufferStridePixels);
              DAT_009ceedc = DAT_009ceedc + DAT_009ced90;
            } while (0 < DAT_009cef04);
            return;
          }
        }
        else {
          iVar7 = DAT_009ceef4;
          if (DAT_005175f0 == 0) {
            for (; 0 < DAT_009cef04; DAT_009cef04 = DAT_009cef04 + -1) {
              iVar1 = DAT_009cf140 + (DAT_009ceedc >> 0x10 & 0xff) * 0x200;
              DAT_009cefd8 = DAT_009ceecc;
              puVar12 = DAT_009ceec4;
              for (DAT_009cef64 = iVar7; 0 < DAT_009cef64; DAT_009cef64 = DAT_009cef64 + -1) {
                uVar3 = *(ushort *)(iVar1 + (DAT_009cefd8 >> 0x10 & 0xff) * 2);
                if (uVar3 != 0) {
                  *puVar12 = ((ushort)*(byte *)((uVar3 >> 5 & 0x3e0 | uVar6) + DAT_0079e7b4) << 5 |
                             (ushort)*(byte *)((uVar3 & 0x3e0 | uVar10) + DAT_0079e7b4)) << 5 |
                             (ushort)*(byte *)(((uVar3 & 0x1f) << 5 | uVar11) + DAT_0079e7b4);
                  uVar6 = DAT_009cefd4;
                  iVar7 = DAT_009ceef4;
                  uVar10 = DAT_009cefd0;
                  uVar11 = DAT_009cefcc;
                }
                DAT_009cefd8 = DAT_009cefd8 + DAT_009cedb4;
                puVar12 = puVar12 + 1;
              }
              DAT_009ceec4 = (ushort *)((int)DAT_009ceec4 + g_BackBufferStridePixels);
              DAT_009ceedc = DAT_009ceedc + DAT_009ced90;
            }
          }
          else if (0 < DAT_009cef04) {
            do {
              iVar1 = DAT_009cf140 + (DAT_009ceedc >> 0x10 & 0xff) * 0x200;
              DAT_009cefd8 = DAT_009ceecc;
              puVar12 = DAT_009ceec4;
              for (DAT_009cef64 = iVar7; 0 < DAT_009cef64; DAT_009cef64 = DAT_009cef64 + -1) {
                uVar3 = *(ushort *)(iVar1 + (DAT_009cefd8 >> 0x10 & 0xff) * 2);
                if (uVar3 != 0) {
                  *puVar12 = ((ushort)*(byte *)((uVar3 >> 6 & 0x3e0 | uVar6) + DAT_0079e7b4) << 5 |
                             (ushort)*(byte *)((uVar3 >> 1 & 0x3e0 | uVar10) + DAT_0079e7b4)) << 6 |
                             (ushort)*(byte *)(((uVar3 & 0x1f) << 5 | uVar11) + DAT_0079e7b4);
                  uVar6 = DAT_009cefd4;
                  iVar7 = DAT_009ceef4;
                  uVar10 = DAT_009cefd0;
                  uVar11 = DAT_009cefcc;
                }
                DAT_009cefd8 = DAT_009cefd8 + DAT_009cedb4;
                puVar12 = puVar12 + 1;
              }
              DAT_009cef04 = DAT_009cef04 + -1;
              DAT_009ceec4 = (ushort *)((int)DAT_009ceec4 + g_BackBufferStridePixels);
              DAT_009ceedc = DAT_009ceedc + DAT_009ced90;
            } while (0 < DAT_009cef04);
            return;
          }
        }
      }
      else if (DAT_009cefe0 == 1) {
        if (DAT_005175f0 == 0) {
          iVar7 = DAT_009ceef4;
          if (0 < DAT_009cef04) {
            do {
              iVar1 = DAT_009cf140 + (DAT_009ceedc >> 0x10 & 0xff) * 0x200;
              DAT_009cefd8 = DAT_009ceecc;
              puVar12 = DAT_009ceec4;
              for (DAT_009cef64 = iVar7; 0 < DAT_009cef64; DAT_009cef64 = DAT_009cef64 + -1) {
                sVar2 = *(short *)(iVar1 + (DAT_009cefd8 >> 0x10 & 0xff) * 2);
                uVar11 = (uint)sVar2;
                if (sVar2 != 0) {
                  uVar5 = (uint)(short)*puVar12;
                  *puVar12 = ((ushort)*(byte *)((uVar11 >> 5 & 0x3e0 | uVar5 & 0x7c00 | uVar6) +
                                               DAT_009cf118) << 5 |
                             (ushort)*(byte *)(((uVar5 & 0x3e0) << 5 | uVar11 & 0x3e0 | uVar10) +
                                              DAT_009cf118)) << 5 |
                             (ushort)*(byte *)((((uVar5 & 0x1f) << 5 | uVar11 & 0x1f) << 5 |
                                               DAT_009cefcc) + DAT_009cf118);
                  uVar6 = DAT_009cefd4;
                  iVar7 = DAT_009ceef4;
                  uVar10 = DAT_009cefd0;
                }
                puVar12 = puVar12 + 1;
                DAT_009cefd8 = DAT_009cefd8 + DAT_009cedb4;
              }
              DAT_009ceec4 = (ushort *)((int)DAT_009ceec4 + g_BackBufferStridePixels);
              DAT_009cef04 = DAT_009cef04 + -1;
              DAT_009ceedc = DAT_009ceedc + DAT_009ced90;
            } while (0 < DAT_009cef04);
            return;
          }
        }
        else {
          iVar7 = DAT_009ceef4;
          if (0 < DAT_009cef04) {
            do {
              iVar1 = DAT_009cf140 + (DAT_009ceedc >> 0x10 & 0xff) * 0x200;
              DAT_009cefd8 = DAT_009ceecc;
              puVar12 = DAT_009ceec4;
              for (DAT_009cef64 = iVar7; 0 < DAT_009cef64; DAT_009cef64 = DAT_009cef64 + -1) {
                uVar11 = (uint)*(short *)(iVar1 + (DAT_009cefd8 >> 0x10 & 0xff) * 2);
                if (uVar11 != 0) {
                  uVar5 = (uint)(short)*puVar12;
                  *puVar12 = ((ushort)*(byte *)(((uVar11 >> 5 & 0x7c0 | uVar5 & 0xf800) >> 1 | uVar6
                                                ) + DAT_009cf118) << 5 |
                             (ushort)*(byte *)((uVar11 >> 1 & 0x3e0 | (uVar5 & 0x7c0) << 4 | uVar10)
                                              + DAT_009cf118)) << 6 |
                             (ushort)*(byte *)((((uVar5 & 0x1f) << 5 | uVar11 & 0x1f) << 5 |
                                               DAT_009cefcc) + DAT_009cf118);
                  uVar6 = DAT_009cefd4;
                  iVar7 = DAT_009ceef4;
                  uVar10 = DAT_009cefd0;
                }
                puVar12 = puVar12 + 1;
                DAT_009cefd8 = DAT_009cefd8 + DAT_009cedb4;
              }
              DAT_009ceec4 = (ushort *)((int)DAT_009ceec4 + g_BackBufferStridePixels);
              DAT_009cef04 = DAT_009cef04 + -1;
              DAT_009ceedc = DAT_009ceedc + DAT_009ced90;
            } while (0 < DAT_009cef04);
            return;
          }
        }
      }
      else if (DAT_009cefe0 == 2) {
        if (DAT_005175f0 == 0) {
          iVar7 = DAT_009ceef4;
          if (0 < DAT_009cef04) {
            do {
              iVar1 = DAT_009cf140 + (DAT_009ceedc >> 0x10 & 0xff) * 0x200;
              DAT_009cefd8 = DAT_009ceecc;
              puVar12 = DAT_009ceec4;
              for (DAT_009cef64 = iVar7; 0 < DAT_009cef64; DAT_009cef64 = DAT_009cef64 + -1) {
                sVar2 = *(short *)(iVar1 + (DAT_009cefd8 >> 0x10 & 0xff) * 2);
                uVar11 = (uint)sVar2;
                if (sVar2 != 0) {
                  uVar5 = (uint)(short)*puVar12;
                  *puVar12 = ((ushort)*(byte *)((uVar11 >> 5 & 0x3e0 | uVar5 & 0x7c00 | uVar6) +
                                               DAT_009ced98) << 5 |
                             (ushort)*(byte *)(((uVar5 & 0x3e0) << 5 | uVar11 & 0x3e0 | uVar10) +
                                              DAT_009ced98)) << 5 |
                             (ushort)*(byte *)((((uVar5 & 0x1f) << 5 | uVar11 & 0x1f) << 5 |
                                               DAT_009cefcc) + DAT_009ced98);
                  uVar6 = DAT_009cefd4;
                  iVar7 = DAT_009ceef4;
                  uVar10 = DAT_009cefd0;
                }
                puVar12 = puVar12 + 1;
                DAT_009cefd8 = DAT_009cefd8 + DAT_009cedb4;
              }
              DAT_009ceec4 = (ushort *)((int)DAT_009ceec4 + g_BackBufferStridePixels);
              DAT_009cef04 = DAT_009cef04 + -1;
              DAT_009ceedc = DAT_009ceedc + DAT_009ced90;
            } while (0 < DAT_009cef04);
            return;
          }
        }
        else {
          iVar7 = DAT_009ceef4;
          if (0 < DAT_009cef04) {
            do {
              iVar1 = DAT_009cf140 + (DAT_009ceedc >> 0x10 & 0xff) * 0x200;
              DAT_009cefd8 = DAT_009ceecc;
              puVar12 = DAT_009ceec4;
              for (DAT_009cef64 = iVar7; 0 < DAT_009cef64; DAT_009cef64 = DAT_009cef64 + -1) {
                uVar11 = (uint)*(short *)(iVar1 + (DAT_009cefd8 >> 0x10 & 0xff) * 2);
                if (uVar11 != 0) {
                  uVar5 = (uint)(short)*puVar12;
                  *puVar12 = ((ushort)*(byte *)(((uVar11 >> 5 & 0x7c0 | uVar5 & 0xf800) >> 1 | uVar6
                                                ) + DAT_009ced98) << 5 |
                             (ushort)*(byte *)((uVar11 >> 1 & 0x3e0 | (uVar5 & 0x7c0) << 4 | uVar10)
                                              + DAT_009ced98)) << 6 |
                             (ushort)*(byte *)((((uVar5 & 0x1f) << 5 | uVar11 & 0x1f) << 5 |
                                               DAT_009cefcc) + DAT_009ced98);
                  uVar6 = DAT_009cefd4;
                  iVar7 = DAT_009ceef4;
                  uVar10 = DAT_009cefd0;
                }
                puVar12 = puVar12 + 1;
                DAT_009cefd8 = DAT_009cefd8 + DAT_009cedb4;
              }
              DAT_009ceec4 = (ushort *)((int)DAT_009ceec4 + g_BackBufferStridePixels);
              DAT_009cef04 = DAT_009cef04 + -1;
              DAT_009ceedc = DAT_009ceedc + DAT_009ced90;
            } while (0 < DAT_009cef04);
            return;
          }
        }
      }
    }
  }
  return;
}


