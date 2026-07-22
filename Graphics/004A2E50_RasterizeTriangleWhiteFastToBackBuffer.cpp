#include "tarzan_ghidra_types.hpp"

// Address: 0x004A2E50
// Label: RasterizeTriangleWhiteFastToBackBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeTriangleWhiteFastToBackBuffer(void)

{
  float *floatCursor;
  int value2;
  char resultFlag;
  int value3;
  int value4;
  uint value8;
  uint value9;
  uint value10;
  char resultFlag2;
  short shortValue;
  uint value7;
  int value;
  short *value5;
  bool flagByte;
  float10 fpuResult;
  float10 fpuResult2;
  float10 fpuResult3;
  uint value6;
  short shortValue2;
  
  g_RasterizerDestScanlinePtr =
       g_BackBufferStridePixels * g_RasterizerCurrentY + g_BackBufferPixelsPtr;
  g_CurrentRasterTexturePageBase =
       (g_CurrentRenderPacketTexturePageIndex & 0xf) * 0x20000 + g_GraphicsPageBufferBase;
  g_TriangleRightEdgeVertexIndex = g_TriangleLeftEdgeVertexIndex;
  g_TriangleRightEdgeEndY = 0;
  g_TriangleLeftEdgeEndY = 0;
  if (g_RasterizerCurrentY < g_RasterizerBottomY) {
    do {
      value4 = g_TriangleLeftEdgeVertexIndex;
      value = g_TriangleLeftEdgeVertexIndex;
      if (g_TriangleLeftEdgeEndY <= g_RasterizerCurrentY) {
        do {
          value = value4 + -1;
          if (value < 0) {
            value = 2;
          }
          if ((float)(&g_TriangleClipVertexY0)[value] - (float)(&g_TriangleClipVertexY0)[value4] !=
              _g_FloatZero) {
            value3 = ConvertFpuTopToInt64();
            g_RasterizerLeftXStepPerScanline16 = value3 - (value3 >> 0x1f);
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexU0_16 + value * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexU0_16 + value4 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            g_RasterizerLeftUStepPerScanline16 =
                 g_RasterizerFpuToIntTemp - (g_RasterizerFpuToIntTemp >> 0x1f);
            _g_RasterizerFpuToIntTemp =
                 (double)(((float10)*(float *)(&g_TriangleClipVertexV0_16 + value * 4) -
                          (float10)*(float *)(&g_TriangleClipVertexV0_16 + value4 * 4)) *
                          fpuResult + (float10)_g_DoubleToIntRoundingBias);
            g_RasterizerLeftVStepPerScanline16 =
                 g_RasterizerFpuToIntTemp - (g_RasterizerFpuToIntTemp >> 0x1f);
          }
          g_TriangleLeftX16 = ConvertFpuTopToInt64();
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexU0_16 + value4 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          value3 = g_RasterizerFpuToIntTemp;
          g_TriangleLeftU16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerFpuToIntTemp =
               (double)(*(float *)(&g_TriangleClipVertexV0_16 + value4 * 4) +
                       (float)_g_DoubleToIntRoundingBias);
          value2 = g_RasterizerFpuToIntTemp;
          g_TriangleLeftV16 = g_RasterizerFpuToIntTemp;
          _g_RasterizerYFractionToNextScanline =
               (float)(fpuResult2 - (float10)(float)(&g_TriangleClipVertexY0)[value4]);
          if (fpuResult2 - (float10)(float)(&g_TriangleClipVertexY0)[value4] !=
              (float10)_g_RenderNearClipDepth) {
            if (_g_RenderNearClipDepth < _g_RasterizerYFractionToNextScanline) {
              _g_RasterizerYFractionToNextScanline =
                   _g_RasterizerYFractionToNextScanline - _g_RenderNearClipDepth;
            }
            value4 = ConvertFpuTopToInt64();
            g_TriangleLeftX16 = g_TriangleLeftX16 + value4;
            _g_RasterizerFpuToIntTemp =
                 (double)((float)g_RasterizerLeftUStepPerScanline16 *
                          _g_RasterizerYFractionToNextScanline + (float)_g_DoubleToIntRoundingBias);
            g_TriangleLeftU16 = value3 + g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)((float)g_RasterizerLeftVStepPerScanline16 *
                          _g_RasterizerYFractionToNextScanline + (float)_g_DoubleToIntRoundingBias);
            g_TriangleLeftV16 = value2 + g_RasterizerFpuToIntTemp;
          }
          g_TriangleLeftEdgeEndY = ConvertFpuTopToInt64();
          value4 = value;
        } while (g_TriangleLeftEdgeEndY <= g_RasterizerCurrentY);
      }
      g_TriangleLeftEdgeVertexIndex = value;
      if (g_TriangleRightEdgeEndY <= g_RasterizerCurrentY) {
        do {
          value = g_TriangleRightEdgeVertexIndex + 1;
          if (2 < value) {
            value = 0;
          }
          floatCursor = (float *)(&g_TriangleClipVertexY0 + g_TriangleRightEdgeVertexIndex);
          if ((float)(&g_TriangleClipVertexY0)[value] -
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
            value4 = ConvertFpuTopToInt64();
            g_TriangleRightX16 = g_TriangleRightX16 + value4;
          }
          g_TriangleRightEdgeVertexIndex = value;
          g_TriangleRightEdgeEndY = ConvertFpuTopToInt64();
        } while (g_TriangleRightEdgeEndY <= g_RasterizerCurrentY);
      }
      g_RasterizerSpanPixelCount = g_TriangleRightEdgeEndY;
      if (g_TriangleLeftEdgeEndY < g_TriangleRightEdgeEndY) {
        g_RasterizerSpanPixelCount = g_TriangleLeftEdgeEndY;
      }
      g_RasterizerScanlineRowCount = g_RasterizerSpanPixelCount - g_RasterizerCurrentY;
      g_RasterizerCurrentY = g_RasterizerSpanPixelCount;
      value = g_CurrentRasterTexturePageBase;
      if (g_RasterizerBottomY < g_RasterizerSpanPixelCount) {
        g_RasterizerScanlineRowCount =
             g_RasterizerScanlineRowCount + (g_RasterizerBottomY - g_RasterizerSpanPixelCount);
      }
      for (; g_CurrentRasterTexturePageBase = value, 0 < g_RasterizerScanlineRowCount;
          g_RasterizerScanlineRowCount = g_RasterizerScanlineRowCount + -1) {
        _g_RasterizerSpanStartX = g_TriangleLeftX16 >> 0x10;
        g_RasterizerSpanPixelCount = (g_TriangleRightX16 >> 0x10) - _g_RasterizerSpanStartX;
        if (0 < g_RasterizerSpanPixelCount) {
          value5 = (short *)(g_RasterizerDestScanlinePtr + _g_RasterizerSpanStartX * 2);
          resultFlag = (char)((uint)g_RasterizerVStepPerPixel16 >> 0x10);
          resultFlag2 = (char)((uint)g_RasterizerUStepPerPixel16 >> 0x10);
          value6 = CONCAT22((short)g_RasterizerUStepPerPixel16,CONCAT11(resultFlag,resultFlag2));
          value9 = g_TriangleLeftV16 << 0x10;
          value10 = CONCAT21((short)((uint)g_TriangleLeftV16 >> 0x10),
                           (char)((uint)g_TriangleLeftU16 >> 0x10)) & 0xffff;
          value7 = CONCAT22((short)g_RasterizerVStepPerPixel16,(short)g_RasterizerSpanPixelCount);
          value4 = g_TriangleLeftU16 << 0x10;
          g_RasterizerCurrentPixelPtr = value5;
          do {
            shortValue = *(short *)(value + value10 * 2);
            value8 = CONCAT22((short)((uint)value4 >> 0x10),shortValue);
            if (shortValue != 0) {
              *value5 = shortValue;
            }
            flagByte = CARRY4(value9,value7);
            value9 = value9 + value7;
            value4 = value8 + value6;
            value10 = (uint)CONCAT11((char)(value10 >> 8) + resultFlag + flagByte,
                                   (char)value10 + resultFlag2 + CARRY4(value8,value6));
            value5 = value5 + 1;
            shortValue2 = (short)value7;
            shortValue = shortValue2 + -1;
            value7 = CONCAT22((short)(value7 >> 0x10),shortValue);
          } while (shortValue != 0 && 0 < shortValue2);
        }
        g_RasterizerDestScanlinePtr = g_RasterizerDestScanlinePtr + g_BackBufferStridePixels;
        g_TriangleLeftX16 = g_TriangleLeftX16 + g_RasterizerLeftXStepPerScanline16;
        g_TriangleRightX16 = g_TriangleRightX16 + g_RasterizerRightXStepPerScanline16;
        g_TriangleLeftU16 = g_TriangleLeftU16 + g_RasterizerLeftUStepPerScanline16;
        g_TriangleLeftV16 = g_TriangleLeftV16 + g_RasterizerLeftVStepPerScanline16;
        value = g_CurrentRasterTexturePageBase;
      }
    } while (g_RasterizerCurrentY < g_RasterizerBottomY);
  }
  return;
}

