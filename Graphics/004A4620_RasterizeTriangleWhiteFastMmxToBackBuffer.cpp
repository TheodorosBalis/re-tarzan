#include "tarzan_ghidra_types.hpp"

// Address: 0x004A4620
// Label: RasterizeTriangleWhiteFastMmxToBackBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeTriangleWhiteFastMmxToBackBuffer(void)

{
  float *floatCursor;
  short shortValue;
  bool flagByte;
  unkuint10 value;
  unkuint10 value2;
  int value4;
  int value5;
  int value6;
  int value7;
  int value3;
  short *value8;
  unkbyte10 fpuValue;
  float10 fpuResult;
  float10 fpuResult2;
  float10 fpuResult3;
  unkbyte10 fpuResult4;
  unkbyte10 fpuResult5;
  
  g_CurrentRasterTexturePageBase =
       (g_CurrentRenderPacketTexturePageIndex & 0xf) * 0x20000 + g_GraphicsPageBufferBase;
  g_RasterizerDestScanlinePtr =
       g_BackBufferStridePixels * g_RasterizerCurrentY + g_BackBufferPixelsPtr;
  g_TriangleRightEdgeVertexIndex = g_TriangleLeftEdgeVertexIndex;
  g_TriangleRightEdgeEndY = 0;
  g_TriangleLeftEdgeEndY = 0;
  if (g_RasterizerCurrentY < g_RasterizerBottomY) {
    do {
      value5 = g_TriangleLeftEdgeVertexIndex;
      value3 = g_TriangleLeftEdgeVertexIndex;
      if (g_TriangleLeftEdgeEndY <= g_RasterizerCurrentY) {
        do {
          value3 = value5 + -1;
          if (value3 < 0) {
            value3 = 2;
          }
          if ((float)(&g_TriangleClipVertexY0)[value3] - (float)(&g_TriangleClipVertexY0)[value5] !=
              _g_FloatZero) {
            value4 = ConvertFpuTopToInt64();
            g_RasterizerLeftXStepPerScanline16 = value4 - (value4 >> 0x1f);
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexU0_16 + value3 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexU0_16 + value5 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            g_RasterizerLeftUStepPerScanline16 =
                 g_RasterizerFpuToIntTemp - (g_RasterizerFpuToIntTemp >> 0x1f);
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexV0_16 + value3 * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexV0_16 + value5 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            g_RasterizerLeftVStepPerScanline16 =
                 g_RasterizerFpuToIntTemp - (g_RasterizerFpuToIntTemp >> 0x1f);
          }
          g_TriangleLeftX16 = ConvertFpuTopToInt64();
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexU0_16 + value5 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          g_TriangleLeftU16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexV0_16 + value5 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          value4 = g_RasterizerFpuToIntTemp;
          g_TriangleLeftV16 = g_RasterizerFpuToIntTemp;
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
            g_TriangleLeftV16 = value4 + g_RasterizerFpuToIntTemp;
          }
          g_TriangleLeftEdgeEndY = ConvertFpuTopToInt64();
          value5 = value3;
          fpuValue = fpuResult4;
        } while (g_TriangleLeftEdgeEndY <= g_RasterizerCurrentY);
      }
      g_TriangleLeftEdgeVertexIndex = value3;
      if (g_TriangleRightEdgeEndY <= g_RasterizerCurrentY) {
        do {
          value3 = g_TriangleRightEdgeVertexIndex + 1;
          if (2 < value3) {
            value3 = 0;
          }
          floatCursor = (float *)(&g_TriangleClipVertexY0 + g_TriangleRightEdgeVertexIndex);
          if ((float)(&g_TriangleClipVertexY0)[value3] -
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
            value5 = ConvertFpuTopToInt64();
            g_TriangleRightX16 = g_TriangleRightX16 + value5;
          }
          g_TriangleRightEdgeVertexIndex = value3;
          g_TriangleRightEdgeEndY = ConvertFpuTopToInt64();
          fpuValue = fpuResult5;
        } while (g_TriangleRightEdgeEndY <= g_RasterizerCurrentY);
      }
      g_RasterizerSpanPixelCount = g_TriangleRightEdgeEndY;
      if (g_TriangleLeftEdgeEndY < g_TriangleRightEdgeEndY) {
        g_RasterizerSpanPixelCount = g_TriangleLeftEdgeEndY;
      }
      g_RasterizerScanlineRowCount = g_RasterizerSpanPixelCount - g_RasterizerCurrentY;
      g_RasterizerCurrentY = g_RasterizerSpanPixelCount;
      value3 = g_RasterizerUStepPerPixel16;
      value5 = g_RasterizerVStepPerPixel16;
      value4 = g_CurrentRasterTexturePageBase;
      if (g_RasterizerBottomY < g_RasterizerSpanPixelCount) {
        g_RasterizerScanlineRowCount =
             g_RasterizerScanlineRowCount + (g_RasterizerBottomY - g_RasterizerSpanPixelCount);
      }
      for (; g_RasterizerUStepPerPixel16 = value3, g_RasterizerVStepPerPixel16 = value5,
          g_CurrentRasterTexturePageBase = value4, 0 < g_RasterizerScanlineRowCount;
          g_RasterizerScanlineRowCount = g_RasterizerScanlineRowCount + -1) {
        _g_RasterizerSpanStartX = g_TriangleLeftX16 >> 0x10;
        g_RasterizerSpanPixelCount = (g_TriangleRightX16 >> 0x10) - _g_RasterizerSpanStartX;
        if (0 < g_RasterizerSpanPixelCount) {
          g_RasterizerCurrentPixelPtr = g_RasterizerDestScanlinePtr + _g_RasterizerSpanStartX * 2;
          fpuValue = CONCAT28((short)((unkuint10)fpuValue >> 0x40),
                            CONCAT44(g_TriangleLeftV16,g_TriangleLeftU16));
          value8 = (short *)(g_RasterizerCurrentPixelPtr + -2);
          value6 = g_RasterizerSpanPixelCount;
          do {
            value2 = (unkuint10)fpuValue >> 0x10;
            value = (unkuint10)fpuValue >> 0x30;
            fpuValue = CONCAT28((short)((unkuint10)fpuValue >> 0x40),
                              CONCAT44((int)((unkuint10)fpuValue >> 0x20) + value5,(int)fpuValue + value3
                                      ));
            shortValue = *(short *)(value4 + (uint)CONCAT11((char)value,(char)value2) * 2);
            value8 = value8 + 1;
            if (shortValue != 0) {
              *value8 = shortValue;
            }
            value7 = value6 + -1;
            flagByte = 0 < value6;
            value6 = value7;
          } while (value7 != 0 && flagByte);
        }
        g_RasterizerDestScanlinePtr = g_RasterizerDestScanlinePtr + g_BackBufferStridePixels;
        g_TriangleRightX16 = g_TriangleRightX16 + g_RasterizerRightXStepPerScanline16;
        g_TriangleLeftX16 = g_TriangleLeftX16 + g_RasterizerLeftXStepPerScanline16;
        g_TriangleLeftU16 = g_TriangleLeftU16 + g_RasterizerLeftUStepPerScanline16;
        g_TriangleLeftV16 = g_TriangleLeftV16 + g_RasterizerLeftVStepPerScanline16;
        value3 = g_RasterizerUStepPerPixel16;
        value5 = g_RasterizerVStepPerPixel16;
        value4 = g_CurrentRasterTexturePageBase;
      }
    } while (g_RasterizerCurrentY < g_RasterizerBottomY);
  }
  return;
}

