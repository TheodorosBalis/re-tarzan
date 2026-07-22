#include "tarzan_ghidra_types.hpp"

// Address: 0x004A5B40
// Label: RasterizeTriangleAdditiveBlendToBackBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeTriangleAdditiveBlendToBackBuffer(void)

{
  float *floatCursor;
  ushort value7;
  int value2;
  int value3;
  uint value8;
  int value4;
  int value5;
  int value6;
  uint value9;
  int value;
  float10 fpuResult;
  float10 fpuResult2;
  float10 fpuResult3;
  
  g_CurrentRasterTexturePageBase =
       (g_CurrentRenderPacketTexturePageIndex & 0xf) * 0x20000 + g_GraphicsPageBufferBase;
  g_RasterizerDestScanlinePtr =
       g_BackBufferStridePixels * g_RasterizerCurrentY + g_BackBufferPixelsPtr;
  g_TriangleRightEdgeVertexIndex = g_TriangleLeftEdgeVertexIndex;
  g_TriangleRightEdgeEndY = 0;
  g_TriangleLeftEdgeEndY = 0;
  value5 = g_TriangleLeftEdgeVertexIndex;
  if (g_RasterizerCurrentY < g_RasterizerBottomY) {
    do {
      value = value5;
      value6 = g_TriangleLeftEdgeVertexIndex;
      if (g_TriangleLeftEdgeEndY <= g_RasterizerCurrentY) {
        do {
          value = value5 + -1;
          if (value < 0) {
            value = 2;
          }
          if ((float)(&g_TriangleClipVertexY0)[value] - (float)(&g_TriangleClipVertexY0)[value5] !=
              _g_FloatZero) {
            value4 = ConvertFpuTopToInt64();
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexU0_16 + value * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexU0_16 + value5 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            value6 = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexV0_16 + value * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexV0_16 + value5 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            value2 = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexShadeRed0_16 + value * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexShadeRed0_16 + value5 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            value3 = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexShadeGreen0_16 + value * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexShadeGreen0_16 + value5 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            g_RasterizerLeftXStepPerScanline16 = value4 - (value4 >> 0x1f);
            g_RasterizerLeftUStepPerScanline16 = value6 - (value6 >> 0x1f);
            g_RasterizerLeftVStepPerScanline16 = value2 - (value2 >> 0x1f);
            g_RasterizerLeftShadeRedStepPerScanline16 = value3 - (value3 >> 0x1f);
            g_RasterizerLeftShadeGreenStepPerScanline16 =
                 g_RasterizerFpuToIntTemp - ((int)g_RasterizerFpuToIntTemp >> 0x1f);
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexShadeBlue0_16 + value * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexShadeBlue0_16 + value5 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            g_RasterizerLeftShadeBlueStepPerScanline16 =
                 g_RasterizerFpuToIntTemp - ((int)g_RasterizerFpuToIntTemp >> 0x1f);
          }
          g_TriangleLeftX16 = ConvertFpuTopToInt64();
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexU0_16 + value5 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftU16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexV0_16 + value5 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftV16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexShadeRed0_16 + value5 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftShadeRed16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexShadeGreen0_16 + value5 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftShadeGreen16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexShadeBlue0_16 + value5 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          value6 = g_RasterizerFpuToIntTemp;
          g_TriangleLeftShadeBlue16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerYFractionToNextScanline =
               (float)(fpuResult2 - (float10)(float)(&g_TriangleClipVertexY0)[value5]);
          if (fpuResult2 - (float10)(float)(&g_TriangleClipVertexY0)[value5] !=
              (float10)_g_RenderNearClipDepth) {
            if (_g_RenderNearClipDepth < _g_RasterizerYFractionToNextScanline) {
              _g_RasterizerYFractionToNextScanline =
                   _g_RasterizerYFractionToNextScanline - _g_RenderNearClipDepth;
            }
            value5 = ConvertFpuTopToInt64();
            g_TriangleLeftX16 = g_TriangleLeftX16 + value5;
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
            g_TriangleLeftShadeBlue16 = value6 + g_RasterizerFpuToIntTemp;
          }
          g_TriangleLeftEdgeEndY = ConvertFpuTopToInt64();
          value5 = value;
          value6 = value;
        } while (g_TriangleLeftEdgeEndY <= g_RasterizerCurrentY);
      }
      g_TriangleLeftEdgeVertexIndex = value6;
      if (g_TriangleRightEdgeEndY <= g_RasterizerCurrentY) {
        do {
          value5 = g_TriangleRightEdgeVertexIndex + 1;
          if (2 < value5) {
            value5 = 0;
          }
          floatCursor = (float *)(&g_TriangleClipVertexY0 + g_TriangleRightEdgeVertexIndex);
          if ((float)(&g_TriangleClipVertexY0)[value5] -
              (float)(&g_TriangleClipVertexY0)[g_TriangleRightEdgeVertexIndex] != _g_FloatZero) {
            g_RasterizerRightXStepPerScanline16 = ConvertFpuTopToInt64();
          }
          g_TriangleRightX16 = ConvertFpuTopToInt64();
          _g_RasterizerYFractionToNextScanline = (float)(fpuResult3 - (float10)*floatCursor);
          if (fpuResult3 - (float10)*floatCursor != (float10)_g_RenderNearClipDepth) {
            if (_g_RenderNearClipDepth < _g_RasterizerYFractionToNextScanline) {
              _g_RasterizerYFractionToNextScanline =
                   _g_RasterizerYFractionToNextScanline - _g_RenderNearClipDepth;
            }
            value6 = ConvertFpuTopToInt64();
            g_TriangleRightX16 = g_TriangleRightX16 + value6;
          }
          g_TriangleRightEdgeVertexIndex = value5;
          g_TriangleRightEdgeEndY = ConvertFpuTopToInt64();
        } while (g_TriangleRightEdgeEndY <= g_RasterizerCurrentY);
      }
      g_RasterizerSpanPixelCount = g_TriangleRightEdgeEndY;
      if (g_TriangleLeftEdgeEndY < g_TriangleRightEdgeEndY) {
        g_RasterizerSpanPixelCount = g_TriangleLeftEdgeEndY;
      }
      g_RasterizerScanlineRowCount = g_RasterizerSpanPixelCount - g_RasterizerCurrentY;
      g_RasterizerCurrentY = g_RasterizerSpanPixelCount;
      value5 = value;
      value6 = g_TriangleLeftShadeRed16;
      value8 = g_TriangleLeftV16;
      value = g_RasterizerCurrentShadeRed;
      value9 = g_RasterizerCurrentV16;
      if (g_RasterizerBottomY < g_RasterizerSpanPixelCount) {
        g_RasterizerScanlineRowCount =
             g_RasterizerScanlineRowCount + (g_RasterizerBottomY - g_RasterizerSpanPixelCount);
        value6 = g_TriangleLeftShadeRed16;
        value8 = g_TriangleLeftV16;
      }
      for (; g_RasterizerCurrentV16 = value8, g_RasterizerCurrentShadeRed = value6,
          g_TriangleLeftShadeRed16 = g_RasterizerCurrentShadeRed,
          g_TriangleLeftV16 = g_RasterizerCurrentV16, 0 < g_RasterizerScanlineRowCount;
          g_RasterizerScanlineRowCount = g_RasterizerScanlineRowCount + -1) {
        _g_RasterizerSpanStartX = g_TriangleLeftX16 >> 0x10;
        g_RasterizerSpanPixelCount = (g_TriangleRightX16 >> 0x10) - _g_RasterizerSpanStartX;
        if (0 < g_RasterizerSpanPixelCount) {
          g_RasterizerCurrentPixelPtr =
               (ushort *)(g_RasterizerDestScanlinePtr + _g_RasterizerSpanStartX * 2);
          g_RasterizerCurrentShadeBlue = g_TriangleLeftShadeBlue16;
          g_RasterizerCurrentShadeGreen = g_TriangleLeftShadeGreen16;
          g_RasterizerCurrentU16 = g_TriangleLeftU16;
          if (g_CurrentGraphicsPixelLayout == 0) {
            do {
              value7 = *(ushort *)
                       (g_CurrentRasterTexturePageBase +
                       ((int)((g_RasterizerCurrentU16 >> 0x10 & 0xff) << 8 |
                             g_RasterizerCurrentV16 & 0xff0000) >> 8) * 2);
              if (value7 != 0) {
                value9 = (uint)(short)*g_RasterizerCurrentPixelPtr;
                *g_RasterizerCurrentPixelPtr =
                     ((ushort)*(byte *)(g_Additive5BitBlendLookupTable +
                                       (g_RasterizerCurrentShadeRed >> 0x13 | value7 >> 5 & 0x3e0 |
                                       value9 & 0x7c00)) << 5 |
                     (ushort)*(byte *)(((value9 & 0x3e0) << 5 | g_RasterizerCurrentShadeGreen >> 0x13
                                       | value7 & 0x3e0) + g_Additive5BitBlendLookupTable)) << 5 |
                     (ushort)*(byte *)((((value9 & 0x1f) << 5 | value7 & 0x1f) << 5 |
                                       g_RasterizerCurrentShadeBlue >> 0x13) +
                                      g_Additive5BitBlendLookupTable);
                value5 = g_TriangleLeftEdgeVertexIndex;
              }
              g_RasterizerCurrentU16 = g_RasterizerCurrentU16 + g_RasterizerUStepPerPixel16;
              g_RasterizerCurrentV16 = g_RasterizerCurrentV16 + g_RasterizerVStepPerPixel16;
              g_RasterizerCurrentShadeRed =
                   g_RasterizerCurrentShadeRed + g_RasterizerShadeRedStepPerPixel16;
              g_RasterizerCurrentShadeGreen =
                   g_RasterizerCurrentShadeGreen + g_RasterizerShadeGreenStepPerPixel16;
              g_RasterizerSpanPixelCount = g_RasterizerSpanPixelCount + -1;
              g_RasterizerCurrentShadeBlue =
                   g_RasterizerCurrentShadeBlue + g_RasterizerShadeBlueStepPerPixel16;
              g_RasterizerCurrentPixelPtr = g_RasterizerCurrentPixelPtr + 1;
              value = g_RasterizerCurrentShadeRed;
              value9 = g_RasterizerCurrentV16;
            } while (0 < g_RasterizerSpanPixelCount);
          }
          else {
            do {
              value7 = *(ushort *)
                       (g_CurrentRasterTexturePageBase +
                       ((int)((g_RasterizerCurrentU16 >> 0x10 & 0xff) << 8 |
                             g_RasterizerCurrentV16 & 0xff0000) >> 8) * 2);
              if (value7 != 0) {
                value9 = (uint)(short)*g_RasterizerCurrentPixelPtr;
                *g_RasterizerCurrentPixelPtr =
                     ((ushort)*(byte *)(((value7 >> 5 & 0x7c0 | value9 & 0xf800) >> 1 |
                                        g_RasterizerCurrentShadeRed >> 0x13) +
                                       g_Additive5BitBlendLookupTable) << 5 |
                     (ushort)*(byte *)((g_RasterizerCurrentShadeGreen >> 0x13 | (value7 & 0x7c0) >> 1
                                       | (value9 & 0x7c0) << 4) + g_Additive5BitBlendLookupTable)) <<
                     6 | (ushort)*(byte *)((((value9 & 0x1f) << 5 | value7 & 0x1f) << 5 |
                                           g_RasterizerCurrentShadeBlue >> 0x13) +
                                          g_Additive5BitBlendLookupTable);
                value5 = g_TriangleLeftEdgeVertexIndex;
              }
              g_RasterizerCurrentU16 = g_RasterizerCurrentU16 + g_RasterizerUStepPerPixel16;
              g_RasterizerCurrentV16 = g_RasterizerCurrentV16 + g_RasterizerVStepPerPixel16;
              g_RasterizerCurrentShadeRed =
                   g_RasterizerCurrentShadeRed + g_RasterizerShadeRedStepPerPixel16;
              g_RasterizerCurrentShadeGreen =
                   g_RasterizerCurrentShadeGreen + g_RasterizerShadeGreenStepPerPixel16;
              g_RasterizerSpanPixelCount = g_RasterizerSpanPixelCount + -1;
              g_RasterizerCurrentShadeBlue =
                   g_RasterizerCurrentShadeBlue + g_RasterizerShadeBlueStepPerPixel16;
              g_RasterizerCurrentPixelPtr = g_RasterizerCurrentPixelPtr + 1;
              value = g_RasterizerCurrentShadeRed;
              value9 = g_RasterizerCurrentV16;
            } while (0 < g_RasterizerSpanPixelCount);
          }
        }
        g_RasterizerCurrentV16 = value9;
        g_RasterizerCurrentShadeRed = value;
        g_RasterizerDestScanlinePtr = g_RasterizerDestScanlinePtr + g_BackBufferStridePixels;
        g_TriangleRightX16 = g_TriangleRightX16 + g_RasterizerRightXStepPerScanline16;
        g_TriangleLeftX16 = g_TriangleLeftX16 + g_RasterizerLeftXStepPerScanline16;
        g_TriangleLeftU16 = g_TriangleLeftU16 + g_RasterizerLeftUStepPerScanline16;
        g_TriangleLeftShadeGreen16 =
             g_TriangleLeftShadeGreen16 + g_RasterizerLeftShadeGreenStepPerScanline16;
        g_TriangleLeftShadeBlue16 =
             g_TriangleLeftShadeBlue16 + g_RasterizerLeftShadeBlueStepPerScanline16;
        value6 = g_TriangleLeftShadeRed16 + g_RasterizerLeftShadeRedStepPerScanline16;
        value8 = g_TriangleLeftV16 + g_RasterizerLeftVStepPerScanline16;
        value = g_RasterizerCurrentShadeRed;
        value9 = g_RasterizerCurrentV16;
      }
      g_RasterizerCurrentShadeRed = value;
      g_RasterizerCurrentV16 = value9;
    } while (g_RasterizerCurrentY < g_RasterizerBottomY);
  }
  return;
}

