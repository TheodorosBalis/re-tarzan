#include "tarzan_ghidra_types.hpp"

// Address: 0x004A3E10
// Label: RasterizeTriangleModulatedMmxToBackBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeTriangleModulatedMmxToBackBuffer(void)

{
  float *floatCursor;
  ushort value9;
  bool flagByte;
  int value6;
  unkuint10 value;
  unkuint10 value2;
  int value7;
  int value8;
  uint value11;
  int value3;
  int value4;
  int value5;
  ushort *bufferCursor;
  float10 fpuValue;
  float10 edgeSlope;
  float10 fpuResult;
  float10 fpuResult2;
  float10 fpuResult3;
  float10 fpuResult4;
  float10 fpuResult5;
  float10 fpuResult6;
  float10 fpuResult7;
  float10 fpuResult8;
  float10 fpuResult9;
  short shortValue;
  short shortValue2;
  float10 fpuValue2;
  short shortValue3;
  short shortValue4;
  short shortValue5;
  ulonglong value10;
  
  g_CurrentRasterTexturePageBase =
       (g_CurrentRenderPacketTexturePageIndex & 0xf) * 0x20000 + g_GraphicsPageBufferBase;
  g_RasterizerDestScanlinePtr =
       g_BackBufferStridePixels * g_RasterizerCurrentY + g_BackBufferPixelsPtr;
  g_TriangleRightEdgeVertexIndex = g_TriangleLeftEdgeVertexIndex;
  g_TriangleRightEdgeEndY = 0;
  g_TriangleLeftEdgeEndY = 0;
  if (g_RasterizerCurrentY < g_RasterizerBottomY) {
    do {
      value4 = g_RasterizerLeftShadeBlueStepPerScanline16;
      value5 = g_TriangleLeftEdgeVertexIndex;
      if (g_TriangleLeftEdgeEndY <= g_RasterizerCurrentY) {
        edgeSlope = (float10)(g_RasterizerCurrentY + 1);
        value8 = g_TriangleLeftEdgeVertexIndex;
        do {
          value5 = value8 + -1;
          if (value5 < 0) {
            value5 = 2;
          }
          if ((float)(&g_TriangleClipVertexY0)[value5] - (float)(&g_TriangleClipVertexY0)[value8] !=
              _g_FloatZero) {
            fpuValue = edgeSlope;
            value7 = ConvertFpuTopToInt64();
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexU0_16 + value5 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexU0_16 + value8 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            value4 = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexV0_16 + value5 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexV0_16 + value8 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            value6 = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexShadeRed0_16 + value5 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexShadeRed0_16 + value8 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            value3 = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexShadeGreen0_16 + value5 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexShadeGreen0_16 + value8 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            g_RasterizerLeftXStepPerScanline16 = value7 - (value7 >> 0x1f);
            g_RasterizerLeftUStepPerScanline16 = value4 - (value4 >> 0x1f);
            g_RasterizerLeftVStepPerScanline16 = value6 - (value6 >> 0x1f);
            g_RasterizerLeftShadeRedStepPerScanline16 = value3 - (value3 >> 0x1f);
            g_RasterizerLeftShadeGreenStepPerScanline16 =
                 g_RasterizerFpuToIntTemp - ((int)g_RasterizerFpuToIntTemp >> 0x1f);
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexShadeBlue0_16 + value5 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexShadeBlue0_16 + value8 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            value4 = g_RasterizerFpuToIntTemp - ((int)g_RasterizerFpuToIntTemp >> 0x1f);
            g_RasterizerLeftShadeBlueStepPerScanline16 = value4;
          }
          g_TriangleLeftX16 = ConvertFpuTopToInt64();
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexU0_16 + value8 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftU16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexV0_16 + value8 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftV16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexShadeRed0_16 + value8 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftShadeRed16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexShadeGreen0_16 + value8 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftShadeGreen16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexShadeBlue0_16 + value8 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          value11 = g_RasterizerFpuToIntTemp;
          g_TriangleLeftShadeBlue16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerYFractionToNextScanline =
               (float)(fpuResult2 - (float10)(float)(&g_TriangleClipVertexY0)[value8]);
          if (fpuResult2 - (float10)(float)(&g_TriangleClipVertexY0)[value8] !=
              (float10)_g_RenderNearClipDepth) {
            if (_g_RenderNearClipDepth < _g_RasterizerYFractionToNextScanline) {
              _g_RasterizerYFractionToNextScanline =
                   _g_RasterizerYFractionToNextScanline - _g_RenderNearClipDepth;
            }
            fpuValue = fpuResult6;
            value8 = ConvertFpuTopToInt64();
            g_TriangleLeftX16 = g_TriangleLeftX16 + value8;
            _g_RasterizerFpuToIntTemp =
                 (double)((float)g_RasterizerLeftUStepPerScanline16 *
                          _g_RasterizerYFractionToNextScanline + (float)_g_DoubleToIntRoundingBias);
            g_TriangleLeftU16 = g_TriangleLeftU16 + g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)((float)g_RasterizerLeftVStepPerScanline16 *
                          _g_RasterizerYFractionToNextScanline + (float)_g_DoubleToIntRoundingBias);
            g_TriangleLeftV16 = g_TriangleLeftV16 + g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)((float)g_RasterizerLeftShadeRedStepPerScanline16 *
                          _g_RasterizerYFractionToNextScanline + (float)_g_DoubleToIntRoundingBias);
            g_TriangleLeftShadeRed16 = g_TriangleLeftShadeRed16 + g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)((float)g_RasterizerLeftShadeGreenStepPerScanline16 *
                          _g_RasterizerYFractionToNextScanline + (float)_g_DoubleToIntRoundingBias);
            g_TriangleLeftShadeGreen16 = g_TriangleLeftShadeGreen16 + g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)((float)g_RasterizerLeftShadeBlueStepPerScanline16 *
                          _g_RasterizerYFractionToNextScanline + (float)_g_DoubleToIntRoundingBias);
            g_TriangleLeftShadeBlue16 = value11 + g_RasterizerFpuToIntTemp;
          }
          fpuValue2 = fpuValue;
          g_TriangleLeftEdgeEndY = ConvertFpuTopToInt64();
          value8 = value5;
          fpuValue = fpuResult7;
          edgeSlope = fpuResult3;
        } while (g_TriangleLeftEdgeEndY <= g_RasterizerCurrentY);
      }
      g_TriangleLeftEdgeVertexIndex = value5;
      if (g_TriangleRightEdgeEndY <= g_RasterizerCurrentY) {
        edgeSlope = (float10)(g_RasterizerCurrentY + 1);
        do {
          value5 = g_TriangleRightEdgeVertexIndex + 1;
          if (2 < value5) {
            value5 = 0;
          }
          floatCursor = (float *)(&g_TriangleClipVertexY0 + g_TriangleRightEdgeVertexIndex);
          if ((float)(&g_TriangleClipVertexY0)[value5] -
              (float)(&g_TriangleClipVertexY0)[g_TriangleRightEdgeVertexIndex] != _g_FloatZero) {
            fpuValue = edgeSlope;
            g_RasterizerRightXStepPerScanline16 = ConvertFpuTopToInt64();
          }
          g_TriangleRightX16 = ConvertFpuTopToInt64();
          _g_RasterizerYFractionToNextScanline = (float)(fpuResult4 - (float10)*floatCursor);
          if (fpuResult4 - (float10)*floatCursor != (float10)_g_RenderNearClipDepth) {
            if (_g_RenderNearClipDepth < _g_RasterizerYFractionToNextScanline) {
              _g_RasterizerYFractionToNextScanline =
                   _g_RasterizerYFractionToNextScanline - _g_RenderNearClipDepth;
            }
            fpuValue = fpuResult8;
            value8 = ConvertFpuTopToInt64();
            g_TriangleRightX16 = g_TriangleRightX16 + value8;
          }
          fpuValue2 = fpuValue;
          g_TriangleRightEdgeVertexIndex = value5;
          g_TriangleRightEdgeEndY = ConvertFpuTopToInt64();
          fpuValue = fpuResult9;
          edgeSlope = fpuResult5;
        } while (g_TriangleRightEdgeEndY <= g_RasterizerCurrentY);
      }
      g_RasterizerSpanPixelCount = g_TriangleLeftEdgeEndY;
      if (g_TriangleRightEdgeEndY <= g_TriangleLeftEdgeEndY) {
        g_RasterizerSpanPixelCount = g_TriangleRightEdgeEndY;
      }
      g_RasterizerScanlineRowCount = g_RasterizerSpanPixelCount - g_RasterizerCurrentY;
      g_RasterizerCurrentY = g_RasterizerSpanPixelCount;
      value5 = g_RasterizerUStepPerPixel16;
      value8 = g_RasterizerVStepPerPixel16;
      value6 = g_CurrentRasterTexturePageBase;
      if (g_RasterizerBottomY < g_RasterizerSpanPixelCount) {
        g_RasterizerScanlineRowCount =
             g_RasterizerScanlineRowCount + (g_RasterizerBottomY - g_RasterizerSpanPixelCount);
      }
      for (; g_RasterizerUStepPerPixel16 = value5, g_RasterizerVStepPerPixel16 = value8,
          g_CurrentRasterTexturePageBase = value6, 0 < g_RasterizerScanlineRowCount;
          g_RasterizerScanlineRowCount = g_RasterizerScanlineRowCount + -1) {
        _g_RasterizerSpanStartX = g_TriangleLeftX16 >> 0x10;
        g_RasterizerSpanPixelCount = (g_TriangleRightX16 >> 0x10) - _g_RasterizerSpanStartX;
        if (0 < g_RasterizerSpanPixelCount) {
          g_RasterizerCurrentPixelPtr = g_RasterizerDestScanlinePtr + _g_RasterizerSpanStartX * 2;
          fpuValue = (float10)CONCAT28((short)((unkuint10)fpuValue >> 0x40),
                                     CONCAT44(g_TriangleLeftV16,g_TriangleLeftU16));
          fpuValue2 = (float10)CONCAT28((short)((unkuint10)fpuValue2 >> 0x40),
                                     CONCAT26((short)((ulonglong)g_MmxRgbLaneRoundBias >> 0x30),
                                              CONCAT24((short)(((ulonglong)
                                                                (g_TriangleLeftShadeRed16 & 0xffe000
                                                                ) << 0x13) >> 0x20) +
                                                       (short)((ulonglong)g_MmxRgbLaneRoundBias >>
                                                              0x20),
                                                       CONCAT22((short)(((g_TriangleLeftShadeGreen16
                                                                         & 0xffe000) << 3) >> 0x10)
                                                                + (short)((ulonglong)
                                                                          g_MmxRgbLaneRoundBias >>
                                                                         0x10),
                                                                (short)((g_TriangleLeftShadeBlue16 &
                                                                        0xffe000) >> 0xd) +
                                                                (short)g_MmxRgbLaneRoundBias))));
          shortValue3 = (short)((g_RasterizerShadeBlueStepPerPixel16 & 0x1fffe000) >> 0xd);
          shortValue4 = (short)(((g_RasterizerShadeGreenStepPerPixel16 & 0x1fffe000) << 3) >> 0x10);
          shortValue5 = (short)(((ulonglong)(g_RasterizerShadeRedStepPerPixel16 & 0x1fffe000) << 0x13) >>
                          0x20);
          shortValue3 = shortValue3 - (shortValue3 >> 0xf);
          shortValue4 = shortValue4 - (shortValue4 >> 0xf);
          shortValue5 = shortValue5 - (shortValue5 >> 0xf);
          bufferCursor = (ushort *)(g_RasterizerCurrentPixelPtr + -2);
          value3 = g_RasterizerSpanPixelCount;
          if (g_CurrentGraphicsPixelLayout == 0) {
            do {
              value2 = (unkuint10)fpuValue >> 0x10;
              value = (unkuint10)fpuValue >> 0x30;
              fpuValue = (float10)CONCAT28((short)((unkuint10)fpuValue >> 0x40),
                                         CONCAT44((int)((unkuint10)fpuValue >> 0x20) + value8,
                                                  SUB104(fpuValue,0) + value5));
              value9 = *(ushort *)(value6 + (uint)CONCAT11((char)value,(char)value2) * 2);
              value11 = (uint)value9;
              bufferCursor = bufferCursor + 1;
              shortValue = (short)((unkuint10)fpuValue2 >> 0x10);
              shortValue2 = (short)((unkuint10)fpuValue2 >> 0x20);
              if (value9 != 0) {
                value10 = ((ulonglong)value11 | (ulonglong)value11 << 0xb | (ulonglong)value11 << 0x16) &
                         _g_MmxRgbLaneExpandMask;
                value10 = CONCAT24((short)(value10 >> 0x20) * shortValue2,
                                  CONCAT22((short)(value10 >> 0x10) * shortValue,
                                           (short)value10 * SUB102(fpuValue2,0))) &
                         _g_MmxRgbLaneMultiplyMask;
                *bufferCursor = (ushort)(value10 >> 0xb) | (ushort)(value10 >> 0x16) |
                           (ushort)(value10 >> 0x21);
              }
              fpuValue2 = (float10)CONCAT28((short)((unkuint10)fpuValue2 >> 0x40),
                                         CONCAT26((short)((unkuint10)fpuValue2 >> 0x30),
                                                  CONCAT24(shortValue2 + shortValue5,
                                                           CONCAT22(shortValue + shortValue4,
                                                                    SUB102(fpuValue2,0) + shortValue3))));
              value7 = value3 + -1;
              flagByte = 0 < value3;
              value3 = value7;
              value4 = g_RasterizerLeftShadeBlueStepPerScanline16;
            } while (value7 != 0 && flagByte);
          }
          else {
            do {
              value2 = (unkuint10)fpuValue >> 0x10;
              value = (unkuint10)fpuValue >> 0x30;
              fpuValue = (float10)CONCAT28((short)((unkuint10)fpuValue >> 0x40),
                                         CONCAT44((int)((unkuint10)fpuValue >> 0x20) + value8,
                                                  SUB104(fpuValue,0) + value5));
              value9 = *(ushort *)(value6 + (uint)CONCAT11((char)value,(char)value2) * 2);
              value11 = (uint)value9;
              bufferCursor = bufferCursor + 1;
              shortValue = (short)((unkuint10)fpuValue2 >> 0x10);
              shortValue2 = (short)((unkuint10)fpuValue2 >> 0x20);
              if (value9 != 0) {
                value10 = ((ulonglong)value11 | (ulonglong)value11 << 10 | (ulonglong)value11 << 0x15) &
                         _g_MmxRgbLaneExpandMask;
                value10 = CONCAT24((short)(value10 >> 0x20) * shortValue2,
                                  CONCAT22((short)(value10 >> 0x10) * shortValue,
                                           (short)value10 * SUB102(fpuValue2,0))) &
                         _g_MmxRgbLaneMultiplyMask;
                *bufferCursor = (ushort)(value10 >> 0xb) | (ushort)(value10 >> 0x15) |
                           (ushort)(value10 >> 0x20);
              }
              fpuValue2 = (float10)CONCAT28((short)((unkuint10)fpuValue2 >> 0x40),
                                         CONCAT26((short)((unkuint10)fpuValue2 >> 0x30),
                                                  CONCAT24(shortValue2 + shortValue5,
                                                           CONCAT22(shortValue + shortValue4,
                                                                    SUB102(fpuValue2,0) + shortValue3))));
              value7 = value3 + -1;
              flagByte = 0 < value3;
              value3 = value7;
              value4 = g_RasterizerLeftShadeBlueStepPerScanline16;
            } while (value7 != 0 && flagByte);
          }
        }
        g_RasterizerDestScanlinePtr = g_RasterizerDestScanlinePtr + g_BackBufferStridePixels;
        g_TriangleLeftX16 = g_TriangleLeftX16 + g_RasterizerLeftXStepPerScanline16;
        g_TriangleRightX16 = g_TriangleRightX16 + g_RasterizerRightXStepPerScanline16;
        g_TriangleLeftU16 = g_TriangleLeftU16 + g_RasterizerLeftUStepPerScanline16;
        g_TriangleLeftV16 = g_TriangleLeftV16 + g_RasterizerLeftVStepPerScanline16;
        g_TriangleLeftShadeRed16 =
             g_TriangleLeftShadeRed16 + g_RasterizerLeftShadeRedStepPerScanline16;
        g_TriangleLeftShadeGreen16 =
             g_TriangleLeftShadeGreen16 + g_RasterizerLeftShadeGreenStepPerScanline16;
        g_TriangleLeftShadeBlue16 = g_TriangleLeftShadeBlue16 + value4;
        value5 = g_RasterizerUStepPerPixel16;
        value8 = g_RasterizerVStepPerPixel16;
        value6 = g_CurrentRasterTexturePageBase;
      }
    } while (g_RasterizerCurrentY < g_RasterizerBottomY);
  }
  return;
}

