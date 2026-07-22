#include "tarzan_ghidra_types.hpp"

// Address: 0x004A5160
// Label: RasterizeRenderPacketToBackBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void RasterizeRenderPacketToBackBuffer(code *graphicsObject)

{
  Entity *entity = (Entity *)graphicsObject;
  byte flagByte;
  byte flagByte3;
  byte flagByte4;
  byte flagByte5;
  byte flagByte6;
  byte flagByte7;
  byte flagByte8;
  byte flagByte9;
  byte flagByte10;
  byte flagByte2;
  float edgeSlope;
  float edgeSlope2;
  int value;
  float edgeSlope3;
  ushort value7;
  ushort value8;
  int value2;
  int value3;
  int value4;
  int value5;
  float *floatCursor;
  short shortValue;
  uint value9;
  int value6;
  short shortValue2;
  int scratchBuffer;
  
  g_CurrentRenderPacketTexturePageIndex = *(byte *)((int)graphicsObject + 0x38) & 0x1f;
  edgeSlope3 = *(float *)((int)graphicsObject + 0x38);
  if (((uint)edgeSlope3 & 0x600) != 0x200) {
    if ((((uint)edgeSlope3 & 0x20) == 0) && (g_RenderWindowWidth < 0x141)) {
      *(float *)graphicsObject = *(float *)graphicsObject * _g_Float32768;
      *(float *)((int)graphicsObject + 0xc) =
           *(float *)((int)graphicsObject + 0xc) * _g_FloatRenderHalfPixelOffset;
      *(float *)((int)graphicsObject + 4) = *(float *)((int)graphicsObject + 4) * _g_Float32768;
      *(float *)((int)graphicsObject + 0x10) =
           *(float *)((int)graphicsObject + 0x10) * _g_FloatRenderHalfPixelOffset;
      *(float *)((int)graphicsObject + 8) = *(float *)((int)graphicsObject + 8) * _g_Float32768;
      *(float *)((int)graphicsObject + 0x14) =
           *(float *)((int)graphicsObject + 0x14) * _g_FloatRenderHalfPixelOffset;
    }
    else {
      *(float *)graphicsObject = *(float *)graphicsObject * _g_FloatMillisecondsPerSecond;
      *(float *)((int)graphicsObject + 4) = *(float *)((int)graphicsObject + 4) * _g_FloatMillisecondsPerSecond;
      *(float *)((int)graphicsObject + 8) = *(float *)((int)graphicsObject + 8) * _g_FloatMillisecondsPerSecond;
    }
    value8 = g_TriangleVerticesPastRightEdgeCount_2;
    value7 = g_ClippedTriangleVertexScratch_2;
    g_CurrentClippedTriangleVertexBuffer = &g_RasterizerTriangleVertexBuffer;
    _g_TriangleAreaReciprocalScratch =
         (*(float *)((int)graphicsObject + 4) - *(float *)graphicsObject) *
         (*(float *)((int)graphicsObject + 0x14) - *(float *)((int)graphicsObject + 0xc)) -
         (*(float *)((int)graphicsObject + 8) - *(float *)graphicsObject) *
         (*(float *)((int)graphicsObject + 0x10) - *(float *)((int)graphicsObject + 0xc));
    if (_g_FloatZero <= _g_TriangleAreaReciprocalScratch) {
      g_RasterizerInputVertex1Y = *(float *)((int)graphicsObject + 0x10);
      flagByte7 = *(byte *)((int)graphicsObject + 0x33);
      flagByte8 = *(byte *)((int)graphicsObject + 0x32);
      flagByte9 = *(byte *)((int)graphicsObject + 0x2a);
      flagByte10 = *(byte *)((int)graphicsObject + 0x29);
      flagByte2 = *(byte *)((int)graphicsObject + 0x28);
      g_RasterizerScanlineRightEdge = *(float *)((int)graphicsObject + 8);
      g_RasterizerInputVertex2Y = *(float *)((int)graphicsObject + 0x14);
      flagByte = *(byte *)((int)graphicsObject + 0x35);
      flagByte3 = *(byte *)((int)graphicsObject + 0x34);
      flagByte4 = *(byte *)((int)graphicsObject + 0x2e);
      flagByte5 = *(byte *)((int)graphicsObject + 0x2d);
      flagByte6 = *(byte *)((int)graphicsObject + 0x2c);
      g_RasterizerScanlineLeftEdge = *(float *)((int)graphicsObject + 4);
    }
    else {
      g_RasterizerInputVertex2Y = *(float *)((int)graphicsObject + 0x10);
      flagByte = *(byte *)((int)graphicsObject + 0x33);
      flagByte3 = *(byte *)((int)graphicsObject + 0x32);
      flagByte4 = *(byte *)((int)graphicsObject + 0x2a);
      flagByte5 = *(byte *)((int)graphicsObject + 0x29);
      flagByte6 = *(byte *)((int)graphicsObject + 0x28);
      g_RasterizerInputVertex1Y = *(float *)((int)graphicsObject + 0x14);
      flagByte7 = *(byte *)((int)graphicsObject + 0x35);
      flagByte8 = *(byte *)((int)graphicsObject + 0x34);
      flagByte9 = *(byte *)((int)graphicsObject + 0x2e);
      flagByte10 = *(byte *)((int)graphicsObject + 0x2d);
      flagByte2 = *(byte *)((int)graphicsObject + 0x2c);
      g_RasterizerScanlineLeftEdge = *(float *)((int)graphicsObject + 8);
      g_RasterizerScanlineRightEdge = *(float *)((int)graphicsObject + 4);
    }
    g_RasterizerInputVertex2ShadeBlue16 = (float)((ulonglong)flagByte6 << 0x10);
    g_RasterizerInputVertex2ShadeGreen16 = (float)((ulonglong)flagByte5 << 0x10);
    g_RasterizerInputVertex2ShadeRed16 = (float)((ulonglong)flagByte4 << 0x10);
    g_RasterizerInputVertex2V16 = (float)((ulonglong)flagByte3 << 0x10);
    g_RasterizerInputVertex2U16 = (float)((ulonglong)flagByte << 0x10);
    g_RasterizerInputVertex1ShadeBlue16 = (float)((ulonglong)flagByte2 << 0x10);
    g_RasterizerInputVertex1ShadeGreen16 = (float)((ulonglong)flagByte10 << 0x10);
    g_RasterizerInputVertex1ShadeRed16 = (float)((ulonglong)flagByte9 << 0x10);
    g_RasterizerInputVertex1V16 = (float)((ulonglong)flagByte8 << 0x10);
    g_RasterizerInputVertex1U16 = (float)((ulonglong)flagByte7 << 0x10);
    g_RasterizerTriangleVertexBuffer = *(float *)graphicsObject;
    g_RasterizerInputVertex0Y = *(float *)((int)graphicsObject + 0xc);
    g_RasterizerInputVertex0U16 = (float)((ulonglong)*(byte *)((int)graphicsObject + 0x31) << 0x10);
    shortValue2 = 0;
    g_RasterizerInputVertex0V16 = (float)((ulonglong)*(byte *)((int)graphicsObject + 0x30) << 0x10);
    g_RasterizerInputVertex0ShadeRed16 = (float)((ulonglong)*(byte *)((int)graphicsObject + 0x26) << 0x10);
    g_RasterizerInputVertex0ShadeGreen16 =
         (float)((ulonglong)*(byte *)((int)graphicsObject + 0x25) << 0x10);
    _g_TriangleVerticesPastRightEdgeCount = (uint)g_TriangleVerticesPastRightEdgeCount_2 << 0x10;
    shortValue = 0;
    g_RasterizerInputVertex0ShadeBlue16 = (float)((ulonglong)*(byte *)((int)graphicsObject + 0x24) << 0x10)
    ;
    _g_ClippedTriangleVertexScratch = (uint)g_ClippedTriangleVertexScratch_2 << 0x10;
    if (_g_FloatZero <= g_RasterizerTriangleVertexBuffer) {
      if (_g_RenderWindowWidthF < g_RasterizerTriangleVertexBuffer) {
        shortValue2 = 1;
        _g_TriangleVerticesPastRightEdgeCount = CONCAT22(value8,1);
      }
    }
    else {
      shortValue = 1;
      _g_ClippedTriangleVertexScratch = CONCAT22(value7,1);
    }
    if (_g_FloatZero <= g_RasterizerScanlineLeftEdge) {
      if (_g_RenderWindowWidthF < g_RasterizerScanlineLeftEdge) {
        shortValue2 = shortValue2 + 1;
        _g_TriangleVerticesPastRightEdgeCount =
             CONCAT22(g_TriangleVerticesPastRightEdgeCount_2,shortValue2);
      }
    }
    else {
      shortValue = shortValue + 1;
      _g_ClippedTriangleVertexScratch = CONCAT22(g_ClippedTriangleVertexScratch_2,shortValue);
    }
    if (_g_FloatZero <= g_RasterizerScanlineRightEdge) {
      if (_g_RenderWindowWidthF < g_RasterizerScanlineRightEdge) {
        shortValue2 = shortValue2 + 1;
        _g_TriangleVerticesPastRightEdgeCount =
             CONCAT22(g_TriangleVerticesPastRightEdgeCount_2,shortValue2);
      }
    }
    else {
      shortValue = shortValue + 1;
      _g_ClippedTriangleVertexScratch = CONCAT22(g_ClippedTriangleVertexScratch_2,shortValue);
    }
    if ((shortValue != 3) && (shortValue2 != 3)) {
      edgeSlope3 = *(float *)((int)graphicsObject + 0x24);
      edgeSlope = *(float *)((int)graphicsObject + 0x28);
      edgeSlope2 = *(float *)((int)graphicsObject + 0x2c);
      scratchBuffer = 3;
      if ((_g_TriangleVerticesPastRightEdgeCount & 0xffff) +
          (_g_ClippedTriangleVertexScratch & 0xffff) != 0) {
        scratchBuffer = ClipTrianglePacketToScreenXBounds();
      }
      value9 = (*(ushort *)((int)graphicsObject + 0x38) & 0x1800) >> 0xb;
      graphicsObject = (code *)g_RasterizeTriangleModulatedFn;
      if (value9 == 0) {
        if (((uint)edgeSlope3 & (uint)edgeSlope & (uint)edgeSlope2 & 0xffffff) == 0xffffff) {
          graphicsObject = (code *)g_RasterizeTriangleWhiteFastFn;
        }
      }
      else if (value9 == 1) {
        graphicsObject = RasterizeTriangleAdditiveBlendToBackBuffer;
      }
      else if (value9 == 2) {
        graphicsObject = RasterizeTriangleSubtractiveBlendToBackBuffer;
      }
      g_TriangleClipVertexX0 = *g_CurrentClippedTriangleVertexBuffer;
      g_TriangleClipVertexY0 = g_CurrentClippedTriangleVertexBuffer[1];
      _g_TriangleClipVertexU0_16 = g_CurrentClippedTriangleVertexBuffer[2];
      _g_TriangleClipVertexV0_16 = g_CurrentClippedTriangleVertexBuffer[3];
      _g_TriangleClipVertexShadeRed0_16 = g_CurrentClippedTriangleVertexBuffer[5];
      _g_TriangleClipVertexShadeGreen0_16 = g_CurrentClippedTriangleVertexBuffer[6];
      _g_TriangleClipVertexShadeBlue0_16 = g_CurrentClippedTriangleVertexBuffer[7];
      if (1 < scratchBuffer + -1) {
        scratchBuffer = scratchBuffer + -2;
        floatCursor = g_CurrentClippedTriangleVertexBuffer;
        value6 = 0x20;
        do {
          g_TriangleClipVertexX1 = *(float *)(value6 + (int)floatCursor);
          g_TriangleClipVertexY1 = *(float *)(value6 + 4 + (int)floatCursor);
          _g_TriangleClipVertexU1_16 = *(float *)(value6 + 8 + (int)floatCursor);
          _g_TriangleClipVertexV1_16 = *(float *)(value6 + 0xc + (int)floatCursor);
          _g_TriangleClipVertexShadeRed1_16 = *(float *)(value6 + 0x14 + (int)floatCursor);
          _g_TriangleClipVertexShadeGreen1_16 = *(float *)(value6 + 0x18 + (int)floatCursor);
          _g_TriangleClipVertexShadeBlue1_16 = *(float *)(value6 + 0x1c + (int)floatCursor);
          g_TriangleClipVertexX2 = *(float *)(value6 + 0x20 + (int)floatCursor);
          g_TriangleClipVertexY2 = *(float *)(value6 + 0x24 + (int)floatCursor);
          g_TriangleClipVertexU2_16 = *(float *)(value6 + 0x28 + (int)floatCursor);
          g_TriangleClipVertexV2_16 = *(float *)(value6 + 0x2c + (int)floatCursor);
          g_TriangleClipVertexShadeRed2_16 = *(float *)(value6 + 0x34 + (int)floatCursor);
          g_TriangleClipVertexShadeGreen2_16 = *(float *)(value6 + 0x38 + (int)floatCursor);
          g_TriangleClipVertexShadeBlue2_16 = *(float *)(value6 + 0x3c + (int)floatCursor);
          edgeSlope = g_TriangleClipVertexY2 - g_TriangleClipVertexY0;
          edgeSlope3 = g_TriangleClipVertexY1 - g_TriangleClipVertexY0;
          _g_TriangleAreaReciprocalScratch =
               (g_TriangleClipVertexX1 - g_TriangleClipVertexX0) * edgeSlope -
               (g_TriangleClipVertexX2 - g_TriangleClipVertexX0) * edgeSlope3;
          if (_g_TriangleAreaReciprocalScratch != _g_FloatZero) {
            _g_TriangleAreaReciprocalScratch =
                 _g_FloatMillisecondsPerSecond / _g_TriangleAreaReciprocalScratch;
            _g_RasterizerFpuToIntTemp =
                 (double)(((_g_TriangleClipVertexU1_16 - _g_TriangleClipVertexU0_16) * edgeSlope -
                          (g_TriangleClipVertexU2_16 - _g_TriangleClipVertexU0_16) * edgeSlope3) *
                          _g_TriangleAreaReciprocalScratch + (float)_g_DoubleToIntRoundingBias);
            value2 = g_RasterizerFpuToIntTemp;
            value = g_RasterizerFpuToIntTemp >> 0x1f;
            _g_RasterizerFpuToIntTemp =
                 (double)(((_g_TriangleClipVertexV1_16 - _g_TriangleClipVertexV0_16) * edgeSlope -
                          (g_TriangleClipVertexV2_16 - _g_TriangleClipVertexV0_16) * edgeSlope3) *
                          _g_TriangleAreaReciprocalScratch + (float)_g_DoubleToIntRoundingBias);
            value3 = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((_g_TriangleClipVertexShadeRed1_16 - _g_TriangleClipVertexShadeRed0_16) *
                           edgeSlope - (g_TriangleClipVertexShadeRed2_16 -
                                    _g_TriangleClipVertexShadeRed0_16) * edgeSlope3) *
                          _g_TriangleAreaReciprocalScratch + (float)_g_DoubleToIntRoundingBias);
            value4 = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((_g_TriangleClipVertexShadeGreen1_16 -
                           _g_TriangleClipVertexShadeGreen0_16) * edgeSlope -
                          (g_TriangleClipVertexShadeGreen2_16 - _g_TriangleClipVertexShadeGreen0_16)
                          * edgeSlope3) * _g_TriangleAreaReciprocalScratch +
                         (float)_g_DoubleToIntRoundingBias);
            value5 = g_RasterizerFpuToIntTemp;
            _g_RasterizerFpuToIntTemp =
                 (double)(((_g_TriangleClipVertexShadeBlue1_16 - _g_TriangleClipVertexShadeBlue0_16)
                           * edgeSlope -
                          (g_TriangleClipVertexShadeBlue2_16 - _g_TriangleClipVertexShadeBlue0_16) *
                          edgeSlope3) * _g_TriangleAreaReciprocalScratch +
                         (float)_g_DoubleToIntRoundingBias);
            g_RasterizerUStepPerPixel16 = value2 - value;
            g_RasterizerVStepPerPixel16 = value3 - (value3 >> 0x1f);
            g_RasterizerShadeRedStepPerPixel16 = value4 - (value4 >> 0x1f);
            g_RasterizerShadeGreenStepPerPixel16 = value5 - (value5 >> 0x1f);
            g_RasterizerShadeBlueStepPerPixel16 =
                 g_RasterizerFpuToIntTemp - (g_RasterizerFpuToIntTemp >> 0x1f);
            _g_TriangleMaxYFloat = g_TriangleClipVertexY0;
            _g_TriangleMinYFloat = g_TriangleClipVertexY0;
            edgeSlope3 = g_TriangleClipVertexY1;
            if (g_TriangleClipVertexY1 < g_TriangleClipVertexY0) {
              _g_TriangleMinYFloat = g_TriangleClipVertexY1;
              edgeSlope3 = _g_TriangleMaxYFloat;
            }
            _g_TriangleMaxYFloat = edgeSlope3;
            g_TriangleLeftEdgeVertexIndex = (uint)(g_TriangleClipVertexY1 < g_TriangleClipVertexY0);
            if (g_TriangleClipVertexY2 < _g_TriangleMinYFloat) {
              g_TriangleLeftEdgeVertexIndex = 2;
              _g_TriangleMinYFloat = g_TriangleClipVertexY2;
            }
            if (_g_TriangleMaxYFloat < g_TriangleClipVertexY2) {
              _g_TriangleMaxYFloat = g_TriangleClipVertexY2;
            }
            g_RasterizerCurrentY = ConvertFpuTopToInt64();
            if (g_RasterizerCurrentY < 0) {
              g_RasterizerCurrentY = 0;
            }
            g_RasterizerBottomY = ConvertFpuTopToInt64();
            if (g_RenderWindowHeight < g_RasterizerBottomY) {
              g_RasterizerBottomY = g_RenderWindowHeight;
            }
            (entity->activeFlags)();
            floatCursor = g_CurrentClippedTriangleVertexBuffer;
          }
          scratchBuffer = scratchBuffer + -1;
          value6 = value6 + 0x20;
        } while (scratchBuffer != 0);
      }
    }
    return;
  }
  if ((((uint)edgeSlope3 & 0x20) == 0) && (g_RenderWindowWidth < 0x141)) {
    *(float *)graphicsObject = *(float *)graphicsObject * _g_FloatRenderHalfPixelOffset;
    *(float *)((int)graphicsObject + 0xc) = *(float *)((int)graphicsObject + 0xc) * _g_FloatRenderHalfPixelOffset;
    *(float *)((int)graphicsObject + 4) = *(float *)((int)graphicsObject + 4) * _g_FloatRenderHalfPixelOffset;
    *(float *)((int)graphicsObject + 0x10) =
         *(float *)((int)graphicsObject + 0x10) * _g_FloatRenderHalfPixelOffset;
    *(float *)((int)graphicsObject + 8) = *(float *)((int)graphicsObject + 8) * _g_FloatRenderHalfPixelOffset;
    *(float *)((int)graphicsObject + 0x14) =
         *(float *)((int)graphicsObject + 0x14) * _g_FloatRenderHalfPixelOffset;
  }
  g_RectPacketLeftX = ConvertFpuTopToInt64();
  g_RectPacketTopY = ConvertFpuTopToInt64();
  g_RectPacketRightX = ConvertFpuTopToInt64();
  g_RectPacketBottomY = ConvertFpuTopToInt64();
  g_RectPacketWidth = ConvertFpuTopToInt64();
  g_RectPacketHeight = ConvertFpuTopToInt64();
  g_RectPacketCurrentU16 = (uint)*(byte *)((int)graphicsObject + 0x31) << 0x10;
  g_RectPacketCurrentV16 = (uint)*(byte *)((int)graphicsObject + 0x30) << 0x10;
  g_RectPacketUSpan16 = (uint)*(ushort *)((int)graphicsObject + 0x32) << 0x10;
  g_RectPacketVSpan16 = (uint)*(ushort *)((int)graphicsObject + 0x34) << 0x10;
  g_CurrentRenderPacketTintColor = (uint)*(float *)((int)graphicsObject + 0x24) & 0xffffff;
  g_CurrentRenderPacketBlendMode = (*(ushort *)((int)graphicsObject + 0x38) & 0x1800) >> 0xb;
  RasterizeRectPacketToBackBuffer();
  return;
}

