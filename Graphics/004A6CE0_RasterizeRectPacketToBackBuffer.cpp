#include "tarzan_ghidra_types.hpp"

// Address: 0x004A6CE0
// Label: RasterizeRectPacketToBackBuffer
// Label origin: project
// Original labels and source files are tracked in manifest.csv.

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void RasterizeRectPacketToBackBuffer(void)

{
  int value;
  short shortValue;
  ushort value7;
  bool flagByte;
  uint value8;
  uint value9;
  int value2;
  int value3;
  int value4;
  uint value5;
  uint value6;
  ushort *bufferCursor;
  
  if (((((0 < g_RectPacketWidth) && (0 < g_RectPacketHeight)) && (-1 < g_RectPacketRightX)) &&
      ((-1 < g_RectPacketBottomY && (g_RectPacketLeftX < g_RenderWindowWidth)))) &&
     (g_RectPacketTopY < g_RenderWindowHeight)) {
    g_RasterizerLeftVStepPerScanline16 = g_RectPacketVSpan16 / g_RectPacketHeight;
    g_RasterizerUStepPerPixel16 = g_RectPacketUSpan16 / g_RectPacketWidth;
    if (g_RectPacketLeftX < 0) {
      g_RectPacketWidth = g_RectPacketWidth + g_RectPacketLeftX;
      g_RectPacketCurrentU16 =
           g_RectPacketCurrentU16 - g_RasterizerUStepPerPixel16 * g_RectPacketLeftX;
      g_RectPacketLeftX = 0;
    }
    if (g_RectPacketTopY < 0) {
      g_RectPacketHeight = g_RectPacketHeight + g_RectPacketTopY;
      g_RectPacketCurrentV16 =
           g_RectPacketCurrentV16 - g_RasterizerLeftVStepPerScanline16 * g_RectPacketTopY;
      g_RectPacketTopY = 0;
    }
    if (g_RenderWindowWidth <= g_RectPacketRightX) {
      g_RectPacketWidth = g_RectPacketWidth + (g_RenderWindowWidth - g_RectPacketRightX);
    }
    if (g_RenderWindowHeight <= g_RectPacketBottomY) {
      g_RectPacketHeight = g_RectPacketHeight + (g_RenderWindowHeight - g_RectPacketBottomY);
    }
    if ((0 < g_RectPacketWidth) && (0 < g_RectPacketHeight)) {
      g_CurrentRasterTexturePageBase =
           (g_CurrentRenderPacketTexturePageIndex & 0xf) * 0x20000 + g_GraphicsPageBufferBase;
      g_RasterizerDestScanlinePtr =
           (ushort *)
           (g_BackBufferPixelsPtr + g_BackBufferStridePixels * g_RectPacketTopY +
           g_RectPacketLeftX * 2);
      value5 = g_CurrentRenderPacketTintColor >> 0xb & 0x1f;
      value9 = g_CurrentRenderPacketTintColor >> 0x13 & 0x1f;
      value6 = g_CurrentRenderPacketTintColor >> 3 & 0x1f;
      g_RasterizerCurrentShadeBlue = value6;
      g_RasterizerCurrentShadeGreen = value5;
      g_RasterizerCurrentShadeRed = value9;
      if (g_CurrentRenderPacketBlendMode == 0) {
        if (g_CurrentRenderPacketTintColor == 0xffffff) {
          if (0 < g_RectPacketHeight) {
            g_RasterizerCurrentShadeGreen = 0x1f;
            g_RasterizerCurrentShadeRed = 0x1f;
            g_RasterizerCurrentShadeBlue = 0x1f;
            do {
              value = g_RasterizerUStepPerPixel16;
              value2 = g_CurrentRasterTexturePageBase +
                      (g_RectPacketCurrentV16 >> 0x10 & 0xff) * 0x200;
              g_RasterizerCurrentU16 = g_RectPacketCurrentU16;
              bufferCursor = g_RasterizerDestScanlinePtr + -1;
              value9 = g_RectPacketCurrentU16;
              value3 = g_RectPacketWidth;
              g_RasterizerSpanPixelCount = g_RectPacketWidth;
              do {
                bufferCursor = bufferCursor + 1;
                value7 = *(ushort *)(value2 + (value9 >> 0x10) * 2);
                value9 = value9 + value;
                if (value7 != 0) {
                  *bufferCursor = value7;
                }
                value4 = value3 + -1;
                flagByte = 0 < value3;
                value3 = value4;
              } while (value4 != 0 && flagByte);
              g_RectPacketHeight = g_RectPacketHeight + -1;
              g_RasterizerDestScanlinePtr =
                   (ushort *)((int)g_RasterizerDestScanlinePtr + g_BackBufferStridePixels);
              g_RectPacketCurrentV16 = g_RectPacketCurrentV16 + g_RasterizerLeftVStepPerScanline16;
            } while (0 < g_RectPacketHeight);
            return;
          }
        }
        else {
          value2 = g_RectPacketWidth;
          if (g_CurrentGraphicsPixelLayout == 0) {
            for (; 0 < g_RectPacketHeight; g_RectPacketHeight = g_RectPacketHeight + -1) {
              value = g_CurrentRasterTexturePageBase +
                      (g_RectPacketCurrentV16 >> 0x10 & 0xff) * 0x200;
              g_RasterizerCurrentU16 = g_RectPacketCurrentU16;
              bufferCursor = g_RasterizerDestScanlinePtr;
              for (g_RasterizerSpanPixelCount = value2; 0 < g_RasterizerSpanPixelCount;
                  g_RasterizerSpanPixelCount = g_RasterizerSpanPixelCount + -1) {
                value7 = *(ushort *)(value + (g_RasterizerCurrentU16 >> 0x10 & 0xff) * 2);
                if (value7 != 0) {
                  *bufferCursor = ((ushort)*(byte *)((value7 >> 5 & 0x3e0 | value9) +
                                               g_Modulate5BitBlendLookupTable) << 5 |
                             (ushort)*(byte *)((value7 & 0x3e0 | value5) +
                                              g_Modulate5BitBlendLookupTable)) << 5 |
                             (ushort)*(byte *)(((value7 & 0x1f) << 5 | value6) +
                                              g_Modulate5BitBlendLookupTable);
                  value9 = g_RasterizerCurrentShadeRed;
                  value2 = g_RectPacketWidth;
                  value5 = g_RasterizerCurrentShadeGreen;
                  value6 = g_RasterizerCurrentShadeBlue;
                }
                g_RasterizerCurrentU16 = g_RasterizerCurrentU16 + g_RasterizerUStepPerPixel16;
                bufferCursor = bufferCursor + 1;
              }
              g_RasterizerDestScanlinePtr =
                   (ushort *)((int)g_RasterizerDestScanlinePtr + g_BackBufferStridePixels);
              g_RectPacketCurrentV16 = g_RectPacketCurrentV16 + g_RasterizerLeftVStepPerScanline16;
            }
          }
          else if (0 < g_RectPacketHeight) {
            do {
              value = g_CurrentRasterTexturePageBase +
                      (g_RectPacketCurrentV16 >> 0x10 & 0xff) * 0x200;
              g_RasterizerCurrentU16 = g_RectPacketCurrentU16;
              bufferCursor = g_RasterizerDestScanlinePtr;
              for (g_RasterizerSpanPixelCount = value2; 0 < g_RasterizerSpanPixelCount;
                  g_RasterizerSpanPixelCount = g_RasterizerSpanPixelCount + -1) {
                value7 = *(ushort *)(value + (g_RasterizerCurrentU16 >> 0x10 & 0xff) * 2);
                if (value7 != 0) {
                  *bufferCursor = ((ushort)*(byte *)((value7 >> 6 & 0x3e0 | value9) +
                                               g_Modulate5BitBlendLookupTable) << 5 |
                             (ushort)*(byte *)((value7 >> 1 & 0x3e0 | value5) +
                                              g_Modulate5BitBlendLookupTable)) << 6 |
                             (ushort)*(byte *)(((value7 & 0x1f) << 5 | value6) +
                                              g_Modulate5BitBlendLookupTable);
                  value9 = g_RasterizerCurrentShadeRed;
                  value2 = g_RectPacketWidth;
                  value5 = g_RasterizerCurrentShadeGreen;
                  value6 = g_RasterizerCurrentShadeBlue;
                }
                g_RasterizerCurrentU16 = g_RasterizerCurrentU16 + g_RasterizerUStepPerPixel16;
                bufferCursor = bufferCursor + 1;
              }
              g_RectPacketHeight = g_RectPacketHeight + -1;
              g_RasterizerDestScanlinePtr =
                   (ushort *)((int)g_RasterizerDestScanlinePtr + g_BackBufferStridePixels);
              g_RectPacketCurrentV16 = g_RectPacketCurrentV16 + g_RasterizerLeftVStepPerScanline16;
            } while (0 < g_RectPacketHeight);
            return;
          }
        }
      }
      else if (g_CurrentRenderPacketBlendMode == 1) {
        if (g_CurrentGraphicsPixelLayout == 0) {
          value2 = g_RectPacketWidth;
          if (0 < g_RectPacketHeight) {
            do {
              value = g_CurrentRasterTexturePageBase +
                      (g_RectPacketCurrentV16 >> 0x10 & 0xff) * 0x200;
              g_RasterizerCurrentU16 = g_RectPacketCurrentU16;
              bufferCursor = g_RasterizerDestScanlinePtr;
              for (g_RasterizerSpanPixelCount = value2; 0 < g_RasterizerSpanPixelCount;
                  g_RasterizerSpanPixelCount = g_RasterizerSpanPixelCount + -1) {
                shortValue = *(short *)(value + (g_RasterizerCurrentU16 >> 0x10 & 0xff) * 2);
                value6 = (uint)shortValue;
                if (shortValue != 0) {
                  value8 = (uint)(short)*bufferCursor;
                  *bufferCursor = ((ushort)*(byte *)((value6 >> 5 & 0x3e0 | value8 & 0x7c00 | value9) +
                                               g_Additive5BitBlendLookupTable) << 5 |
                             (ushort)*(byte *)(((value8 & 0x3e0) << 5 | value6 & 0x3e0 | value5) +
                                              g_Additive5BitBlendLookupTable)) << 5 |
                             (ushort)*(byte *)((((value8 & 0x1f) << 5 | value6 & 0x1f) << 5 |
                                               g_RasterizerCurrentShadeBlue) +
                                              g_Additive5BitBlendLookupTable);
                  value9 = g_RasterizerCurrentShadeRed;
                  value2 = g_RectPacketWidth;
                  value5 = g_RasterizerCurrentShadeGreen;
                }
                bufferCursor = bufferCursor + 1;
                g_RasterizerCurrentU16 = g_RasterizerCurrentU16 + g_RasterizerUStepPerPixel16;
              }
              g_RasterizerDestScanlinePtr =
                   (ushort *)((int)g_RasterizerDestScanlinePtr + g_BackBufferStridePixels);
              g_RectPacketHeight = g_RectPacketHeight + -1;
              g_RectPacketCurrentV16 = g_RectPacketCurrentV16 + g_RasterizerLeftVStepPerScanline16;
            } while (0 < g_RectPacketHeight);
            return;
          }
        }
        else {
          value2 = g_RectPacketWidth;
          if (0 < g_RectPacketHeight) {
            do {
              value = g_CurrentRasterTexturePageBase +
                      (g_RectPacketCurrentV16 >> 0x10 & 0xff) * 0x200;
              g_RasterizerCurrentU16 = g_RectPacketCurrentU16;
              bufferCursor = g_RasterizerDestScanlinePtr;
              for (g_RasterizerSpanPixelCount = value2; 0 < g_RasterizerSpanPixelCount;
                  g_RasterizerSpanPixelCount = g_RasterizerSpanPixelCount + -1) {
                value6 = (uint)*(short *)(value + (g_RasterizerCurrentU16 >> 0x10 & 0xff) * 2);
                if (value6 != 0) {
                  value8 = (uint)(short)*bufferCursor;
                  *bufferCursor = ((ushort)*(byte *)(((value6 >> 5 & 0x7c0 | value8 & 0xf800) >> 1 | value9
                                                ) + g_Additive5BitBlendLookupTable) << 5 |
                             (ushort)*(byte *)((value6 >> 1 & 0x3e0 | (value8 & 0x7c0) << 4 | value5)
                                              + g_Additive5BitBlendLookupTable)) << 6 |
                             (ushort)*(byte *)((((value8 & 0x1f) << 5 | value6 & 0x1f) << 5 |
                                               g_RasterizerCurrentShadeBlue) +
                                              g_Additive5BitBlendLookupTable);
                  value9 = g_RasterizerCurrentShadeRed;
                  value2 = g_RectPacketWidth;
                  value5 = g_RasterizerCurrentShadeGreen;
                }
                bufferCursor = bufferCursor + 1;
                g_RasterizerCurrentU16 = g_RasterizerCurrentU16 + g_RasterizerUStepPerPixel16;
              }
              g_RasterizerDestScanlinePtr =
                   (ushort *)((int)g_RasterizerDestScanlinePtr + g_BackBufferStridePixels);
              g_RectPacketHeight = g_RectPacketHeight + -1;
              g_RectPacketCurrentV16 = g_RectPacketCurrentV16 + g_RasterizerLeftVStepPerScanline16;
            } while (0 < g_RectPacketHeight);
            return;
          }
        }
      }
      else if (g_CurrentRenderPacketBlendMode == 2) {
        if (g_CurrentGraphicsPixelLayout == 0) {
          value2 = g_RectPacketWidth;
          if (0 < g_RectPacketHeight) {
            do {
              value = g_CurrentRasterTexturePageBase +
                      (g_RectPacketCurrentV16 >> 0x10 & 0xff) * 0x200;
              g_RasterizerCurrentU16 = g_RectPacketCurrentU16;
              bufferCursor = g_RasterizerDestScanlinePtr;
              for (g_RasterizerSpanPixelCount = value2; 0 < g_RasterizerSpanPixelCount;
                  g_RasterizerSpanPixelCount = g_RasterizerSpanPixelCount + -1) {
                shortValue = *(short *)(value + (g_RasterizerCurrentU16 >> 0x10 & 0xff) * 2);
                value6 = (uint)shortValue;
                if (shortValue != 0) {
                  value8 = (uint)(short)*bufferCursor;
                  *bufferCursor = ((ushort)*(byte *)((value6 >> 5 & 0x3e0 | value8 & 0x7c00 | value9) +
                                               g_Subtractive5BitBlendLookupTable) << 5 |
                             (ushort)*(byte *)(((value8 & 0x3e0) << 5 | value6 & 0x3e0 | value5) +
                                              g_Subtractive5BitBlendLookupTable)) << 5 |
                             (ushort)*(byte *)((((value8 & 0x1f) << 5 | value6 & 0x1f) << 5 |
                                               g_RasterizerCurrentShadeBlue) +
                                              g_Subtractive5BitBlendLookupTable);
                  value9 = g_RasterizerCurrentShadeRed;
                  value2 = g_RectPacketWidth;
                  value5 = g_RasterizerCurrentShadeGreen;
                }
                bufferCursor = bufferCursor + 1;
                g_RasterizerCurrentU16 = g_RasterizerCurrentU16 + g_RasterizerUStepPerPixel16;
              }
              g_RasterizerDestScanlinePtr =
                   (ushort *)((int)g_RasterizerDestScanlinePtr + g_BackBufferStridePixels);
              g_RectPacketHeight = g_RectPacketHeight + -1;
              g_RectPacketCurrentV16 = g_RectPacketCurrentV16 + g_RasterizerLeftVStepPerScanline16;
            } while (0 < g_RectPacketHeight);
            return;
          }
        }
        else {
          value2 = g_RectPacketWidth;
          if (0 < g_RectPacketHeight) {
            do {
              value = g_CurrentRasterTexturePageBase +
                      (g_RectPacketCurrentV16 >> 0x10 & 0xff) * 0x200;
              g_RasterizerCurrentU16 = g_RectPacketCurrentU16;
              bufferCursor = g_RasterizerDestScanlinePtr;
              for (g_RasterizerSpanPixelCount = value2; 0 < g_RasterizerSpanPixelCount;
                  g_RasterizerSpanPixelCount = g_RasterizerSpanPixelCount + -1) {
                value6 = (uint)*(short *)(value + (g_RasterizerCurrentU16 >> 0x10 & 0xff) * 2);
                if (value6 != 0) {
                  value8 = (uint)(short)*bufferCursor;
                  *bufferCursor = ((ushort)*(byte *)(((value6 >> 5 & 0x7c0 | value8 & 0xf800) >> 1 | value9
                                                ) + g_Subtractive5BitBlendLookupTable) << 5 |
                             (ushort)*(byte *)((value6 >> 1 & 0x3e0 | (value8 & 0x7c0) << 4 | value5)
                                              + g_Subtractive5BitBlendLookupTable)) << 6 |
                             (ushort)*(byte *)((((value8 & 0x1f) << 5 | value6 & 0x1f) << 5 |
                                               g_RasterizerCurrentShadeBlue) +
                                              g_Subtractive5BitBlendLookupTable);
                  value9 = g_RasterizerCurrentShadeRed;
                  value2 = g_RectPacketWidth;
                  value5 = g_RasterizerCurrentShadeGreen;
                }
                bufferCursor = bufferCursor + 1;
                g_RasterizerCurrentU16 = g_RasterizerCurrentU16 + g_RasterizerUStepPerPixel16;
              }
              g_RasterizerDestScanlinePtr =
                   (ushort *)((int)g_RasterizerDestScanlinePtr + g_BackBufferStridePixels);
              g_RectPacketHeight = g_RectPacketHeight + -1;
              g_RectPacketCurrentV16 = g_RectPacketCurrentV16 + g_RasterizerLeftVStepPerScanline16;
            } while (0 < g_RectPacketHeight);
            return;
          }
        }
      }
    }
  }
  return;
}

