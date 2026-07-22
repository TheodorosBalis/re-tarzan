#include "tarzan_ghidra_types.hpp"

// Address: 0x004A3360
// Label: RasterizeTriangleModulatedToBackBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeTriangleModulatedToBackBuffer(void)

{
  float *floatCursor;
  ushort value8;
  int value3;
  uint value9;
  int value4;
  int value5;
  uint value10;
  int value6;
  int value7;
  int value;
  int value2;
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
  value7 = g_TriangleLeftEdgeVertexIndex;
  if (g_RasterizerCurrentY < g_RasterizerBottomY) {
    do {
      value2 = value7;
      value = g_TriangleLeftEdgeVertexIndex;
      if (g_TriangleLeftEdgeEndY <= g_RasterizerCurrentY) {
        do {
          value2 = value7 + -1;
          if (value2 < 0) {
            value2 = 2;
          }
          if ((float)(&g_TriangleClipVertexY0)[value2] - (float)(&g_TriangleClipVertexY0)[value7] !=
              _g_FloatZero) {
            value6 = ConvertFpuTopToInt64();
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexU0_16 + value2 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexU0_16 + value7 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            value = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexV0_16 + value2 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexV0_16 + value7 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            value3 = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexShadeRed0_16 + value2 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexShadeRed0_16 + value7 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            value4 = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexShadeGreen0_16 + value2 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexShadeGreen0_16 + value7 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            g_RasterizerLeftXStepPerScanline16 = value6 - (value6 >> 0x1f);
            g_RasterizerLeftUStepPerScanline16 = value - (value >> 0x1f);
            g_RasterizerLeftVStepPerScanline16 = value3 - (value3 >> 0x1f);
            g_RasterizerLeftShadeRedStepPerScanline16 = value4 - (value4 >> 0x1f);
            g_RasterizerLeftShadeGreenStepPerScanline16 =
                 g_RasterizerFpuToIntTemp - ((int)g_RasterizerFpuToIntTemp >> 0x1f);
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexShadeBlue0_16 + value2 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexShadeBlue0_16 + value7 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            g_RasterizerLeftShadeBlueStepPerScanline16 =
                 g_RasterizerFpuToIntTemp - ((int)g_RasterizerFpuToIntTemp >> 0x1f);
          }
          g_TriangleLeftX16 = ConvertFpuTopToInt64();
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexU0_16 + value7 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftU16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexV0_16 + value7 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftV16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexShadeRed0_16 + value7 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftShadeRed16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexShadeGreen0_16 + value7 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftShadeGreen16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexShadeBlue0_16 + value7 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          value = g_RasterizerFpuToIntTemp;
          g_TriangleLeftShadeBlue16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerYFractionToNextScanline =
               (float)(fpuResult2 - (float10)(float)(&g_TriangleClipVertexY0)[value7]);
          if (fpuResult2 - (float10)(float)(&g_TriangleClipVertexY0)[value7] !=
              (float10)_g_RenderNearClipDepth) {
            if (_g_RenderNearClipDepth < _g_RasterizerYFractionToNextScanline) {
              _g_RasterizerYFractionToNextScanline =
                   _g_RasterizerYFractionToNextScanline - _g_RenderNearClipDepth;
            }
            value7 = ConvertFpuTopToInt64();
            g_TriangleLeftX16 = g_TriangleLeftX16 + value7;
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
            g_TriangleLeftShadeBlue16 = value + g_RasterizerFpuToIntTemp;
          }
          g_TriangleLeftEdgeEndY = ConvertFpuTopToInt64();
          value7 = value2;
          value = value2;
        } while (g_TriangleLeftEdgeEndY <= g_RasterizerCurrentY);
      }
      g_TriangleLeftEdgeVertexIndex = value;
      if (g_TriangleRightEdgeEndY <= g_RasterizerCurrentY) {
        do {
          value7 = g_TriangleRightEdgeVertexIndex + 1;
          if (2 < value7) {
            value7 = 0;
          }
          floatCursor = (float *)(&g_TriangleClipVertexY0 + g_TriangleRightEdgeVertexIndex);
          if ((float)(&g_TriangleClipVertexY0)[value7] -
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
            value = ConvertFpuTopToInt64();
            g_TriangleRightX16 = g_TriangleRightX16 + value;
          }
          g_TriangleRightEdgeVertexIndex = value7;
          g_TriangleRightEdgeEndY = ConvertFpuTopToInt64();
        } while (g_TriangleRightEdgeEndY <= g_RasterizerCurrentY);
      }
      g_RasterizerSpanPixelCount = g_TriangleRightEdgeEndY;
      if (g_TriangleLeftEdgeEndY < g_TriangleRightEdgeEndY) {
        g_RasterizerSpanPixelCount = g_TriangleLeftEdgeEndY;
      }
      g_RasterizerScanlineRowCount = g_RasterizerSpanPixelCount - g_RasterizerCurrentY;
      g_RasterizerCurrentY = g_RasterizerSpanPixelCount;
      value7 = value2;
      value4 = g_TriangleLeftShadeBlue16;
      value6 = g_TriangleLeftShadeGreen16;
      value5 = g_TriangleLeftShadeRed16;
      value10 = g_TriangleLeftV16;
      value2 = g_RasterizerCurrentShadeBlue;
      value = g_RasterizerCurrentShadeGreen;
      value3 = g_RasterizerCurrentShadeRed;
      value9 = g_RasterizerCurrentV16;
      if (g_RasterizerBottomY < g_RasterizerSpanPixelCount) {
        g_RasterizerScanlineRowCount =
             g_RasterizerScanlineRowCount + (g_RasterizerBottomY - g_RasterizerSpanPixelCount);
        value4 = g_TriangleLeftShadeBlue16;
        value6 = g_TriangleLeftShadeGreen16;
        value5 = g_TriangleLeftShadeRed16;
        value10 = g_TriangleLeftV16;
      }
      for (; g_RasterizerCurrentV16 = value10, g_RasterizerCurrentShadeRed = value5,
          g_RasterizerCurrentShadeGreen = value6, g_RasterizerCurrentShadeBlue = value4,
          g_TriangleLeftShadeBlue16 = g_RasterizerCurrentShadeBlue,
          g_TriangleLeftShadeGreen16 = g_RasterizerCurrentShadeGreen,
          g_TriangleLeftShadeRed16 = g_RasterizerCurrentShadeRed,
          g_TriangleLeftV16 = g_RasterizerCurrentV16, 0 < g_RasterizerScanlineRowCount;
          g_RasterizerScanlineRowCount = g_RasterizerScanlineRowCount + -1) {
        _g_RasterizerSpanStartX = g_TriangleLeftX16 >> 0x10;
        g_RasterizerSpanPixelCount = (g_TriangleRightX16 >> 0x10) - _g_RasterizerSpanStartX;
        if (0 < g_RasterizerSpanPixelCount) {
          g_RasterizerCurrentPixelPtr =
               (ushort *)(g_RasterizerDestScanlinePtr + _g_RasterizerSpanStartX * 2);
          g_RasterizerCurrentU16 = g_TriangleLeftU16;
          if (g_CurrentGraphicsPixelLayout == 0) {
            do {
              value8 = *(ushort *)
                       (g_CurrentRasterTexturePageBase +
                       ((int)((g_RasterizerCurrentU16 >> 0x10 & 0xff) << 8 |
                             g_RasterizerCurrentV16 & 0xff0000) >> 8) * 2);
              if (value8 != 0) {
                *g_RasterizerCurrentPixelPtr =
                     ((ushort)*(byte *)((value8 >> 5 & 0x3e0 | g_RasterizerCurrentShadeRed >> 0x13) +
                                       g_Modulate5BitBlendLookupTable) << 5 |
                     (ushort)*(byte *)((value8 & 0x3e0 | g_RasterizerCurrentShadeGreen >> 0x13) +
                                      g_Modulate5BitBlendLookupTable)) << 5 |
                     (ushort)*(byte *)(((value8 & 0x1f) << 5 | g_RasterizerCurrentShadeBlue >> 0x13)
                                      + g_Modulate5BitBlendLookupTable);
                value7 = g_TriangleLeftEdgeVertexIndex;
              }
              g_RasterizerCurrentU16 = g_RasterizerCurrentU16 + g_RasterizerUStepPerPixel16;
              g_RasterizerCurrentShadeRed =
                   g_RasterizerCurrentShadeRed + g_RasterizerShadeRedStepPerPixel16;
              g_RasterizerCurrentV16 = g_RasterizerCurrentV16 + g_RasterizerVStepPerPixel16;
              g_RasterizerCurrentShadeGreen =
                   g_RasterizerCurrentShadeGreen + g_RasterizerShadeGreenStepPerPixel16;
              g_RasterizerSpanPixelCount = g_RasterizerSpanPixelCount + -1;
              g_RasterizerCurrentShadeBlue =
                   g_RasterizerCurrentShadeBlue + g_RasterizerShadeBlueStepPerPixel16;
              g_RasterizerCurrentPixelPtr = g_RasterizerCurrentPixelPtr + 1;
              value2 = g_RasterizerCurrentShadeBlue;
              value = g_RasterizerCurrentShadeGreen;
              value3 = g_RasterizerCurrentShadeRed;
              value9 = g_RasterizerCurrentV16;
            } while (0 < g_RasterizerSpanPixelCount);
          }
          else {
            do {
              value8 = *(ushort *)
                       (g_CurrentRasterTexturePageBase +
                       ((int)((g_RasterizerCurrentU16 >> 0x10 & 0xff) << 8 |
                             g_RasterizerCurrentV16 & 0xff0000) >> 8) * 2);
              if (value8 != 0) {
                *g_RasterizerCurrentPixelPtr =
                     ((ushort)*(byte *)((value8 >> 6 & 0x3e0 | g_RasterizerCurrentShadeRed >> 0x13) +
                                       g_Modulate5BitBlendLookupTable) << 5 |
                     (ushort)*(byte *)((value8 >> 1 & 0x3e0 | g_RasterizerCurrentShadeGreen >> 0x13)
                                      + g_Modulate5BitBlendLookupTable)) << 6 |
                     (ushort)*(byte *)(((value8 & 0x1f) << 5 | g_RasterizerCurrentShadeBlue >> 0x13)
                                      + g_Modulate5BitBlendLookupTable);
                value7 = g_TriangleLeftEdgeVertexIndex;
              }
              g_RasterizerCurrentU16 = g_RasterizerCurrentU16 + g_RasterizerUStepPerPixel16;
              g_RasterizerCurrentShadeRed =
                   g_RasterizerCurrentShadeRed + g_RasterizerShadeRedStepPerPixel16;
              g_RasterizerCurrentV16 = g_RasterizerCurrentV16 + g_RasterizerVStepPerPixel16;
              g_RasterizerCurrentShadeGreen =
                   g_RasterizerCurrentShadeGreen + g_RasterizerShadeGreenStepPerPixel16;
              g_RasterizerSpanPixelCount = g_RasterizerSpanPixelCount + -1;
              g_RasterizerCurrentShadeBlue =
                   g_RasterizerCurrentShadeBlue + g_RasterizerShadeBlueStepPerPixel16;
              g_RasterizerCurrentPixelPtr = g_RasterizerCurrentPixelPtr + 1;
              value2 = g_RasterizerCurrentShadeBlue;
              value = g_RasterizerCurrentShadeGreen;
              value3 = g_RasterizerCurrentShadeRed;
              value9 = g_RasterizerCurrentV16;
            } while (0 < g_RasterizerSpanPixelCount);
          }
        }
        g_RasterizerCurrentV16 = value9;
        g_RasterizerCurrentShadeRed = value3;
        g_RasterizerCurrentShadeGreen = value;
        g_RasterizerCurrentShadeBlue = value2;
        g_RasterizerDestScanlinePtr = g_RasterizerDestScanlinePtr + g_BackBufferStridePixels;
        g_TriangleRightX16 = g_TriangleRightX16 + g_RasterizerRightXStepPerScanline16;
        g_TriangleLeftX16 = g_TriangleLeftX16 + g_RasterizerLeftXStepPerScanline16;
        g_TriangleLeftU16 = g_TriangleLeftU16 + g_RasterizerLeftUStepPerScanline16;
        value4 = g_TriangleLeftShadeBlue16 + g_RasterizerLeftShadeBlueStepPerScanline16;
        value6 = g_TriangleLeftShadeGreen16 + g_RasterizerLeftShadeGreenStepPerScanline16;
        value5 = g_TriangleLeftShadeRed16 + g_RasterizerLeftShadeRedStepPerScanline16;
        value10 = g_TriangleLeftV16 + g_RasterizerLeftVStepPerScanline16;
        value2 = g_RasterizerCurrentShadeBlue;
        value = g_RasterizerCurrentShadeGreen;
        value3 = g_RasterizerCurrentShadeRed;
        value9 = g_RasterizerCurrentV16;
      }
      g_RasterizerCurrentShadeBlue = value2;
      g_RasterizerCurrentShadeGreen = value;
      g_RasterizerCurrentShadeRed = value3;
      g_RasterizerCurrentV16 = value9;
    } while (g_RasterizerCurrentY < g_RasterizerBottomY);
  }
  return;
}

